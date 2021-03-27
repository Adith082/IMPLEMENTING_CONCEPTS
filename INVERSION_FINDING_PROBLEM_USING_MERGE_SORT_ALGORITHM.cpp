//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>

using namespace std;

int res = 0;
int n;
void merge(int a[],int lb,int mid,int ub){
    int i,j,n,m,k;
    i = lb;
    n = mid;
    j = mid+1;
    m = ub;
    int temp[(ub-lb+1)];
    k = 0;
    while(i<=n && j <= m){
        if(a[i] > a[j]){
            res += ((n-i)+1);
            temp[k++] = a[j++];
        }else if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
    }   while(i<=n) temp[k++] = a[i++];
        while(j<=m) temp[k++] =a[j++];
        k = 0;
        for(i = lb;i<=ub;i++) a[i] = temp[k++];
        return;
}
void mergeSort(int a[],int lb,int ub){
    if(lb >= ub) return;
    int mid = (lb + ub)/2;
    mergeSort(a,lb,mid);
    mergeSort(a,mid+1,ub);
    merge(a,lb,mid,ub);
    return;
}
int main(){
    int i,j,t,m;
    string s;
    cin >> t;
    while(t--){
        res = 0;
        cin >> n;
        int a[n];
        for(i = 0;i<n;i++) cin >> a[i];
        mergeSort(a,0,n-1);
        cout << res << endl;
    }
    
    return 0;
}
