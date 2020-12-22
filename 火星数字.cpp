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
using namespace std;

int main()
{
    string low[12]={"jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    string high[12]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    int n,i,t;
    cin>>n;
    getchar();
    while(n--)
    {
        t = 0;
        string temp;
        cin.clear();
        temp.clear();
        getline(cin,temp);
        if(isalpha(temp[0]))
        {
            int len;
            len = temp.size();
            if(len > 4)
            {
                string fro,bac;
                fro += temp[0];
                fro += temp[1];
                fro += temp[2];
                bac += temp[4];
                bac += temp[5];
                bac += temp[6];
                for(i=0;i<12;i++)
                {
                    if(high[i] == fro)
                    {
                        t += (i+1)*13;
                        break;
                    }
                }
                for(i=0;i<12;i++)
                {
                    if(low[i] == bac)
                    {
                        t += i+1;
                        break;
                    }
                }
            }
            else if(len == 4)
            {
                t = 0;
            }
            else
            {
                for(i=0;i<12;i++)
                {
                    if(low[i] == temp)
                    {
                        t = i+1;
                        break;
                    }
                    else if(high[i] == temp)
                    {
                        t = (i+1)*13;
                    }
                }
            }
            cout<<t<<endl;
        }
        else
        {
            stringstream ss;
            string outp;
            int h,l,num=0;
            ss<<temp;
            ss>>num;
            ss.clear();
            if(num == 0)
                outp = "tret";
            else
            {
                h = num / 13;
                l = num % 13;
                if(h >= 1)
                {
                    outp += high[h-1];
                    if(l > 0)
                    {
                        outp += " ";
                        outp += low[l-1];
                    }
                }
                else
                {
                    outp += low[l-1];
                }
            }
            cout<<outp<<endl;
        }
    }
	return 0;
}