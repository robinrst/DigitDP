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
#define          N (int)2e6+5
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
 
int n,m,k,q,a,b;
vi v;
int dp[30][2000][2];
 
int sumDigit(int pos = 0, int dSum = 0, int f = 0 )
{
	if( pos == v.size() )
	{
		// bug(dSum);
		return dp[pos][dSum][f] = dSum;
	}
 
	int& ans = dp[pos][dSum][f];
 
	if( ~ans ) return ans;
	ans = 0;
 
	int mx = v[pos] + 1;
	if( f ) mx = 10;
 
	int cn = 0;
 
	fo(d,0,mx)
	{
		int nf = f;
		int ndSum = dSum + d;
 
		if( d < v[pos] ) nf = 1;
 
		cn += sumDigit( pos+1, ndSum , nf );
	}
	return ans = cn;
}
 
void seperateDigits( int x )
{
	v.clear();
 
	while(x )
	{
		v.pb( x%10 );
		x /= 10;
	}
 
	reverse( all( v ) );
}
 
void go()
{
		cin >> a >> b;

		memset(dp , -1 , sizeof dp );
 
		seperateDigits(b);
		int xx = sumDigit();

		memset(dp , -1 , sizeof dp );
		seperateDigits(a-1);
		int yy = sumDigit();
 
		int ans =  xx - yy ;
 
		cout << ans << endl;
}
 
int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	cin>>t;
	test(t) go();
	time();
}