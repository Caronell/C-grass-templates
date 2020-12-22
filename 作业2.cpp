#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

//#===================================================================================
//# ● Class Setup
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
//# ● Initialize
//#===================================================================================
    void initialize()
    {
        printf("#============================================================\n");
        printf("# ● Triangel Calculator\n");
        printf("#    Version 1.0.0\n");
        printf("#                                           王欣鹏 1004176109\n");
        printf("#============================================================\n");
        printf("# 每次输入依次按照提示输入三点坐标数字x、y，中间以空格隔开\n");
        printf("#============================================================");
        cout<<endl;
        printf("#---------------------------------------\n");
        printf("# 请选择：\n");
        printf("# 1————开始计算\n");
        printf("# 2————退出\n");
        printf("#---------------------------------------\n");
        cout<<endl;
    }

//#===================================================================================
//# ● Update_Message
//#===================================================================================
    void update_message()
    {
        printf("#---------------------------------------\n");
        printf("# 是否继续？\n");
        printf("# 1————继续\n");
        printf("# 2————退出\n");
        printf("#---------------------------------------\n");
        cout<<endl;
    }

//#===================================================================================
//# ● Main
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
                cout<<"请输入A点坐标： ";
                cin>>ax>>ay;
                cout<<"请输入B点坐标： ";
                cin>>bx>>by;
                cout<<"请输入C点坐标： ";
                cin>>cx>>cy;
                pa.setValue(ax,ay);
                pb.setValue(bx,by);
                pc.setValue(cx,cy);
                Triangle tr(pa,pb,pc);
                tmp = tr.getArea();
                cout<<endl;
                if(tmp == 0)
                    cout<<"无法构成三角形！"<<endl;
                else
                {
                    cout<<"该三角形周长为： "<<tr.getPerimeter()<<endl;
                    cout<<"该三角形面积为： "<<tmp<<endl;
                }
            }
            else
                cout<<"无效输入！请重新输入。"<<endl;
            cout<<endl;
            update_message();
        }
        return 0;
    }

//#===================================================================================
//# ● Class Point
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
//# ● Class Triangel
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