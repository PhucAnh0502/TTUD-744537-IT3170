#include<iostream>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(NULL), right(NULL) {}
};

Node* insert(Node *root, int key){
    if(root == NULL) return new Node(key);
    if(key < root->key){
        root->left = insert(root->left, key);
    } else if(key > root->key){
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrder(Node* root){
    if(root != NULL){
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    Node* root = NULL;
    int key;
    string cmd;
    while(cin >> cmd){
        if(cmd == "#") break;
        if(cmd == "insert"){
            cin >> key;
            root = insert(root, key);
        }
    }
    preOrder(root);
    return 0;
}
