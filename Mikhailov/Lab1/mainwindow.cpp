#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sstream>

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h = new Hamming();
}

MainWindow::~MainWindow()
{
    delete ui;
}

string Hamming::code()
{
    string ans = "", s;
    int pow = 1, cur = 0;
    int last = 0, ind = 0;
    ans = getMask(n, m);
    int l = ans.length();
    x = QStringList();
    while (pow < l) {
        cur = sum(ans, pow);
        ans[pow - 1] = (char)((int)'0' + cur);
        s = toString(pow) + " " + toString(ans[pow - 1]);
        x << QString(s.c_str());
        pow *= 2;
    }
    int r = 0;
    for (int i = 0; i<l; i++) {
        r += ((int)ans[i] - (int)'0');
        r %= 2;
    }
    char a = (char)(r + (int)'0');
    ans = a + ans;
    string s1 = "";
    s1 += "0 ";
    s1 += a;
    x<<QString(s1.c_str());
    x.sort();
    return ans;
}

string Hamming::decode(string s)
{
    int pow = 1, cur = 0, i = 1;
    string s1 = s.substr(1, s.length()-1), s2 = "";
    int l = s1.length(), last = 0;\
    N = 0;
    string ans ="";
    s2 = "0 ";
    s2 += s[0];
    e = QStringList();
    e<< QString(s2.c_str());
    s2 = "";
    ks = "";
    while (pow < l) {
        cur = sum(s1, pow);
        ks += toString(cur);
        N += cur* pow;
        last = pow;
        s2 = toString(i) + " " + toString(cur);
        e << QString(s2.c_str());
        pow*= 2;
        i = i +1;
        for (int i= last; i<pow - 1 && i< l; i++) {
            ans += s1[i];
        }
    }
    char a;
    int k = ks.length();
    for (int i=0; i<k/2; i++) {
        a = ks[i];
        ks[i] = ks[k-i-1];
        ks[k-i-1] = a;
    }
    return ans;
}

int Hamming::sum(string s, int pow)
{
    int ans = 0, cur = pow - 1, l = s.length();
    while (cur < l) {
        int i;
        for (i = cur; i<cur + pow && i< l; i++) {
            ans = ans + (int)s[i] - (int)'0';
            ans %= 2;
        }
        cur = i + pow;
    }
    return ans;
}

void Hamming::calcM(int l)
{
    m = 0;
    int pow = 1;
    while (pow < l + m) {
        pow*= 2;
        m++;
    }
}

string Hamming::getMask(string s, int m)
{
    string ans="";
    int ind = 0, pow = 1;
    for (int i=0; i< s.length() + m; i++) {
        if (i == pow - 1) {
            ans += '0';
            pow *= 2;
        } else {
            ans += s[ind];
            ind ++;
        }
    }
    return ans;
}

void Hamming::setValues(string s)
{
    n = s;
    k = s.length();
    calcM(k);
}

void MainWindow::on_InputButton_clicked()
{
    string s2 = ui->InformSequence->text().toStdString();
    h->setValues(s2);
    string s = toString(h->k);
    ui->k->setText(s.c_str());
    s = toString(h->m);
    ui->m->setText(s.c_str());
    s = toString(h->k + h->m);
    ui->n->setText(s.c_str()); // !!!надо уменьшить на единицу!!!!
}

void MainWindow::on_CodeButton_clicked()
{
    ui->CodeCombination->setText(h->code().c_str());
    ui->StaffChoicee->clear();
    ui->StaffChoicee->addItems(h->x);
}

void MainWindow::on_DecodeButton_clicked()
{
    string s = ui->AcceptedCodeCombination->text().toStdString();
    string s2 = "", N="";
    int r = 0, k = 0;
    s2 = h->decode(s);
    if (h->N!= 0) k = h->N;
    ui->StaffChoiceE->clear();
    ui->StaffChoiceE->addItems(h->e);
    int sum = 0;
    string ks = h->ks;
    for (int i=0; i<s.length(); i++) {
        sum += (int)s[i] - (int)'0';
        sum %= 2;
    }
    if (sum == 0) {
        if (h->N!=0) {
            r = 2;
            s2 = "Повторная передача";
        } else {
            r = 0;
        }
    } else if (h->N != 0) {
        r = 1;
        N = toString(h->N);
        int pow = 1;
        s[h->N] = (char)((int('0')+1-((int)s[h->N] - (int)'0')));
    }
    ui->textBrowser_4->setText(ks.c_str());
    ui->r->setText(toString(r).c_str());
    ui->N->setText(N.c_str());
    ui->Result->setText(s2.c_str());
}

void MainWindow::on_ExitButton_clicked()
{
    this->close();
}
