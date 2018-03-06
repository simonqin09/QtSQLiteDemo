#ifndef SQLITESET_H
#define SQLITESET_H

#include <QtCore/QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QFile>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/* Sqlite Database create */
QSqlDatabase sql_create();
/* Sqlite Database close */
void sql_close(QSqlDatabase DatabaseName);
/* Sqlite Database Table create */
QSqlQuery sql_create_table(QString sql_table_keys);
/* Sqlite Database data insert */
int sql_insert_data(QSqlQuery sql_table, QString data_string);
/* Sqlite Database data delete */
int sql_delete_data(QSqlQuery sql_table, QString delete_string, int id);
/* Sqlite Database Table clear */
int sql_clear_table(QSqlQuery sql_table, QString clear_string);
/* Sqlite database Table current max id select */
int sql_select_maxid(QSqlQuery sql_table, QString select_string);

/* Colibri iMX6 CPU Temperature read */
QString temp_read();

#endif // SQLITESET_H
