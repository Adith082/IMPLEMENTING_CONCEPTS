//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n,w;
    cin >> n >> w;
    int a[n];
    for(i = 0;i<n;i++) cin >> a[i];
    int dp[w+1];
    dp[0] = 1;
    for(i = 1;i<=w;i++){
         dp[i] = 0;   
    }
     for(i = 1;i<=n;i++){
         for(j = w;j>=a[i];j--){
             if(dp[j] == 1 || dp[j-a[i]] == 0) continue;
             else dp[j] = 1;
         }
     }
    // for(i = 0;i<=w;i++) cout << dp[i] << " ";
   //  cout << endl;
    if(dp[w]) cout << "true" << endl; else cout << "false" << endl;
    return 0;
}
