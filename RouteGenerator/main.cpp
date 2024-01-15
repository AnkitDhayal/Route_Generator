#include "stdafx.h"
#include "RouteGenerator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RouteGenerator w;
    w.show();
    return a.exec();
}
