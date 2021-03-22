//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxx;
    int i,j,t,n,k = 1,temp;
    stack <pair<int,int> > s;
    stack <pair<int,int> > s2;
  
    cin >> t;
    while(t--){
        maxx = 0;
        cin >> n;
        int mm[n+1];
        int a[n+1];
        for(i = 1;i<=n;i++){
            cin >> a[i];
            mm[i] = 0;
        }
        for(i = 1,j = n;i<=n;i++,j--){
            if(s.empty()){
                s.push({a[i],i});
            }else{
                while(!s.empty() && (s.top().first > a[i])){
                    temp = (i-s.top().second)*s.top().first;
                    mm[s.top().second] += temp;
                    s.pop();
                }    s.push({a[i],i});
            }
            if(s2.empty()) s2.push({a[j],j});
            else{
                while(!s2.empty() && (s2.top().first > a[j])){
                    temp = (s2.top().second - j)*s2.top().first;
                     mm[s2.top().second] += temp;
                     s2.pop();
                }    s2.push({a[j],j});
            }
            
        }  while(!s.empty()){
            
              temp = ((n+1) - (s.top().second))*s.top().first;
               mm[s.top().second] += temp;
              s.pop();
        }    while(!s2.empty()){
             temp = s2.top().second * s2.top().first;
              mm[s2.top().second] += temp;
             s2.pop();
        }
         for(i = 1;i<=n;i++){
             maxx = max(maxx,(mm[i]-a[i]));
         }
        cout << "Case " << k++ << ": " << maxx << endl;
    }
    
    return 0;
}
