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

    //connect signals
    QObject::connect(newTabButton, SIGNAL(clicked()), this, SLOT(makeNewTab()));
    QObject::connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(deleteTab(int)));

    //create keyboard shortcuts
    QShortcut *shortcut = new QShortcut(QKeySequence("ctrl+w"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(deleteCurrentTab()));

    shortcut = new QShortcut(QKeySequence("ctrl+t"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(makeNewTab()));

    shortcut = new QShortcut(QKeySequence("ctrl+s"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionSave_triggered()));

    shortcut = new QShortcut(QKeySequence("ctrl+shift+s"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionSave_As_triggered()));

    shortcut = new QShortcut(QKeySequence("ctrl+o"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionOpen_triggered()));

    shortcut = new QShortcut(QKeySequence("ctrl+q"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionQuit_triggered()));

    shortcut = new QShortcut(QKeySequence("ctrl+tab"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(switchToNextTab()));

    shortcut = new QShortcut(QKeySequence("ctrl+shift+tab"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(switchToPrevTab()));

    shortcut = new QShortcut(QKeySequence("ctrl+d"), ui->tabWidget);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(deleteLine()));
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
    ui->tabWidget->setTabsClosable(false);
    ui->tabWidget->removeTab(1); // removes the redunant second tab

    //sets the tab data for the first tab
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

void MainWindow::switchToNextTab()
{
    if (currentTab() != (tabs.size() - 1))
    {
        ui->tabWidget->setCurrentIndex(currentTab() + 1);
    }else
    {
        ui->tabWidget->setCurrentIndex(0);
    }
}

void MainWindow::switchToPrevTab()
{
    if (currentTab() != 0)
    {
        ui->tabWidget->setCurrentIndex(currentTab() - 1);
    }
    else
    {
        ui->tabWidget->setCurrentIndex(tabs.size() - 1);

    }
}

void MainWindow::deleteLine()
{
    cerr << "Delete line";
    //tabs[currentTab()].textEdit->textCursor().movePosition(QTextCursor::StartOfLine);
    //tabs[currentTab()].textEdit->textCursor().removeSelectedText();
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

    ui->tabWidget->setCurrentIndex(tab.number);

    if (tabs.size() > 1) {
        ui->tabWidget->setTabsClosable(true);
    }
}

void MainWindow::deleteCurrentTab()
{
    deleteTab(currentTab());
}

void MainWindow::deleteTab(int i)
{
    tabs[i].textEdit->deleteLater();
    tabs.erase(tabs.begin() + i);
    ui->tabWidget->removeTab(i);
    if (tabs.size() == 1) {
        ui->tabWidget->setTabsClosable(false);
    }
}

void MainWindow::displaySettingsDialog()
{
    //settings dialog(this);
    //dialog.exec();
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

void MainWindow::on_actionAnimate_triggered()
{
}

void MainWindow::on_actionSettings_triggered()
{
   displaySettingsDialog();
}
