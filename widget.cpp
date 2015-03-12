#include "widget.h"
#include <QtWidgets>
#include <QLayout>
#include <QMessageBox>
#include <QDebug>
#include <QStyle>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    text=new QTextEdit(this);
    calbt=new QPushButton(tr("计算"));
    quitbt=new QPushButton(tr("退出"));

    connect(calbt,SIGNAL(clicked()),this,SLOT(work()));
    connect(quitbt,SIGNAL(clicked()),qApp,SLOT(quit()));

    QHBoxLayout *btlayout=new QHBoxLayout;
    QVBoxLayout *mainlayout=new QVBoxLayout;
    btlayout->addWidget(calbt);
    btlayout->addWidget(quitbt);
    mainlayout->addWidget(text);
    mainlayout->addLayout(btlayout);
    setLayout(mainlayout);
}
void Widget::xianshi(QStringList  name,int *JNS,int *zy)
{
    QStringList remain;
    remain<<"酒仙"<<"酒仙"<<"防护骑士"<<"冰DK/防护骑士"<<"冰DK/暗牧/痛苦术"<<"元素萨/增强萨/毁灭术/图拉妮"<<"织雾/戒律/暗牧"
         <<"酒仙/织雾/戒律/增强萨/神牧"<<"熊德/兽王猎/酒仙/踏风/防护骑士"<<"奶德/神牧/三系萨满"<<"织雾/神圣骑士/元素萨/恢复萨/毁灭术"
        <<"奶德/防护骑士/神圣骑士/戒律/暗牧/痛苦术"<<"奶德/织雾/神圣骑士/戒律/神牧/恢复萨"<<"冰DK/奶德/神牧/暗牧/恢复萨/痛苦术"
       <<"冰DK/织雾/防护骑士/神圣骑士/恢复萨/痛苦术"<<"三系DK/兽王猎/武器战/防战"<<"猫德/熊德/兽王猎/酒仙/踏风/武器战/防战"
      <<"奶德/酒仙/神圣骑士/戒律/元素萨/增强萨/毁灭术"<<"血DK/邪DK/猫德/熊德/酒仙/防护骑士/防战"<<"三系DK/踏风/防护骑士/武器战/防战"
     <<"三系DK/猫德/踏风/兽王猎/武器战"<<"猫德/熊德/生存猎/酒仙/刺杀贼/敏锐贼/狂暴战/防战"<<"熊德/生存猎/冰法/酒仙/惩戒骑士/防护骑士/刺杀贼/敏锐贼"
    <<" 血DK/邪DK/生存猎/冰法/惩戒骑士/狂暴战/防战/敏锐贼/恶魔术"<<"血DK/邪DK/猫德/生存猎/冰法/惩戒骑士/刺杀贼/恶魔术/狂暴战"
    <<" 血DK/邪DK/冰法/惩戒骑士/防护骑士/刺杀贼/敏锐贼/恶魔术/狂暴战/防战"<<" 射击猎/奥法/火法/踏风/织雾/三系盗贼/三系战士"
    <<"鸟德/三系猎人/火法/神牧/暗牧/战斗贼/敏锐贼/增强萨/三系战士"<<"猫德/鸟德/三系猎人/奥法/火法/踏风/暗牧/刺杀贼/战斗贼/增强萨/武器战/狂暴战"
    <<"三系DK/射击猎/三系法师/踏风僧/惩戒骑士/刺杀贼/战斗贼/元素萨/恶魔术/痛苦术/武器战/狂暴战"
    <<"鸟德/奶德/三系猎人/火法/冰法/惩戒骑士/暗牧/战斗贼/敏锐贼/元素萨/增强萨/痛苦术"<<"射击猎/三系法师/踏风/三系骑士/三系盗贼/元素萨/痛苦术/毁灭术"
    <<"熊德/鸟德/三系猎人/奥法/火法/酒仙/踏风/戒律/暗牧/三系盗贼/增强萨"<<"鸟德/三系猎人/三系法师/踏风/惩戒骑士/暗牧/刺杀贼/战斗贼/元素萨/增强萨/痛苦术/毁灭术"
    <<"三系DK/射击猎/火法/冰法/惩戒骑士/战斗贼/敏锐贼/元素萨/恢复萨/痛苦术/恶魔术/三系战士"
    <<"三系DK/鸟德/三系猎人/火法/冰法/暗牧/战斗贼/元素萨/增强萨/恶魔术/痛苦术/武器战/狂暴战";
    QStringList jgm;
    jgm<<"重击+野生怪物: "<<"群体伤害+野生怪物："<<"魔法减益+野生怪物: "<<"危险区域+野生怪物: "<<"爪牙围攻+野生怪物: "<<"强力法术+野生怪物: "
      <<"致命爪牙+野生怪物: "<<"限时战斗+野生怪物: "<<"群体伤害+重击： "<<"魔法减益+重击: "<<"危险区域+重击: "<<"重击+爪牙围攻: "<<"重击+强力法术: "
     <<"致命爪牙+重击 :"<<"限时战斗+重击: "<<"群体伤害+魔法减益： "<<"危险区域+群体伤害: "<<"群体伤害+爪牙围攻: "<<"群体伤害+强力法术: "
    <<"致命爪牙+群体伤害: "<<"群体伤害+限时战斗: "<<"危险区域+魔法减益: "<<"魔法减益+爪牙围攻: "<<"魔法减益+强力法术: "<<"致命爪牙+魔法减益: "
    <<"魔法减益+限时战斗: "<<"危险区域+爪牙围攻: "<<"危险区域+强力法术: "<<"危险区域+致命爪牙: "<<"危险区域+限时战斗: "<<"爪牙围攻+强力法术: "
    <<"致命爪牙+爪牙围攻: "<<"爪牙围攻+限时战斗: "<<"致命爪牙+强力法术: "<<"强力法术+限时战斗: "<<"致命爪牙+限时战斗: ";
    QString xs="";
    int num[36]={8,1,9,2,25,20,21,16,6,17,18,24,15,22,23,4,3,19,0,5,7,10,13,11,14,12,27,26,
                 29,34,31,33,28,35,30,32};
    int i,v;
    int count;
    for(i=0;i<36;i++)
    {
        v=num[i];
        if(skillnow[match[v]]==v)
            count=0;
        else
            count=JNS[zy[match[v]]];
        if(weight[match[v]][v]==999999)
            xs+="<font color=blue>"+jgm[v]+"</font>"+"<font color=red>"+remain[i]+"</font>"+"<br>";
        else
            xs+="<font color=blue>"+jgm[v]+"</font>"+"<font color=green>"+name[match[v]]+"("+QString::number(count)+")"+"</font>"+"<br>";
    }
    QString str1="限时战斗+限时战斗： ";
    QString str2="恶魔术/毁灭术(仅通过初始技能为限时战斗随从升级获得)。";
    if(!sxsyes)
        xs+="<font color=blue>"+str1+"</font>"+"<font color=red>"+str2+"</font>"+"<br>";
    else
        xs+="<font color=blue>"+str1+"</font>"+"<font color=green>"+sxs+"</font>"+"<br>";
     QMessageBox mes(QMessageBox::NoIcon,tr("分析结果"),xs);
     mes.exec();
}

