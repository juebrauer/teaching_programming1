#include <QApplication>
#include "my_gui.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 my_gui g;
 g.show();

 return app.exec();
}