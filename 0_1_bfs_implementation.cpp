//BISMILLAH
//0-1-BFS
#include <bits/stdc++.h>
using namespace std;
#define sz 10000
vector <int> adj[sz];
vector <int> weight[sz];
int cost[sz];
deque <int> qq;
void dijkstra_bfs(int source){
    cost[source] = 0;
    qq.push_front(source);
    int i,j,x,len;
    while(!qq.empty()){
        x = qq.front();
        qq.pop_front();
        len = adj[x].size();
        for(i = 0;i<len;i++)
        {
            if(weight[x][i] + cost[x] < cost[adj[x][i]]){
                cost[adj[x][i]] = weight[x][i] + cost[x];
                if(weight[x][i] == 0) qq.push_front(adj[x][i]);
                else if(weight[x][i] == 1) qq.push_back(adj[x][i]);
            }
        }
    }
    return;
}
void dijkstra_bfs_init(int n){
    int i,j;
    for(i = 0;i<n;i++) cost[i] = INT_MAX;
}

int main(){
    cout << "ENTER THE NUMBER OF NODES AND EDGES" << endl;
    int n,m,i,j,s,c,p,q;
    cin >> n >> m;
    cout << "give the edge nodes  and the weights" << endl;
    for(i = 0;i<m;i++){
        // only give weights 0 or 1
        cin >> p >> q >> c;
        adj[p].push_back(q);
        adj[q].push_back(p);
        weight[p].push_back(c);
        weight[q].push_back(c);
    }
    dijkstra_bfs_init(n);
    cout << "please enter the source node " << endl;
    cin >> s;
    dijkstra_bfs(s);
    cout << "finally the shortest path cost from " << s << " to every other nodes are " << endl;
    for(i = 0;i<n;i++) cout << " node " << i << " cost " << cost[i] << endl;
    return 0;
}