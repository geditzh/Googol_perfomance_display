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

//    vector<vector<double>> pos;
//    QFile file("C:/Users/df/Desktop/Googol_point_move/googol/test.txt");
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        cout<<"Can't open the file!"<<endl;
//    }

//    QStringList list;
//    while(!file.atEnd())
//    {
//        QByteArray line = file.readLine();
//        QString str(line);
//        list = str.split("\t");

//        double x = list[0].toDouble();
//        double y = list[1].toDouble();
//        double z = list[2].toDouble();

//        vector<double> temp;
//        temp.push_back(x);
//        temp.push_back(y);
//        temp.push_back(z);
//        pos.push_back(temp);
//    }


//    vector<long> time;
//    QFile file1("C:/Users/df/Desktop/Googol_point_move/googol/time.txt");
//    if(!file1.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        cout<<"Can't open the file!"<<endl;
//    }

//    while(!file1.atEnd())
//    {
//        QByteArray line = file1.readLine();
//        QString str(line);
//        time.push_back(str.toLong());
//    }

//    cout<<time.size()<<endl;
//    cout<<pos.size()<<endl;


//    cout.setf(ios::fixed);
//    cout.precision(16);
//    short flag=1;
//    long lGpiValue;

//    AssemblyRobot myrobot;
//    cout << "myrobot.Initial():"<<myrobot.Initial(RbtAllAxis)<<endl;

//    vector<long> time1;
//    for(int i=0;i<pos.size();i++)
//    {
//        time1.push_back(8*i);
//    }
//    for(int i =0;i<pos.size();i++)
//    {
//        cout<<time1[i]<<endl;
//    }

//    vector<long> time2;
//    for(int i=0;i<pos.size();i++)
//    {
//        time2.push_back(4*i);
//    }
//    for(int i =0;i<pos.size();i++)
//    {
//        cout<<time2[i]<<endl;
//    }

//    while(flag == 1)
//    {
//        GT_GetDi(MC_GPI,&lGpiValue);
//        if(lGpiValue& (1<<1))
//        {
//            if(myrobot.PointMove(pos,time1,pos.size())!=RobotSuccess)
//                cout<<"oh my god"<<endl;

//            if(myrobot.PointMove(pos,time2,pos.size())!=RobotSuccess)
//                cout<<"oh my god"<<endl;
//        }
//        if(lGpiValue& (1<<powerIO))
//        {
//            flag = 0;
//        }
//    }
//    cout <<"myrobot.Close():"<< myrobot.Close()<<endl;



        cout.setf(ios::fixed);
        cout.precision(16);
        short flag=1;
        long lGpiValue;

        AssemblyRobot myrobot;
        cout << "myrobot.Initial():"<<myrobot.Initial(RbtAllAxis)<<endl;

        double vel1[1][3] = {{0.005,0.3,0.005}};
        double vel2[1][3] = {{0.01,0.15,0.01}};
        double vel3[1][3] = {{0.01,0.1,0.01}};

        double ang0[2][3] = {{0,0,0},{0,0,0}};
        double ang1[2][3] = {{0,0,0},{-20,0,0}};
        double ang2[2][3] = {{0,0,0},{20,0,0}};
        double ang3[2][3] = {{0,0,0},{0,-20,0}};
        double ang4[2][3] = {{0,0,0},{0,20,0}};
        double ang5[2][3] = {{0,0,0},{0,0,-20}};
        double ang6[2][3] = {{0,0,0},{0,0,20}};

        double ang7[2][3] = {{0,0,0},{-10,10,0}};
        double ang8[2][3] = {{0,0,0},{-10,-10,0}};
        double ang9[2][3] = {{0,0,0},{10,-10,0}};
        double ang10[2][3] = {{0,0,0},{10,10,0}};

        while(flag == 1)
        {
            GT_GetDi(MC_GPI,&lGpiValue);
            if(lGpiValue& (1<<1))
            {
                for(int o=0;o<1;o++)
                {
                    if(myrobot.AngMove(ang5,vel3,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang6,vel3,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang0,vel3,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang3,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang4,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang0,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang1,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang2,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang0,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;
                }

                for(int o=0;o<3;o++)
                {
                    if(myrobot.AngMove(ang4,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang1,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang3,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang2,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang0,vel3,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang4,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;
                    if(myrobot.AngMove(ang7,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang1,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;
                    if(myrobot.AngMove(ang8,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang3,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;
                    if(myrobot.AngMove(ang9,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang2,vel1,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;
                    if(myrobot.AngMove(ang10,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang0,vel3,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang7,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang8,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang9,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang10,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;

                    if(myrobot.AngMove(ang0,vel2,1)!=RobotSuccess)
                        cout<<"oh my god"<<endl;
                }
            }

            if(lGpiValue& (1<<powerIO))
            {
                flag = 0;
            }
        }
        cout <<"myrobot.Close():"<< myrobot.Close()<<endl;

    return e.exec();
}

//int main(int argc,char *argv[])	//电机点位运动
//{
//    QCoreApplication a(argc, argv);
//    AssemblyRobot myrobot;
//    short count,flag=1;
//    long lGpiValue;

//    cout << "myrobot.Initial():"<<myrobot.Initial(RbtAllAxis)<<endl;

//    while(flag == 1)
//    {
//        GT_GetDi(MC_GPI,&lGpiValue);
//        if(lGpiValue& (1<<1))
//        {
//            double ang1[1][3];
//            long time[1] = { 5000 };
//            while(lGpiValue& (1<<1))
//            {
//                cout<<"input three numbers"<<endl;
//                scanf("%lf%lf%lf",&ang1[0][0],&ang1[0][1],&ang1[0][2]);
//                if(ang1[0][0] == 100) break;
//                count = sizeof(time) / sizeof(time[0]);
//                cout << "count = " << count << endl;
//                cout << "AngMove(): = " << myrobot.PointMove(ang1, time, count) << endl;
//            }
//        }

//        if(lGpiValue& (1<<powerIO))
//        {
//            flag = 0;
//        }
//    }

//    cout <<"myrobot.Close():"<< myrobot.Close()<<endl;

//    return a.exec();
//}
