#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int i=0;
	long long k,sum=0;
	char n;
	while((n = getchar()) != '\n')
	{
		sum += (int)(n-48);
	}
	k = sum;
	while(k>0)
	{
		i += 1;
		k /= 10;
	}
	if(i == 0)
		i = 1;
	int arr[i] = {0};
	k = sum;
	i = 0;
	while(k>0)
	{
		arr[i] = k%10;
		i += 1;
		k /= 10;
	}
	i -= 1;
	do{
		switch(arr[i])
		{
			case 0:
				cout<<"ling";
				break;
			case 1:
				cout<<"yi";
				break;
			case 2:
				cout<<"er";
				break;
			case 3:
				cout<<"san";
				break;
			case 4:
				cout<<"si";
				break;
			case 5:
				cout<<"wu";
				break;
			case 6:
				cout<<"liu";
				break;
			case 7:
				cout<<"qi";
				break;
			case 8:
				cout<<"ba";
				break;
			case 9:
				cout<<"jiu";
				break;
		}
		i -= 1;
		if(i >= 0)
			cout<<" ";
	}while(i >= 0);
	return 0;
}
