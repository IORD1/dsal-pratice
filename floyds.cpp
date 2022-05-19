#include<iostream>
using namespace std;

void floyd(int b[][4]){
    int i,j,k;
    for(int k=0; k<4; k++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if((b[i][k] * b[k][j] != 0) && (i != j)){
                    if(b[i][k] + b[k][j] < b[i][j] || b[i][j] == 0){
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for(i=0 ; i<4; i++){
        cout<<"\nMinimum cost with respect to Node :"<<i<<endl;
        for(j=0 ; j<4; j++){
            cout<<b[i][j]<<"    ";
        }
    }
}

int main(){
    int b[4][4];
    cout<<"Enter the values in the matri"<<endl;
    for(int i=0; i<4; i++){
        cout<<"Enter the values for row " <<i<<endl;
        for(int j=0; j<4; j++){
            cin>>b[i][j];
        }
    }
    floyd(b);
    return 0;
}