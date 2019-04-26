#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int cal(const vector<int> &seq){
    vector<int> ans;
    for (int x : seq){
        if(ans.empty() || ans.back() < x){
            ans.push_back(x);
        }
    }
    return ans.size();
}
int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int n;
        scanf("%d",&n);
        int a[1000005];
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for(int l = 0 ; l < n ; l++){
            for(int r = l ; r < n ; r++ ){
                ans = max (ans, cal(vector<int>(a+l, a+r+1)));
            }
        }
        printf("%d\n", ans);
    }
}
/*

Bob is trying to solve the [longest increasing subsequence (LIS) problem](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) which is one of the most famous problem in the field of competitive programming. Unfortunately, he wrongly designed the algorithm to solve LIS. Therefore, he constantly get a wrong answer (WA) from the online judge system. He is very close to fail the competitive programming course. 

Last night, you accidentally got the password of the TA account. You are Bob's best friend, so you worried about him. You are afraid that Bob's will not get enough points to pass. Thus, you want to change the judge results of Bob's submissions by replacing the answer files of the test data. 

As the first step, you downloaded the input files. Then, you must understand Bob's algorithm to generate the corresponding outputs of his program.  It is so crucial, because you must upload Bob's outputs to make his program accepted (AC). 

You pretended to discuss the LIS problem with Bob. He said that he was using a greedy strategy to solve LIS. For the sequence $s_1,s_2,\ldots,s_n$, his algorithm first selects the first element $s_1$ as the candidate answer subsequence, and then his algorithm visits the rest elements in sequence by ascending order of indices. If the candidate answer sequence is empty or the element $s_i$ is no less than the last element in the candidate answer subsequence, the algorithm appends this element to the candidate answer subsequence. Otherwise, it keeps removing removing the last element of the candidate answer subsequence until the subsequence is empty or the last element of the subsequence is less than $s_i$. After $s_i$ is appended, update the answer subsequence (initially empty) if the candidate is longer.

Please write a program to compute the length of sequence output by the Bob's algorithm.

Note: Bob's algorithm is wrong if the input sequence is $2, 3, 1, 4$.

/*
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
}*/