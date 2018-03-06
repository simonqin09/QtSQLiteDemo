#include <sqliteset.h>


QSqlDatabase sql_create()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
        database.setUserName("Toradex");
        database.setPassword("123456");
    }
    return database;
}

void sql_close(QSqlDatabase DatabaseName)
{
    DatabaseName.close();
}

QSqlQuery sql_create_table(QString sql_table_keys)
{
    QSqlQuery sql_table;
    //QString create_sql = "create table student (id int primary key, name varchar(30), age int)";
    //sql_table.prepare(sql_table_keys);
    if(!sql_table.exec(sql_table_keys))
    {
        qDebug() << "Error: Fail to create table." << sql_table.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
    return sql_table;
}

int sql_insert_data(QSqlQuery sql_table, QString data_string)
{
    if(!sql_table.exec(data_string))
    {
        qDebug() << sql_table.lastError();
        return -1;
    }
    else
    {
        qDebug() << "inserted successfully!";
        return 0;
    }
}

int sql_delete_data(QSqlQuery sql_table, QString delete_string, int id)
{
    QString delete_string_set = delete_string + QString::number(id);
    qDebug() << delete_string_set;
    if(!sql_table.exec(delete_string_set))
    {
        qDebug()<<sql_table.lastError();
        return -1;
    }
    else
    {
        qDebug()<<"deleted!";
        return 0;
    }
}

int sql_clear_table(QSqlQuery sql_table, QString clear_string)
{
    if(!sql_table.exec(clear_string))
    {
        qDebug() << sql_table.lastError();
        return -1;
    }
    else
    {
        qDebug() << "table cleared";
        return 0;
    }
}

int sql_select_maxid(QSqlQuery sql_table, QString select_string)
{
    int max_id = 0;
    if(!sql_table.exec(select_string))
    {
        qDebug() << sql_table.lastError();
        return -1;
    }
    else
    {
        while(sql_table.next())
            {
                max_id = sql_table.value(0).toInt();
            }
        return max_id;
    }
}


QString temp_read()
{
    QString temp;
    float temp_float;
    QByteArray temp_byte;
    QFile file("/sys/devices/virtual/thermal/thermal_zone0/temp");
    if(file.open(QIODevice::ReadOnly))
    {
        temp_byte = file.readLine();
        temp = temp_byte;
        temp_float = temp.toFloat();
        temp = QString("%1").arg(temp_float/1000);
        //qDebug() << temp;
    }
    file.close();
    return temp;
}
