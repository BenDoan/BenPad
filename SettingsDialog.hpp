#ifndef SETTINGSDIALOG_HPP
#define SETTINGSDIALOG_HPP

#include <QDialog>

class QDialogButtonBox;
class QFileInfo;
class QTabWidget;

class GeneralTab : public QWidget
{
    Q_OBJECT

    public:
        GeneralTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

class SecondaryTab : public QWidget
{
    Q_OBJECT

    public:
        SecondaryTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

class SettingsDialog : public Qdialog
{
    Q_OBJECT

    public:
        SettingsDialog(const QString &filename, QWidget *parent = 0);

    private:
        QTabWidget *tabWidget;
        QDialogButtonBox *buttonBox;

};

#endif
