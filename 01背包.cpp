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

unsigned int f[V];          //ȫ�ֱ������Զ���ʼ��Ϊ0
unsigned int weight[10];
unsigned int value[10];

int main()
{
    int N,M;
	cin>>N;                 //��Ʒ����
	cin>>M;                 //��������
	for(int i=1;i<=N;i++)
	{
		cin>>weight[i]>>value[i];
	}
	for(int i=1;i<=N;i++)
    {
        for (int j=M;j>=1;j--)
        {
			if(weight[i] <= j)
			{
				f[j]=max(f[j],f[j-weight[i]]+value[i]);
			}
		}
    }
	cout<<f[M]<<endl;       //������Ž�
	return 0;
}