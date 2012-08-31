#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QIcon>
#include <QIODevice>
#include <QToolButton>
#include <vector>

#include <QMainWindow>

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
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionNew_File_triggered();

    void on_actionCopy_triggered();

    void on_actionSave_As_triggered();

    void on_actionPaste_triggered();

    void on_actionAbout_triggered();

    void on_actionSelect_All_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionDelete_triggered();

    void on_actionCut_triggered();

    void on_actionQuit_triggered();

    void on_actionNew_Tab_triggered();

    void makeNewTab();

    int currentTab();

private:
    void saveFileAs();
    void saveFile();
    void openFile();
    Ui::MainWindow *ui;
    QString fileName;

    struct Tab {
        int number;
        QString path;
    };
    vector<Tab> tabs;
};

#endif // MAINWINDOW_H
