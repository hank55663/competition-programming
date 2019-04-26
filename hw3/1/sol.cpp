#include<bits/stdc++.h>
#define index INDEX
using namespace std;
struct node{
    node *n[2];
    int cnt;
    node():cnt(0){
        n[0]=n[1]=NULL;
    }
}*root;
int index=0;
void add(const char *c){
    node *now = root;
    for(int i = 0;c[i]!=0;i++){
        if(!now->n[c[i]-'0']){
            now->n[c[i]-'0'] = new node();
        }
        now = now->n[c[i]-'0'];
        now->cnt ++;
    }
}
int search(const char *c){
    node *now = root;
    for(int i = 0;c[i]!=0;i++){
        now = now->n[c[i]-'0'];
    }
    return now->cnt;
}
string s[1000005];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    root = new node();
    for(int i = 0;i<n;i++){
        cin>>s[i];
        add(s[i].c_str());
    }
    int q;
    cin>>q;
    for(int i =0;i<q;i++){
        cin>>s[i];
        cout<<search(s[i].c_str())<<'\n';
    }
}