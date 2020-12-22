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

int dp[1005][1005];

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int i,j,len1,len2;
        memset(dp,0,sizeof dp);
        len1 = s1.size();
        len2 = s2.size();
        s1 = "."+s1;
        s2 = "."+s2;
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
	return 0;
}