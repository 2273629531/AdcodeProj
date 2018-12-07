# AdcodeProj
Adcode区域代码解析

# 代码特点
1、提供了中国境内的省、地市、县adcode编码解析方式，采用hashmap组织数据结构，达到高效查询的目的

2、存储adcode的文件不要求录入数据的顺序

# 数据结构讲解
QHash<QString,Area> &hash_adcodeManager是一个hash结构，key为ADCODE，每个key都对应着一个value，该value为Area数据结构，Area存储了该地区的名称、所属上级地区和管辖的下级地区，如石家庄市，hash_adcodeManager中对应的key为130100，Area中存储了名称（石家庄市）、父级编码（河北省130000）、自己的编码（130100）、22个管辖区域的编码列表。注意，代码读取的txt文件对录入数据的顺序没有要求。
