// linked list insertion and deletion #include<bits/stdc++.h>

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

void insertion(int pos, vector<node*>& v){
    int value;
    cout<<"enter data in the node that is going to be inserted : \t  ";
    cin>>value;
    node* newNode = new node;
    newNode -> data = value;

    newNode->next = v[pos];  // assign the inserted nodes next pointer to its going to be  next node which is originally is at the position(pos)
    v[pos-1]->next=newNode; //  assigning the prev node next pointer after which a new node is inserted as the node address of the newNode
    //then new node is successfully inserted in the linked list 
    v.insert(v.begin()+pos,newNode); // new node is  inserted in the vector

    cout<<"successfully inserted ..."<<endl;
}

void deletion(int pos , vector<node*>& v){
    v[pos-1]->next = v[pos+1];
    v.erase(v.begin()+pos);
    cout<<"successfully deleted"<<endl;

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
    insertion(3,v);
    display(v);

    deletion(2,v);
    display(v);
    
    return 0;

}