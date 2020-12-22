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

int main()
{
    int i,temp,len,tlen,pos_point,pos_E;
    int sign1,sign2;
    string str,ans,tt,tem;
    stringstream ss;
    cin>>str;
    len = str.size();
    pos_point = str.find('.',0);
    ans.clear();
    tt.clear();
    if(str[0] == '-')
    {
        sign1 = -1;
        ans += "-";
    }
    else
        sign1 = 1;
    pos_E = str.find('E',0);
    tlen = pos_E - pos_point;
    if(str[pos_E+1] == '-')
        sign2 = -1;
    else
        sign2 = 1;
    for(i=pos_E+2;i<len;i++)
        tt += str[i];
    ss<<tt;
    ss>>temp;
    if(sign2 == -1)
    {
        ans += "0.";
        for(i=1;i<temp;i++)
            ans += "0";
        ans += str[1];
        for(i=pos_point+1;i<pos_E;i++)
            ans += str[i];
    }
    else
    {
        if(temp >= tlen)
        {
            ans += str[1];
            for(i=pos_point+1;i<pos_E;i++)
                ans += str[i];
            for(i=0;i<=temp-tlen;i++)
                ans += "0";
        }
        else
        {
            ans += str[1];
            for(i=3;i<3+temp;i++)
                ans += str[i];
            if(i < pos_E)
                ans += ".";
            for(i;i<pos_E;i++)
                ans += str[i];
        }
    }
    cout<<ans<<endl;
	return 0;
}