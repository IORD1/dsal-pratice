#include<iostream>
#include<cstring>
using namespace std;
#define MAX 50
#define SIZE 20

struct node{
    public:
    char word[SIZE], mean[MAX];
    node*left, *right;
    int iht;
};

class tree{
    public:
    node* root;
    
    tree(){
        root = NULL;
    }

    int height(node*);
    int bf(node*);
    node* insert(node* root, char newword[SIZE], char newmean[MAX]);
    node* leftrotate(node*);
    node* rightrotate(node*);
    node* LL(node*);
    node* LR(node*);
    node* RR(node*);
    node* RL(node*);
    void inorder(node*);
};

int tree::height(node* root){
    if(root== NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }else{
        int lh,rh;
        lh = lh+height(root->left);
        rh = rh+height(root->right);
        if(lh>rh){
            return lh+1;
        }
        return rh+1;
    }

}
int tree::bf(node* root){
    int lh,rh;
    if(root == NULL){
        return 0;
    }else{
        if(root->left == NULL){
            lh = 0;
        }else{
            lh = root->left->iht;
        }
        if(root->right == NULL){
            rh = 0;
        }else{
            rh = root->right->iht;
        }
        return lh-rh;
    }
}


node *tree::insert(node* root, char newword[SIZE], char newmean[MAX]){
    if(root == NULL){
        root = new node;
        root->left = NULL;
        root->right = NULL;
        strcpy(root->word,newword);
        strcpy(root->mean, newmean);
        return root;
    }else if(strcmp(root->word,newword) != 0){
            if(strcmp(root->word,newword) > 0){
                root->left = insert(root->left, newword, newmean);
                if(bf(root->left) == 2){
                    if(strcmp(root->left->word, newword) > 0){
                        root = LL(root);
                    }else{
                        root = LR(root);
                    }
                }
            }else if(strcmp(root->word, newword) < 0){
                root->right = insert(root->right, newword, newmean);
                if(bf(root->right) == -2){
                    if(strcmp(root->right->word, newword) > 0){
                        root = RR(root);
                    }else{
                        root = RL(root);
                    }
                }
            }
        }else{
            cout<<"redudant avl node"<<endl;
        }
    root->iht = height(root);
    return root;
}

node* tree::leftrotate(node* curr){
    node* temp ;
    temp = curr->right;
    curr->right = temp->left;
    temp->left = curr;
    temp->iht = height(temp);
    return temp;
}

node* tree::rightrotate(node* curr){
    node* temp;
    temp = curr->left;
    curr->left = temp->right;
    temp->right = curr;
    temp->iht = height(temp);
    return temp;
}

node* tree::LL(node* curr){
    curr = rightrotate(curr);
    return curr;
}

node* tree::RR(node* curr){
    curr = leftrotate(curr);
    return curr;
}

node* tree::LR(node* curr){
    curr->left = leftrotate(curr->left);
    curr = rightrotate(curr);
    return curr;
}

node* tree::RL(node* curr){
    curr->right = rightrotate(curr->right);
    curr = leftrotate(curr);
    return curr;
}

void tree::inorder(node* curr){
    if(curr != NULL){
        inorder(curr->left);
        cout<<"\n\t"<<curr->word<<"\t"<<curr->mean;
        inorder(curr->right);
    }
}


int main(){
    tree t;
    char inword[SIZE], inmean[MAX];
    for(int i=0; i<5; i++){
        cout<<"ENter word : " ;
        cin>>inword;
        cout<<"ENter mean: ";cin>>inmean;
        t.root = t.insert(t.root,inword,inmean);
    }

    cout<<"\n\tWORD\tMEANING";
	t.inorder(t.root);

    return 0;
}