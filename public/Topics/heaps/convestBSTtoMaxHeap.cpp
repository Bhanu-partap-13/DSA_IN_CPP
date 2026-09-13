#include<iostream>
#include<vector>
using namespace std;

class Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
         left = right = NULL;
    }
};
void inorder(Node* root, vector<int>& res){
    if(root == NULL) return;
    //reverse inorder
    inorder(root->right, res);
    res.push_back(root->val);
    inorder(root->left, res);
}
int main(){
    //now we will make bST(Binary search tree)
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(12);
    Node* d = new Node(8);
    Node* e = new Node(4);
    Node* f = new Node(16);
    Node* g = new Node(2);
    a->left = b, a->right = c;
    b->left = d, b->right = e;
    c->left = f, c->right = g;
    vector<int> res; //reverse inorder
    inorder(a, res);

    for(int i : res){
        cout<<i<<" ";
    }
    cout << endl;
}
