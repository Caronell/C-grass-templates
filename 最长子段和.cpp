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
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int dp[10005]={0};
        int aa[10005]={0};
        bool f1=false,f2=false;
        int i,j,pos1=0,pos2=0,st=0,en=0,sum,maxn=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&aa[i]);
            if(aa[i] >= 0)
                f2 = true;
        }
        sum = aa[0];
        for(i=1;i<n;i++)
        {
            if(sum+aa[i] < aa[i])
            {
                f1 = true;
                sum = aa[i];
                pos1 = i;
                pos2 = i;
            }
            else
            {
                sum += aa[i];
                pos2 = i;
            }
            if(maxn < sum)
            {
                maxn = sum;
                st = pos1;
                en = pos2;
            }
            else if(maxn==sum && maxn==0)
            {
                st = pos1;
                en = pos2;
            }
        }
        if(f1 == false)
            st = 0;
        if(f2 == false)
        {
            st = 0;
            en = n-1;
            maxn = 0;
        }
        if(f2 == true)
        {
            if(n == 1)
            {
                maxn = aa[0];
                st = 0;
                en = 0;
            }
        }
        printf("%d %d %d\n",maxn,aa[st],aa[en]);
    }
	return 0;
}