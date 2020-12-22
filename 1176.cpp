#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n,i=1;
	double c,a=2,b=1,sum=0;
	cin>>n;
	while(i<=n)
	{
		sum += a/b;
		c = a;
		a = a+b;
		b = c;
		i++;
	}
	cout<<fixed<<setprecision(8)<<sum<<endl;
	return 0;
}
