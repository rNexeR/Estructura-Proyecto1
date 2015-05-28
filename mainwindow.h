#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <list>
#include "tamagotchi.h"
#include "CrearTamagotchi.h"
#include "Cuidar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    list<Tamagotchi*> *granja;

public slots:
    void update();

private slots:
    void on_cmbAnimales_currentIndexChanged(const QString &arg1);

    void on_btnCuidar_2_clicked();

    void on_btnCuidar_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
};

#endif // MAINWINDOW_H
