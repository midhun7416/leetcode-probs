#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <numeric>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <stack>
#include <unordered_map>
using namespace std;
// Input macros
#define s(n)                    	scanf("%d",&n)
#define sn(n)                    	scanf("%d\n",&n)
#define sc(n)                   	scanf("%c",&n)
#define sl(n)                   	scanf("%lld",&n)
#define sf(n)                   	scanf("%lf",&n)
#define ss(n)                   	scanf("%s",n)

// Useful constants
#define INF                     	(int)1e9
#define EPS                     	1e-9

// Useful hardware instructions
#define bitcount                	__builtin_popcount
#define gcd                     	__gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)           	for(int i=a;i<b;i++)
#define foreach(v, c)           	for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                  	a.begin(), a.end()
#define in(a,b)                 	( (b).find(a) != (b).end())
#define pb                      	push_back
#define fill(a,v)                	memset(a, v, sizeof a)
#define sz(a)                   	((int)(a.size()))
#define mp                      	make_pair

// Some common useful functions
#define maX(a,b)                 	( (a) > (b) ? (a) : (b))


#define mp make_pair // useful for working with pairs
#define fi first
#define se second
#define X real() // useful for working with #include <complex> for computational geometry
#define Y imag()

// iteration macros: have advantage of auto-casting and not recomputing arguments
#define rep(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i,n) for(int i=(n); --i>=0; )
#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define PC 1

int main()
{
#ifdef PC
	freopen("input","r",stdin);
#endif
	int T;
	sn(T);
	int N,C,Q,L,R;
	while(T--)
	{
		s(N);s(C);sn(Q);
		while(Q--)
		{
			s(L);sn(R);
			if(L<=C and C<=R) 
				C = R+L-C;
		}
		printf("%d\n",C);
	}
	return 0;
}
