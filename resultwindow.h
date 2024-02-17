#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>

namespace Ui {
class resultwindow;
}

class resultwindow : public QDialog
{
    Q_OBJECT
public:
    explicit resultwindow(int score,QWidget *parent = nullptr);
    ~resultwindow();

private slots:
    void on_pushButton_3_clicked();     //// Tlacitko Quit

    void on_pushButton_2_clicked();     //// Tlacitko Menu

    void on_pushButton_clicked();       //// Tlacitko Play again

private:
    Ui::resultwindow *ui;
};

#endif // RESULTWINDOW_H
