// Ss - feb 3
//input - 50, 15, 62, 5, 20, 58, 91, 3, 8, 37, 60, 24

// b 6 Beginning with an empty binary search tree, Construct binary search tree by inserting the
// values in the order given. After constructing a binary tree -
// i. Insert new node
// ii. Find number of nodes in longest path from root
// iii. Minimum data value found in the tree
// iv. Change a tree so that the roles of the left and right pointers are swapped at every
// node
// v. Search a value 

#include<iostream>
#include<queue>
using namespace std;

class tree{
    struct node{
        int data;
        node *left = NULL;
        node *right = NULL;
    }*root;

    public:
    tree(){
        root = NULL;
    }

    node* ROOT(){
        return root;
    }

    void insert(){
        node *temp, *curr, *parent;
        temp = new node;
        cout<<"Enter the data : ";
        cin>>temp->data;
        parent = root;
        curr = root;

        if(root == NULL){
            root = temp;
        }else{
            while(curr){
                if(temp->data > curr->data){
                    parent = curr;
                    curr = curr->right;
                }else{
                    parent = curr;
                    curr = curr->left;
                }
            }

            if(temp->data > parent->data){
                parent->right  =  temp;
            }else{
                parent->left = temp;
            }
        }
    }

    int height(node *temp){
        int lheight, rheight;
        if(temp == NULL){
             return 0;
        }
        lheight = height(temp->left);
        rheight = height(temp->right);
        if(lheight > rheight){
            return lheight + 1;
        }else{
            return rheight + 1;
        }
    }

    void search(){
        node* temp;
        int tar,flag = 0;
        cout<<"Enter the target: ";cin>>tar;
        temp = root;

        while(temp != NULL){
            if(tar > temp->data){
                temp = temp->right;
            }else if(tar == temp->data){
                cout<<"data found "<<endl;
                flag = 1;
                break;
            }else{
                temp= temp->left;
            }
        }

        if(!flag){
            cout<<"data not found"<<endl;
        }

    }

    void minimumintree(){
        node *temp;
        temp = root;
        if(temp == NULL){
            cout<<"Not elements in tree"<<endl;
        }else{
            while(temp->left != NULL){
                temp = temp->left;
            }
            cout<<"Minimum element in tree : " <<temp->data<<endl;
        }
    }

    int logestlength(){
        node* temp;
        temp = root;
        int lheight, rheight;
        if(temp == NULL){
            return 0;
        }else{
             lheight = height(temp->left);
             rheight = height(temp->right);
             
             if(lheight> rheight){
                 return lheight +1;
             }else{
                 return rheight+1;
             }
        }
    }

    void switchnode(){
        if(root == NULL){
            return ;
        }else{
            queue<node *> q;
            q.push(root);
            while(!q.empty()){
                int node_count = q.size();
                while(node_count > 0){
                    node *temp = q.front();
                    cout<<temp->data<< " ";
                    q.pop();
                    if(temp->left != NULL){
                        q.push(temp->left);
                    }
                    if(temp->right != NULL){
                        q.push(temp->right);
                    }
                    node_count--;
                }
                cout<<endl;
            }
        }
    }
};



int main(){
        tree t;

        cout << "---------MENU---------" << endl;
        cout << "Enter 1 to INSERT Number" << endl;
        cout << "Enter 2 to Show Height of tree" << endl;
        cout << "Enter 3 to SEARCH tree" << endl;
        cout << "Enter 4 to know smallest number in tree" << endl;
        cout << "Enter 5 to know longest path from root "<< endl;
        cout << "Enter 6 to switch the left and right nodes "<<endl;
        cout << "Enter 7 to EXIT"<<endl;

        while(true){
            int opt;
            cout<<"---------------------------"<<endl;
            cout<<">>>>>Enter You Choice: ";
            cin>>opt;

            if(opt == 1){
                t.insert();
            }else if(opt == 2){
                cout<<"Height of tree is : "<<t.height(t.ROOT())<<endl;
            }else if(opt == 3){
                t.search();
            }else if(opt == 4){
                t.minimumintree();
            }else if(opt == 5){
                cout<<"longest path from root is : "<<t.logestlength()<<endl;
            }else if(opt == 6){
                t.switchnode();
            }else if(opt == 7){
                cout<<"------------------------END---------------------"<<endl;
                break;
            }else{
                cout<<"Entered a Valid option"<<endl;
            }
        }

    return 0;
}