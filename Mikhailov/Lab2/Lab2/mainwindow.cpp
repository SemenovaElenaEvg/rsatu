#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AcceptButton_clicked()
{
    code = ui->InformSequence->text();
    m = 0;
    l = 0;
    n = code.length();
    pos.clear();
    ui->StaffChoicee->clear();
    QString s;
    QString lr;
    QString numb;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (code[i] == '1') {
            m++;
            pos.push_back(i);
            s.setNum(i);
            numb.setNum(j);
            j++;
            s = "a[" + numb + "] = " + s;
            ui->StaffChoicee->addItem(s);
        }
    }
    if (n == 8) {
        lr = "3";
    }
    if (n == 4) {
        lr = "2";
    }
    if (n == 16) {
        lr = "4";
    }
    if (n == 2) {
        lr = "";
    }
    s.setNum(m);
    ui->m->setText(s);
    s.setNum(n);
    ui->l->setText(lr);
    ui->n->setText(s);
}

void MainWindow::on_CodeButton_clicked()
{
    int r = 0;
    for (int i=0; i<pos.size(); i++) {
        r += pos[i];
    }
    r %= n;
    QString s;
    s.setNum(r, 2);
    double cur = log(n);
    cur /= log(2);
    l = ceil(cur);
    while (s.length() < l) {
        s = '0' + s;
    }
    ui->R->setText(s);
    ui->CodeCombination->setText(code + s);
}

void MainWindow::on_DecodeButton_clicked()
{
    QString s = ui->AcceptedCodeCombination->text();
    QString nr = s.mid(s.length() - l, l), new_rs;
    s = s.mid(0, s.length() - l);
    int nm = 0, nn = s.length(), new_r = 0;
    ui->StaffChoicee_2->clear();
    ui->J->clear();
    QString str;
    vector <int> a;
    QString numb;
    int num = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '1') {
            nm++;
            str.setNum(i);
            numb.setNum(num);
            num++;
            str = "a*[" + numb + "] = " + str;
            ui->StaffChoicee_2->addItem(str);
            new_r += i;
            a.push_back(i);
        }
    }
    str.setNum(nm);
    ui->mm->setText(str);
    new_r %= nn;
    str.setNum(new_r, 2);
    int j = 0;
    while (str.length() < l) {
        str = '0' + str;
    }
    new_rs = str;
    bool ok;
    int r = nr.toInt(&ok, 2);
    int k = 0;
    ui->RR->setText(str);
    if (nm != m) {
        for (int i=0; i< a.size(); i++) {
            j += a[i];
        }
        j %= nn;
        if (nm < m) {
            j = (r - j) % nn;
            if (j<0) {
                j = nn + j;
            }
            if (s[j] == '0') {
                s[j] = '1';
            } else {
                s[j] =  '0';
            }
            nm = 0;
            for (int i=0; i<nn; i++) {
                if (s[i] == '1') {
                    nm++;
                }
            }
            if (nm == m) {
                str.setNum(j);
                ui->J->setText(str);
                ui->Result->setText(s);
                ui->r->setText("1");
            } else {
                ui->Result->setText("Несимметричная ошибка второй кратности");
                ui->r->setText("2");
            }
        } else {
            j = (j - r) % nn;
            if (j<0) {
                j = nn + j;
            }
            if (s[j] == '0') {
                s[j] = '1';
            } else {
                s[j] =  '0';
            }
            nm = 0;
            for (int i=0; i<nn; i++) {
                if (s[i] == '1') {
                    nm++;
                }
            }
            if (nm == m) {
                str.setNum(j);
                ui->J->setText(str);
                ui->Result->setText(s);
                ui->r->setText("1");
            } else {
                ui->Result->setText("Несимметричная ошибка второй кратности");
                ui->r->setText("2");
            }
        }
    } else {
        for (int i=0; i<nr.length(); i++) {
            if (nr[i]!= new_rs[i]) {
                k++;
                j = i;
            }
        }
        if (k == 0) {
            ui->r->setText("0");
            ui->Result->setText(s);
        } else if (k == 1) {
            ui->r->setText("1");
            ui->Result->setText(s);
            j = j + nn;
            str.setNum(j);
            ui->J->setText(str);
        } else {
            ui->Result->setText("Симметричная ошибка второй кратности");
            ui->r->setText("2");
        }
    }
}

void MainWindow::on_ExitButton_clicked()
{
    this->close();
}
