#include<bits/stdc++.h>

using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define endl 	            "\n"
#define pb                  push_back
#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<ll>());
#define pn                  printf("\n")
#define md                  10000007
#define debug               printf("I am here\n")

#define l(s)                      s.size()
#define tcas(i,t)             for(ll i=1;i<=t;i++)
#define pcas(i)                printf("Case %lld: ",i)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define M 10000
const ll maxN=307;

double dp[maxN][maxN][maxN];
ll on=0,tw=0,thr=0;
 ll n;
double func(ll x,ll y,ll z){
    if(x==0 && y==0 && z==0) return 0;
    if(x<0 || y<0 || z<0) return 0;
   
   if(dp[x][y][z]>-0.9) return dp[x][y][z];

   double ans=n+(x*func(x-1,y,z))+(y*func(x+1,y-1,z))+(z*func(x,y+1,z-1));
    return dp[x][y][z]=ans/(x+y+z);
}

int main()
{
    fast;
     ll t;


     t=1;
    ///cin>>t;
   while(t--){
    memset(dp,-1,sizeof(dp));
   
    cin>>n;
    ll k;
    for(ll i=0;i<n;i++){
        cin>>k;
        if(k==1) on++;
        else if(k==2) tw++;
        else thr++;
    }
    cout<<fixed<<setprecision(10)<<func(on,tw,thr)<<endl;
    }



    return 0;
}
