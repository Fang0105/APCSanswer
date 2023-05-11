#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main(){
    IOS
	int n,m;
	cin>>n>>m;
	int tot = 0;
	vector<int>ve;
	ve.push_back(tot);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		tot+=a;
		ve.push_back(tot);
	}
	int loc = 0;
	while(m--){
		int p;
		cin>>p;
		int tem = lower_bound(ve.begin(),ve.end(),(p+ve[loc])%tot)-ve.begin();
		loc = tem;
	}
	cout<<loc%n<<endl;






	return 0;
}