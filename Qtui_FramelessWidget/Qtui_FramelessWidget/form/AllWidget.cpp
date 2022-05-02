#include "AllWidget.h"
#include "ui_frmmain.h"


#include "QSystemTrayIcon"
#pragma execution_character_set("utf-8")
Widget::Widget(QWidget *parent) : FramelessWidget(parent), ui(new Ui::AllWidget)
{
    ui->setupUi(this);
    this->initForm();
  QSystemTrayIcon *ico=new QSystemTrayIcon(this);
  ico->setIcon(QIcon(":/ico/1.jpg"));
  ico->show();
  move(600,22);
  resize(1100,700);

}

Widget::~Widget()
{
    delete ui;

}








void Widget::initForm()
{
    //设置标题栏控件
    //ui->labTitle->setText("Qt自定义标题栏");
    this->setWindowTitle(ui->labTitle->text());
    this->setTitleBar(ui->labTitle);

    //关联信号
    connect(this, SIGNAL(titleDblClick()), this, SLOT(titleDblClick()));
    connect(this, SIGNAL(windowStateChange(bool)), this, SLOT(windowStateChange(bool)));

    //设置样式表
    QStringList list;
    list << "#titleBar{background:#BBBBBB;}";
    //list << "#titleBar{border-top-left-radius:8px;border-top-right-radius:8px;}";
    list << "#widgetMain{border:0px solid #BBBBBB;background:#FFFFFF;}";
    //list << "#widgetMain{border-bottom-left-radius:8px;border-bottom-right-radius:8px;}";
    this->setStyleSheet(list.join(""));
}

void Widget::titleDblClick()
{
    on_btnMenu_Max_clicked();
}

void Widget::windowStateChange(bool max)
{
    //ui->btnMenu_Max->setText(max ? "11" : "22");
}

void Widget::on_btnMenu_Min_clicked()
{
#ifdef Q_OS_MACOS
    this->setWindowFlags(this->windowFlags() & ~Qt::FramelessWindowHint);
#endif
    this->showMinimized();
}
#include "QDebug"
void Widget::on_btnMenu_Max_clicked()
{
    if (this->isMaximized()) {
        this->showNormal();
         qDebug()<<"11111";
        //ui->btnMenu_Max->setText("123");
    } else {
        this->showMaximized();
        qDebug()<<"22222";
        //ui->btnMenu_Max->setText("321");
    }
}

void Widget::on_btnMenu_Close_clicked()
{
    this->close();
}

#include "QFileDialog"
