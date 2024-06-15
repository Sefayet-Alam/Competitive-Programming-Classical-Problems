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

#define int long long
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


struct item {
          int sum  = 0 , a= 0 ;
 
} ;
struct segtree{
 
    vector <int> op;
    vector <int>  operations;
    vector <item > val ;
 
    int sz =1;
    segtree(int n){         //empty
        while(sz<n)sz*=2;
        operations.resize(2*sz);
        op.resize(2*sz);
        val.resize(2*sz) ;
 
    }
 
    int Neutral_elemnt  = 0 ;
    item merge(item m1  ,  item m2 , int len){
         item res  ;
         res.sum =  m1.sum +m2.sum ;
         res.a  =   m1.a + m2.a + m2.sum *len ;
         return res;
    }
 
    int  operation (int a ,  int  b , int x){
       return  a+b;
    }
 
    void apply(int& a ,int b , int x){
          a=operation (a, b ,x);
    }
 
    void update(item & cur  , int  oper , int len){
        cur.sum +=len*oper;
        cur.a  +=  ((len*(len+1))/2)*oper;
    }
 
    void reset (int x , int  lx ,int rx){
         if (rx- lx==1){
              val[x] = {0, 0} ;
             if (op[x])
              update(val[x] , operations[x]  , 1) ;
         }
         else {
            val[x] = merge(val[2*x+1] , val[2*x+2] , (rx-lx)/2 ) ;
            if (op[x])
              update(val[x] , operations[x] , rx-lx ) ;
         }
    }
 
    void propagate(int x  , int lx  ,int rx){
          if (rx-lx==1 || !op[x])
            return  ;
 
          apply(operations[2*x+1], operations[x] , 2*x+1) ;
          apply(operations[2*x+2] ,operations[x] ,2*x+2) ;
          op[2*x+1] =op[2*x+2] =1;
          //clear op of node
          op[x]=0;
          operations[x]  =  0;
          int md  =  (lx+rx)/2;
          reset(2*x+1 , lx, md);
          reset(2*x+2, md, rx); 
          reset(x , lx, rx);   
    }
 
 
    void change  (int  l , int r,int oper , int x, int lx ,  int rx){
        propagate(x , lx, rx);
        if (rx<=l || lx>=r)
            return  ;
        if (lx >=l and rx<=r){
 
                 apply( operations[x] , oper ,x);
                 op[x]  = 1;
 
                 reset(x  , lx , rx) ;
 
                return ;
        }
        int md  = (lx+rx)/2;
        change( l, r, oper, 2*x+1 ,lx, md);
        change (l, r, oper ,  2*x+2 , md, rx);
 
        val[x] = merge(val[2*x+1] , val[2*x+2] , (rx-lx)/2) ;
    }
    void change (int  l ,int r ,int oper){
        change(l,r , oper,0 ,0,sz);
    }
    int calc( int  l,  int r , int x , int lx , int rx ){
 
          propagate(x,lx,rx);
          if (lx>=r  ||rx<=l)
            return  0;
          if (lx>= l  and rx<=r){
             //   cout<<x<<" "<<lx<<" "<<rx<<" "<<val[x].a<<" "<<val[x].sum<<" >> "<<val[x].a  + val[x].sum*(lx-l)<<" \n ";
            return val[x].a  + val[x].sum*(lx-l);
          }
 
          int md  =  (lx+rx)/2;
          int res1 = calc( l , r , 2*x+1 ,lx ,md);
          int res2 = calc( l , r, 2*x+2 , md, rx) ;
          return   res1+ res2;
 
    }
    int calc(int l,  int r){
       return calc(l , r , 0, 0, sz) ;
    }
 
 
};
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
 
    int n, m ;
    cin>>n>>m;
    segtree sg(n+1);
 
 
    for (int i  = 0 ; i < n ; ++i){
        int v;
        cin>>v;
        sg.change(i, i+1 ,v);
    }
 
    for (int  i = 0 ; i  <m; ++i)
    {
         int q;
         cin>>q;
         if (q==1)
         {
              int l  , r ,v ;
              cin>>l>>r>>v;
              l--;
              sg.change( l ,r ,v);
 
         }
         else
         {
             int l , r;
             cin>>l>>r;
             l--;
             cout<<sg.calc( l ,r) <<"\n";
         }
 
    }
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
