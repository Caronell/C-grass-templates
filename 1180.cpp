#include <iostream>
#include <string.h> 
using namespace std;

int main()
{
	string str;
	string target;
	char n,c;
	int i;
	while((n=getchar()) != '\n')
	{
		str += n;
	}
	while((c=getchar()) != '\n')
	{
		target += c;
	}
	i = str.find(target);
	cout<<i<<endl;
	return 0;
}
