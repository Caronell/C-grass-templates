#include <iostream>
using namespace std;

int main()
{
    int s = 1, h;
    int i, j;
    cin>>h;
    cout<<"1"<<endl;
    for (i = 2; i <= h; s = 1, i++)
    {
        cout<<"1 ";
        for (j = 1; j <= i - 2; j++)
        {
        	s = (i - j) * s / j;
        	cout<<s<<" ";
		}
        cout<<"1"<<endl;
    }
    return 0;
}
