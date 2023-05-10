#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb(X) push_back(X)
using namespace std;

signed main(){
    int k,q,r;
    cin>>k>>q>>r;
    vector<char>ve(k);
    for(int i=0;i<k;i++){
        cin>>ve[i];
    }
    char ans[r][q];
    for(int t=0;t<q;t++){
        vector<char>tem(k);
        for(int i=0;i<k;i++){
            int n;
            cin>>n;
            tem[n-1] = ve[i];
        }
        for(int i=0;i<r;i++){
            ans[i][t] = tem[i];
        }
        ve = tem;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<q;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    



    return 0;
}