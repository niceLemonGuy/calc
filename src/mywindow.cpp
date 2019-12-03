#include "mywindow.h"
const int sz = 10;
int op(0), mass[sz], val(0), tr_mn(10), mn(10);
int n_1(0), n_2(0); double x10Val;
int count(0), count_init(0);
bool addBool(false), subBool(false), multBool(false), divBool(false), transBool(false),
    n_2Bool(false);
QString value = "";

MyWindow::MyWindow(QWidget *parent) :
    QDialog(parent)
{
    for(int i=0;i<sz;i++)
        mass[i] = 0;

    sb1 = new QSpinBox;
    sb1->setMinimum(2);
    sb1->setMaximum(16);
    sb1->setValue(10);

    sb2 = new QSpinBox;
    sb2->setMinimum(2);
    sb2->setMaximum(16);
    sb2->setValue(10);

    //text_button = new QPushButton("Text");
    push_mass[0] = new QPushButton("0");
    push_mass[1] = new QPushButton("1");
    push_mass[2] = new QPushButton("2");
    push_mass[3] = new QPushButton("3");
    push_mass[4] = new QPushButton("4");
    push_mass[5] = new QPushButton("5");
    push_mass[6] = new QPushButton("6");
    push_mass[7] = new QPushButton("7");
    push_mass[8] = new QPushButton("8");
    push_mass[9] = new QPushButton("9");
    push_mass[10] = new QPushButton("A");
    push_mass[10]->setEnabled(false);
    push_mass[11] = new QPushButton("B");
    push_mass[11]->setEnabled(false);
    push_mass[12] = new QPushButton("C");
    push_mass[12]->setEnabled(false);
    push_mass[13] = new QPushButton("D");
    push_mass[13]->setEnabled(false);
    push_mass[14] = new QPushButton("E");
    push_mass[14]->setEnabled(false);
    push_mass[15] = new QPushButton("F");
    push_mass[15]->setEnabled(false);
    push_mass[16] = new QPushButton("+");
    push_mass[17] = new QPushButton("-");
    push_mass[18] = new QPushButton("*");
    push_mass[19] = new QPushButton("/");
    push_mass[20] = new QPushButton("=");
    push_mass[21] = new QPushButton("Tr");
    push_mass[22] = new QPushButton("Cl");


    label = new QLabel("0");
    font = new QFont;
    font->setPointSize(32);
    label->setFont(*font);
    label->setAlignment(Qt::AlignRight);

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(sb1, 1,0);
    grid->addWidget(sb2, 5,3);
    grid->addWidget(push_mass[21], 5,2);
    grid->addWidget(push_mass[11], 2,0);
    grid->addWidget(push_mass[12], 2,1);
    grid->addWidget(push_mass[13], 2,2);
    grid->addWidget(push_mass[14], 2,3);
    grid->addWidget(push_mass[15], 2,4);
    grid->addWidget(push_mass[6], 3,0);
    grid->addWidget(push_mass[7], 3,1);
    grid->addWidget(push_mass[8], 3,2);
    grid->addWidget(push_mass[9], 3,3);
    grid->addWidget(push_mass[10], 3,4);
    grid->addWidget(push_mass[1], 4,0);
    grid->addWidget(push_mass[2], 4,1);
    grid->addWidget(push_mass[3], 4,2);
    grid->addWidget(push_mass[4], 4,3);
    grid->addWidget(push_mass[5], 4,4);
    //grid->addWidget(text_button, 5,0);
    grid->addWidget(push_mass[0], 5,0);
    grid->addWidget(push_mass[20], 5,4);
    grid->addWidget(push_mass[22], 5,1);
    grid->addWidget(push_mass[16], 1,1);
    grid->addWidget(push_mass[17], 1,2);
    grid->addWidget(push_mass[18], 1,3);
    grid->addWidget(push_mass[19], 1,4);

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(label);

    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addLayout(grid);

    QVBoxLayout *main_lay = new QVBoxLayout;
    {
        main_lay->setMargin(11);
        main_lay->setSpacing(6);
        main_lay->addLayout(lay1);
        main_lay->addLayout(lay2);
    }

    connect(sb1, SIGNAL(valueChanged(int)), this, SLOT(changePrecision_1(int)));
    connect(sb2, SIGNAL(valueChanged(int)), this, SLOT(changePrecision_2(int)));
    //connect(text_button, SIGNAL(released()), this, SLOT(initial(one)));
    connect(push_mass[0], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[1], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[2], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[3], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[4], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[5], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[6], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[7], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[8], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[9], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[10], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[11], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[12], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[13], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[14], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[15], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[16], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[17], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[18], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[19], SIGNAL(released()), this, SLOT(setValue()));
    connect(push_mass[20], SIGNAL(released()), this, SLOT(equal()));
    connect(push_mass[21], SIGNAL(released()), this, SLOT(transform()));
    connect(push_mass[22], SIGNAL(released()), this, SLOT(clear()));


    setLayout(main_lay);
    setWindowTitle(tr("Calculator"));

}

void MyWindow::text()
{
    label->setText("Hello");
}

void MyWindow::changePrecision_1(int val_mn)
{
    mn = val_mn;
    for(int i=0; i<val_mn; i++)
        push_mass[i]->setEnabled(true);
    for(int i=val_mn; i<16; i++)
        push_mass[i]->setEnabled(false);
}

void MyWindow::changePrecision_2(int val_tr)
{
    tr_mn = val_tr;
}

