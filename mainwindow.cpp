#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName();
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        file.write(ui->textEdit->toPlainText().toUtf8());
    }
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    //if (file.open(QIODevice::ReadOnly|QIODevice::Text)) return;
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    ui->textEdit->setPlainText(QString::fromUtf8(file.readAll()));
}

void MainWindow::on_actionOpen_triggered()
{
  openFile();
}

void MainWindow::on_actionSave_triggered()
{
  saveFile();
}

void MainWindow::on_actionNew_File_triggered()
{
    ui->textEdit->clear();
}
