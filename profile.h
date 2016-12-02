#ifndef PROFILE_H
#define PROFILE_H
#include <QJsonObject>
#include <QString>

class Profile
{
private:
    QString m_name;
    QString m_seperator;
    QString m_templateText;
public:
    Profile();
    Profile(QString name, QString seperator, QString templateText);

    QString getName() const;
    void setName(QString name);

    QString getSeperator() const;
    void setSeperator(QString seperator);

    QString getTemplateText() const;
    void setTemplateText(QString templateText);

    void writeToJson(QJsonObject &json) const;
    void readFromJson(QJsonObject &json);
};

#endif // PROFILE_H
