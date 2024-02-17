#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "resultwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("Menu");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//// Nastaveni tlacitek
void MainWindow::on_pushButton_clicked()        //// Play - spusteni hry
{

    this->hide();
    Game game = Game();                         //// presmerovani na okno hry
    int x=game.run();
    resultwindow resw=resultwindow(x);
    resw.setModal(true);
    resw.exec();
}

void MainWindow::on_pushButton_3_clicked()      //// Quit - vypnuti hry
{
    close();
}

