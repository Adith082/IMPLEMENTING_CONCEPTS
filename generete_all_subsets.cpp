//BISMILLAH
//GENERATE ALL SUBSETS
#include <bits/stdc++.h>
using namespace std;
int main(){
	
    int i,j,n,p;
	cin >> n;
	int a[n];
	for(i = 0;i<n;i++){
		cin >> a[i];
	}
	p = pow(2,n) - 1; 
	for(i = 0;i<=p;i++){
		for(j = 0;j<n;j++){
			if(i & (1<<j)) cout << a[j];
		}
		  cout << endl;
	}
	return 0;
}
