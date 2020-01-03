#include        "iostream"
#include        "algorithm"
#include		"numeric"
#include        "cstring"
#include        "math.h"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

#include        <ext/pb_ds/assoc_container.hpp> // Common file
#include        <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include        <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;


#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          N (int)2e5+5
#define          pb push_back
#define          mod 1000000007
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long 
#define          pii pair<int,int>
#define 		 pis pair<int,string>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          db(x) cout<<#x <<" : "<< x <<endl;
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define          PI acos(-1.0)
#define 		 bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > 
OS ;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);   
	    freopen("ou.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q,a,b,SZ;
vi mn, mx;
pis dp[20][2][2][2];

pis maxProduct( int pos = 0, int small = 1, int big  = 1, int strt = 0 )
{
	if( pos == SZ ) 
	{
		// bug(no);
		return dp[pos][small][big][strt] = { 1 , "" };
	}

	pis& ans = dp[pos][small][big][strt];

	if( ~ans.f ) return ans;

	ans = { -1 , "" };

	int lo = 0;
	int hi = 9;

	if( small ) lo = mn[pos];
	if( big  ) hi = mx[pos];

	pis mxx = { -1 , "" };

	fo(d,lo,hi+1)
	{
		int nsmall = ( small & ( d == lo ));
		int nbig = ( big & ( d == hi ));
		int nstrt = strt | ( d > 0);

		int mul;
		if( strt == 0 and d == 0 ) mul = 1;
		else mul = d;

		pis now = maxProduct( pos+1, nsmall , nbig , nstrt );
		now.f *= mul;
		now.sc = char('0'+d) + now.sc;

		mxx = max( mxx, now );
	}

	return ans = mxx;
	
}

pis seperateDigits()
{
	mn.clear();
	mx.clear();

	int x = b;

	while( x > 0 )
	{
		mx.pb( x%10 );
		x /= 10;
	}

	// for( auto i : mx ) cout << i;
	// cout << endl;
	x = a;

	while( x > 0 )
	{
		mn.pb( x%10);
		x /= 10;
	}

	SZ = mx.size();
	while( mn.size() < SZ )
	{
		mn.pb(0);
	}

	reverse( all(mn) );
	reverse( all(mx) );


	return maxProduct();
}

void go()
{
	cin >> a >> b;

	fo(i,0,20) fo(j,0,2) fo(k,0,2) fo(l,0,2) dp[i][j][k][l] = { -1, "" };

	pis ans = seperateDigits();

	cout << stoll(ans.sc) << endl;
	
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}
