#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLCDNumber>
#include <QImage>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>

int cur=0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString img_path = "/home/aa248424/images.png";
    QImage img(img_path);
    QPixmap buf = QPixmap::fromImage(img);

    buf = buf.scaled(1024,1024);


    QGraphicsScene* scene = new QGraphicsScene;
    ui->coffeeg->setScene(scene);

    scene->addPixmap(buf);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::enablebutton(){
    ui->lcdNumber->display(cur);
    if(cur >= 300){
        ui->Aronia->setEnabled(true);
        ui->coffee->setEnabled(true);
        ui->tea->setEnabled(true);
    }
    else if(cur >= 150){
        ui->Aronia->setEnabled(false);
        ui->coffee->setEnabled(true);
        ui->tea->setEnabled(true);
    }
    else if(cur >= 100){
        ui->Aronia->setEnabled(false);
        ui->coffee->setEnabled(false);
        ui->tea->setEnabled(true);
    }
    else{
        ui->Aronia->setEnabled(false);
        ui->coffee->setEnabled(false);
        ui->tea->setEnabled(false);
    }
}


void Widget::on_coffee_clicked()
{
    cur -= 150;
    enablebutton();
}

void Widget::on_c50_clicked()
{
    cur += 50;
    enablebutton();
}

void Widget::on_c100_clicked()
{
    cur += 100;
    enablebutton();
}

void Widget::on_c500_clicked()
{
    cur += 500;
    enablebutton();
}

void Widget::on_tea_clicked()
{
    cur -= 100;
    enablebutton();
}

void Widget::on_Aronia_clicked()
{
    cur -= 300;
    enablebutton();
}
