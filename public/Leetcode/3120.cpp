//we have to check whether the lowercase and uppercase both of the same alphabet are present or not if yes then count will increase
#include<bits/stdc++.h>
using namespace std;

int countVowel(string& word){
    set<char> lower, upper;

    for(char c : word){
        if(islower(c)){
            lower.insert(c);
        }
        else {
            upper.insert(islower(c));
        }
        int count = 0;
        for(char c : lower){
            if(upper.count(c)){
                count++;
            }
        }
        return count;
    }
}

int main(){
    string word = "aaAbBcC";
    cout << countVowel(word) << endl;
}