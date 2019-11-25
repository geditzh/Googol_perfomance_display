#include <QCoreApplication>
#include "AssemblyRobot.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include  <QFile>
#include "gts.h"
using namespace std;

int main(int argc, char *argv[])    //读取文件，性能展示
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

    cout<<pos.size()<<endl;

    short flag=1;
    long lGpiValue;

    AssemblyRobot myrobot;
    cout << "myrobot.Initial():"<<myrobot.Initial(RbtAllAxis)<<endl;

    vector<long> time;
    for(int i=0;i<pos.size();i++)
    {
        time.push_back(1*i);
    }

    while(flag == 1)
    {
        GT_GetDi(MC_GPI,&lGpiValue);
        if(lGpiValue& (1<<1))
        {


            if(myrobot.PointMove(pos,time,pos.size())!=RobotSuccess)
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
