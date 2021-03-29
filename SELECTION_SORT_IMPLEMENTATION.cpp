//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
//SELECTION SORT ALGORITHM IMPLEMENTATION UNSTABLE ONE 
int main(){
    int id;
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
        }    swap(a[id],a[i]);
    }       cout << "sorted array is "  << endl;
             for(i = 0;i<n;i++) cout << a[i] << " ";
            cout << endl;
    
    return 0;
}
