#include "ventanatop10.h"
#include "ui_ventanatop10.h"

VentanaTop10::VentanaTop10(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaTop10)
{
    ui->setupUi(this);
}

VentanaTop10::~VentanaTop10()
{
    delete ui;
}

void VentanaTop10::setTop10(QString top10[10], int pecados[10])
{
    ui->pais1->setText(top10[0]);
    ui->cantPec->setText(QString::number(pecados[0]));

    ui->pais2->setText(top10[1]);
    ui->cantPec_2->setText(QString::number(pecados[1]));

    ui->pais3->setText(top10[2]);
    ui->cantPec_3->setText(QString::number(pecados[2]));

    ui->pais4->setText(top10[3]);
    ui->cantPec_4->setText(QString::number(pecados[3]));

    ui->pais5->setText(top10[4]);
    ui->cantPec_5->setText(QString::number(pecados[4]));

    ui->pais6->setText(top10[5]);
    ui->cantPec_6->setText(QString::number(pecados[5]));

    ui->pais7->setText(top10[6]);
    ui->cantPec_7->setText(QString::number(pecados[6]));

    ui->pais8->setText(top10[7]);
    ui->cantPec_8->setText(QString::number(pecados[7]));

    ui->pais9->setText(top10[8]);
    ui->cantPec_9->setText(QString::number(pecados[8]));

    ui->pais10->setText(top10[9]);
    ui->cantPec_10->setText(QString::number(pecados[9]));

}

void VentanaTop10::setBandera(QString top10[10])
{
    QString resourceBase = ":/banderas/banderas/";
    QString finExtension = ".png";


    QPixmap pixmap(resourceBase + top10[0] + finExtension);
    ui->Bandera->setPixmap(pixmap);

    QPixmap pixmap1(resourceBase + top10[1] + finExtension);
    ui->Bandera_2->setPixmap(pixmap1);

    QPixmap pixmap2(resourceBase + top10[2] + finExtension);
    ui->Bandera_3->setPixmap(pixmap2);

    QPixmap pixmap3(resourceBase + top10[3] + finExtension);
    ui->Bandera_4->setPixmap(pixmap3);

    QPixmap pixmap4(resourceBase + top10[4] + finExtension);
    ui->Bandera_5->setPixmap(pixmap4);

    QPixmap pixmap5(resourceBase + top10[5] + finExtension);
    ui->Bandera_6->setPixmap(pixmap5);

    QPixmap pixmap6(resourceBase + top10[6] + finExtension);
    ui->Bandera_7->setPixmap(pixmap6);

    QPixmap pixmap7(resourceBase + top10[7] + finExtension);
    ui->Bandera_8->setPixmap(pixmap7);

    QPixmap pixmap8(resourceBase + top10[8] + finExtension);
    ui->Bandera_9->setPixmap(pixmap8);

    QPixmap pixmap9(resourceBase + top10[9] + finExtension);
    ui->Bandera_10->setPixmap(pixmap9);


}



