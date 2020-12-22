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

int node[i]; //每个节点
int rank[i]; //树的高度

void Init(int n);
int find(int x);
void Unite(int x, int y);
bool same(int x, int y);

int main()
{

	return 0;
}

//初始化n个节点
void Init(int n)
{
    for(int i = 0; i < n; i++)
    {
        node[i] = i;
        rank[i] = 0;
    }
}

//查找当前元素所在树的根节点(代表元素)
int find(int x)
{
    if(x == node[x])
        return x;
    return node[x] = find(node[x]); //在第一次查找时，将节点直连到根节点
}

//合并元素x， y所处的集合
void Unite(int x, int y)
{
    //查找到x，y的根节点
    x = find(x);
    y = find(y);
    if(x == y)
        return ;
    //判断两棵树的高度，然后在决定谁为子树
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

//判断x，y是属于同一个集合
bool same(int x, int y)
{
    return find(x) == find(y);
}