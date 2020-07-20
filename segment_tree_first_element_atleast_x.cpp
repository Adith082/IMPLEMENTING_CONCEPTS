//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define sz 100006
struct edge{
    int sum;
}tree[4*sz];
int a[sz];
int res = -1;
int k;
   void build(int ind,int lb,int ub){
       if(lb == ub){
           tree[ind].sum = a[lb];
           return;
       }
       int mid = lb + (ub - lb) / 2;
       build(ind * 2,lb,mid);
       build(ind * 2  + 1,mid + 1, ub);
       tree[ind].sum = max(tree[ind * 2].sum , tree[ind * 2 + 1].sum);
       return;
   }
   void update(int ind,int lb,int ub,int pos,int val){
       if(pos < lb || pos > ub) return;
       if(lb == ub) {
           if(lb == pos) tree[ind].sum = val;
           return;
       }
       int mid = lb + (ub - lb)/2;
       if(pos <= mid) update(ind * 2,lb,mid,pos,val);
       else update(ind * 2 + 1,mid + 1 , ub,pos,val);
       tree[ind].sum = max(tree[ind * 2].sum ,tree[ind * 2 + 1].sum);
       return;
   }
   int query(int ind,int lb,int ub,int x){
       if(lb == ub){
           if(tree[ind].sum >= x) return lb;
           else return -1;
       }
       int mid = lb + (ub - lb)/2;
       int temp = tree[ind * 2].sum;
       int temp2 = tree[ind * 2 + 1].sum;
       if(temp >= x) return query(ind * 2,lb,mid,x);
       else if(temp2 >= x ) return query(ind * 2 + 1,mid + 1, ub ,  x);
       else return -1;
   }
int main(){
    int n,m,p,x,k;
    cin >> n >> m;
    int i,j;
    for(i = 0;i<n;i++) cin >> a[i];
    build(1,0,n-1);
    while(m--){
        cin >> p;
        if(p == 1){
            cin >> i >> k;
            update(1,0,n-1,i,k);
        }
        else if(p == 2){
            cin >> x;
            cout << query(1,0,n-1,x) << endl;
        }
    }
    return 0;
}


