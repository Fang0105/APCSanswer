#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    int n;
    cin>>n;
    int mxt = 0;
    int mxs = -100;
    int wrong = 0;
    for(int i=0;i<n;i++){
        int t,s;
        cin>>t>>s;
        if(s==-1){
            wrong++;
        }else if(s>mxs){
            mxs = s;
            mxt = t;
        }   
    }
    int score = mxs-n-wrong*2;
    if(score<0){
        score = 0;
    }
    cout<<score<<" "<<mxt<<endl;




    return 0;
}