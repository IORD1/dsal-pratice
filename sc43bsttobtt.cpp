// Convert given binary tree into threaded binary tree.
// Analyze time and space complexity
// of the algorithm. 

#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    node *left, *right;
    bool isthreaded;
};


node *newNode(int key){
    node *temp = new node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

void populateq(node* root , queue<node *>*q){
    if(root == NULL){
        return;
    }
    if(root->left){
        populateq(root->left,q);
    }
    q->push(root);
    if(root->right){
        populateq(root->right,q);
    }
}

void createthreadutil(node* root,queue<node *>*q){
    if(root == NULL){
        return;
    }
    if(root->left){
        createthreadutil(root->left,q);
    }
    q->pop();
    if(root->right){
        createthreadutil(root->right,q);
    }else{
        root->right = q->front();
        root->isthreaded = true;
    }
}

void createthread(node* root){
    queue<node *>q;
    populateq(root, &q);
    createthreadutil(root,&q);
}

node *leftmost(node* root){
    while(root!= NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

void inorderbtt(node* root){
    if(root == NULL){
        return;
    }

    node* curr = leftmost(root);

    while(curr != NULL){
        cout<<curr->data<<" ";
        if(curr->isthreaded){
            curr =curr->right;
        }else{
            curr = leftmost(curr->right);
        }
    }
}

void inorder(node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){

	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
    cout<<"Inorder "<<endl;
    inorder(root);
    cout<<"converted to threaded"<<endl;
    createthread(root);
    cout<<"Inorder of btt"<<endl;
    inorderbtt(root);
    return 0;
}