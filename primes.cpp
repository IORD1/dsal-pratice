// Dr. Ajitkumar Shitole08:58
// You have a business with several offices; you want to lease phone lines to connect them up with each other;\
//  and the phone company charges different amounts of money to connect different pairs of cities. 
//  You want a set of lines that connects all your offices
// with a minimum total cost. Solve the problem by suggesting appropriate data structures.


// Prim's Algorithm in C++

#include<iostream>
using namespace std;

class Office{
    int n;
    int a[10][10];
    string office[10];
    public:
        void input();
        void display();
        void primes();
};


void Office::input(){
    cout<<"Enter the Number offices : ";cin>>n;
    cout<<"Enter the names of the offices "<<endl;
    for(int i=0; i<n; i++){
        cin>>office[i];
    }

    cout<<"Enter the cost to connect the offices : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i==j){
                a[i][j] = 0;
                continue;
            }
            cout<<"Enter the distance for "<<office[i]<<" and " <<office[j]<< " : ";
            cin>>a[i][j];
            a[j][i] = a[i][j];
        }
    }
}

void Office::display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<< "   ";
        }cout<<endl;
    }
}

void Office::primes(){
    int visit[n], mincost = 0, count = 1, minindex , cost = 0;
    for(int i=0; i<n ; i++){
        visit[i] = 0;
    }
    cout<<"Shortest Path : ";
    visit[0] = 1;
    cout<<office[0]<< " --> ";
    while(1){
        mincost = 10000;
        for(int i=0; i<n; i++){
            for(int j=0; j<n ; j++){
                 if(visit[i] == 1 && a[i][j] != 0 && a[i][j] < mincost && visit[j] == 0){
                     mincost = a[i][j];
                     minindex = j;
                 }
            }
        }

        visit[minindex] = 1;
        cout<<office[minindex]<<"-->";
        cost = cost+mincost;
        count++;

        if(count== n){
            break;  
        }
    }
    cout<<"Minimum cost : "<<cost<<endl;
}


int main()
{
    Office o1;
    int choice;
MENU:
    cout << "\n\nMINIMUM SPANNING TREE";
    cout << "\n1. Input data";
    cout << "\n2. Display data";
    cout << "\n3. Calculate minimum cost";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        o1.input();
        break;
    case 2:
        o1.display();
        break;
    case 3:
        o1.primes();
        break;
    case 4:
        return 0;
    default:
        cout << "\nInvalid choice.Try again!";
    }
    if (choice != 5)
        goto MENU;
    return 0;
}