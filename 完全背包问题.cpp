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
#define  V 1500
using namespace std;

unsigned int f[V];          //全局变量，自动初始化为0
unsigned int weight[10];
unsigned int value[10];

int main()
{
    int N,M;
	cin>>N;                 //物品个数
	cin>>M;                 //背包容量
	for(int i=1;i<=N;i++)
	{
		cin>>weight[i]>>value[i];
	}
	for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
		{
			if(weight[i] <= j)
			{
				f[j]=max(f[j],f[j-weight[i]]+value[i]);
			}
		}
    }
	cout<<f[M]<<endl;       //输出最优解
	return 0;
}