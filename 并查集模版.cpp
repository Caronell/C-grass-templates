#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int node[i]; //ÿ���ڵ�
int rank[i]; //���ĸ߶�

void Init(int n);
int find(int x);
void Unite(int x, int y);
bool same(int x, int y);

int main()
{

	return 0;
}

//��ʼ��n���ڵ�
void Init(int n)
{
    for(int i = 0; i < n; i++)
    {
        node[i] = i;
        rank[i] = 0;
    }
}

//���ҵ�ǰԪ���������ĸ��ڵ�(����Ԫ��)
int find(int x)
{
    if(x == node[x])
        return x;
    return node[x] = find(node[x]); //�ڵ�һ�β���ʱ�����ڵ�ֱ�������ڵ�
}

//�ϲ�Ԫ��x�� y�����ļ���
void Unite(int x, int y)
{
    //���ҵ�x��y�ĸ��ڵ�
    x = find(x);
    y = find(y);
    if(x == y)
        return ;
    //�ж��������ĸ߶ȣ�Ȼ���ھ���˭Ϊ����
    if(rank[x] < rank[y])
    {
        node[x] = y;
    }
    else
    {
        node[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}

//�ж�x��y������ͬһ������
bool same(int x, int y)
{
    return find(x) == find(y);
}