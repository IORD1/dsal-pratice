// Dr. Ajitkumar Shitole08:54
// Write a program in C++ to implement dictionary using hashing.
// Use separate chaining and perform 
// insertion, display, search and deletion operations.	

#include<iostream>
#include<list>
using namespace std;

class hashtable{
    private:
        list<int> *table;
    public:
        hashtable(){
            table = new list<int>[10];
        }

        void insert(int d);
        void print();
        void search(int tar);

};

void hashtable::insert(int d){
    int loc = d%10;
    table[loc].push_back(d);
}

void hashtable::print(){
    for(int i=0; i<10; i++){
        cout<<"|"<<i<<"| ";
        for(auto j: table[i]){
            cout<<" -> |"<<j<<" | ";
        }cout<<endl;
    }
}

void hashtable::search(int tar){
    int flag = 0;
    for(int i=0; i<10 ;i++){
        for(auto j: table[i]){
            if(tar == j){
                cout<<"Entered Number found on index : "<<i<<endl;
                flag = 1;
            }
        }
    }

    if(!flag){
        cout<<"Entered Number not found "<<endl;
    }
}


int main(){
    hashtable ht;

    system("clear");
    cout<<"---------MENU---------"<<endl;
    cout<<"Enter 1 to INSERT Number"<<endl;
    cout<<"Enter 2 to DISPLAY Hast Table"<<endl;
    cout<<"Enter 3 to SEARCH Hash Table"<<endl;
    cout<<"Enter 4 to EXIT"<<endl;
    while(true){
        int opt;
        cout<<"---------------------------"<<endl;
        cout<<">>>>>Enter You Choice: ";
        cin>>opt;
        if(opt == 1){
            cout<<"Enter the No. : ";
            int en;
            cin>>en;
            ht.insert(en);
        }else if(opt == 2){
            ht.print();
        }else if(opt == 3){
            cout<<"Enter the No. : ";
            int sn;
            cin>>sn;
            ht.search(sn);
        }else if(opt == 4){
            break;
        }else{
            cout<<"Entered a Valid option"<<endl;
        }
    }
    return 0;
}

