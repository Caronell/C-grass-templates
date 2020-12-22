#include <iostream>
#include <cmath>
using namespace std;

int prime(int n);

int main()
{
    int n,a,b,i=6;
	cin>>n;
	while(i<=n)
	{
		for(a=2;a<=i/2;a++)
		{
			if(prime(a) == 0)
				continue;
			else
			{
				b = i-a;
				if(prime(b) == 1)
				{
					cout<<i<<"="<<a<<"+"<<b<<endl;
					break;
				}
			}
		}
		i += 2;
	}
    return 0;
}

int prime(int n)
{
	int i;
	if(n<2)
		return 0;
	else if(n == 2)
		return 1;
	else if(n == 3)
		return 1;
	else
	{
		for(i=2;i<=sqrt((double)n)+1;i++)
		{
			if(n%i == 0)
				return 0;
		}
		return 1;
	}
}
