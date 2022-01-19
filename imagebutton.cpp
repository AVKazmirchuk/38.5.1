#include "imagebutton.h"

ImageButton::ImageButton(QWidget *parent ) : QPushButton(parent)
{
    buttonUpPixmap = QPixmap(":/src/up.png");
    buttonDownPixmap = QPixmap(":/src/down.png");
    currentButtonPixmap = buttonUpPixmap;

    connect(this, &QPushButton::pressed, this, &ImageButton::setDown);

    connect(this, &QPushButton::released, this, &ImageButton::setUp);

    player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/src/button_click.wav"));

}
void ImageButton::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(), currentButtonPixmap);
}

/*QSize ImageButton::sizeHint() const
{
    return QSize(240, 240);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}*/

void ImageButton::keyPressEvent(QKeyEvent*)
{
    setDown();
}

void ImageButton::setDown()
{
    currentButtonPixmap = buttonDownPixmap;
    update();
    player->play();
}

void ImageButton::setUp()
{
    currentButtonPixmap = buttonUpPixmap;
    update();
}
