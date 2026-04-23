// #include<iostream>
// using namespace std;

// bool isValid(string s){
//     stack<int>st;
//     int n = s.size();
//     for(int i=0; i<n; i++){
//         if(s[i] == '('){
//             st.push(i);
//         }
//         else{
//             if(st.size() == 0) return false;
//             else st.pop();
//         }
//     }
//     if(st.size() == 0) return true;
//     else return false;
// }

// int main(){
//     string s;
//     cin>>s;
//     if(isValid(s)){
//         cout<<"Valid";
//     }
//     else{
//         cout<<"Invalid";
//     }
//     return 0;
// }

//Multiple braces

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<int> st;
    int n = s.size();
    if(n==1) return false;
    for(int i=0; i<n; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.size()== 0) return false;
            else if((st.top() == '(' &&  s[i] == ')') || (st.top() == '[' &&  s[i] == ']') || 
            (st.top() == '{' &&  s[i] == '}')) st.pop();
        else{
            return false;
        }
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