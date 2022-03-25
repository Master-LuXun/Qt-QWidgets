#ifndef MASKLABEL_H
#define MASKLABEL_H

#include <QLabel>

class MaskLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MaskLabel(QWidget *parent = nullptr);

signals:
protected:
    void paintEvent(QPaintEvent *e);

};

#endif // MASKLABEL_H
