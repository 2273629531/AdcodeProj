#ifndef ADCODEREAD_H
#define ADCODEREAD_H
#include <QString>
#include <QHash>
#include <area.h>
#include <QStringList>

class AdCodeRead
{
public:
    AdCodeRead();
    ~AdCodeRead();
    bool ReadFile(QString filePath,QHash<QString,Area>& hash_adcodeManager);

private:
    QStringList specialProvList;

private:
    bool init();
};

#endif // ADCODEREAD_H
