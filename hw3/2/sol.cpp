#include<bits/stdc++.h>
#define x first
#define y second
#define LL long long
using namespace std;
int main(){
    int a,b,q;
    scanf("%d %d %d",&a,&b,&q);
    map<int,int> m;
    m[0]=1e9;
    m[b+1]=0;
    LL tot=a*b;
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        auto it = m.lower_bound(x);
        if(it->y>=y){
            printf("QAQ\n");
        }
        else{
            LL last=it->y;
            LL ans=0;
            vector<int> need_erase;
            while(true){
                it--;
                ans+=(min(it->y,y)-last)*(x-it->x);
                last=it->y;
              //  printf("%d %d %d?\n",it->x,it->y,ans);
                if(it->y<=y){
                    need_erase.push_back(it->x);
                    //m.erase(it);
                }
                else
                    break;
            }
            for(auto it:need_erase)
                m.erase(it);
            m[x]=y;
            printf("%lld\n",ans);
            tot-=ans;
        }
    }
    printf("%lld\n",tot);
}