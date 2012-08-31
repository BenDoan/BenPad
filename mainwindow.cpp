#include "mainwindow.h"
#include "ui_mainwindow.h"

    MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setAcceptRichText(FALSE);
    QToolButton *newTabButton = new QToolButton(this);
    ui->tabWidget->setCornerWidget(newTabButton);
    newTabButton->setAutoRaise(true);
    newTabButton->setText("+");
    QObject::connect(newTabButton, SIGNAL(clicked()), this, SLOT(makeNewTab()));
    MainWindow::setWindowTitle("Untitled - BenPad");
    MainWindow::setWindowIcon(QIcon(QApplication::applicationDirPath() + "/icon.png"));

    Tab tab;
    tab.number = 0;
    tab.path = "";
    tabs.push_back(tab);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::currentTab(){
    return ui->tabWidget->currentIndex();
}

void MainWindow::saveFileAs()
{
    QFile file(tabs[currentTab()].path = QFileDialog::getSaveFileName());
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        file.write(ui->textEdit->toPlainText().toUtf8());
    }
    MainWindow::setWindowTitle(tabs[currentTab()].path.toUtf8() + " - BenPad");
}

void MainWindow::saveFile()
{
    QFile file(tabs[currentTab()].path);
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        file.write(ui->textEdit->toPlainText().toUtf8());
    }
}

void MainWindow::openFile()
{
    QFile file(tabs[currentTab()].path = QFileDialog::getOpenFileName(this));
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    MainWindow::setWindowTitle(tabs[currentTab()].path.toUtf8() + " - BenPad");
}

void MainWindow::makeNewTab()
{
   ui->tabWidget->addTab(new QTextEdit, "new tab");
   Tab tab;
   tab.number = tabs[0].number + 1;
   tab.path = "";
   tabs.push_back(tab);
}

void MainWindow::on_actionOpen_triggered()
{
  openFile();
}

void MainWindow::on_actionSave_triggered()
{
  if (tabs[currentTab()].path.isEmpty())
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
    cerr << "about\n";
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

void MainWindow::on_actionNew_Tab_triggered()
{
  makeNewTab();
}
