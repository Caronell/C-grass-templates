#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#define MAXN 50005
#define INF 0x3f
using namespace std;

int n;
int prime[MAXN];
bool vis[MAXN];

void linear_prime();

int main()
{
    scanf("%d",&n);
    linear_prime();
	return 0;
}

void linear_prime()
{
    memset(vis,true,sizeof(vis));
    int num = 0;
    for(int i=2;i<=n;i++)
    {
        if(vis[i] == true)
        {
            num++;
            prime[num] = i;
        }
        for(int j=1;j<=num;j++)
        {
            if(prime[j]*i > n)
                break;
            vis[prime[j]*i] = false;
            if(i%prime[j] == 0)
                break;
        }
    }
}