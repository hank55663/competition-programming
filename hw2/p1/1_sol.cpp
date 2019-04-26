#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[10000005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,l,r;
        scanf("%lld %lld %lld",&n,&l,&r);
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        sort(a,a+n);
        int ok=0;
        int index=0;
        for(LL i=0;i<r-l+1;i++){
            if(index==n||a[index]!=l+i){
                printf("%lld\n",l+i);
                ok=1;
                break;
            }
            index++;
            while(index<n&&a[index]==a[index-1])index++;
        }
        if(!ok)
        printf("^v^\n");
        /*
        fill(cnt,cnt+n+10,0);
        for(int i=0;i<n;i++){
            LL x;
            scanf("%lld",&x);
            if(x-l<=n){
                cnt[x-l]++;
            }
        }
        int ok=0;
        for(LL i=l;i<=r;i++){
            if(!cnt[i-l]){
                ok=1;
                printf("%lld\n",i);
                break;
            }
        }
        if(!ok)
        printf("^v^\n");*/
    }
}