void MyWindow::setValue()
{
    QPushButton *button = (QPushButton *) sender();
    emit valueChanged(button->text()[0].digitValue());
    value = button->text();

             if(value == "0") { val=0;              initial(); }
        else if(value == "1") { val=1;              initial(); }
        else if(value == "2") { val=2;              initial(); }
        else if(value == "3") { val=3;              initial(); }
        else if(value == "4") { val=4;              initial(); }
        else if(value == "5") { val=5;              initial(); }
        else if(value == "6") { val=6;              initial(); }
        else if(value == "7") { val=7;              initial(); }
        else if(value == "8") { val=8;              initial(); }
        else if(value == "9") { val=9;              initial(); }
        else if(value == "A") { val=10;             initial(); }
        else if(value == "B") { val=11;             initial(); }
        else if(value == "C") { val=12;             initial(); }
        else if(value == "D") { val=13;             initial(); }
        else if(value == "E") { val=14;             initial(); }
        else if(value == "F") { val=15;             initial(); }
        else if(value == "+") { addBool = true;     actions(); }
        else if(value == "-") { subBool = true;     actions(); }
        else if(value == "*") { multBool = true;    actions(); }
        else if(value == "/") { divBool = true;     actions(); }
}

void MyWindow::initial()
{
    QString str;
    if(count_init < sz)
    {
        if(mass[0] != 0)
            mass[count_init] = val;
        else
        {
            mass[0] = val;
            count_init = 0;
        }

        count_init++;

        for(int i=0; i<count_init; i++)
        {
            if(mass[i] >= 0 && mass[i] < 10)
                str[i] = mass[i]+48;
            if(mass[i] >= 10 && mass[i] < 16)
                str[i] = mass[i]+55;
        }
        label->setText(str);
        count = count_init;
    }
}

void MyWindow::actions()
{
    if(n_2Bool)
    {
        for(int i=0; i<count; i++)
        {
            for(int j=i; j<count-1; j++)
                mass[i] *= mn;
            n_2 += mass[i];
        }
        switch(op)
        {
        case 16: n_1 += n_2; break;
        case 17: n_1 -= n_2; break;
        case 18: n_1 *= n_2; break;
        case 19: n_1 *= n_2; break;
        default: label->setText("ERROR"); break;
        }
        n_2 = 0;
        count_init = 0;
    }

    if(!n_2Bool)
    {
        n_1 = 0;
        for(int i=0; i<count; i++)
        {
            for(int j=i; j<count-1; j++)
                mass[i] *= mn;
            n_1 += mass[i];
        }
        n_2Bool = true;
    }

         if(addBool)    { op = 16;  addBool = false;    label->setText("+"); }
    else if(subBool)    { op = 17;  subBool = false;    label->setText("-"); }
    else if(multBool)   { op = 18;  multBool = false;   label->setText("*"); }
    else if(divBool)    { op = 19;  divBool = false;    label->setText("/"); }
    else label->setText("ERROR");

    count_init = 0;
}

void MyWindow::clear()
{
    label->setText("0");
    n_1 = 0;
    n_2 = 0;
    op = 0;
    addBool = false;
    subBool = false;
    multBool = false;
    divBool = false;
    n_2Bool = false;
    transBool = false;
    for(int i=0; i<sz; i++)
        mass[i] = 0;
    count = 0;
    count_init = 0;
}

void MyWindow::transform()
{
    n_1 = 0;
    if(mn != tr_mn)
    {
        QString str;
        for(int i=0; i<count; i++)
        {
            for(int j=i; j<count-1; j++)
                mass[i] *= mn;
            n_1 += mass[i];
        }
        int temp_1, temp_2 = n_1;
        count = 0;
        while(n_1 && (count < sz))
        {
            temp_1 = n_1;
            n_1 /= tr_mn;
            temp_1 %= tr_mn;
            mass[count] = temp_1;
            count++;
        }

        int i, j;
        for(i=0, j=count-1; i<j; ++i, --j)
        {
            temp_1 = mass[i];
            mass[i] = mass[j];
            mass[j] = temp_1;
        }

        for(int i=0; i<count; i++)
        {
            if(mass[i] >= 0 && mass[i] < 10)
                str[i] = mass[i] + 48;
            if(mass[i] >= 10 && mass[i] < 16)
                str[i] = mass[i] + 55;
        }
        label->setText(str);
        n_1 = temp_2;
        count_init = 0;
    }
}

void MyWindow::equal()
{
    if(n_2Bool)
    {
        QString str;
        for(int i=0; i<count; i++)
        {
            for(int j=i; j<count-1; j++)
                mass[i] *= mn;
            n_2 += mass[i];
        }
        switch(op)
        {
            case 16: n_1 += n_2; break;
            case 17: n_1 -= n_2; break;
            case 18: n_1 *= n_2; break;
            case 19: n_1 /= n_2; break;
            default: label->setText("ERROR"); break;
         }
        if(mn != 10)
        {
            int temp_1, temp_2 = n_1;
            count = 0;
            while(n_1 && (count < sz))
            {
                temp_1 = n_1;
                n_1 /= mn;
                temp_1 %= mn;
                mass[count] = temp_1;
                count++;
            }
            int i, j;
            for(i=0, j=count-1; i<j; ++i, --j)
            {
                temp_1 = mass[i];
                mass[i] = mass[j];
                mass[j] = temp_1;
            }
            for(i=0; i<count; i++)
            {
                if(mass[i] >= 0 && mass[i] < 10)
                    str[i] = mass[i] + 48;
                if(mass[i] >= 10 && mass[i] < 16)
                    str[i] = mass[i] + 55;
            }
            label->setText(str);
            n_1 = temp_2;
        }
        else
        {
            label->setNum(n_1);
        }
        n_2 = 0;
        op = 0;
        addBool = false;
        subBool = false;
        multBool = false;
        divBool = false;
        count_init = 0;
    }
}
