#ifndef CREARTAMAGOTCHI_H
#define CREARTAMAGOTCHI_H

#include <QWidget>

namespace Ui {
class CrearTamagotchi;
}

class CrearTamagotchi : public QWidget
{
    Q_OBJECT

public:
    explicit CrearTamagotchi(QWidget *parent = 0);
    ~CrearTamagotchi();

private:
    Ui::CrearTamagotchi *ui;
};

#endif // CREARTAMAGOTCHI_H
