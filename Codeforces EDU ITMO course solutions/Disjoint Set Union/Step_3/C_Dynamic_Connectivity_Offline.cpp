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

// Printings & debugging
#define nn '\n'
#define Setpre(n) cout << fixed << setprecision(n)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debug printf("I am here\n")

// CONSTANTS
#define md 10000007
#define PI acos(-1)
const double EPS = 1e-9;
const ll N = 3e5 + 10;
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
namespace io
{
    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const pair<First, Second> &p) { return os << p.first << " " << p.second; }
    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const map<First, Second> &mp)
    {
        for (auto it : mp)
        {
            os << it << endl;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const vector<First> &v)
    {
        bool space = false;
        for (First x : v)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const set<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const multiset<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First, typename Second>
    istream &operator>>(istream &is, pair<First, Second> &p) { return is >> p.first >> p.second; }
    template <typename First>
    istream &operator>>(istream &is, vector<First> &v)
    {
        for (First &x : v)
        {
            is >> x;
        }
        return is;
    }

    long long fastread()
    {
        char c;
        long long d = 1, x = 0;
        do
            c = getchar();
        while (c == ' ' || c == '\n');
        if (c == '-')
            c = getchar(), d = -1;
        while (isdigit(c))
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return d * x;
    }
    static bool sep = false;
    using std::to_string;
    string to_string(bool x) { return (x ? "true" : "false"); }
    string to_string(const string &s) { return "\"" + s + "\""; }
    string to_string(const char *s) { return "\"" + string(s) + "\""; }
    string to_string(const char &c)
    {
        string s;
        s += c;
        return "\'" + s + "\'";
    }
    template <typename Type>
    string to_string(vector<Type>);
    template <typename First, typename Second>
    string to_string(pair<First, Second>);
    template <typename Collection>
    string to_string(Collection);
    template <typename First, typename Second>
    string to_string(pair<First, Second> p) { return "{" + to_string(p.first) + ", " + to_string(p.second) + "}"; }
    template <typename Type>
    string to_string(vector<Type> v)
    {
        bool sep = false;
        string s = "[";
        for (Type x : v)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "]";
        return s;
    }
    template <typename Collection>
    string to_string(Collection collection)
    {
        bool sep = false;
        string s = "{";
        for (auto x : collection)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "}";
        return s;
    }
    void print()
    {
        cerr << endl;
        sep = false;
    }
    template <typename First, typename... Other>
    void print(First first, Other... other)
    {
        if (sep)
            cerr << " | ";
        sep = true;
        cerr << to_string(first);
        print(other...);
    }
}
using namespace io;



struct persistent_dsu
{
    struct state
    {
        int u, v, rnku, rnkv;
        state()
        {
            u = -1;
            v = -1;
            rnkv = -1;
            rnku = -1;
        }
        state(int _u, int _rnku, int _v, int _rnkv)
        {
            u = _u;
            rnku = _rnku;
            v = _v;
            rnkv = _rnkv;
        }
    };

    stack<state> st;
    int par[N], depth[N];
    int comp;
    persistent_dsu()
    {
        comp = 0;
        memset(par, -1, sizeof(par));
        memset(depth, 0, sizeof(depth));
    }

    int root(int x)
    {
        if (x == par[x])
            return x;
        return root(par[x]);
    }

    void init(int n)
    {
        comp = n;
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            depth[i] = 1;
        }
    }

    bool connected(int x, int y)
    {
        return root(x) == root(y);
    }

    void unite(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
        {
            st.push(state());
            return;
        }
        if (depth[rx] < depth[ry])
            par[rx] = ry;
        else if (depth[ry] < depth[rx])
            par[ry] = rx;
        else
        {
            par[rx] = ry;
            depth[rx]++;
        }
        comp--;
        st.push(state(rx, depth[rx], ry, depth[ry]));
    }
    /// how many last added edges you want to erase
    void backtrack(int c)
    {
        while (!st.empty() && c)
        {
            if (st.top().u == -1)
            {
                st.pop();
                c--;
                continue;
            }
            par[st.top().u] = st.top().u;
            par[st.top().v] = st.top().v;
            depth[st.top().u] = st.top().rnku;
            depth[st.top().v] = st.top().rnkv;
            st.pop();
            c--;
            comp++;
        }
    }
};
persistent_dsu d;
vector<pair<int, int>> alive[4 * N];
void upd(int n, int b, int e, int i, int j, pair<int, int> &p)
{
    if (b > j || e < i)
        return;
    if (b >= i && e <= j)
    {
        alive[n].push_back(p); /// this edge was alive in this time range
        return;
    }
    int l = 2 * n, r = l + 1, mid = b + e >> 1;
    upd(l, b, mid, i, j, p);
    upd(r, mid + 1, e, i, j, p);
}
int ans[N];
void query(int n, int b, int e)
{
    if (b > e)
        return;
    int prevsz = d.st.size();
    /// add edges which were alive in this range
    for (auto p : alive[n])
        d.unite(p.first, p.second);
    if (b == e)
    {
        ans[b] = d.comp;
        d.backtrack(d.st.size() - prevsz);
        return;
    }
    int l = 2 * n, r = l + 1, mid = b + e >> 1;
    query(l, b, mid);
    query(r, mid + 1, e);
    d.backtrack(d.st.size() - prevsz);
}
struct HASH
{
    size_t operator()(const pair<int, int> &x) const
    {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
set<pair<int, int>> se;
bool isquery[N];
unordered_map<pair<int, int>, int, HASH> st;
int main()
{
    fast;
    st.reserve(1LL << 20);
    int i, j, k, n, m, u, v;
    cin >> n >> m;
    d.init(n);
    for (i = 1; i <= m; i++)
    {
        string ty;
        cin >> ty;
        if (ty == "?")
        {
            isquery[i] = 1;
        }
        else if (ty == "+")
        {
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            pair<int, int> p = {u, v};
            se.insert(p);
            st[p] = i;
        }
        else
        {
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            pair<int, int> p = {u, v};
            se.erase(p);
            upd(1, 1, m, st[p], i - 1, p); /// in this time range this edge was in the DSU
        }
    }
    for (auto p : se)
        upd(1, 1, m, st[p], m, p); /// update rest of the edges
    se.clear();
    query(1, 1, m);
    for (i = 1; i <= m; i++)
        if (isquery[i])
            cout << ans[i] << endl;
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
