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

string Reserve(string str);
string Summon(string a, string b);
bool Palin(string c);

int main()
{
    int t=0;
    bool flag=false;
    string num,rnum,sum;
    cin>>num;
    if(Palin(num) == true)
    {
        sum = num;
        flag = true;
        t = 11;
    }
    while(t<10)
    {
        rnum = Reserve(num);
        sum = Summon(num,rnum);
        cout<<num<<" + "<<rnum<<" = "<<sum<<endl;
        if(Palin(sum) == true)
        {
            flag = true;
            break;
        }
        num = sum;
        t++;
    }
    if(flag == true)
        cout<<sum<<" is a palindromic number."<<endl;
    else
        cout<<"Not found in 10 iterations."<<endl;
	return 0;
}

string Reserve(string str)
{
    string temp;
    temp.clear();
    int i,len;
    len = str.size();
    for(i=0;i<len;i++)
        temp += str[len-1-i];
    return temp;
}

string Summon(string a, string b)
{
    int i,j,flag,temp,lena,lenb;
    lena = a.size();
    lenb = b.size();
    if(lenb < lena)
    {
        swap(a,b);
        swap(lena,lenb);
    }
    flag = 0;
    j = lena-1;
    for(i=lenb-1;i>=0;i--)
    {
        temp = b[i]-'0';
        temp +=  flag;
        if(j >= 0)
        {
            temp += a[j]-'0';
        }
        if(temp >= 10)
        {
            flag = 1;
            temp %= 10;
        }
        else
            flag = 0;
        b[i] = (char)(temp+'0');
        j--;
    }
    if(flag == 1)
        b = "1" + b;
    return b;
}

bool Palin(string c)
{
    int i,len;
    len = c.size();
    for(i=0;i<len/2;i++)
    {
        if(c[i] != c[len-1-i])
            return false;
    }
    return true;
}