//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
int main(){
	
	  int i,j,n,pos,prev,maxx = 0;
	  int res = 1;
	  cin >> n;
	  int a[n];
      int dp[n];	  
      cout << "give the array elements " << endl;
	  for(i = 0;i<n;i++) cin >> a[i];
	  for(i = 0;i<n;i++) dp[i] = 1;
	  for(i = n-2;i>=0;i--){
	  	   for(j = i+1;j<n;j++){
	  	   	    if(a[j] > a[i]) {
	  	   	    	  dp[i] = max(dp[i],1 + dp[j]);
					 }  
			 }
			 res = max(dp[i],res);
	  }      cout << " the longest increasing subsequence length is " << res << endl;
	         cout << "printing the path " << endl;
	         maxx = 0;
	         for(i = 0;i<n;i++) if(dp[i] > maxx){
	         	    pos = i;
	         	    maxx = dp[i];
			 }  vector <int> ans;
			    ans.push_back(a[pos]);
			    prev = dp[pos];
			    for(i = pos + 1;i<n;i++){
			    	if(dp[i] == (prev - 1)){
			    		prev = dp[i];
			    		ans.push_back(a[i]);
					}
				}    for(i = 0;i<ans.size();i++) cout << ans[i] << " ";
	    return 0;
}
