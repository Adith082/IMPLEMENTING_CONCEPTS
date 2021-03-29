//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
// BUBBLE SORT  OPTIMIZED ALGORITHM IMPLEMENTATION
int main(){
	
    int i,j,t,n;
    bool  fl;
    cin >> n;
    int a[n];
    for(i = 0;i<n;i++) cin >> a[i];
    
    for(i = 0;i<n-1;i++){
        fl = false;
        for(j = 0;j<(n-i-1);j++){
            if(a[j+1] < a[j]){
                swap(a[j],a[j+1]);
                fl = true;
            }
        }    if(fl == false) break;
    }     
          cout << "sorted array " << endl;
          for(i = 0;i<n;i++) cout << a[i] << " ";
          cout << endl;
    return 0;
}
