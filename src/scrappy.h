#ifndef SCRAPPY_H
#define SCRAPPY_H

#include <QMainWindow>

namespace Ui {
class Scrappy;
}

class Scrappy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Scrappy(QWidget *parent = 0);
    ~Scrappy();

private:
    Ui::Scrappy *ui;
};

#endif // SCRAPPY_H
