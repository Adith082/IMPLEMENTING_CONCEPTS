//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int pri[1000][1000];
int solve(int i,int j,int a[]){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int k,minn = INT_MAX;
    for(k = i;k<j;k++){
        int cnt = solve(i,k,a) + solve(k+1,j,a) + (a[i-1] * a[k] * a[j]);
        if(cnt < minn) {
            minn = cnt;
            pri[i][j] = k;
        }
    }   return dp[i][j] = minn;
}
void find_path(int i,int j,int a[]){
    if(i == j){
        cout << i;
        return;
    }   
        cout << "(";
        find_path(i,pri[i][j],a);
        find_path(pri[i][j] + 1,j,a);
        cout << ")";
            return;
}
int main(){
    
    
     memset(dp,-1,sizeof(dp));
     int i,j,n;
     
     cin >> n;
     int a[n];
    
    for(i = 0;i<n;i++) cin >> a[i];
    
    cout << solve(1,n-1,a) << endl;
    find_path(1,n-1,a);
    return 0;
}
