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
    string hand[15];
    string eyes[15];
    string mouth[15];
    string moe,t;
    int n,i,j,h=0,e=0,m=0,len,temp;
    bool flag;
    for(i=0;i<3;i++)
    {
        t.clear();
        getline(cin,t);
        len = t.size();
        for(j=0;j<len;j++)
        {
            if(t[j] == '[')
            {
                while(t[j+1]!=']' && j+1<len)
                {
                    if(i == 0)
                        hand[h] += t[j+1];
                    else if(i == 1)
                        eyes[e] += t[j+1];
                    else
                        mouth[m] += t[j+1];
                    j++;
                }
                if(i == 0)
                    h++;
                else if(i == 1)
                    e++;
                else
                    m++;
                j--;
            }
        }
    }
    cin>>n;
    while(n--)
    {
        moe.clear();
        flag = true;
        for(i=0;i<5;i++)
        {
            cin>>temp;
            temp--;
            if(temp < 0)
                flag = false;
            if(i==0 || i==4)
            {
                if(temp >= h)
                    flag = false;
            }
            else if(i==1 || i==3)
            {
                if(temp >= e)
                    flag = false;
            }
            else
                if(temp >= m)
                    flag = false;
            if(flag == true)
            {
                if(i==0 || i==4)
                    moe += hand[temp];
                else if(i==1 || i==3)
                    moe += eyes[temp];
                else
                    moe += mouth[temp];
                if(i == 0)
                    moe += '(';
                else if(i == 3)
                    moe += ')';
            }
        }
        if(flag == true)
            cout<<moe<<endl;
        else
            cout<<"Are you kidding me? @\\/@"<<endl;
    }
	return 0;
}