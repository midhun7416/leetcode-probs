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
	string s, res;
	cin>>s;
	int a[26]={0}, i, j=0, n,p;
	bool v[26] = {false};
	n = s.size();
	char prime='A';
	for(i=0;i<n;++i)
		++a[s[i]-'a'];
	//printf("Initial:  %s\n", s.c_str());
	for(int k=0;k<n/2;++k)
	{
		char ch = s[k];
		s[k] = s[n-1-k];
		s[n-1-k] = ch;
	}
	//printf("Reversed:  %s\n",s.c_str() );
	int need[26] = {0};
	for (i = 0; i < 26; ++i)
	{
		/* code */
		a[i] /= 2;
		v[i] = a[i];
		need[i] = a[i];
		if(a[i] and prime == 'A')
			prime = char(i+'a');
	}
	//printf("%c\n",prime );
	while(j<n)
	{
		i = s[j]-'a';
		if(prime==s[j]) {
			//printf("p: %c ", s[j]);
			res += prime;
			if(need[i]) {
				--a[i];--need[i];
			}
		} else {
			//printf("np: %c ", s[j]);
			if(a[i]) {
				--a[i];
			} else if(need[i]) {
				--need[i];
				res += s[j];
			}
		}
		if(!need[i]) {
			while(!need[i])
				++i;
			prime = i+'a';
		}
		++j; 
	}
	printf("%s\n", res.c_str());
	return 0;
}
