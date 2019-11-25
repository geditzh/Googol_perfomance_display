#include <QCoreApplication>
#include "AssemblyRobot.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include  <QFile>
#include "gts.h"
using namespace std;

int main(int argc, char *argv[])    //正逆街测试
{
    QCoreApplication e(argc, argv);

    vector<vector<double>> pos;
    QFile file("./debug/display.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout<<"Can't open the file!"<<endl;
    }

    QStringList list;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        list = str.split("\t");

        double x = list[0].toDouble();
        double y = list[1].toDouble();
        double z = list[2].toDouble();

        vector<double> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        pos.push_back(temp);
    }

    vector<vector<double>> pos1;
    QFile file1("./debug/luoxuanxian.txt");
    if(!file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout<<"Can't open the file!"<<endl;
    }

    QStringList list1;
    while(!file1.atEnd())
    {
        QByteArray line1 = file1.readLine();
        QString str(line1);
        list1 = str.split("\t");

        double x = list1[0].toDouble();
        double y = list1[1].toDouble();
        double z = list1[2].toDouble();

        vector<double> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        pos1.push_back(temp);
    }

    cout<<pos.size()<<endl;
    cout<<pos1.size()<<endl;

    cout.setf(ios::fixed);
    cout.precision(16);
    short flag=1;
    long lGpiValue;

    AssemblyRobot myrobot;
    cout << "myrobot.Initial():"<<myrobot.Initial(RbtAllAxis)<<endl;

    vector<long> time1;
    for(int i=0;i<pos.size();i++)
    {
        time1.push_back(1*i);
    }

    vector<long> time2;
    for(int i=0;i<pos1.size();i++)
    {
        time2.push_back(8*i);
    }

    while(flag == 1)
    {
        GT_GetDi(MC_GPI,&lGpiValue);
        if(lGpiValue& (1<<1))
        {

//            if(myrobot.PointMove(pos,time1,pos.size())!=RobotSuccess)
//                cout<<"oh my god"<<endl;

            if(myrobot.PointMove(pos1,time2,pos1.size())!=RobotSuccess)
                cout<<"oh my god"<<endl;

        }
        if(lGpiValue& (1<<powerIO))
        {
            flag = 0;
        }
    }
    cout <<"myrobot.Close():"<< myrobot.Close()<<endl;

    return e.exec();
}
