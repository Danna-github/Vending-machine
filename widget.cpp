#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) //객체가 생성될 때 실행
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMike->setEnabled(false);
    //button click -> Enable!
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pb_10_clicked()
{
    changeMoney(10);
    changeBtn();
    //money += 10;
    //ui->lcdNumber->display(money);
}

void Widget::on_pb_50_clicked()
{
    changeMoney(50);
    changeBtn();
}

void Widget::on_pb_100_clicked()
{
    changeMoney(100);
    changeBtn();
}

void Widget::on_pb_500_clicked()
{
    changeMoney(500);
    changeBtn();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    changeBtn();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    changeBtn();
}

void Widget::on_pbMike_clicked()
{
    changeMoney(-200);
    changeBtn();
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    int change_500 = 0;
    int change_100 = 0;
    int change_50 = 0;
    int change_10 = 0;

    if (money >= 500){
        change_500 = money / 500;
        money -= 500*change_500;
        change_100 = money / 100;
        money -= 100*change_100;
        change_50 = money / 50;
        money -= 50*change_50;
        change_10 = money / 10;
        money -= 10*change_10;
    } else if(money >= 100 && money < 500){
        change_100 = money / 100;
        money -= 100*change_100;
        change_50 = money / 50;
        money -= 50*change_50;
        change_10 = money / 10;
        money -= 10*change_10;
    } else if(money >= 50 && money < 100){
        change_50 = money / 50;
        money -= 50*change_50;
        change_10 = money / 10;
        money -= 10*change_10;
    } else {
        change_10 = money / 10;
        money -= 10*change_10;
    }
    ui->lcdNumber->display(money);
    m.information(nullptr, "Small change", "10원: "+QString::number(change_10)+"개\n"+"50원: "+QString::number(change_50)+"개\n"+"100원: "+QString::number(change_100)+"개\n"+"500원: "+QString::number(change_500)+"개\n");
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::changeBtn(){
    if(money >= 100 && money < 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbMike->setEnabled(false);
    }else if(money >=150 && money < 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMike->setEnabled(false);
    }else if(money >=200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMike->setEnabled(true);
    } else {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMike->setEnabled(false);
    }
}
