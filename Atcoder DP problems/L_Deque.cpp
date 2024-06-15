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
const ll maxN=3007;
#define M 10000

void setIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

}
ll n,k,tot;
ll dp[maxN][maxN][2];

vector<ll>vec(maxN);

ll x,y,m;
ll ans=0;
ll func(ll l,ll r,bool f){
  
  if(l>r) return 0;
 // cout<<dq.front()<<" "<<dq.back()<<" "<<f<<" "<<x<<" "<<y<<endl;
    if(dp[l][r][f]!=-1)  return dp[l][r][f];
  if(f){
       ans=max(vec[l]+func(l+1,r,0),vec[r]+func(l,r-1,0));
     }
    else{
      ans=min(func(l+1,r,1),func(l,r-1,1));
   }

  return dp[l][r][f]=ans;
}
int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    //cin>>t;

    while(t--){
       for(ll i=0;i<=3000;i++){
        for(ll j=0;j<=3000;j++){
         for(ll k=0;k<=1;k++){
          dp[i][j][k]=-1;
         }
        }
       }
        cin>>n;
        ll k;
        ll sum=0;
        for(ll i=0;i<n;i++){
          cin>>vec[i];
          sum+=vec[i];
        }
         //for(ll i=0;i<n;i++){cout<<dq[i]<<" ";}
      ll sumx=func(0,n-1,0);
      cout<<(sum-sumx)-sumx<<endl;
    }
   


    return 0;
}

