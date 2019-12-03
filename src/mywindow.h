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

class MyWindow : public QDialog
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent=0);
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
