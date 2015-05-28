#ifndef CREARTAMAGOTCHI_H
#define CREARTAMAGOTCHI_H

#include <QWidget>
#include "tamagotchi.h"

namespace Ui {
class CrearTamagotchi;
}

class CrearTamagotchi : public QWidget
{
    Q_OBJECT

public:
    explicit CrearTamagotchi(QWidget *parent = 0);
    ~CrearTamagotchi();
    void calcularTotal();
    void setGranja(list<Tamagotchi*>* granja);

private slots:
    void on_spinBox_valueChanged(const QString &arg1);

    void on_spinBox_2_editingFinished();

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::CrearTamagotchi *ui;
    list<Tamagotchi*>* granja;
};

#endif // CREARTAMAGOTCHI_H
