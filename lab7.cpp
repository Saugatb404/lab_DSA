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

void insertion(int pos, vector<node*>& v) {

    if (pos < 0 || pos > (int)v.size()) {
        cout << "Invalid position" << endl;
        return;
    }

    int value;
    cout << "Enter data in the node that is going to be inserted : ";
    cin >> value;

    node* newNode = createNode(value);

    
    if (v.empty()) {
        v.push_back(newNode);
        cout << "Successfully inserted" << endl;
        return;
    }

    //insert at beginning
    if (pos == 0) {
        newNode->next = v[0];
        v.insert(v.begin(), newNode);
        cout << "Successfully inserted" << endl;
        return;
    }

    //insert at end
    if (pos == (int)v.size()) {
        v[pos - 1]->next = newNode;
        v.push_back(newNode);
        cout << "Successfully inserted" << endl;
        return;
    }

    //insert in middle
    newNode->next = v[pos];
    v[pos - 1]->next = newNode;
    v.insert(v.begin() + pos, newNode);

    cout << "Successfully inserted" << endl;
}

void deletion(int pos, vector<node*>& v) {

    // Empty list
    if (v.empty()) {
        cout << "Deletion not possible. List is empty.\n";
        return;
    }

    // Invalid position
    if (pos < 0 || pos >= (int)v.size()) {
        cout << "Deletion not possible. Invalid position.\n";
        return;
    }

    // Only one node
    if (v.size() == 1) {
        delete v[0];
        v.clear();
        cout << "Successfully deleted.\n";
        return;
    }

    // Delete first node
    if (pos == 0) {
        delete v[0];
        v.erase(v.begin());

        if (!v.empty())
            v[0]->next = (v.size() > 1) ? v[1] : nullptr;

        cout << "Successfully deleted.\n";
        return;
    }

    // Delete last node
    if (pos == (int)v.size() - 1) {
        v[pos - 1]->next = nullptr;
        delete v[pos];
        v.erase(v.begin() + pos);

        cout << "Successfully deleted.\n";
        return;
    }

    // Delete middle node
    v[pos - 1]->next = v[pos + 1];
    delete v[pos];
    v.erase(v.begin() + pos);

    cout << "Successfully deleted.\n";
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