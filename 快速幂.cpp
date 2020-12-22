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

typedef long long ll;

ll quick_pow_mod(ll x, ll n, ll p);

int main()
{

	return 0;
}

ll quick_pow_mod(ll x, ll n, ll p)
{
    ll ans = 1;
    x %= p;
    while(n)
    {
        if(n & 1)
            ans = (ans*x)%p;
        x = (x*x)%p;
        n >>= 1;
    }
    return ans;
}