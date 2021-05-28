//IN THE NAME OF ALLAH THE MOST MERICFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
long long int cntDiv[1000];
long long int sumOfDiv[1000];
//HERE WE ARE GONNA FIND THE NUMBER OF DIVISORS AND THE SUM OF THOSE DIVISORS OF (ANY NUMBER FROM 1 UPTO N) using
//SPECIAL SIEVE IN ONLY (nlogn) COMPLEXITY
void sieve(long long int n){
    int i,j;
    for(i = 1;i<=n;i++){
        for(j = i;j<=n;j+=i){
            cntDiv[j]++;
            sumOfDiv[j] += i;
        }
    }    return;
}
int main(){
    
    long long int i,j,t,n;
    cin >> n;
    sieve(n);
    for(i = 1;i<=n;i++){
        cout << "number " << i << " count of divisor " << cntDiv[i] << " sum of the divisor " << sumOfDiv[i] << endl;
    }
    return 0;
}
