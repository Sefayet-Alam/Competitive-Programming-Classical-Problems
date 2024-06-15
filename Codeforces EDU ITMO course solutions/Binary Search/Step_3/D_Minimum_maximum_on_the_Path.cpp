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



vector<int> findMinPath(const vector<vector<pair<int, int>>> &graph, int edgeLimit, int minWeight, int maxWeight) {
    auto n = graph.size() - 1;
    std::function<bool(int, vector<int> &, set<int> &, map<int, int> &)> dfs;
    dfs = [&graph, n, edgeLimit, &dfs](int weightLimit, vector<int> &trace, set<int> &seen, map<int, int> &bestHistory) -> bool {
        auto currentNode = trace[trace.size() - 1];
        // use bestHistory to prune search space:
        // if currentNode has been visited and in that visit, that trace is better (i.e. smaller) than this trace
        // then obviously, this search is unnecessary, just drop it
        if (bestHistory.find(currentNode) != bestHistory.end() && bestHistory[currentNode] <= trace.size()) {
            return false;
        }
        bestHistory[currentNode] = trace.size();
        if (currentNode == n) {
            return true;
        }
        if (trace.size() >= edgeLimit + 1) {
            return false;
        }
        for (const auto &edge : graph[currentNode]) {
            if (edge.second > weightLimit || seen.find(edge.first) != seen.end()) {
                continue;
            }
            trace.push_back(edge.first);
            seen.insert(edge.first);
            if (dfs(weightLimit, trace, seen, bestHistory)) {
                return true;
            }
            seen.erase(edge.first);
            trace.pop_back();
        }
        return false;
    };
    auto canArrive = [&dfs](int weightLimit) {
        vector<int> trace{1};
        set<int> seen{1};
        map<int, int> best;
        return dfs(weightLimit, trace, seen, best);
    };
    if (!canArrive(maxWeight)) {  // it's impossible to find a path
        return vector<int>();
    }
    auto lo = minWeight - 1, hi = maxWeight;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (canArrive(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    vector<int> trace{1};
    set<int> seen{1};
    map<int, int> best;
    dfs(hi, trace, seen, best);
    return trace;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, d;
    while (cin >> n >> m >> d) {
        vector<vector<pair<int, int>>> graph(n + 1);
        int minWeight = 1e9, maxWeight = 0;  // to help reduce the search space
        for (auto i = 0; i < m; i++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            graph[from].push_back({to, weight});
            minWeight = min(minWeight, weight);
            maxWeight = max(maxWeight, weight);
        }
        auto res = findMinPath(graph, d, minWeight, maxWeight);
        if (res.size() == 0) {
            cout << -1 << endl;
        } else {
            cout << res.size() - 1 << endl;
            for (const auto x : res) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
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
