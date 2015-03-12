#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
private slots:
    void work();
    bool chazhao(int u);
    void xianshi(QStringList name,int *JNS,int *zy);
private:
    QPushButton *calbt;
    QPushButton *quitbt;
    QTextEdit *text;
    int skillnow[200];
    int id;
    int weight[200][200];
    int lx[200],ly[200];
    bool sx[200],sy[200];
    int match[200];
    int dx;
    bool sxsyes;
    QString sxs;
};

#endif // WIDGET_H
