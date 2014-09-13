#include "simplebird.h"
#include "SimpleBirdApplication.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    SimpleBirdApplication a(argc, argv);
    SimpleBird w;
    w.show();
    return a.exec();
}
