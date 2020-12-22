#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

//#====================================================
//# Get random strings
//#====================================================
void Initialize(string &a, string &b)
{
    a = "";
    b = "";
    string code="abcd";
    srand((unsigned)time(NULL));
    int la,lb;
    la = rand()%2000 + 50;
    lb = la%10 + 1;
    for(int i=0;i<la;++i)
        a += code[rand()%code.length()];
    for(int i=0;i<lb;++i)
        b += code[rand()%code.length()];
}

//#====================================================
//# Solution 1: BF
//#====================================================
int index_BF(string m, string x)
{
    int i=0,j=0;
    int mlen=m.length(),xlen=x.length();
    while(i<mlen && j<xlen)
    {
        if(m[i] == x[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i-j+1;
            j = 0;
        }
    }
    if(j == xlen)
        return i-j;
    else
        return -1;
}

//#====================================================
//# Solution 2: KMP
//#====================================================
//# Get next-array
//#-------------------------------------------------
int* getNext(string x)
{
    int j=0,k=-1;
    int xlen=x.length();
    int *next = new int[x.size()];
    next[0] = -1;
    while(j < xlen-1)
    {
        if(k==-1 || x[j]==x[k])
        {
            if (x[++j] == x[++k])
                next[j] = next[k];
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
    return next;
}

//#-------------------------------------------------
//# KMP-Core
//#-------------------------------------------------
int index_KMP(string m, string x)
{
    int i=0,j=0;
    int mlen = m.length();
    int xlen = x.length();
    int *next = getNext(x);
    while(i<mlen && j<xlen)
    {
        if(j==-1 || m[i]==x[j])
        {
            j++;
            i++;
        }
        else
            j = next[j];
    }
    if(j == xlen)
        return i-j;
    else
        return -1;
}

//#====================================================
//# Analysis
//#====================================================
void Analysis(string a, string b)
{
    int time1=0,time2=0,time3=0,time4=0;
    const char *ta,*tb,*p;
    int t1,t2,t3,t4;
    clock_t start,finish;
    for(int i=0;i<100000;++i)
    {
        Initialize(a,b);
        start = clock();
        t1 = index_BF(a,b);
        finish =clock();
        time1 += finish-start;
        start = clock();
        t2 = index_KMP(a,b);
        finish = clock();
        time2 += finish-start;
        start = clock();
        t3 = a.find(b);
        finish = clock();
        time3 += finish-start;
        start = clock();
        ta = a.c_str();
        tb = b.c_str();
        p = strstr(ta,tb);
        finish = clock();
        time4 += finish-start;
    }
    cout<<"The last one example:"<<endl;
    cout<<"Main string:"<<endl;
    cout<<a<<endl;
    cout<<"Sub string:"<<endl;
    cout<<b<<endl;
    cout<<"Index of BF:"<<endl;
    cout<<t1<<endl;
    cout<<"Index of KMP:"<<endl;
    cout<<t2<<endl;
    cout<<"Index of STL-string::find()"<<endl;
    cout<<t3<<endl;
    cout<<"Index of strstr():"<<endl;
    cout<<(p==NULL ? -1 : (int)(p-ta))<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"Time costs:"<<endl;
    cout<<"Brute-Force:"<<endl;
    cout<<time1<<" ms"<<endl;
    cout<<endl;
    cout<<"KMP:"<<endl;
    cout<<time2<<" ms"<<endl;
    cout<<endl;
    cout<<"STL-string::find():"<<endl;
    cout<<time3<<" ms"<<endl;
    cout<<endl;
    cout<<"strstr():"<<endl;
    cout<<time4<<" ms"<<endl;
}

//#====================================================
//# Main
//#====================================================
int main()
{
    string a,b;
    Analysis(a,b);
    cin.get();
	return 0;
}