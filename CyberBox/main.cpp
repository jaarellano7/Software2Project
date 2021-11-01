#include "cyberbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CyberBox w;
    w.show();
    return a.exec();
}
