#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#define ll long long
#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()

//Printings & debugging
#define nn '\n'
#define Setpre(n) cout << fixed << setprecision(n)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debug printf("I am here\n")

// CONSTANTS
#define md 10000007
#define PI acos(-1)
const double EPS = 1e-9;
const ll N = 2e5 + 10;
const ll M = 1e9 + 7;

/// INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline double logb(ll base, ll num) { return (double)log(num) / (double)log(base); }


/// Data structures
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using QP = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> 
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_multimap = tree<T, R, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
namespace io{
    template<typename First, typename Second> ostream& operator << ( ostream &os, const pair<First, Second> &p ) { return os << p.first << " " << p.second; }
    template<typename First, typename Second> ostream& operator << ( ostream &os, const map<First, Second> &mp ) { for( auto it : mp ) { os << it << endl;  } return os; }
    template<typename First> ostream& operator << ( ostream &os, const vector<First> &v ) { bool space = false; for( First x : v ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const set<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const multiset<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First, typename Second> istream& operator >> ( istream &is, pair<First, Second> &p ) { return is >> p.first >> p.second; }
    template<typename First> istream& operator >> ( istream &is, vector<First> &v ) { for( First &x : v ) { is >> x; } return is; }
    
    long long fastread(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x; }
    static bool sep = false;
    using std::to_string;
    string to_string( bool x ){ return ( x ? "true" : "false" ); }
    string to_string( const string & s ){ return "\"" + s + "\""; }
    string to_string( const char * s ){ return "\"" + string( s ) + "\""; }
    string to_string ( const char & c ) { string s; s += c; return "\'" + s + "\'"; }
    template<typename Type> string to_string( vector<Type> );
    template<typename First, typename Second> string to_string( pair<First, Second> );
    template<typename Collection> string to_string( Collection );
    template<typename First, typename Second> string to_string( pair<First, Second> p ){ return "{" + to_string( p.first ) + ", " + to_string( p.second ) + "}"; }
    template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }
    template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }
    void print() { cerr << endl; sep = false; }
    template <typename First, typename... Other> void print( First first, Other... other ) { if( sep ) cerr << " | "; sep = true; cerr << to_string( first ); print( other... ); }
} using namespace io;

struct line {
    ll m, c; // y = mx+c
    line(ll _m, ll _c) {
        m = _m, c = _c;
    }
};

struct CHT {
    vector < line > vec;
    ll t, ptr;
    void init(ll x) {
        t = x, ptr = 0;
        vec.clear();
    }
    inline ll func(ll idx, ll x) {
        return vec[idx].m * x + vec[idx].c;
    }
    bool bad(line f1, line f2, line f3) {
        __int128 a = (f3.c - f1.c);
        a = a * (f1.m - f2.m);
        __int128 b = (f2.c - f1.c);
        b = b * (f1.m - f3.m);

        if(t == 1) return a <= b; // m_i > m_i+1. min query.
        if(t == 2) return a >= b; // m_i > m_i+1. max query.
        if(t == 3) return a >= b; // m_i < m_i+1. min query.
        if(t == 4) return a <= b; // m_i < m_i+1. max query.
        assert(0);
    }
    void add(line x) {
        ll sz = vec.size();
        while(sz >= 2 && bad(vec[sz - 2], vec[sz - 1], x)) {
            vec.pop_back();
            sz--;
        }
        vec.push_back(x);
    }
    ll ask(ll x) // ternary search
    {
        if(vec.empty())
        return 0;
        ll lo = 0, hi = vec.size() - 1;
        ll ret = (t & 1)? LLONG_MAX : LLONG_MIN;
        while(lo <= hi) {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);

            ll ans1 = func(mid1,x);
            ll ans2 = func(mid2,x);

            if(ans1 > ans2) {
                if(t & 1)
                    ret = min(ret, ans2), lo = mid1 + 1;
                else
                    ret = max(ret, ans1), hi = mid2 - 1;
            }
            else {
                if(t & 1)
                    ret =  min(ret,ans1), hi = mid2 - 1;
                else
                    ret = max(ret,ans2), lo = mid1 + 1;
            }
        }
        return ret;
    }
    ll ask1(ll x) // pointer search (linear)
    {
        if(vec.empty())
            return 0;
        if(ptr >= vec.size()) ptr = vec.size() - 1;

        while(ptr < (vec.size() - 1)) {
            if(t & 1) {
                if(func(ptr,x) > func(ptr + 1,x))
                    ptr++;
                else break;
            }
            else {
                if(func(ptr,x) < func(ptr + 1,x))
                    ptr++;
                else break;
            }
        }
        return func(ptr,x);
    }
};

int main()
{
    fast;
    ll t;
    ll n,c;
    cin>>n>>c;
    vector<ll>h(n);
    cin>>h;
    CHT ch;
    ch.init(1);
    vector<ll>dp(n+1,M);
    dp[0]=0;
    line now(-2*h[0],h[0]*h[0]+dp[0]);
    ch.add(now);
    for(ll i=1;i<n;i++){
        dp[i]=h[i]*h[i]+c+min(dp[i],ch.ask(h[i]));
        line now(-2*h[i],h[i]*h[i]+dp[i]);
        ch.add(now);
    }
    // deb(dp);
    cout<<dp[n-1]<<nn;
    return 0;
}

/* Points tO CONSIDER
    # RTE? -> check array bounds and constraints
    #TLE? -> thinks about binary search/ dp / optimization techniques
    # WA? 
    -> overflow,reset global variables
    -> Check corner cases
    -> think from different approaches
    -> bruteforce to find pattern
    -> use Setpre for precision problems
*/
