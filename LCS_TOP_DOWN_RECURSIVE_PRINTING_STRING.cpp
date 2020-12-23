//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
string s,t;
int dp[3004][3004];
int solve(int i,int j,int n,int m){
       if(i == n || j == m) return 0;
       if(dp[i][j] != -1) return dp[i][j];
       int len1 = 0,len2 = 0;
       if(s[i] == t[j]){
           len1 = 1 + solve(i+1,j+1,n,m);
       }   len2 = max(solve(i+1,j,n,m),solve(i,j+1,n,m));
       return dp[i][j] = max(len1,len2);
}
int main(){
       memset(dp,-1,sizeof(dp));
       int i,j,n,m;
       string res;
       cin >> s;
       cin >> t;
       n = s.size();
       m = t.size();
       s += '#';
       t += '#';
       for(i = n-1;i>=0;i--){
           for(j = m-1;j>=0;j--)
               int ff = solve(i,j,n,m);
       }  i = 0; j = 0;
         while(i<n && j < m){
             if(s[i] == t[j]){
                 res += s[i];
                 i++;
                 j++;
             }else{
                 if(dp[i+1][j] >= dp[i][j+1]) i++;
                 else j++;
             }
         }          
                    cout << res << endl;
    return 0;
}
