#include<iostream>
#include<vector>
#define int long long
#define endl '\n'
using namespace std;

int n,k;
vector<int>wall;
vector<int>post;
bool canPost(int h){
	int width = 0;
	int success = 0;
	for(int &i:wall){
		if(success==k){
			return true;
		}
		if(i>=h){
			width++;
		}else{
			width = 0;
			continue;
		}
		if(post[success]==width){
			success++;
			width = 0;
		}
	}
	if(success>=k){
		return true;
	}else{
		return false;
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	int mx = 0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		mx = max(mx,a);
		wall.push_back(a);
	}
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		post.push_back(a);
	}
	int L=1,R=mx+5;
	while(R-L>5){
		int mid = (L+R)/2;
		if(canPost(mid)==true){
			L=mid;
		}else{
			R=mid-1;
		}
	}
	for(int i=R;i>=L;i--){
		if(canPost(i)){
			cout<<i<<endl;
			break;
		}
	}





	return 0;
}