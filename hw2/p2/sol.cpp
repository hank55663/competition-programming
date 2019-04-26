#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<pii> v;
        v.pb(mp(1e9,1));
        int ans=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            int now=0;
            while(v.back().x<x){
                now=max(v.back().y,now);
                v.pop_back();
            }
            v.pb(mp(x,now+1));
            ans=max(ans,now+1);
        }
        printf("%d\n",v.back().y);
    }
}