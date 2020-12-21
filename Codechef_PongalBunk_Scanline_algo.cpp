//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
 long long int pref[2000008];
 long long int line[2000008];
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int i,j,n,q,l,r,m,id;
    
    cin >> n;
    
    cin >> q;
    
    while(q--){
        cin >> l >> r;
        pref[l]++;
        pref[r+1]--;
        line[r+1] -= (r - l + 1);
    }   
        for(i = 2;i<=n;i++) pref[i] += pref[i-1];
        line[1] += pref[1];
        for(i = 2;i<=n;i++) line[i] += (line[i-1] + pref[i]);
        cin >> m;
        while(m--){
            cin >> id;
            cout << line[id] << endl;
        }
      return 0;
}
