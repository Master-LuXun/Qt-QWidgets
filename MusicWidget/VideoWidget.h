#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>

class VideoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);

signals:


protected:

    QImage image;
    void paintEvent(QPaintEvent *event);

    bool isKeepAspectRatio=false;
public slots:
       void showVideo(QImage image);
};

#endif // VIDEOWIDGET_H
