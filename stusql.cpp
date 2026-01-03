#include "stusql.h"

#include <QMessageBox>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>

stuSql * stuSql::ptrstuSql = nullptr;
stuSql::stuSql(QObject *parent)
    : QObject{parent}
{


//    StuInfo s;
//    s.name = "小抓";
//    for(int i =0;i<10;i++)
//    {
//    addStu(s);
//    }
//    getStuCnt();

//    getPageStu(2,3);
   // delStu(18);
//    StuInfo s;
//    s.id = 8;
//    s.name = "dd";
//    UpdateStuInfo(s);
//    UserInfo info;
//    info.username = "xiaoyu";
//    info.password = "123456";
//    info.aut = "admin";

//    AddUser(info);
//    AddUser(info);
//    auto l =getAllUser();
//    qDebug()<<isExit("xiaoyu");
//    info.password = "666";
//    updateUser(info);
//    delUser("xiaoyu");
}

void stuSql::init()
{
    if (QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";

    m_db = QSqlDatabase::addDatabase("QSQLITE");
#if 1
    auto str = QCoreApplication::applicationDirPath()+"/data.db";
    qDebug()<<str;
#endif
//    str = "G:\\data.db";
   m_db.setDatabaseName(str);
    if (!m_db.open())
       qDebug()<<"db not open";

}

quint32 stuSql::getStuCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from student;");
    quint32 uiCnt = 0;
    while(sql.next())
    {
        uiCnt =  sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<StuInfo> stuSql::getPageStu(quint32 page, quint32 uiCnt)
{
    QList<StuInfo> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from student order by id limit %1 offset %2").
            arg(uiCnt).arg(page*uiCnt);
    sql.exec(strsql);

    StuInfo info;
    while(sql.next())
    {
        info.id =  sql.value(0).toUInt();
        info.name =  sql.value(1).toString();
        info.age  =  sql.value(2).toUInt();
        info.grade =  sql.value(3).toUInt();
        info.uiclass =  sql.value(4).toUInt();
        info.studentid =  sql.value(5).toUInt();
        info.phone =  sql.value(6).toString();
        info.wechat =  sql.value(7).toString();
        l.push_back(info);
    }
    return l;
}

bool stuSql::addStu(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql= QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7')").
            arg(info.name).
            arg(info.age).
            arg(info.grade).
            arg(info.uiclass).
            arg(info.studentid).
            arg(info.phone).
            arg(info.wechat);
    return sql.exec(strSql);
}

bool stuSql::addStu(QList<StuInfo> l)
{
    QSqlQuery sql(m_db);
    m_db.transaction();
    for(auto info:l)
    {
        QString strSql= QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7')").
                arg(info.name).
                arg(info.age).
                arg(info.grade).
                arg(info.uiclass).
                arg(info.studentid).
                arg(info.phone).
                arg(info.wechat);
        sql.exec(strSql);
    }
    m_db.commit();

   return true;
}

bool stuSql::delStu(int id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from student where id = %1").arg(id));
}

bool stuSql::clearStuTable()
{
    QSqlQuery sql(m_db);
    sql.exec("delete from student");
    return  sql.exec(" delete from sqlite_sequence where name ='student'");
}

bool stuSql::UpdateStuInfo(StuInfo info)
{
    // fix
    //qDebug() << ">>> ENTER UpdateStuInfo <<<";

    QSqlQuery sql(m_db);

    // 使用 ? 代替 :name
    sql.prepare("UPDATE student SET name=?, age=?, grade=?, class=?, "
                "studentid=?, phone=?, wechat=? WHERE id=?"); // class not uiclass

    // 必须严格按照 SQL 语句中 ? 出现的顺序添加
    sql.addBindValue(info.name);
    sql.addBindValue(info.age);
    sql.addBindValue(info.grade);
    sql.addBindValue(info.uiclass);
    sql.addBindValue(info.studentid);
    sql.addBindValue(info.phone);
    sql.addBindValue(info.wechat);
    sql.addBindValue(info.id); // WHERE 子句的 id 放在最后 ★ 必须最后绑

    // sql.prepare(
    //     "UPDATE student SET "
    //     "name = :name, "
    //     "age = :age, "
    //     "grade = :grade, "
    //     "class = :uiclass, " // class not uiclass
    //     "studentid = :studentid, "
    //     "phone = :phone, "
    //     "wechat = :wechat "
    //     "WHERE id = :id"
    //     );

    // sql.bindValue(":name", info.name);
    // sql.bindValue(":age", info.age);
    // sql.bindValue(":grade", info.grade);
    // sql.bindValue(":uiclass", info.uiclass);
    // sql.bindValue(":studentid", info.studentid);
    // sql.bindValue(":phone", info.phone);
    // sql.bindValue(":wechat", info.wechat);
    // sql.bindValue(":id", info.id);


    qDebug() << "SQL =" << sql.lastQuery();
    qDebug() << "bound values count =" << sql.boundValues().size();
    qDebug() << "bound values =" << sql.boundValues();

    bool ret = sql.exec();

    qDebug() << "update ret:" << ret
             << "rows:" << sql.numRowsAffected()
             << sql.lastError();

    return ret;
    // QSqlQuery sql(m_db);
    // QString strSql= QString("update student set name = '%1',age=%2,grade=%3,class=%4,studentid=%5,"
    //                         "phone='%6',wechat='%7' where id=%8").
    //         arg(info.name).
    //         arg(info.age).
    //         arg(info.grade).
    //         arg(info.uiclass).
    //         arg(info.studentid).
    //         arg(info.phone).
    //         arg(info.wechat).arg(info.id);

    // qDebug()<<strSql;

    // bool ret =   sql.exec(strSql);
    // QSqlError e =  sql.lastError();
    // if(e.isValid())
    // {
    //     qDebug()<<e.text();
    // }
    // return ret;
}

QList<UserInfo> stuSql::getAllUser()
{

    QList<UserInfo> l;
    QSqlQuery sql(m_db);

    sql.exec("select * from username");

    UserInfo info;
    while(sql.next())
    {
        info.username =  sql.value(0).toString();
        info.password =  sql.value(1).toString();
        info.aut  =  sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

bool stuSql::isExit(QString strUser)
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from username where username='%1'").arg(strUser));
    return sql.next();
}

bool stuSql::updateUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql= QString("update username set password='%1',auth='%2' where username='%3'").
            arg(info.password).
            arg(info.aut).arg(info.username);

    bool ret =   sql.exec(strSql);
    QSqlError e =  sql.lastError();
    if(e.isValid())
    {
        qDebug()<<e.text();
    }
    return ret;
}

bool stuSql::AddUser(UserInfo info)
{

    QSqlQuery sql(m_db);
    QString strSql= QString("insert into username  values ('%1', '%2', '%3')").
            arg(info.username).
            arg(info.password).
            arg(info.aut);
    return sql.exec(strSql);
}

bool stuSql::delUser(QString strUserName)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from username where username='%1'").arg(strUserName));
}

