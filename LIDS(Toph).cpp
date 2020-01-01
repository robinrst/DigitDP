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

int n,m,k,q,SZ,TAG,a,b;
vi mn , mx;
int dp[11][2][2][11][10];

// pos -> denotes the poition of digit in number
// small -> denotes whther the sequence become smaller than bigger number or not // 0 -> become , 1 -> not become
// big -> denotes whther the sequence become larger than smaller number or not // 0 -> become , 1 -> not become
// zero -> parameter to avoid leading zero , if any digit greater than zero is placed then it is set to 1
// pre -> denotes the previous digit putted in sequence
// len -> denotes length of LIDS upto position pos

int LIDS( int pos = 0, int small = 1 , int big = 1 , int zero = 0 , int pre = -1 , int len = 0 )
{
	if( pos == SZ )
	{
		return dp[pos][small][big][pre+1][len] = ( len == k );
	}

	int& ans = dp[pos][small][big][pre+1][len];

	if( ~ans  ) return ans;

	ans = 0;

	int lo = 0;
	int hi = 9;

	if( small ) lo = mn[pos];
	if( big )  hi  = mx[pos];

	int cn = 0;

	fo(d,lo,hi+1)
	{
		int nsmall = small;
		int nbig = big;
		int nzero = zero;

		if( d > lo ) nsmall = 0;
		if( d < hi ) nbig = 0;
		if( d > 0 ) nzero = 1;

		if( d > pre and nzero ) // include in LIDS
		{
			cn += LIDS( pos+1, nsmall, nbig, nzero, d,  len+1 );
		}
		// not included in LIDS
		cn += LIDS( pos+1, nsmall, nbig, nzero, pre, len );
	}

	return ans = cn;
}

void seperateDigits()
{
	mn.clear();
	mx.clear();

	int x = a;

	while( x )
	{
		mn.pb( x%10);
		x /= 10;
	}
	x = b;

	while( x )
	{
		mx.pb( x%10);
		x /= 10;
	}

	SZ = mx.size();

	while( mn.size() < SZ )
	{
		mn.pb(0);
	}

	reverse( all( mn ) );
	reverse( all( mx) ) ;

}

void go(int tt)
{
	cin >> a >> b;

	seperateDigits();

	rfo(len,SZ,1) // maximum length of LIDS can be only the size of bigger number
	{
		k = len;
		memset( dp , -1 , sizeof dp);

		int ans = LIDS();
		// bug( ans );

		if ( ans > 0 )
		{
			cout << "Case " << tt <<": " << len << ' ' << ans << endl;
			break;
		}
	}
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	cin>>t;
	fo(i,1,t+1) go(i);
	// time();
}
