#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <vector>
#include <math.h>
#include "math.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_AcceptButton_clicked();

    void on_CodeButton_clicked();

    void on_DecodeButtonClicked_clicked();

    void on_ExitButton_clicked();

    void on_DecodeButton_clicked();

private:
    Ui::MainWindow *ui;
    QString code;
    int m;
    int n;
    vector <int> pos;
    int l;
};

#endif // MAINWINDOW_H
