#include<bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i=a ; i<(b) ; i++)

struct node{
    int data;
    node* next;
};

node* createNode(int x ){
    node* newNode = new node;
    newNode -> data = x;
    newNode -> next = nullptr;
    return newNode;

}

void display(vector<node*>& v){
    cout<<"the linked list is "<<endl;
        cout<<"_______________________________________________________________________________________________________"<<endl;
    rep(i,0,v.size()){
        
        cout<<"["<< v[i]->data <<"   |  "<<v[i]->next<<"]------";

    }


}

int main(){
    vector<node*> v;
    while(true){
        char choice;
        cout<<"do you want to add a new node at the end (y/n) :\t ";
        cin>> choice;
        if(choice=='n') break;

        int value;
        cout<<"enter value ";
        cin>>value;

        if(v.empty()){
            v.push_back(createNode(value));
        }
        else{
            node* prevNode = v[v.size() - 1];

            v.push_back(createNode(value));

            prevNode->next = v[v.size()-1];
        }


    }
    display(v);
    return 0;

}