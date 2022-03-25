#include "VideoWidget.h"
#include "QPainter"

VideoWidget::VideoWidget(QWidget *parent) : QWidget(parent)
{


}

void VideoWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    int width = this->width();
    int height = this->height();


    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width, height);

//    if (isKeepAspectRatio) {
//        QImage img = image.scaled(QSize(width, height), Qt::KeepAspectRatio);

//        /* calculate display position */
//        int x = (this->width() - img.width()) / 2;
//        int y = (this->height() - img.height()) / 2;

//        painter.drawImage(QPoint(x, y), img);
//    } else {
        QImage img = image.scaled(QSize(width, height));

        painter.drawImage(QPoint(0, 0), img);
    //}

}

int ii=0;
#include "QDebug"

void VideoWidget::showVideo(QImage image)
{
    this->image = image;
    qDebug()<<ii++<<"showVideo";
    update();
}
