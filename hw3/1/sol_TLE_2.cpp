#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    vector<string> v;
    int n;
    cin>>n;
    for(int i = 0 ; i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(),v.end());
    int cnt=0;
    string str = v[0];
    for(auto& it : v){
        if(str == it)cnt++;
        else{
            cout<<str<<" "<<cnt<<endl;
            cnt = 1;
            str = it;
        }
    }
    cout<<str<<" "<<cnt<<endl;
}