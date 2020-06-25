//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
   int r1,c1,r2,c2;
   int q;
   int n,m,i,j;
   cout << "number of rows and columns " << endl;
   cin >> n >> m;
   int adj[n][m];
   for(i = 0;i<n;i++){
       for(j = 0;j<m;j++){
           cin >> adj[i][j];
       }
   }
   int pref[n][m];
   int sum = 0;
   for(j = 0;j<m;j++){
       sum = sum + adj[0][j];
       pref[0][j] = sum;
   }
   sum = adj[0][0];
   for(i = 1;i<n;i++){
       sum = sum + adj[i][0];
       pref[i][0] = sum;
   }
   for(i = 1;i<n;i++){
       for(j = 1;j<m;j++){
           pref[i][j] = adj[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
       }
   }
   cout << "NOW GIVE THE NUMBER OF QUERIES" << endl;
   cin >> q;
   while(q--){
        cout << "give the starting position and the ending position respectively " << endl;
        cin >> r1 >> c1 >> r2 >> c2;
        int result = pref[r2][c2];
        if(c1 > 0) result = result - pref[r2][c1-1];
        if(r1 > 0) result = result - pref[r1-1][c2];
        if(r1 > 0 && c1 > 0) result = result + pref[r1-1][c1-1];
        cout << result << endl;
   }
    return 0;
}




