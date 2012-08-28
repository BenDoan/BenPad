#include "mainwindow.h"
#include "ui_mainwindow.h"

    MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setAcceptRichText(FALSE);
    MainWindow::setWindowTitle("Untitled - BenPad");
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
    MainWindow::setWindowTitle(filePath.toUtf8() + " - BenPad");
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
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    MainWindow::setWindowTitle(filePath.toUtf8() + " - BenPad");
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
    MainWindow::setWindowTitle("Untitled - BenPad");
}

void MainWindow::on_actionSave_As_triggered()
{
    saveFileAs();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionAbout_triggered()
{
    std::cerr << "about\n";
}

void MainWindow::on_actionSelect_All_triggered()
{
   ui->textEdit->selectAll();
}

void MainWindow::on_actionUndo_triggered()
{
   ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
   ui->textEdit->redo();
}

void MainWindow::on_actionDelete_triggered()
{
   ui->textEdit->textCursor().removeSelectedText();
}

void MainWindow::on_actionCut_triggered()
{
   ui->textEdit->cut();
}

void MainWindow::on_actionQuit_triggered()
{
   qApp->exit();
}
