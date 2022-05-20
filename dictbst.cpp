// A Dictionary stores keywords and its meanings.
//  Provide facility for adding new keywords, deleting keywords, updating values of any entry.
//  Provide facility to display whole data sorted in ascending/ Descending order.
//  Also find how many maximum comparisons may require for finding any keyword.
//   Use Binary Search Tree for implementation.

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct node{
    char word[20];
    char meaning[40];
    node *left, *right;
    node(char *word,char *meaning){
        strcpy(this->word,word);
        strcpy(this->meaning, meaning);
        this->left = this->right = NULL;

    }
};


node* insert(node *root, char *word , char *mean){
    if(root == NULL){
        return new node(word,mean);
    }else{
        if(strcmp(root->word,word) <= 0){
            root->left = insert(root->left, word , mean);
        }else{
            root->right = insert(root->right, word, mean);
        }
    }

    return root;
}


void preorder(node *root){
    if(root){
        cout<<root->word<<" => " <<root->meaning<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root){
    if(root){
        inorder(root->left);
        cout<< root->word << " => "<<root->meaning<<endl;
        inorder(root->right);
    }
}

void postorder(node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->word<<" => "<<root->meaning<<endl;
    }
}

void search(node *root, char *word){
    if(root == NULL){
        cout<<"Not Found " <<endl;
        return;
    }
    if(strcmp(root->word,word) == 0){
        cout<<"Meaning is : "<<root->meaning<<endl;
    }else if(strcmp(root->word,word)< 0){
        search(root->left,word);
    }else{
        search(root->right,word);
    }

}

int main(){
    node *root = NULL;
    cout<<"Inserting"<<endl;
    while(true){
        char a[20];
        char b[20];
        cout<<"Enter word : ";cin>>a;
        cout<<"Enter meaning : ";cin>>b;
        root = insert(root,a,b);
        cout<<"continue : ";
        int opt ; cin>>opt;
        if(opt == 0){
            break;
        }

    }
    cout<<">>>>>>>>perorder"<<endl;
    preorder(root);
    cout<<">>>>>>>>Inorder"<<endl;
    inorder(root);
    cout<<">>>>>>>>postorder"<<endl;
    postorder(root);
    cout<<">>>>>>>>Search"<<endl;
    char s[20];
    while(true){
    cout<<">>>>>>>>Enter what to seach : ";cin>>s;
    search(root,s);
    }
    

    return 0;
}