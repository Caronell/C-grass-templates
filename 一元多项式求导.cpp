#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
	int fun[1000][2];
	int a,b,i=0,j=0,sum=0;
	while(cin>>a>>b)
	{
		fun[i][0] = a;
		fun[i][1] = b;
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(fun[j][1] != 0)
		{
			fun[j][0]*=fun[j][1];
			fun[j][1] -= 1;
			sum++;
		}
	}
	if(fun[0][1] == 0)
	{
		cout<<"0 0"<<endl;
		return 0;
	}
	else
	{
		for(j=0;j<sum;j++)
		{
			cout<<fun[j][0]<<" "<<fun[j][1];
			if(j<sum-1)
				cout<<" ";
		}
		return 0;
	}
}
