/*Read the marks obtained by students of second year 
in an online examination of particular subject.
 Find out maximum and minimum marks obtained in that subject. 
 Use heap data structure. Analyze the algorithm.*/
#include<iostream>
using namespace std;

class heap{
    int n;
    int *minheap,*maxheap;
    public:
    void get();
    void displayMin(){cout<<"Minimum marks are : "<<minheap[0]<<endl;}
    void displayMax(){cout<<"Maximum marks are : "<<maxheap[0]<<endl;}
    void upadjust(bool,int);
};

void heap::get(){
    cout<<"Enter number of students : ";cin>>n;
    int k;
    minheap = new int[n];
    maxheap = new int[n];
    cout<<"Enter marks of students : "<<endl;
    for(int i=0; i<n; i++){
        cin>>k;
        minheap[i] =k ;
        upadjust(0,i);
        maxheap[i] = k;
        upadjust(1,i);
    }
}

void heap::upadjust(bool m, int l){
    int s ;
    if(!m){//for max heap
        while(minheap[(l-1)/2] <minheap[l]){
            s = minheap[l];
            minheap[l] = minheap[(l-1)/2];
            minheap[(l-1)/2] = s;
            l = (l-1)/2;
            if(l ==-1){
                break;
            }
        }
    }else{
        while(maxheap[(l-1)/2] > maxheap[l]){
            s = maxheap[l];
            maxheap[l] = maxheap[(l-1)/2];
            maxheap[(l-1)/2] = s;
            l = (l-1)/2;
            if(l == -1){break;}
        }
    }
}

int main(){
    heap h;
    h.get();
    h.displayMin();
    h.displayMax();
    return 0;
}