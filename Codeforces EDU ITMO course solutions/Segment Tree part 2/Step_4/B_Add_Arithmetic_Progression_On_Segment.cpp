#include<bits/stdc++.h>
using namespace std;
 
#define N 300007
//#define mod 1000
#define int long long
#define F first
#define S second
 
/*
   hints :
        main idea
         op(l,r,a,d)  >>  add a to elemnts , 0d for l elemnt , 1d to l+1 ele ...)
         op (l,r,a,d)
           means op (lx ,rx ,  a+(lx-l)*a , d)     without diffrence (lx>=l and rx<=r)
 
        proof :
                     d
                  d  d
                d d  d
              d d d  d
            0 d d d  d
            a a a a  a
            l.............r
                lx   rx
                so it's easy to see that u need to add (4*d +a) to all seg  , then add 0d 1d and so on
 
*/
struct item {
   int a =0 , d = 0 ;
 
};
 
struct segtree{
    vector<item> operation;
 
    int sz =1;
    segtree(int n){
        while(sz<n)sz*=2;
        operation.resize(2*sz);
    }
    item  merge_op (item op1  , item op2){
         return   {op1.a+op2.a  , op1.d +op2.d} ;
    }
 
    void change  (int  l , int r,int a , int d , int x, int lx ,  int rx){
        if (rx<=l || lx>=r)
            return ;
        if (lx >=l and rx<=r){
                item oper  = {a + (lx-l)*d  , d}  ;
                operation[x]  =merge_op(operation[x] ,oper);
                return ;
        }
        int md  = (lx+rx)/2;
        change( l, r, a, d, 2*x+1 ,lx, md);
        change (l, r, a ,d  ,  2*x+2 , md, rx);
    }
    void change (int  l ,int r ,int a   , int d){
        change(l,r,a, d,0 ,0,sz);
    }
    int calc(int  i, int x , int lx , int rx ){
          if (rx-lx==1){
             return operation[x] . a;
          }
          int md   = (lx+rx)/2;
          int bonus =  (i -lx) * operation[x].d  + operation[x].a;
          if (i<md){
 
                  return bonus +  calc(i , 2*x+1 , lx , md);
          }
 
          return bonus + calc( i  , 2*x+2 , md ,rx)  ;
 
    }
    int calc(int i  ){
        return calc(i , 0 , 0,sz);
    }
 
 
};
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
 
    int n, m ;
    cin>>n>>m;
    segtree sg(n+1);
 
    for (int  i = 0 ; i  <m; ++i){
        int q;
        cin>>q;
        if(q==1){
            int l  , r , a , d;
            cin>>l>>r>>a>>d;
            l--;
            sg.change( l, r, a, d);
            continue;
        }
        int idx ;
        cin>>idx;
        idx--;
        cout<<sg.calc(idx)<<" \n" ;
 
    }
 
}