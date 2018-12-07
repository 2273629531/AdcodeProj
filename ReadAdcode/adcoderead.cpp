#include "adcoderead.h"
#include <QFile>
#include <QIODevice>
#include <QStringList>
#include <QByteArray>



AdCodeRead::AdCodeRead()
{
    init();
}

AdCodeRead::~AdCodeRead()
{

}

bool AdCodeRead::ReadFile(QString filePath, QHash<QString,Area> &hash_adcodeManager)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
       return false;
    }

    int n=0;
    while (!file.atEnd()) {
        n++;
        QByteArray line = file.readLine();
        QString str(line);
        QStringList lineStrList = str.split(" ",QString::SkipEmptyParts);
        if(lineStrList.size() <2)
        {
            continue;
        }
        QString code = lineStrList.at(0);
        QString name = lineStrList.at(1);

        if(code.endsWith("0000"))//省
        {
            Area area(code,name,"china");
            hash_adcodeManager[code] = area;
            continue;
        }
        else if(!(code.endsWith("0000")) && code.endsWith("00"))//市
        {
            QString provinceCode = code.mid(0,2)+"0000";
            Area area(code,name,provinceCode);
            hash_adcodeManager[code] = area;
            hash_adcodeManager[provinceCode].getChildList().append(code);
            continue;
        }
        else //区
        {
            QString provinceCode = code.mid(0,2);
            QString cityCode;
            if(specialProvList.indexOf(provinceCode) != -1)//单独处理直辖市
            {
                cityCode = provinceCode +"0000";

            }else
            {
                cityCode = code.mid(2,2);
                cityCode = provinceCode +cityCode+"00";
            }

            Area area(code,name,cityCode);
            hash_adcodeManager[code] = area;
            hash_adcodeManager[cityCode].getChildList().append(code);
            continue;
        }
    }
    file.close();

    Area a = hash_adcodeManager["110000"];
    Area b = hash_adcodeManager["120000"];
    Area c = hash_adcodeManager["130000"];
    Area d = hash_adcodeManager["810000"];
    Area e = hash_adcodeManager["820000"];
    Area f = hash_adcodeManager["130100"];
    Area h = hash_adcodeManager["140000"];

    return true;
}

bool AdCodeRead::init()
{
    specialProvList<<"11"<<"31"<<"12"<<"50";

}



