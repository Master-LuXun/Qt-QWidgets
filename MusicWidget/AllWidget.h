#ifndef WIDGET_H
#define WIDGET_H

#include "FramelessWidget.h"

#include <windows.h>
#include <tlhelp32.h>

namespace Ui {
class Widget;
}

#include "decoder.h"
class Widget : public FramelessWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    void initFFmpeg();

   void playVideo(QString file);
   QString fileType(QString file);
   QString currentPlay;        // current playing video file path
   QString currentPlayType;
   Decoder *coder;


private slots:
    void initForm();
    void titleDblClick();
    void windowStateChange(bool max);

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void on_pushButton_clicked();
signals:
    void selectedVideoFile(QString file, QString type);
    void stopVideo();

};

#endif // WIDGET_H
