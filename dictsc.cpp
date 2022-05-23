#include <iostream>
using namespace std;
#define MAX 10

class hashing{
    struct node{
        string word;
        string mean;
        node* next;
        node*prev;
    };
    node *hash_t[MAX];
    node *head;
    int key;

    public:
        hashing(){
            for(int i=0; i<MAX; i++){
                hash_t[i] = NULL;
            }
        }

        int hash_func(string);
        void insert();
        void display();
        void search();
        void deleteit();
};

int hashing::hash_func(string s){
    int asscii = static_cast<int>(s[0]);
    return asscii%10;
}

void hashing::insert(){
    node* temp, *t;
    temp = new node();
    cout<<"Enter the word : ";
    cin>>temp->word;
    cout<<"Enter it's meaning : ";
    cin>>temp->mean;
    temp->prev = temp->next = NULL;
    int hv = hash_func(temp->word);
    t = hash_t[hv];

    //algo
    if(t == NULL){
        head = temp;
        hash_t[hv] = head;
    }else{
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
        temp->prev = t;
    }
    
}

void hashing::display(){
    node *t;
    cout<<"Index    "<<"word "<<endl;
    for(int i=0; i<MAX; i++){
        cout<<i<<"        ";
        t = hash_t[i];
        while(t != NULL){
            cout<<t->word<<"-->";
            t = t->next;
        }cout<<endl;
    }
}

void hashing::search(){
    node *t;
    string tar;
    cout<<"Enter the word to search: ";cin>>tar;
    cout<<"Searchig : "<<tar<<endl;

    int flag = 0;
    int loc = hash_func(tar);
    t = hash_t[loc];
        while(t != NULL){
            if(t->word == tar){
                cout<<"Word Found on index : "<<loc<<endl;
                cout<<"Meaning : "<<t->mean<<endl;
                flag = 1;
                break;
            }
            t = t->next;
        }

    if(!flag){
        cout<<"word not found "<<endl;
    }
}

void hashing::deleteit(){
    node*t;
    string tar;
    cout<<"Enter word to delete: ";cin>>tar;
    int flag = 0;
    int index = hash_func(tar);
    t = hash_t[index];
    while(t != NULL){
        if(t->word == tar){
            flag = 1;
            t->prev->next = t->next;
            delete t;
            break;
        }
        t = t->next;
    }
    if(flag){
        cout<<"Word successfully deleted"<<endl;
    }else{
        cout<<"word not found "<<endl;
    }
}

void menu()
{
    cout<<endl;
    cout<<" 1. Insert an word in hash table"<<endl;
    cout<<" 2. Display the hash table \n";
    cout<<" 3. Search an element \n 4. Delete a word \n";
    cout<<" 4. EXIT"<<endl;
    cout<<endl;
}


int main()
{
    int choice;
    hashing h1;
    menu();
    do
    {   cout<<"-----------------"<<endl;
        cout<<"Enter your choice \n";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
            {
                h1.insert();
                break;
            }
            case 2:
            {
                h1.display();
                break;
            }
            case 3:
            {
                h1.search();
                break;
            }
            case 4:
            {
                h1.deleteit();
                break;
            }
            case 5:
            {
                break;
            }
        }
    }while(choice != 5);
}