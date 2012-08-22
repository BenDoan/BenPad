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

void MainWindow::saveFileAs()
{
    filePath = QFileDialog::getSaveFileName();
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        file.write(ui->textEdit->toPlainText().toUtf8());
    }
}

void MainWindow::saveFile()
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        file.write(ui->textEdit->toPlainText().toUtf8());
    }
}

void MainWindow::openFile()
{
    filePath = QFileDialog::getOpenFileName(this);
    QFile file(filePath);
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
  if (filePath.isEmpty())
  {
      saveFileAs();
  }else
  {
      saveFile();
  }

}

void MainWindow::on_actionNew_File_triggered()
{
    ui->textEdit->clear();
    filePath = "";
}

void MainWindow::on_actionCopy_triggered()
{
    std::cout << "hello";
}

void MainWindow::on_actionSave_As_triggered()
{
    saveFileAs();
}
