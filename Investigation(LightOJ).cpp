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

int n,m,k,q,a,b;
string s;
vi v;
int dp[12][95][100][2];

// pos -> denotes the position of digit in number
// dSum -> denotes the sum of digits of formed number
// no -> stores the formed number throught the process with modulo k
// f -> denotes whether the sequence has become smaller than number of not , if we have placed a digit
//      smaller than digit in actual number then it set to be 1 otherwisr 0

int getNumbers( int i = 0, int dSum = 0, int no = 0 , int f = 0 )
{
	if( i == v.size() )
	{	
		// bug(dSum , no );
		if( dSum == 0 and no == 0 ) return dp[i][dSum][no][f] = 0;
		return dp[i][dSum][no][f] = ( (dSum%k == 0) and (no%k == 0 ) );
	}

	int& ans = dp[i][dSum][no][f];

	if( ~ans ) return ans;
	ans = 0;

	int d = v[i] + 1;
	if( f ) d = 10;

	int cn = 0;

	fo(j,0,d)
	{
		int nf = f;
		int nno = ( no*10 + j )%k;

		if( j < v[i] ) nf = 1;

		cn += getNumbers( i+1, dSum + j , nno%k ,nf);
	}

	return ans = cn;
}

int seperateDigits( int x )
{
	v.clear();
	memset(dp,-1,sizeof dp);

	while(x)
	{
		v.pb( x%10);
		x /= 10;
	}
	reverse( all(v) );

	return getNumbers();
}

void go(int tt)
{
	cin >> a >> b >> k;

	if( k > 90 )
	{
		cout << "Case " << tt <<": " << 0 << endl;
		return;
	}

	int xx =  seperateDigits(b);
	int yy = seperateDigits(a - 1);

	int ans = xx - yy;
	cout << "Case " << tt <<": " << ans << endl;
}

int32_t main()
{
	// INP(); 
	FAST;     
	int t=1; 
	cin>>t;
	fo(i,1,t+1) go(i);
}