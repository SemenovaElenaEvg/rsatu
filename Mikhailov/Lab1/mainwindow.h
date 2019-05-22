#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QCloseEvent>

#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class Hamming
{
public:
    int k;
    int m;
    QStringList x;
    int N;
    QStringList e;
    string ks;
    Hamming() {
        k = 0;
        m = 0;
        n = "";
        ks = "";
    };
    ~Hamming() {};
    string code();
    string decode(string s);
    void setValues(string s);

private:
    string n;
    int sum(string s, int pow);
    void calcM(int l);
    string getMask(string s, int m);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_InputButton_clicked();

    void on_CodeButton_clicked();

    void on_DecodeButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
    Hamming* h;
    Hamming* h1;
};

#endif // MAINWINDOW_H
