#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int min,a,i=0,j=0,k=0;
	int arr[3][4];
	int brr[4];
	while(i<3 or j<4)
	{
		j = 0;
		while(j<4)
		{
			cin>>arr[i][j];
			j++;
		}
		i++;
	}
	min = arr[0][0];
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		{
			if(arr[i][j] < min)
				min = arr[i][j];
		}
		brr[k] = min;
		min = arr[0][j+1];
		k++;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<setw(3)<<arr[i][j];
		}
		cout<<"\n";
	}
	for(k=0;k<4;k++)
	{
		cout<<setw(3)<<brr[k];
	}
	return 0;
}
