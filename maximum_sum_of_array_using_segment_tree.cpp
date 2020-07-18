//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define sz 100005
typedef long long int  ll;
ll a[sz];
  struct edge{
      ll sum,pref,suff,seg;    
  }tree[4*sz];
     
     void build(ll ind,ll lb,ll ub){
           if(lb == ub){
               tree[ind].sum = a[lb];
               tree[ind].pref = a[lb];
               tree[ind].suff = a[lb];
               tree[ind].seg = a[lb];
               return;
           }   
            ll mid = lb + (ub - lb) / 2;
             build(ind * 2, lb, mid);
            build(ind * 2  + 1,mid + 1 , ub);
          tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
          tree[ind].pref = max(tree[ind * 2].pref,tree[ind * 2].sum + tree[ind * 2 + 1].pref);
          tree[ind].suff = max(tree[ind * 2 + 1].suff,tree[ind * 2 + 1].sum + tree[ind * 2].suff);
          tree[ind].seg = max({tree[ind * 2].seg,tree[ind * 2 + 1].seg,tree[ind * 2].suff + tree[ind * 2 + 1].pref});
          return;
     }
     void update(ll ind,ll lb , ll ub,ll pos, ll val){
          if(pos < lb || pos > ub) return;
          if(lb == ub){
              if(lb == pos){
                  tree[ind].sum = val;
                  tree[ind].pref = val;
                  tree[ind].suff = val;
                  tree[ind].seg = val;
              }
              return;
          }
          ll mid = lb + (ub - lb) / 2;
          if(pos <= mid) update(ind * 2,lb,mid,pos,val);
          else update(ind * 2 + 1,mid + 1, ub , pos , val);
          tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
          tree[ind].pref = max(tree[ind * 2].pref,tree[ind * 2].sum + tree[ind * 2 + 1].pref);
          tree[ind].suff = max(tree[ind * 2 + 1].suff,tree[ind * 2 + 1].sum + tree[ind * 2].suff);
          tree[ind].seg = max({tree[ind * 2].seg,tree[ind * 2 + 1].seg,tree[ind * 2].suff + tree[ind * 2 + 1].pref});
          return;
     }

     edge query(){
           return tree[1];
     }
     
int main(){
    edge get;
    ll i,j,n,m,id,val , res;
    cin >> n >> m;
    for(i = 0;i<n;i++){
        cin >> a[i];
    }    
    build(1,0,n-1);
    get = query();
    if(get.seg < 0) cout << 0 << endl;
    else cout << get.seg << endl;
    while(m--){
        cin >> id >> val;
        update(1,0,n-1,id,val);
        get = query();
        if(get.seg < 0) cout << 0 << endl;
        else cout << get.seg << endl;
    }
    return 0;
}