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
    int n,i,j,k,fro,temp,wait,space,left;
    char ch;
    cin>>n>>ch;
    temp = sqrt((n+1)/2);
    left = n-2*pow(temp,2)+1;
    wait = 2*temp-1;
    space = 0;
    for(i=0;i<temp;i++)
    {
        fro = space/2;
        for(j=0;j<fro;j++)
            cout<<" ";
        for(j=0;j<wait;j++)
            cout<<ch;
        cout<<endl;
        space += 2;
        wait -= 2;
    }
    space -= 4;
    wait += 4;
    for(i=1;i<temp;i++)
    {

        fro = space/2;
        for(j=0;j<fro;j++)
            cout<<" ";
        for(j=0;j<wait;j++)
            cout<<ch;
        cout<<endl;
        space -= 2;
        wait += 2;
    }
    cout<<left;
	return 0;
}