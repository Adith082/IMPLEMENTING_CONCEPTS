//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
//QUICK SORT SIMPLE IMPLEMENTATION 
int partition(int a[],int left,int right){
    int pivot = a[right];
    //assuming the right most indexed element as the pivot element in this implementation;
    int i = left-1,j;
    for(j = left;j<right;j++){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }   swap(a[right],a[i+1]);
    return (i+1);
}

void quickSort(int a[],int left,int right){
    if(left < right){
        
        int pid = partition(a,left,right);
        
        quickSort(a,left,pid-1);
        quickSort(a,pid+1,right);
        
    }   return;
}
int main(){
    int i,j,n;
    cin >> n;
    int a[n];
    for(i = 0;i<n;i++) cin >> a[i];
    quickSort(a,0,n-1);
    cout << "sorted array is " << endl;
    for(i = 0;i<n;i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
