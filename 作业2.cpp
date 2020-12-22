#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

//#===================================================================================
//# �� Class Setup
//#===================================================================================
    class Point
    {
        public:
            Point();
            void setValue(double nx, double ny);
            double getx();
            double gety();
        private:
            double x, y;
    };
//---------------------------------------------------------------
    class Triangle
    {
        public:
            Triangle(Point& pa, Point& pb, Point& pc);
            double getDistance(Point& tp1, Point& tp2);
            bool judge(double a, double b, double c);
            double getArea();
            double getPerimeter();
        private:
            Point p1, p2, p3;
    };

//#===================================================================================
//# �� Initialize
//#===================================================================================
    void initialize()
    {
        printf("#============================================================\n");
        printf("# �� Triangel Calculator\n");
        printf("#    Version 1.0.0\n");
        printf("#                                           ������ 1004176109\n");
        printf("#============================================================\n");
        printf("# ÿ���������ΰ�����ʾ����������������x��y���м��Կո����\n");
        printf("#============================================================");
        cout<<endl;
        printf("#---------------------------------------\n");
        printf("# ��ѡ��\n");
        printf("# 1����������ʼ����\n");
        printf("# 2���������˳�\n");
        printf("#---------------------------------------\n");
        cout<<endl;
    }

//#===================================================================================
//# �� Update_Message
//#===================================================================================
    void update_message()
    {
        printf("#---------------------------------------\n");
        printf("# �Ƿ������\n");
        printf("# 1������������\n");
        printf("# 2���������˳�\n");
        printf("#---------------------------------------\n");
        cout<<endl;
    }

//#===================================================================================
//# �� Main
//#===================================================================================
    int main()
    {
        int n;
        double ax,ay,bx,by,cx,cy,tmp;
        Point pa,pb,pc;
        initialize();
        while(cin>>n)
        {
            if(n == 2)
                exit(0);
            else if(n == 1)
            {
                cout<<"������A�����꣺ ";
                cin>>ax>>ay;
                cout<<"������B�����꣺ ";
                cin>>bx>>by;
                cout<<"������C�����꣺ ";
                cin>>cx>>cy;
                pa.setValue(ax,ay);
                pb.setValue(bx,by);
                pc.setValue(cx,cy);
                Triangle tr(pa,pb,pc);
                tmp = tr.getArea();
                cout<<endl;
                if(tmp == 0)
                    cout<<"�޷����������Σ�"<<endl;
                else
                {
                    cout<<"���������ܳ�Ϊ�� "<<tr.getPerimeter()<<endl;
                    cout<<"�����������Ϊ�� "<<tmp<<endl;
                }
            }
            else
                cout<<"��Ч���룡���������롣"<<endl;
            cout<<endl;
            update_message();
        }
        return 0;
    }

//#===================================================================================
//# �� Class Point
//#===================================================================================
    Point::Point()
    {
        x = 0;
        y = 0;
    }
//---------------------------------------------------------------
    void Point::setValue(double nx, double ny)
    {
        x = nx;
        y = ny;
    }
//---------------------------------------------------------------
    double Point::getx()
    {
        return x;
    }
//---------------------------------------------------------------
    double Point::gety()
    {
        return y;
    }

//#===================================================================================
//# �� Class Triangel
//#===================================================================================
    Triangle::Triangle(Point& pa, Point& pb, Point& pc)
    {
        p1 = pa;
        p2 = pb;
        p3 = pc;
    }
//---------------------------------------------------------------
    double Triangle::getDistance(Point& tp1, Point& tp2)
    {
        double tmp,dx,dy;
        dx = abs(tp1.getx() - tp2.getx());
        dy = abs(tp1.gety() - tp2.gety());
        tmp = sqrt(dx*dx + dy*dy);
        return tmp;
    }
//---------------------------------------------------------------
    bool Triangle::judge(double a, double b, double c)
    {
        if(a>0 && b>0 && c>0)
        {
            if(a+b>c && a+c>b && b+c>a)
                return true;
            else
                return false;
        }
        else
            return false;
    }
//---------------------------------------------------------------
    double Triangle::getPerimeter()
    {
        double a,b,c,tmp;
        a = getDistance(p1,p2);
        b = getDistance(p2,p3);
        c = getDistance(p1,p3);
        if(judge(a,b,c))
            tmp = a+b+c;
        else
            tmp = 0;
        return tmp;
    }
//---------------------------------------------------------------
    double Triangle::getArea()
    {
        double a,b,c,p,tmp;
        a = getDistance(p1,p2);
        b = getDistance(p2,p3);
        c = getDistance(p1,p3);
        if(judge(a,b,c))
        {
            p = (a+b+c)/2;
            tmp = sqrt(p*(p-a)*(p-b)*(p-c));
        }
        else
            tmp = 0;
        return tmp;
    }