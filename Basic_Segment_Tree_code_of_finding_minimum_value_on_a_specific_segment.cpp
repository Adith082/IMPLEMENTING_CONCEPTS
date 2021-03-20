//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>

using namespace std;
#define sz 100007
struct node{
    int value;
}tree[4*sz];

void build(int ind,int lb,int ub,int pos,int val){
   // cout << "hello" << endl;
    if(pos < lb || pos > ub) return;
    if(lb == ub) {
      if(pos == lb)   tree[ind].value = val;
      return;
    }
    int mid = (lb + ub)/2;
    if(pos <= mid) build(ind*2,lb,mid,pos,val);
    else build(ind * 2 + 1,mid+1,ub,pos,val);
    tree[ind].value = min(tree[ind*2].value,tree[ind*2 + 1].value);
    return;
}
int query(int ind,int lb,int ub,int qlb,int qub){
     // cout << "bye" << endl;
      if(ub < qlb || lb > qub) return INT_MAX;
      if(lb >= qlb && ub <= qub) return tree[ind].value;
      int mid = (lb + ub)/2;
      int x = query(ind*2,lb,mid,qlb,qub);
      int y = query(ind * 2 + 1,mid+1,ub,qlb,qub);
      return min(x,y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,t,n,m,q,l,r,val;
    j = 1;
    cin >> t;
    while(t--){
        cout << "Case " << j++ << ":" << endl;
        cin >> n >> q;
        for(i = 1;i<=n;i++){
            cin >> val;
            build(1,1,n,i,val);
        } while(q--){
            cin >> l >> r;
            cout << query(1,1,n,l,r) << endl;
        }
    }
    
    return 0;
}
