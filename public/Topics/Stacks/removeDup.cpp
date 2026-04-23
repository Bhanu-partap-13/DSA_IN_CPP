
#include<bits/stdc++.h>
using namespace std;

string removeDup(string s){
    stack<char>st;
    st.push(s[0]);
    for(int i=0; i<s.length(); i++){
        if(s[i] != st.top()) st.push(s[i]);
    }
    s="";
    while(st.size()>0){
        s+=st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string s="aaaafgggghhhheeddffdd";
    cout<<s<<endl;
    s = removeDup(s);
    cout<<s<<endl;

}