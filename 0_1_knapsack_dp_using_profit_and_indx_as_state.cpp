//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define sz 109
long long int weight[sz];
long long int profit[sz];
long long int dp[sz][100003],n;
    long long int solve(long long int i,long long int p){
       if(i == n){
           if(p == 0) return 0;
           else return INT_MAX;
       }
        if(dp[i][p] != -1) return dp[i][p];
        long long int x = INT_MAX,y = INT_MAX;
        if(p - profit[i] >= 0){
              x = weight[i] + solve(i + 1,p - profit[i]);
        }
         y = solve(i+1,p);
         return dp[i][p] = min(x,y);
    }
int main(){
    memset(dp,-1,sizeof(dp));
    long long int w,v,i,j;
    long long int sum = 0;
    cin >> n >> w;
    for(i = 0;i<n;i++) {
        cin >> weight[i] >> profit[i];
        sum += profit[i];
    }
    for(i = sum;i>=0;i--)
    {
        if(solve(0,i) <= w){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

