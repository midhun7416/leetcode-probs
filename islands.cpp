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
using namespace std::chrono;
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
#define MAXL 100010

int main()
{
#ifdef PC
	freopen("input","r",stdin);
#endif
	int T;
	string s;
	//char s[MAXL]
	cin>>s;
	sn(T);
	int n = s.size();
	int res=0;
	unordered_map<string,bool> u;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	printf("%d\n",n);
	for(int i=0;i<n;++i)
	{
		for(int l=1;l<=(n-i);++l)
		{
			bool m[MAXL] = {0};
			/*string t = s.substr(i,l);
			if(u.find(t)!=u.end())
				continue;
			u[t] = true;
			int islands = 0;*/
			/*for(int j=0;j<n-l+1;++j)
			{
				if(s.substr(j,l) == t)
				{
					forall(k,j,j+l)
						m[k] = true;
				}
				if(j==0 and m[j])
					++islands;
				if(j and m[j] and !m[j-1])
					++islands;
				if(islands > T)
					break;
			}
			/*printf("%s ",t.c_str());
			forall(p,0,n)
				printf("%d  ", m[p]);
			//printf("\n" );
			if(islands ==T) {
				++res;
			}*/
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
	cout<<duration<<endl;
	printf("%d\n", res);
	return 0;
}
