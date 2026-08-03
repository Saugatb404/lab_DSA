#include<bits/stdc++.h>

using namespace std;
  
// Insertion sort O(n^2)
void InsertionSort(vector<int>&v){

    for(int i = 1 ; i<v.size() ; i++){
        int curr = v[i];
        int j = i-1;
        while( v[j] > curr && j>=0){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = curr;

    }

    cout<<"   after the insertion sorting the array of data is :"<<endl;
    for(int x : v){
        cout<<x<<" , ";
    }
    cout<<endl;
    return;

}


// linear search  O(n)
void LinearSearch(vector<int>&v , int num){  
    for(int i= 0 ; i< v.size() ; i++){
        if(v[i] == num){
            cout<<"  "<<num<<" is found using Linear Search"<<endl;
            return;
        }
    }
    cout<<"not found!!"<<endl;
    return;

}


// Binary search for the sorted int  O(nlogn) + O(logn) = O(nlogn)
void BinarySearch(vector<int>&v, int num)
{
    InsertionSort(v);

    int low = 0;
    int high = v.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] == num)
        {
            cout<<"  "<< num << " is found using Binary Search in the sorted array" << endl;
            return;
        }

        if (v[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Not found!!" << endl;
}

int main(){
    vector<int> v = {2,4,1,3,0,10,80, 54,27,100,60,99,45,90};
    cout << "original data array of int  : "<<endl;
    for(int x : v){
        cout<<" "<<x;
    }
    cout<<endl;


    int num ;
    cout<<"enter the number to search : ";
    cin>>num;
    LinearSearch(v,num);
    BinarySearch(v,num);

    return 0;
    
}