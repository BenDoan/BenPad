#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QIODevice>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void saveFile();
    void openFile();
    
private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
