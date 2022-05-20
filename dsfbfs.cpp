// Represent a given graph using adjacency matrix/list
//  to perform DFS and using adjacency list to perform BFS.
//   Use the map of the area around the college as the graph.
//    Identify the prominent land marks as nodes and perform DFS and BFS on that.

#include<iostream>
using namespace std;

int main(){
    int cost[10][10]={0},visit[10],visited[10],qu[10],rear,front,i,j;
    cout<<"Enter number of vertice : ";int ver;cin>>ver;
    cout<<"ENter number of edges : ";int edg; cin>>edg;

    cout<<"EDGES : "<<endl;
    for(int k=1; k<=edg; k++){
        cin>>i>>j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    //display
    cout<<"Adjancey matrixk is : "<<endl;
    for(int i=0; i<ver; i++){
        for(int j=0; j<ver;j++){
            cout<<" "<<cost[i][j];
        }cout<<endl;
    }

    cout<<"Enter the starting vertex : ";int v;cin>>v;
    cout<<"BFS is : "<<endl;
    cout<<v<<" ";
    visited[v] = 1;
    int k = 1;
    while(k<ver){
        for(int j=1;j<=ver; j++){
            if(cost[v][j] != 0 && visit[j] != 1 && visited[j] != 1){
                visit[j] = 1;
                qu[rear++] = j;
            }
        }

        v = qu[front++];
        cout<<v<<" ";
        visit[v] = 0;
        visited[v] = 1;
        k++;
    }

    cout<<endl;
    //BFS startes here
    int visited1[10],visit1[10],stk[10],top;
    cout<<"Enter starting vertiex : ";cin>>v;
    cout<<v<<" ";
    visited1[v] = 1;
    k = 1;
    while(k<ver){
        for(int j=ver; j>=1 ; j--){
            if(cost[v][j] != 0 && visit1[j] != 1 && visited1[j] != 1){
                visit1[j] = 1;
                stk[top] = j;
                top++;
            }
        }
        v = stk[--top];
        cout<<v<<" ";
        k++;
        visit1[v] = 0;
        visited1[v] = 1;
    }



    return 0;
}