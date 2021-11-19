#include "hauptfenster.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HauptFenster w;
    w.show();
    return a.exec();
}
