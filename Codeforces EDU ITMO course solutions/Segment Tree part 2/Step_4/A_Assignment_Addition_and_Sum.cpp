#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long
#define ff first
#define ss second
#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)),(a).end())
#define eb emplace_back
#define mp make_pair


///BIT MANIPULATION

#define Set(x, k) (x |= (1LL << k))
#define Unset(x, k) (x &= ~(1LL << k))
#define Check(x, k) (x & (1LL << k))
#define Toggle(x, k) (x ^ (1LL << k))

//LOOPS

#define scl(n)              scanf("%lld", &n)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)

///PRINTING

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define nn '\n'
#define pfl(x)              printf("%lld\n",x)
#define pcas(i)                printf("Case %lld: ",i)
#define Setpre(n) cout<<fixed<<setprecision(n)
#define itr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define debug               printf("I am here\n")

///SORTING AND FILLING

#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<ll>());
#define rev(x) reverse(all(x))
#define sortall(x) sort(all(x))
#define mem(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))

//CONSTANTS
#define md                  10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e5+10;
const ll M = 1e9+7;


///INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll Ceil(ll p, ll q)  {return p < 0 ? p / q : p / q + !!(p % q);}
inline ll Floor(ll p, ll q) {return p > 0 ? p / q : p / q - !!(p % q);}
inline double logb(ll base,ll num){ return (double)log(num)/(double)log(base);}
inline bool isPerfectSquare(long double x){ if (x >= 0) { long long sr = sqrt(x);return (sr * sr == x); }return false; }
double euclidean_distance(ll x1,ll y1,ll x2,ll y2){double a=(x2-x1)*(x2-x1);double b=(y2-y1)*(y2-y1);double c=(double)sqrt(a+b);return c;}
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};


/// Data structures
typedef unsigned long long ull;
typedef pair<ll, ll>    pll;
typedef vector<ll>      vl;
typedef vector<pll>     vpll;
typedef vector<vl>      vvl;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using QP = priority_queue<T,vector<T>,greater<T>>;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_map = tree<T, R , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
;

 
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
 

/*===================================================================//
            
        ░█▀▀▀█ ░█▀▀▀ ░█▀▀▀ ─█▀▀█ ░█──░█ ░█▀▀▀ ▀▀█▀▀ 
        ─▀▀▀▄▄ ░█▀▀▀ ░█▀▀▀ ░█▄▄█ ░█▄▄▄█ ░█▀▀▀ ─░█── 
        ░█▄▄▄█ ░█▄▄▄ ░█─── ░█─░█ ──░█── ░█▄▄▄ ─░█──
//====================================================================*/

void setIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct item{
    ll value;//current value
    ll lazy;//value to be lazyed 
    ll assign;//value to be assigned
};

struct segment_tree{
    ll size;
    vector<item>tree;
    ll neutral=0;
    ll no_op=LLONG_MIN;
    
    //General operations : O(1)

    ll merge(ll a,ll b){
       if(a==no_op) return b;
        return (a+b);
    }
    ll addnodes(ll a,ll b){
        return a+b;
    }

   
    //INITIALIZATION: O(log2 n)

    void init(ll n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);
        tree.assign(2*size,{0,no_op,no_op});
    }
    
    ///BUILD
    void build(vector<ll> &a,ll x,ll lx,ll rx){
        if(rx-lx==1){
            if(lx<a.size()){
                tree[x]={a[lx],no_op,no_op};
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]={ tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value),no_op,no_op};
    }

    void build(vector<ll> &a){
        //linear time
        build(a,0,0,size);
    }

    ///LAZY PROPAGATION
    
    //throws lazy values to its children nodes 
     //updates values to children nodes
   void propagate(ll x, ll lx, ll rx) {
        if ((tree[x].assign == no_op && tree[x].lazy == no_op) || rx == lx + 1) return;
        ll m = (lx + rx) / 2;

        if (tree[x].assign != no_op) {
            tree[2*x+1].assign=tree[x].assign;
            tree[2*x+1].lazy = no_op;
            tree[2*x+1].value= (m - lx) * tree[x].assign;

            tree[2*x+2].assign = tree[x].assign;
            tree[2*x+2].lazy = no_op;
            tree[2*x+2].value= (rx - m) * tree[x].assign;
        }

        if (tree[x].lazy != no_op) {
            tree[2*x+1].lazy = merge(tree[2*x+1].lazy, tree[x].lazy);
            tree[2*x+1].value+= (m - lx) * tree[x].lazy;

            tree[2*x+2].lazy = merge(tree[2*x+2].lazy, tree[x].lazy);
            tree[2*x+2].value+= (m - lx) * tree[x].lazy;
        }

        tree[x].assign = tree[x].lazy = no_op;
    }

    ///RANGE SUM
    ll sum(ll l,ll r,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx>=l && rx<=r){
            return tree[x].value;
        }
        ll m=(lx+rx)/2;
        ll s1=sum(l,r,2*x+1,lx,m);
        ll s2=sum(l,r,2*x+2,m,rx);
        return  addnodes(s1,s2);
    }

    
    ll sum(ll l,ll r){
        //returns sum from l to r
       
        return sum(l,r,0,0,size);
    }

    //RANGE operation
    
    void RangeUpdate(ll l,ll r,ll v,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return;
        }
        if(lx>=l && rx<=r){
            tree[x].lazy=merge(tree[x].lazy,v);
            tree[x].value+=(rx-lx)*v;
            return;
        }
        ll m=(lx+rx)/2;
        RangeUpdate(l,r,v,2*x+1,lx,m);
        RangeUpdate(l,r,v,2*x+2,m,rx);  
         tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value);
    }
    

    void RangeUpdate(ll l,ll r,ll v){
        //multipliess v from l to r
        RangeUpdate(l,r,v,0,0,size);
    }
    ///RANGE ASSIGN
     void RangeAssign(ll l,ll r,ll v,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return;
        }
        if(lx>=l && rx<=r){
            tree[x].assign=v;
            tree[x].lazy=no_op;
            tree[x].value=(rx-lx)*v;
            
            return;
        }
        ll m=(lx+rx)/2;
        RangeAssign(l,r,v,2*x+1,lx,m);
        RangeAssign(l,r,v,2*x+2,m,rx);  
        tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value);
    }
    
    void RangeAssign(ll l,ll r,ll v){
        //multipliess v from l to r
      RangeAssign(l,r,v,0,0,size);
    }   
};




int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    //cin>>t;

    while(t--){
      ll n,q;
      cin>>n>>q;
    //   cout<<n<<q<<nn;
      vector<ll>vec(n,0);

      segment_tree sg;
      sg.init(n);
    //   sg.build(vec);

      ll op,l,r,x;
      while(q--){
        cin>>op;
       
        if(op==1){
            
            cin>>l>>r>>x;
            
            sg.RangeAssign(l,r,x);
        }
        else if(op==2){
            cin>>l>>r>>x;
              
            sg.RangeUpdate(l,r,x);
        }
        else{
            cin>>l>>r;
            
            cout<<sg.sum(l,r)<<nn;
        }
      }
    }


    return 0;
}

