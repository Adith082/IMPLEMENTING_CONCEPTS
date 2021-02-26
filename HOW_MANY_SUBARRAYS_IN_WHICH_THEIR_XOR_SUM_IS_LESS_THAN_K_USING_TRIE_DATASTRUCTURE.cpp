//IN THE NAME OF ALLAH THE MOST MERCIFUL THE ENTIRELY MERCIFUL 
#include <iostream>

using namespace std;

class Trietree{
    struct trienode{
        long long int zerocnt,onecnt;
        trienode* arr[2];
    };
    trienode* root;
    trienode* getNode(){
       trienode* cur = new trienode;
       cur->zerocnt = 0;
       cur->onecnt = 0;
       cur->arr[0] = NULL;
       cur->arr[1] = NULL;
       return cur;
    }
    public :
      Trietree(){
          root = getNode();
      }
      void insert(long long int x){
           trienode* cur = root;
           long long int i,j,p;
           for(j = 31;j>=0;j--){
              
               if(x&(1LL<<j)){
                    if(cur->arr[1] == NULL) cur->arr[1] = getNode();
                    cur->onecnt++;
                    cur = cur->arr[1];
               }else{
                    if(cur->arr[0] == NULL) cur->arr[0] = getNode();
                    cur->zerocnt++;
                    cur = cur->arr[0];
               }
           }    return;
      }      long long int xorNumberLessthanK(long long int x,long long int k){
                  trienode* cur = root;
                  long long int p,q,i,j,res = 0;
                  for(j = 31;j>=0;j--){
                      p = (x&(1LL<<j));
                      q = (k&(1LL<<j));
                      if(q){
                          if(p == 0){
                              res+= cur->zerocnt;
                              if(cur->arr[1] != NULL) cur = cur->arr[1];
                              else break;
                          }else{
                              res += cur->onecnt;
                              if(cur->arr[0] != NULL) cur = cur->arr[0];
                              else break;
                          }
                      }else{
                          if(p == 0) if(cur->arr[0] != NULL) cur = cur->arr[0];
                          else break;
                          else  if(cur->arr[1] != NULL) cur = cur->arr[1];
                          else break;
                      }
                  }      return res;
      }
};




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int i,j,n,t,xx,val,pre = 0,rr,k;
    cin >> t;
    while(t--){
        rr = 0;
        pre = 0;
        Trietree* ob = new Trietree();
        ob->insert(0);
        cin >> n >> k;
        for(i = 0;i<n;i++){
            cin >> val;
            pre = pre ^ val;
            rr += ob->xorNumberLessthanK(pre,k);
            ob->insert(pre);
        }   cout << rr << endl;
    }
    return 0;
}
