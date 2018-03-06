#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sqliteset.h>
#include <QTimer>

namespace Ui {
class MainWindow;
class QLineEdit;
class QLable;
class QPushButton;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Pre_clicked();

    void on_pushButton_Next_clicked();

    void on_pushButton_Del_clicked();

    void data_time_temp_refresh();

    void on_pushButton_Clear_clicked();

private:
    Ui::MainWindow *ui;
    Ui::QLineEdit *lineEdit_Item;
    Ui::QLineEdit *lineEdit_Time;
    Ui::QLineEdit *lineEdit_Temp;
    Ui::QLineEdit *lineEdit_IimeRecord;
    Ui::QLineEdit *lineEdit_ItemRecord;

    QSqlDatabase MyDataBase;
    QSqlQuery sql_table;
    QString sql_table_set = "CREATE TABLE IF NOT EXISTS date_time_temp_table (id int primary key, date_time_record varchar(50), temp_record float)";
    QString select_string_set = "select max(id) from date_time_temp_table";
    QString delete_string_set = "DELETE FROM date_time_temp_table WHERE id IS ";
    QString clear_string_set = "DELETE FROM date_time_temp_table";
    int max_id = 0;

    QDateTime DataTime;
    QString CurrentDataTime;
    QTimer *refresh_time;



};

#endif // MAINWINDOW_H
