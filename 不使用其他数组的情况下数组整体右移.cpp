#include <iostream>
using namespace std;

int main()
{
	int k,n,m,i=0;
	cin>>n>>m;
	if(m>=n)
		m = m%n;
	int arr[n+m]; 
	k = n;
	while(n--)
	{
		cin>>arr[i];
		i++;
	}
	i = k-1;
	while(i>=0)
	{
		arr[i+m] = arr[i];
		i--;
	}
	i = 0;
	while(i<m)
	{
		arr[i] = arr[i+k];
		i++;
	}
	i = 0;
	while(i<k)
	{
		cout<<arr[i];
		i++;
		if(i<k)
			cout<<" ";
	}
	return 0;
}
