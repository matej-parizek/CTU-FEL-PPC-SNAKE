#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();           //// Tlacitko Play

    void on_pushButton_3_clicked();         //// Tlacitko Quit

private:
    Ui::Menu *ui;
};

#endif // MAINWINDOW_H
