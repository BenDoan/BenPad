#include "mainwindow.h"
#include "ui_mainwindow.h"

    MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpEditor();

    //adds new tab button
    QToolButton *newTabButton = new QToolButton(this);
    ui->tabWidget->setCornerWidget(newTabButton);
    newTabButton->setAutoRaise(true);
    newTabButton->setText("+");
    QObject::connect(newTabButton, SIGNAL(clicked()), this, SLOT(makeNewTab()));
    QObject::connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(deleteTab(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::currentTab()
{
    return ui->tabWidget->currentIndex();
}

QString MainWindow::extractFilename(QString path)
{
    string stdPath = path.toStdString();
    #ifdef WIN32
        return QString::fromStdString(stdPath.substr(stdPath.find_last_of('\\') + 1));
    #else
        return QString::fromStdString(stdPath.substr(stdPath.find_last_of('/') + 1));
    #endif
}

void MainWindow::setUpEditor()
{
    ui->textEdit->setAcceptRichText(FALSE);
    MainWindow::setWindowTitle("Untitled - BenPad");
    MainWindow::setWindowIcon(QIcon(QApplication::applicationDirPath() + "/icon.png"));
    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->removeTab(1); // removes the redunant second tab
    ui->tabWidget->setTabText(0, "Untitled");

    Tab tab;
    tab.number = 0;
    tab.path = "";
    tab.filename = "";
    tab.textEdit = ui->textEdit;
    tabs.push_back(tab);
}

void MainWindow::setTabName(unsigned int index, QString text){
    ui->tabWidget->setTabText(index, text);
}

void MainWindow::saveFileAs()
{
    QString tmpPath = QFileDialog::getSaveFileName();
    QFile file(tmpPath);
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        tabs[currentTab()].path = tmpPath;
        file.write(ui->textEdit->toPlainText().toUtf8());
        MainWindow::setWindowTitle(tabs[currentTab()].path.toUtf8() + " - BenPad");
        tabs[currentTab()].filename = extractFilename(tabs[currentTab()].path);
        setTabName(currentTab(), tabs[currentTab()].filename);
    }
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
    QString tmpPath = QFileDialog::getOpenFileName(this);
    QFile file(tmpPath);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        tabs[currentTab()].path = tmpPath;
        QByteArray byteArray = file.readAll();
        tabs[currentTab()].textEdit->setPlainText(byteArray.data());

        MainWindow::setWindowTitle(tabs[currentTab()].path.toUtf8() + " - BenPad");
        tabs[currentTab()].filename = extractFilename(tabs[currentTab()].path);
        setTabName(currentTab(), tabs[currentTab()].filename);
    }
}

void MainWindow::makeNewTab()
{
    Tab tab;
    tab.textEdit = new QTextEdit;
    ui->tabWidget->addTab(tab.textEdit, "Untitled");
    tab.number = tabs[tabs.size() - 1].number + 1;
    tab.path = "";
    tab.filename = "";
    tabs.push_back(tab);
}

void MainWindow::deleteTab(int i)
{
    tabs[i].textEdit->deleteLater();
    tabs.erase(tabs.begin() + i);
    ui->tabWidget->removeTab(i);
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
    setTabName(currentTab(), "Untitled");
}

void MainWindow::on_actionSave_As_triggered()
{
    saveFileAs();
}

void MainWindow::on_actionCopy_triggered()
{
   tabs[currentTab()].textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
   tabs[currentTab()].textEdit->paste();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About - BenPad", "BenPad pre-alpha\n");
}

void MainWindow::on_actionSelect_All_triggered()
{
   tabs[currentTab()].textEdit->selectAll();
}

void MainWindow::on_actionUndo_triggered()
{
   tabs[currentTab()].textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
   tabs[currentTab()].textEdit->redo();
}

void MainWindow::on_actionDelete_triggered()
{
   tabs[currentTab()].textEdit->textCursor().removeSelectedText();
}

void MainWindow::on_actionCut_triggered()
{
   tabs[currentTab()].textEdit->cut();
}

void MainWindow::on_actionQuit_triggered()
{
   qApp->exit();
}

void MainWindow::on_actionNew_Tab_triggered()
{
  makeNewTab();
}
