#include<iostream>
using namespace std;

bool isValid(string s){
    stack<int>st;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(st.size() == 0) return false;
            else st.pop();
        }
    }
    if(st.size() == 0) return true;
    else return false;
}

int main(){
    string s;
    cin>>s;
    if(isValid(s)){
        cout<<"Valid";
    }
    else{
        cout<<"Invalid";
    }
    return 0;
}