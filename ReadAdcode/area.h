#ifndef AREA_H
#define AREA_H
#include <QString>
#include <QList>

class Area
{
public:
    Area(QString code="",QString name ="",QString parentCode="");
    ~Area();

    QString getCode() const;
    void setCode(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getParentCode() const;
    void setParentCode(const QString &value);

    QList<QString>& getChildList();
    void setChildList(const QList<QString> &value);

    bool getIsSpecial() const;
    void setIsSpecial(bool value);

private:

    QString code;
    QString name;
    QString parentCode;
    QList<QString> childList;
    bool isSpecial;



};

#endif // AREA_H
