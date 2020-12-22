#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long sum=0;
	long long a[10];
	char n;
	int i=0,j=0;
	while((n = getchar()) != ' ')
	{
		a[i] = (int)(n-48);
		i++;
		j++;
	}
	while((n = getchar()) != '\n')
	{
		for(i=0;i<j;i++)
		{
			sum += (a[i] * ((int)(n-48)));
		}
	}
	cout<<sum<<endl;
	return 0;
}
