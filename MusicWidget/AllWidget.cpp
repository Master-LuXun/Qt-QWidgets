#include "AllWidget.h"
#include "ui_AllWidget.h"


#include "QSystemTrayIcon"
#pragma execution_character_set("utf-8")
Widget::Widget(QWidget *parent) : FramelessWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->initForm();
  QSystemTrayIcon *ico=new QSystemTrayIcon(this);
  ico->setIcon(QIcon(":/ico/1.jpg"));
  ico->show();
  move(600,22);
  resize(500,1000);
   initFFmpeg();


  coder=new Decoder;
   connect(this, SIGNAL(stopVideo()),coder, SLOT(stopVideo()));
  connect(this, SIGNAL(selectedVideoFile(QString,QString)), coder, SLOT(decoderFile(QString,QString)));
  connect(coder, SIGNAL(gotVideo(QImage)), ui->widgetMain, SLOT(showVideo(QImage)));


}

Widget::~Widget()
{
    delete ui;
    delete  coder;
}

void Widget::initFFmpeg()
{
    avfilter_register_all();

    /* ffmpeg init */
    av_register_all();

    /* ffmpeg network init for rtsp */
    if (avformat_network_init()) {
        //qDebug() << "avformat network init failed";
    }

    /* init sdl audio */
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
       // qDebug() << "SDL init failed";
    }
}

void Widget::playVideo(QString file)
{

    currentPlay = file;
    currentPlayType = fileType(file);
    emit selectedVideoFile(file, currentPlayType);
}

QString Widget::fileType(QString file)
{
    QString type;

    QString suffix = file.right(file.size() - file.lastIndexOf(".") - 1);
    if (suffix == "mp3" || suffix == "ape" || suffix == "flac" || suffix == "wav") {
        type = "music";
    } else {
        type = "video";
    }

    return type;
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

void Widget::on_btnMenu_Max_clicked()
{
    if (this->isMaximized()) {
        this->showNormal();
        //ui->btnMenu_Max->setText("123");
    } else {
        this->showMaximized();
        //ui->btnMenu_Max->setText("321");
    }
}

void Widget::on_btnMenu_Close_clicked()
{
    this->close();
}

#include "QFileDialog"
void Widget::on_pushButton_clicked()
{
    QString filePath;
     emit stopVideo();

        filePath = QFileDialog::getOpenFileName(
                this, "选择播放文件", "/",
                "(*.264 *.mp4 *.rmvb *.avi *.mov *.flv *.mkv *.ts *.mp3 *.flac *.ape *.wav)");
        if (!filePath.isNull() && !filePath.isEmpty())
        {

         playVideo(filePath);

        }

}
