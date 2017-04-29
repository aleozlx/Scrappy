#include "scrappy.h"
#include <QApplication>
#include <QWidget>
#include "listwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Scrappy w;
   // w.show();
    
    ListWidget window;

  window.setWindowTitle("QListWidget");
  window.show();

    return app.exec();
}

