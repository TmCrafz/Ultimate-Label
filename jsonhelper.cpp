#include "jsonhelper.h"
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

const QString JSONHelper::JSON_PROFILES = "profiles";
const QString JSONHelper::PROFILES_FILENAME = "profiles.json";

JSONHelper::JSONHelper()
{

}

bool JSONHelper::writeToJson(QString fileName, std::vector<Profile> *profiles)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        qWarning() << "Error by opening Json file \n";
        return false;
    }
    QJsonArray profilesArray;
    for (Profile& profile : *profiles)
    {
        QJsonObject profileObject;
        profile.writeToJson(profileObject);
        profilesArray.append(profileObject);
    }
    QJsonObject root;
    root.insert(JSON_PROFILES, profilesArray);
    QJsonDocument saveDoc(root);
    file.write(saveDoc.toJson());
    return true;
}

bool JSONHelper::readFromJson(QString fileName, std::vector<Profile> *profiles)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning() << "Error by opening Json file \n";
        return false;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonObject root(doc.object());
    QJsonArray profilesArray = root.value(JSON_PROFILES).toArray();
    // Load profiles and store them
    for (int i = 0; i < profilesArray.size(); i++)
    {
        QJsonObject profileObject = profilesArray.at(i).toObject();
        Profile profile;
        profile.readFromJson(profileObject);
        profiles->push_back(profile);
    }
    return true;


}
