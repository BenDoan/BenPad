#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QIcon>
#include <QIODevice>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegExp>
#include <QShortcut>
#include <QTextEdit>
#include <QTextStream>
#include <QToolButton>
#include <QWidget>
#include <string>
#include <vector>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QTextCursor>
#include <QDialog>

#include "settings.h"
#include "highlighter.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleNewSettings();
    void deleteLine();
    void switchToPrevTab();
    void switchToNextTab();
    void makeNewTab();
    void deleteTab(int);
    void deleteCurrentTab();
    void on_actionAbout_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionDelete_triggered();
    void on_actionNew_File_triggered();
    void on_actionNew_Tab_triggered();
    void on_actionOpen_triggered();
    void on_actionPaste_triggered();
    void on_actionQuit_triggered();
    void on_actionRedo_triggered();
    void on_actionSave_As_triggered();
    void on_actionSave_triggered();
    void on_actionSelect_All_triggered();
    void on_actionUndo_triggered();
    void on_actionAnimate_triggered();
    void on_actionSettings_triggered();

private:
    void saveFileAs();
    void saveFile();
    void openFile();
    void setUpEditor();
    void displaySettingsDialog();
    int currentTab();
    void setTabName(unsigned int index, QString text);
    QString extractFilename(QString path);
    Ui::MainWindow *ui;

    struct Tab {
        int number;
        QString path;
        QString filename;
        QTextEdit *textEdit;
        Highlighter *highlighter;
    };
    vector<Tab> tabs;
};

#endif // MAINWINDOW_H
