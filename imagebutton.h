#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <QMediaPlayer>

class ImageButton : public QPushButton
{
    Q_OBJECT
public:
    ImageButton(QWidget* parent = nullptr);

    void paintEvent(QPaintEvent* e) override;
    //QSize sizeHint() const override;
    //QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent* e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap currentButtonPixmap;
    QPixmap buttonDownPixmap;
    QPixmap buttonUpPixmap;

    QMediaPlayer* player;
};

#endif // IMAGEBUTTON_H
