#include "widget.h"
#include "ui_widget.h"
#include <QDate>
#include <QTime>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);//声明计时器

    connect(timer,SIGNAL(timeout()),this,SLOT(mysetText()));//信号函数
    timer->start(1000);//一秒刷新一次
}

QDate currentDate = QDate::currentDate();
QTime currentTime = QTime::currentTime();
const static QDate dayunDate = QDate::fromString("2023/07/28", "yyyy/MM/dd");

// 设置字体
void Widget::initView() {
    // ui->timeLabel->setPalette();
    // ui->titleLabel->setText("距离第31届\n世界大运会 还有");
}

// 更新时间
void Widget::mysetText()
{
    currentDate = QDate::currentDate();//获取当前时间
    currentTime = QTime::currentTime();
    QString timeString = currentTime.toString("hh:mm");

    // currentDate.toString("yyyy/MM/dd")
    // 设置左上角时间
    ui->timeLabel->setText(timeString);

    // 设置倒计时,大运会
    int countDays = currentDate.daysTo(dayunDate);
    ui->label->setText(QString::number(countDays));
}

Widget::~Widget()
{
    delete ui;
}
