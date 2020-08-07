//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int root = 1;
int leaf[300];
int lv[300];
vector <int> adj[300];
    void dfs(int src,int par){
        int l = 0,i;
        int len = adj[src].size();
        for(i = 0;i<len;i++){
            int child = adj[src][i];
            if(child != par){
                dfs(child,src);
                l += lv[child];
            }
        }
        if(src != root && len == 1){
            leaf[src] = 0;
            lv[src] = 1;
            return;
        }
        else{
            leaf[src] = l;
            lv[src] = l;
            return;
        }
    }
int main(){
    int n,m,i,j,p,q;
    cin >> n;
    for(i = 1;i<=n-1;i++){
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
      dfs(1,0);
      for(i = 1;i<=n;i++) cout << leaf[i] << " ";
      cout << endl;
    return 0;
}
