//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
map <int,int> mm;
int main(){
    int pref = 0,res = 0;
    int i,j,n,k;
    cin >> n >> k;
    int a[n];
    for(i = 0;i<n;i++) {
          cin >> a[i];
          pref = pref ^ a[i];
          if(pref == k) res++;
          if(mm.find(pref ^ k) != mm.end()) res += mm[pref ^ k];
          mm[pref]++;
    }
       cout << res << endl;
    return 0;
}
