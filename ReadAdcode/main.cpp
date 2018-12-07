#include "mainwindow.h"
#include <QApplication>
#include "adcoderead.h"
#include "area.h"
#include "QHash"
#include "QTextCodec"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec* utf8 = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForCStrings(utf8);
    QTextCodec::setCodecForLocale(utf8);
    QTextCodec::setCodecForTr(utf8);

    MainWindow w;
    w.show();

    QHash<QString,Area> hash_adcodeManager;
    AdCodeRead adcodeRead;
    adcodeRead.ReadFile(QString(":/province.txt"),hash_adcodeManager);


    return a.exec();
}
