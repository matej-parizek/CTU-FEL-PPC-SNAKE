#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "mainwindow.h"
#include "game.h"
#include <string>
#include <sstream>

resultwindow::resultwindow(int score,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultwindow)
{

    ui->setupUi(this);
    setWindowTitle("Table");
    ui->label_3->setText( QString::number(score) );     //// Zobrazeni skore
}

resultwindow::~resultwindow()
{
    delete ui;
}

//// Nastaveni tlacitek
void resultwindow::on_pushButton_3_clicked()            //// Quit - vypnuti hry
{
    close();
}

void resultwindow::on_pushButton_2_clicked()            //// Menu - navrat do hlaniho menu
{
    this->close();
    MainWindow *mainWin=new MainWindow();
    mainWin->show();
}

void resultwindow::on_pushButton_clicked()              //// Play again - opetovne spusteni hry
{
    this->hide();
    Game game = Game();
    int x=game.run();
    resultwindow resw = resultwindow(x);
    resw.setModal(true);
    resw.exec();
}
