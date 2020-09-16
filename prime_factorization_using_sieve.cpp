//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define sz 10000
int primes[sz + 1];

//ADVANTAGES OF THIS TECHNIQUE IS WHEN THERE ARE MANY QUERIES THEN SQRT(N) TRICK MIGHT NOT WORK INSTEAD WE CAN DO BIG OF LOGN PER QUERY PRIME_FACTORIZATION USING SIEVE METHOD
//SO IT IS ALSO A VERY USEFUL TECHNIQUE
//prime factorization using sieve

void sieve(){
    int i,j;
    for(i = 1;i<=sz;i++) primes[i] = -1;
    for(i = 2;i<=sz;i++){
        if(primes[i] == -1)
        {for(j = i; j <= sz;j += i){
               if(primes[j] == -1){
                   primes[j] = i;
               }
        }
        }
    }
}
void get_prime_factor(int n){
    while(n != 1){
        cout << primes[n]  << " ";
        n = n / primes[n];
    }
    cout << endl;
    return;
}
int main(){
   int q,n;
   sieve();
   cout << "give the number of queries" << endl;
   cin >> q;
   while(q--){
       cin >> n;
       get_prime_factor(n);
   }
    return 0;
}