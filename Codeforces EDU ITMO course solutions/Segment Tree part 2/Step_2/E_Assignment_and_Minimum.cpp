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

struct item{
    ll value,lazy;
};

struct segment_tree{
    ll size;
    vector<item>tree;
    ll neutral=LLONG_MAX;
    ll no_op=LLONG_MIN;


    //General operations : O(1)

    ll merge(ll a,ll b){
        return min(a,b);
    }

    ll calc(ll a,ll b,ll len){
        return a+b*len;
    }

    ll modify(ll b,ll len){
        return b;
    }

    //INITIALIZATION: O(log2 n)

    void init(ll n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);
    }
    
    ///BUILD
    void build(vector<ll> &a,ll x,ll lx,ll rx){
        if(rx-lx==1){
            if(lx<a.size()){
                tree[x]={a[lx],no_op};
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]={merge(tree[2*x+1].value,tree[2*x+2].value),no_op};
    }

    void build(vector<ll> &a){
        //linear time
        build(a,0,0,size);
    }

    ///LAZY PROPAGATION
    
    //throws lazy values to its children nodes 
    //updates values to children nodes

    item propagate_op(item par,item child,ll len){
        item ret;
        ret.lazy=modify(par.lazy,1);
        ret.value=modify(par.lazy,len);
        return ret;
    }

    void propagate(ll x,ll lx,ll rx){
        if(rx-lx==1 || tree[x].lazy==no_op){
            return;
        }
        ll m=(rx+lx)/2;
        tree[2*x+1]=propagate_op(tree[x],tree[2*x+1],m-lx);
        tree[2*x+2]=propagate_op(tree[x],tree[2*x+2],rx-m);
        tree[x].lazy=no_op;
    }
    //SET AND GET
    
    void set(ll i,ll val,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(rx-lx==1){
            //leaf
            tree[x].value=val;
            tree[x].lazy=no_op;
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }
        else{
            set(i,val,2*x+2,m,rx);
        }
        tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value);
    }

    void set(ll i,ll val){
        // assigns val at index i
        set(i,val,0,0,size);
    }

     ll get(ll i,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(rx-lx==1) return tree[x].value;
        ll m=(lx+rx)/2;
        ll ret;
        if(i<m){
            ret=get(i,2*x+1,lx,m);
        }
        else{
            ret=get(i,2*x+2,m,rx);
        }
        tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value);
        return merge(ret,tree[x].value);
    }
    ll get(ll i){
        //gets the value of the ith position
       
        return get(i,0,0,size);
    }

    ///RANGE SUM
    ll MinOp(ll l,ll r,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return neutral;
        }
        if(lx>=l && rx<=r){
            return tree[x].value;
        }
        ll m=(lx+rx)/2;
        ll s1=MinOp(l,r,2*x+1,lx,m);
        ll s2=MinOp(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    
    ll MinOp(ll l,ll r){
        //returns MinOp from l to r
       
        return MinOp(l,r,0,0,size);
    }

    //RANGE operation
    
    void RangeUpdate(ll l,ll r,ll v,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return;
        }
        if(lx>=l && rx<=r){
            tree[x].lazy=(tree[x].lazy+v);
            tree[x].value=calc(tree[x].value,v,rx-lx);
            return;
        }
        ll m=(lx+rx)/2;
        RangeUpdate(l,r,v,2*x+1,lx,m);
        RangeUpdate(l,r,v,2*x+2,m,rx);  
        tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value);
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
            tree[x].lazy=modify(v,1);
            tree[x].value=modify(v,rx-lx);
            return;
        }
        ll m=(lx+rx)/2;
        RangeAssign(l,r,v,2*x+1,lx,m);
        RangeAssign(l,r,v,2*x+2,m,rx);  
        tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value);
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

      vector<ll>vec(n,0);
      
      segment_tree sg;
      sg.init(n);
      sg.build(vec);

      ll op,l,r,x;
      while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>x;
            sg.RangeAssign(l,r,x);
        }
        else{
            cin>>l>>r;
            cout<<sg.MinOp(l,r)<<nn;
            
        }
      }

    }


    return 0;
}

