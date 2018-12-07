#include "area.h"

Area::Area(QString code,QString name ,QString parentCode)
    :code(code),name(name),parentCode(parentCode),isSpecial(false)
{

}

Area::~Area()
{

}
QString Area::getCode() const
{
    return code;
}

void Area::setCode(const QString &value)
{
    code = value;
}
QString Area::getName() const
{
    return name;
}

void Area::setName(const QString &value)
{
    name = value;
}
QString Area::getParentCode() const
{
    return parentCode;
}

void Area::setParentCode(const QString &value)
{
    parentCode = value;
}
QList<QString>& Area::getChildList()
{
    return childList;
}

void Area::setChildList(const QList<QString> &value)
{
    childList = value;
}
bool Area::getIsSpecial() const
{
    return isSpecial;
}

void Area::setIsSpecial(bool value)
{
    isSpecial = value;
}








