#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	int n;
	float a,b,sum;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		sum = a*0.3 + b*0.7;
		if(sum >= 60)
			cout<<(int)sum<<endl;
		else if(sum<60 && ((60 - b*0.7)/0.3) <= 100)
			cout<<"60"<<endl<<"You are so lucky!"<<endl;
		else
			cout<<"Sorry,you have not passed the exam"<<endl;
	}
	return 0;
}
