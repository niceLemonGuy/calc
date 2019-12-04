#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include <QList>
#include <QString>

#define sz 10

class MyWindow : public QDialog
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);

    int op = 0, mass[sz], val = 0, tr_mn = 10, mn = 10;
    int n_1 = 0, n_2 = 0; double x10Val;
    int count = 0, count_init = 0;
    bool addBool = false, subBool = false, multBool = false;
    bool divBool = false, transBool = false, n_2Bool = false;

    QString value = "";

private slots:
    void actions();
    void initial();
    void transform();
    void equal();
    void changePrecision_1(int);
    void changePrecision_2(int);
    void clear();
    void text();
    void setValue();

signals:
    void valueChanged(int);

private:
    QFont *font;
    QSpinBox *sb1;
    QSpinBox *sb2;
    QLabel *label;
    QPushButton *push_mass[23];
    QPushButton *text_button;
};

#endif // MYWINDOW_H
