//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRRELY MERCIFUL
#include <bits/stdc++.h>

using namespace std;
#define sz 100004
long long int primes[sz];
long long int res[sz];
vector <long long int> vv;
void sieve(){
   long long int i,j;
   primes[1] = 1;
   vv.push_back(2);
   for(i = 4;i<sz;i+=2) primes[i] = 1;
   for(i = 3;i<sz;i+=2){
       if(primes[i] == 0){
           for(j = i*i;j<sz;j+=(2*i)){
               primes[j] = 1;
           }
       }
   }    for(j = 3;j<sz;j+=2) if(primes[j] == 0) vv.push_back(j);
   return;
}    long long int segmentedSieve(long long int a,long long int b){
      long long int i,j,cmp = 0;
      if(a == 1) res[0] = 1;
      for(i = 0;i<vv.size();i++){
          if(vv[i]*vv[i] <= b){
              j = (a/vv[i]) * (vv[i]);
              if(j<a) j = j + vv[i];
              for(  ;j<=b;j+=vv[i]){
                     if(j!=vv[i]) res[j-a] = 1;
              }
          }  else break;
      }
        for(i = 0;i<=(b-a);i++){
          if(res[i] == 0) {
              cmp++;
          }
      }
          return cmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    long long int i,j,t,n,a,b,tt;
    cin >> t;
    j = 1;
    while(t--){
          cin >> a >> b;
        cout << "Case " << j++ << ": " << segmentedSieve(a,b) << endl;
        for(i = 0;i<=(b-a);i++) res[i] = 0;
    }
    return 0;
}





