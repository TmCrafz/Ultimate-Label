#ifndef PROFILESDIALOG_H
#define PROFILESDIALOG_H
#include "profile.h"
#include <QDialog>
#include <QListWidgetItem>
#include <QMap>
#include <QString>


namespace Ui {
class ProfilesDialog;
}

class ProfilesDialog : public QDialog
{
    Q_OBJECT
private:
       Ui::ProfilesDialog *ui;
       QMap<QString,Profile> m_profiles;
public:
    explicit ProfilesDialog(QWidget *parent = 0);
    ~ProfilesDialog();

private slots:
       void on_listWidget_profiles_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

       void on_pushButton_delete_clicked();

private:
    // Set all option widgets to enabled or not enabled
    void setOptionsEnabled(bool enabled);
    // Clear all fields of options so there are empty
    void clearOptionFields();
};

#endif // PROFILESDIALOG_H
