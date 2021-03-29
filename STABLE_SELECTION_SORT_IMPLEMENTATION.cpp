//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
//(STABLE)   SELECTION SORT ALGORITHM IMPLEMENTATION (STABLE) ONE
int main(){
    int id,temp;
    int i,j,n;
    cin >> n;
    int a[n];
    for(i = 0;i<n;i++) cin >> a[i];
    
    for(i = 0;i<n-1;i++){
        id = i;
        for(j = i+1;j<n;j++){
            if(a[id] > a[j]){
                id = j;
            }
        }      temp = a[id];
               while(id>i){
                   a[id] = a[id-1];
                   id--;
               }   a[i] = temp;
    }      
    
    
             cout << "sorted array is "  << endl;
             for(i = 0;i<n;i++) cout << a[i] << " ";
            cout << endl;
    
    return 0;
}
