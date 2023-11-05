#include <iostream>
using namespace std;
struct node{
    int Id;
    int marks;
    struct Node *next;
} *start=NULL;
void insertionaAtStart(){
    struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));
    
}
void deleteNode(int *start){
    int deleteId;
    int *prev;
    int *curr;
    cout<<"Enter the number you want to delete :"<<endl;
    cin>>deleteId;
    struct node* curr=start;
    if (deleteId==start){
        
    }else{
        curr=start->next;
        while(curr !=null){
            if(deleteId==curr){

            }else{
                prev=curr;+
                  curr=start->next;
            }
        }
    }


}

int main(){
    // struct Node 

    return 0;
}
