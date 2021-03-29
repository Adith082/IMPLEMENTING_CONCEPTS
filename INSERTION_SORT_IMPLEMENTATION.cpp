//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
//INSERTION SORT IMPLEMENTATION 
using namespace std;

int main(){
    
    int i,j,n,v;
    cin >> n;
    int a[n+1];
    
    for(i = 0;i<n;i++) cin >> a[i];
    for(i = 1;i<n;i++){
        j = i-1;
        v = a[i];
        while(j>=0 && v < a[j]){
            a[j+1] = a[j];
            j--;
        } a[j+1] = v;
    }      for(i = 0;i<n;i++) cout << a[i] << " ";
           cout << endl;
    return 0;
}
