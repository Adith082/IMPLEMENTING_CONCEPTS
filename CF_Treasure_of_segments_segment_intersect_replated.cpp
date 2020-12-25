//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <pair<int,int>> vv;
    vector <int> l;
    vector <int> r;
    int i,j,t,n,ind,ll,rr,res,id,id2;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0;i<n;i++){
            cin >> ll >> rr;
            vv.push_back({ll,rr});
            l.push_back(ll);
            r.push_back(rr);
        }   sort(l.begin(),l.end());
            sort(r.begin(),r.end());
            res = n-1;
            for(i = 0;i<n;i++){
                id = lower_bound(r.begin(),r.end(),vv[i].first) - r.begin();
                id2 = n - (upper_bound(l.begin(),l.end(),vv[i].second) - l.begin());
               // cout << "n " << n << " " << id2 << endl;
                res = min(res,id + id2);
            }   cout << res << endl;
            vv.clear();
            l.clear();
            r.clear();
    }
    return 0;
}
