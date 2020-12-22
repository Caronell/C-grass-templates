#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#define MAXN 50005
#define INF 0x3f
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{

	return 0;
}

int gcd(int a, int b)
{
    return (b ? gcd(b,a%b) : a);
}

int lcm(int a, int b)
{
    return (a*b / gcd(a,b));
}