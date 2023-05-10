#include<bits/stdc++.h>
#define int unsigned long long
#define endl '\n'
using namespace std;

string str;
int idx=0;
int calculateStack(stack<char>*st){
    int ans = 1;
    int tem = 0;
    int straightPlus = 0;
    int k = 1;
    while(!st->empty()){
        char c = st->top();
        st->pop();
        if(c=='+'){
            straightPlus += tem;
            tem = 0;
            k = 1;
        }else if(c=='*'){
            straightPlus += tem;
            ans *= straightPlus;
            straightPlus = 0;
            tem = 0;
            k = 1;
        }else{
            tem += (c-'0')*(k);
            k*=10;
        }
    }
    return ans;
}

int maxminusmin(vector<int>ve){
    int mx = ve[0];
    int mn = ve[0];
    for(int i:ve){
        mx = max(mx,i);
        mn = min(mn,i);
    }
    return (mx-mn);
}

int f(){
    int ret;
    stack<char>st;
    vector<int>num;
    st.push('*');
    for(idx = idx+2;;){
        char c = str[idx];
        if((c>='0'&&c<='9') || (c=='+') || (c=='*')){
            st.push(c);
            idx++;
        }else if(c==','){
            num.push_back(calculateStack(&st));
            st.push('*');
            idx++;
        }else if(c=='f'){
            int ret = f();
            stringstream ss;
            ss << ret;
            string strret = ss.str();
            for(char p:strret){
                st.push(p);
            }
        }else if(c==')'){
            num.push_back(calculateStack(&st));
            idx++;
            break;
        }
    }
    return maxminusmin(num);
}

signed main(){
    cin>>str;
    stack<char>st;
    st.push('*');
    for(idx = 0;idx<str.size();){
        char c = str[idx];
        if( (c>='0'&&c<='9') || (c=='+') || (c=='*')){
            st.push(c);
            idx++;
        }else if(c=='f'){
            int ret = f();
            stringstream ss;
            ss << ret;
            string strret = ss.str();
            for(char p:strret){
                st.push(p);
            }
        }
    }
    int ans = calculateStack(&st);
    cout<<ans<<endl;

    return 0;
}