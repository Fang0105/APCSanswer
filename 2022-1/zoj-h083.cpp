#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	set<string>se;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		se.insert(str);
	}
	int cnt = 0;
	for(string str:se){
		int len = str.size();
		for(int i=(len-1)/2+1;i<len;i++){
			bool isGood = true;
			for(int j=0;i+j<len;j++){
				if(str[j] != str[i+j]){
					isGood = false;
					break;
				}
			}
			if(isGood){
				string goal = str.substr(len-i,2*i-len);
				if(se.find(goal)!=se.end()){
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;








	return 0;
}
