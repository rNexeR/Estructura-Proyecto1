#ifndef CUIDAR_H
#define CUIDAR_H

#include <QWidget>
#include <QTimer>
#include <list>
#include "tamagotchi.h"

namespace Ui {
class Cuidar;
}

class Cuidar : public QWidget
{
    Q_OBJECT

public:
    explicit Cuidar(QWidget *parent = 0);
    ~Cuidar();

public slots:
    void setParametros(list<Tamagotchi*>* animales, Tamagotchi* actual);
    void update();
    void closeEvent (QCloseEvent *event);
    void closeWindow();
    void changeButtonsState(bool state);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Cuidar *ui;
    QTimer* timer;
    list<Tamagotchi*>* animales;
    Tamagotchi* actual;
    int segundos;
};

#endif // CUIDAR_H
