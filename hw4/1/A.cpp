#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string,int> m;
    vector<string> v;
    string str;
    while(cin>>str){
        string temp="";
        for(auto it:str){
            if(it>='a'&&it<='z'){
                temp += it;
            }
            if(it>='A'&&it<='Z'){
                it = it-'A'+'a';
                temp+=it;
            }
        }
        if(temp.size()==0)continue;
        m[temp]++;
        if(m[temp]==1)
        v.pb(temp);
    }
    for(auto it:v){
        cout<<it<<" "<<m[it]<<endl;
    }
}