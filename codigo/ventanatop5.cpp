#include "ventanatop5.h"
#include "ui_ventanatop5.h"

VentanaTop5::VentanaTop5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaTop5)
{
    ui->setupUi(this);
}

VentanaTop5::~VentanaTop5()
{
    delete ui;
}
void VentanaTop5::setTop5(QString top5[5], int pecados[5])
{
    ui->pais1->setText(top5[0]);
    ui->cantPec->setText(QString::number(pecados[0]));

    ui->pais2->setText(top5[1]);
    ui->cantPec_2->setText(QString::number(pecados[1]));

    ui->pais3->setText(top5[2]);
    ui->cantPec_3->setText(QString::number(pecados[2]));

    ui->pais4->setText(top5[3]);
    ui->cantPec_4->setText(QString::number(pecados[3]));

    ui->pais5->setText(top5[4]);
    ui->cantPec_5->setText(QString::number(pecados[4]));


}

void VentanaTop5::setBandera(QString top5[5])
{
    QString resourceBase = ":/banderas/banderas/";
    QString finExtension = ".png";


    QPixmap pixmap(resourceBase + top5[0] + finExtension);
    ui->Bandera->setPixmap(pixmap);

    QPixmap pixmap1(resourceBase + top5[1] + finExtension);
    ui->Bandera_2->setPixmap(pixmap1);

    QPixmap pixmap2(resourceBase + top5[2] + finExtension);
    ui->Bandera_3->setPixmap(pixmap2);

    QPixmap pixmap3(resourceBase + top5[3] + finExtension);
    ui->Bandera_4->setPixmap(pixmap3);

    QPixmap pixmap4(resourceBase + top5[4] + finExtension);
    ui->Bandera_5->setPixmap(pixmap4);


}
