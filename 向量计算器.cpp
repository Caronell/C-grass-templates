#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#define INF 0x7f
#define MAXN 500005
using namespace std;

int main()
{
    int n,a1,b1,c1,a2,b2,c2;
    printf("#==============================================\n");
    printf("# ● 向量计算器\n");
    printf("#    版本：v1.0.1\n");
    printf("#    制作：信息工程学院 Caronell\n");
    printf("#==============================================\n");
    printf("\n");
    while(1)
    {
        cout<<"1——求叉积"<<endl;
        cout<<"2——求点积"<<endl;
        cout<<"3——退出"<<endl;
        cin>>n;
        cout<<endl;
        if(n == 1)
        {
            int x,y,z;
            cout<<"输入n1的x、y、z，以空格隔开："<<endl;
            cin>>a1>>b1>>c1;
            cout<<"输入n2的x、y、z，以空格隔开："<<endl;
            cin>>a2>>b2>>c2;
            x = b1*c2 - c1*b2;
            y = -(a1*c2 - c1*a2);
            z = a1*b2 - b1*a2;
            cout<<endl;
            printf("结果为：(%d,%d,%d)\n",x,y,z);
            printf("=============================================\n");
            cout<<endl;
        }
        else if(n == 2)
        {
            int sum;
            cout<<"输入n1的x、y、z，以空格隔开："<<endl;
            cin>>a1>>b1>>c1;
            cout<<"输入n2的x、y、z，以空格隔开："<<endl;
            cin>>a2>>b2>>c2;
            sum = a1*a2 + b1*b2 + c1*c2;
            cout<<endl;
            printf("结果为：%d\n",sum);
            printf("=============================================\n");
            cout<<endl;
        }
        else if(n == 3)
            exit(0);
        else
            cout<<"输入无效！\n"<<endl;
    }
	return 0;
}