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
ll n,m,q,cnt;
ll par[N];
ll sz[N];
multiset<int> sizes;
stack<pair<ll,ll>>history;
vector<pair<ll,ll>>edges(N);

void make(ll v){
    par[v]=v;
    sz[v]=1;
    // sizes.insert(1);
}

int find(ll v){
    if(par[v]==v) return v;
    return find(par[v]);
}

void merge(ll a,ll b){
    sizes.erase(sizes.find(sz[a]));
    sizes.erase(sizes.find(sz[b]));
    sizes.insert(sz[a]+sz[b]);
}

void Union(ll a,ll b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);

        history.push({a,par[a]});
        history.push({b,par[b]});
       
        // merge(a,b);
        sz[a]+=sz[b];
        par[b]=a;
        cnt-=2;
    }
}

void Persist() {
    history.push({-1, -1});
}
ll getCNT(){
    return cnt/2;
}
void Rollback() {
    while (!history.empty()) {
        auto it=history.top();
        history.pop();
        if(it.first==-1 && it.second==-1){
         break;
        }
        par[it.first]=it.second;
        ++cnt;
    }
}

void init(ll n){
    cnt=2*n;
    for(ll i=0;i<=n;i++){
        make(i);
    }
}   


//set N=30005 if TLE


struct query{
    ll l, r, ind;
    ll k;
}qs[200005];

ll ans[200005];
ll bucket;


int main()
{
    fast;
    cin>>n>>m;
    init(n);
    edges.resize(m);
    bucket=max(int(sqrt(m)),1);
    ll i;
    fr(i,m){
        cin>>edges[i].first>>edges[i].second;
    }
    cin>>q;
    fr(i,q){
        cin>>qs[i].l>>qs[i].r, qs[i].ind=i; 
        qs[i].l--;
        qs[i].r--;
    }
    sort(qs,qs+q,[](query a, query b){
        if(a.l/bucket!=b.l/bucket) return a.l<b.l;
        return a.r<b.r;
    });
    // int l=0, r=0;
    ll l=-1,r=-1;
    ll lob,hib;
    for(ll i=0;i<q;i++){
     lob=qs[i].l/bucket,hib=qs[i].r/bucket;
      if(lob!=l){
        init(n);
        r=(lob+1)*bucket-1;
      }
       l=lob;
       if(lob==hib){
        Persist();
        for(ll j=qs[i].l;j<=qs[i].r;j++){
            Union(edges[j].first,edges[j].second);
        }
        ans[qs[i].ind]=getCNT();
        Rollback();
       }
       else{
        while(r<qs[i].r){
            r++;
            Union(edges[r].first, edges[r].second);
        }
        Persist();
        for (ll j=qs[i].l;j<(lob+1)*bucket;j++) {
            Union(edges[j].first,edges[j].second);
        }
        ans[qs[i].ind]=getCNT();
        Rollback();
       }
    }
    for(ll i=0;i<q;i++){
        cout<<ans[i]<<nn;
    }
    return 0;
}
