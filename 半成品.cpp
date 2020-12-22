#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#define MAXN 55
using namespace std;

void creator(int a[]);
void output(int a[],int n);
void arrcopy(int a[], int b[], int n);
int halfsearch(int a[], int tar, int l, int r);
void insertsort(int a[], int n);
void shellsort(int a[], int n);

int main()
{
	int arr[MAXN]={0};
	int brr[MAXN]={0};
	srand((unsigned)time(NULL));
	creator(arr);
	output(arr,50);
	cout<<endl;
	arrcopy(arr,brr,50);
	shellsort(arr,50);
	output(arr,50);
	
/*
	int temp;
	temp = halfsearch(arr,777,1,51);
	cout<<temp<<endl;
*/
	return 0;
}

void creator(int a[])
{
	int i,temp;
	for(i=1;i<=MAXN;++i)
	{
		a[i] = rand()%1000;
	}
}

void output(int a[], int n)
{
	int len,i,j=0;
	for(i=1;i<=n;++i)
	{
		cout<<setw(6)<<a[i];
		j++;
		if(j == 10)
		{
			cout<<endl;
			j = 0;
		}
	}
}

void arrcopy(int a[], int b[], int n)
{
	int i;
	for(i=1;i<=n;++i)
		b[i] = a[i];
}

int halfsearch(int a[], int tar, int l, int r)
{
	int mid;
	while(l<r)
	{
		mid = (l+r)/2;
		if(a[mid] == tar)
			return mid;
		else if(a[mid] > tar)
			r = mid-1;
		else
			l = mid+1;
	}
	return -1;
}

void insertsort(int a[], int n)
{
	int i,j=1;
	for(i=2;i<=n;++i)
	{
		if(a[i] >= a[i-1])
			continue;
		else
		{
			a[0] = a[i];
			for(j=i-1;a[0]<a[j];j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = a[0];
		}
	}
}

void shellsort(int a[], int n)
{
	int d;
	for(d=n/2;d>=1;d/=2)
	{
		int i,j=1;
		for(i=d+1;i<=n;i++)
		{
			if(a[i] >= a[i-d])
				continue;
			else
			{
				a[0] = a[i];
				for(j=i-d;a[0]<a[j] && j>=1;j-=d)
				{
					a[j+d] = a[j];
				}
				a[j+d] = a[0];
			}
		}	
	}
}
