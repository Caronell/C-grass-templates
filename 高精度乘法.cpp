#include <iostream>
#include <cstring>
using namespace std;

void bignum(char a[], char b[], char res[]);

int main()
{
	const int N=1001;
	char a[N],b[N],c[2*N]={0};
	cin>>a>>b;
	bignum(a,b,c);
	cout<<c;
	return 0;
}

void bignum(char a[], char b[], char res[])
{
	int a_len,b_len,len,i,j;
	a_len = strlen(a);
	b_len = strlen(b);
	len = a_len+b_len;
	int c[len]={0};
	for(i=0;i<b_len;i++)
	{
		for(j=0;j<a_len;j++)
		{
			c[i+j] += (b[b_len-i-1]-'0')*(a[a_len-j-1]-'0');
		}
	}
	int inc=0; 								//进位 
	for(i=0;i<len;i++)
	{
		c[i] += inc;
		inc = c[i]/10;
		c[i] %= 10;
		res[len-i-1] = (char)(c[i]+'0');
	}
	if(inc != 0) 							//首项进位 
		res[0] = (char)(inc+'0');
	int idx=0; 								//去除多余前导0 
	while(res[idx] == '0')
	{
		idx++;
	}
	strcpy(res,res+idx);
}
