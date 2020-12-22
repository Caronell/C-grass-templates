#include <iostream>
using namespace std;

int HalfSearch(int a[], int n, int x);

int main()
{
	int a[10] = {1,5,13,14,20,26,34,48,52,60};
	int n,i;
	cin>>n;
	i = HalfSearch(a, 10, n);
	cout<<i<<endl;
	return 0;
}

int HalfSearch(int a[], int n, int x)
{
	int mid,first=0,last=n-1,pos=-1;
	while(first < last)
	{
		mid = (first+last)/2;
		if(a[mid] == x)
		{
			pos = mid;
			break;
		}
		else if(a[mid] > x)
			last = mid-1;
		else
			first = mid+1;
	}
	return pos;
}