bool Widget::chazhao(int u)
{
    int i,t;
    sx[u]=1;
    for(i=0;i<id;i++)
    {
        if(!sy[i])
        {
            t=weight[u][i]-lx[u]-ly[i];
            if(t==0)
            {
                sy[i]=1;
                if(match[i]==-1||chazhao(match[i]))
                {
                    match[i]=u;
                    return true;
                }
            }
            else if(t>0&&dx>t)
                     dx=t;
        }
    }
    return 0;
}

void Widget::work()
{
    QStringList tfm;
    sxsyes=false;
    tfm<<"0"<<"1"<<"血迪凯"<<"冰迪凯"<<"邪迪凯"<<"5"
      <<"鸟德"<<"猫德"<<"熊德"<<"奶德"
       <<"兽王猎"<<"生存猎"<<"射击猎"<<"13"
      <<"奥法"<<"火法"<<"冰法"
     <<"酒仙"<<"奶僧"<<"风僧"
    <<"奶骑"<<"防骑"<<"惩戒骑"
     <<"戒律牧"<<"神牧"<<"暗牧"
       <<"刺杀贼"<<"战斗贼"<<"敏锐贼"
       <<"元素萨"<<"增强萨"<<"奶萨"
       <<"痛苦术"<<"恶魔术"<<"毁灭术"
      <<"武器战"<<"36"<<"狂暴战"<<"防战";
    int map[10]={0,0,8,15,21,26,30,33,35};
    int JNS[40]={
        0,0,10,9,10,0,6,5,
        6,6,10,0,10,10,6,10,
        10,10,6,10,6,10,9,6,
        5,10,10,10,10,10,10,6,
        7,5,5,10,0,10,10,0};
    int JNZH[40][10]={
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {4,0,5,7,11,14,12,34,30,32},{25,2,22,23,5,7,34,30,32,-1},
        {4,0,5,7,11,14,12,34,30,32},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {26,29,31,28,35,32,-1,-1,-1,-1},{3,7,0,10,14,-1,-1,-1,-1,-1},
        {6,3,0,10,13,28,-1,-1,-1,-1},{17,24,15,22,19,31,-1,-1,-1,-1},
        {6,4,3,7,26,29,31,28,35,32},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {27,34,26,29,31,33,28,35,30,32},{10,13,11,14,26,29,31,28,35,32},
        {27,34,29,33,28,35,-1,-1,-1,-1},{27,34,26,29,31,33,28,35,30,32},
        {13,11,14,12,34,31,33,35,30,32},{8,1,16,6,3,19,0,10,13,28},
        {21,16,18,15,27,23,-1,-1,-1,-1},{6,3,5,7,27,34,29,33,28,35},
        {18,24,15,19,33,23,-1,-1,-1,-1},{9,2,6,24,0,5,13,12,33,23},
        {13,11,14,12,34,31,33,35,30,-1},{21,16,24,15,19,28,-1,-1,-1,-1},
        {16,17,15,22,26,-1,-1,-1,-1,-1},{25,21,24,22,26,29,31,28,35,32},
        {10,13,14,12,27,34,29,33,28,35},{27,34,26,29,31,33,28,35,30,32},
        {10,13,11,12,27,26,31,33,28,30},{20,17,18,19,34,31,33,35,30,32},
        {20,16,17,19,26,29,31,28,35,32},{17,18,15,22,30,23,-1,-1,-1,-1},
        {24,22,34,31,33,30,23,-1,-1,-1},{11,14,12,30,32,-1,-1,-1,-1,-1},
        {20,18,19,33,35,-1,-1,-1,-1,-1},{4,3,5,7,27,34,26,29,30,32},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{10,11,14,12,27,34,26,29,30,32},
        {4,3,0,5,10,11,12,27,26,30},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},

    };
    QString content=text->toPlainText();
    QString cmd="";
    QStringList words;
    int i,j;
    QString str;
    QStringList name;
    int zy[200];
    int pz,jn1,jn2;
    int tmp,res;
    for(i=0;i<200;i++)
        for(j=0;j<200;j++)
            weight[i][j]=999999;
    for(i=0;i<content.size();i++)
    {
        if(content[i]=='\n')
            break;
    }
    i++;
    id=0;
    for(;i<content.size();i++)
    {
        if(content[i]=='\n'||i==content.size()-1)
        {
            words=cmd.split(",");
            cmd="";
            str=words[1];
            zy[id]=words[3].toInt();
            pz=words[5].toInt();
            str=str+"-----"+tfm[zy[id]];
            if(words[8]=="0")str="<u>"+str+"</u>";
            name.append(str);
            jn1=words[9].toInt();
            if(pz==4)
            {
               jn2=words[11].toInt();
               if(jn1>5)jn1--;
               if(jn2>5)jn2--;
               if(jn1>jn2)
               {
                   tmp=jn1;
                   jn1=jn2;
                   jn2=tmp;
               }
               if(jn1!=jn2)
               {
                   res=map[jn1]+(jn2-jn1)-1;

                   skillnow[id]=res;
                   for(j=0;j<JNS[zy[id]];j++)
                   {
                       weight[id][JNZH[zy[id]][j]]=JNS[zy[id]];
                   }
                   weight[id][res]=0;

               }
               else
               {
                   sxsyes=true;
                   sxs=str+"(0)";
               }
              }

            id++;
        }
        else
        {
             cmd+=content[i];
        }
   }
   for(i=0;i<id;i++)
   {
       lx[i]=0x7fffffff;
       ly[i]=0;
       for(j=0;j<id;j++)
       {
           if(weight[i][j]<lx[i])
               lx[i]=weight[i][j];
       }
   }
   memset(match,-1,sizeof(match));
   dx=0x7fffffff;
   for(i=0;i<id;i++)
   {
        memset(sx,0,sizeof(sx));
        memset(sy,0,sizeof(sy));
        while(!chazhao(i))
        {
            for(j=0;j<id;j++)
            {
                if(sx[j])lx[j]+=dx;
                if(sy[j])ly[j]-=dx;
            }
            memset(sx,0,sizeof(sx));
            memset(sy,0,sizeof(sy));
        }
   }
   qDebug()<<id;
   xianshi(name,JNS,zy);
}

