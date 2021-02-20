#include<iostream>

using namespace std;

int cnt = 1;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST(){
        root = NULL;
    }

    Node* insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data < node->data) 
            node->left = insert(node->left, data);
        else if (data == node->data) {}
         else {
            node->right = insert(node->right, data);
        }
        return node;
    }
    
    int count(Node *root){
        if(root == NULL)
            cnt += 0; 
        if(root->left)
            count(root->left);
        if (root->right != NULL && root->left != NULL) 
            cnt++; 
    }
};

int main(){
    int x;
    BST *bst = new BST();
    while(cin >> x){
        if(x == 0)
            break;
        bst->root = bst->insert(bst->root, x);
    }
    cout << bst->count(bst->root);
}

