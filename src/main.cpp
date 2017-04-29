#include "scrappy.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Scrappy w;
    w.show();

    return app.exec();
}

