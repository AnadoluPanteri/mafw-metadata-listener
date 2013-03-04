
#include <QtCore>
#include <QtGui>

#include "mafw-metadata-listener.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Receiver receiver;

    return app.exec();
}

