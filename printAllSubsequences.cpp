//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
void solve(int i,string s,int n,string temp){
    if(i == n){
        cout << temp << endl;
        return;
    }
    temp += s[i];
    solve(i+1,s,n,temp);
    temp.pop_back();
    solve(i+1,s,n,temp);
}
int main(){
    int i,j,t,n;
    string s,temp;
    cin >> s;
    solve(0,s,s.size(),temp);
    
    return 0;
}
