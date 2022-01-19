#include "imagebutton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ImageButton button;

    button.setMinimumSize(100, 100);

    button.show();

    return app.exec();
}
