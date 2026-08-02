#include<bits/stdc++.h>

using namespace std;


// linear search  O(n)
void LinearSearch(vector<int>v , int num){  
    for(int i= 0 ; i< v.size() ; i++){
        if(v[i] == num){
            cout<<"  "<<num<<" is found using Linear Search in the index "<<i<<endl;
            return;
        }
    }
    cout<<"not found!!"<<endl;
    return;

}


// Binary search for the sorted int  O(nlogn) + O(logn) = O(nlogn)
void BinarySearch(vector<int> v , int num){
    sort(v.begin(), v.end()); // O(n log n)
    int low = 0;
    int high = v.size()-1;
    //O(logn)
    while(low <= high){
        int mid = low + floor(high-low/2);
        if(v[mid]==num){
            cout<<"  "<<num<<" is found using Binary Search in the index "<<mid<<endl;
            return;
        }
        if(v[mid]<num) high=mid;
        else low = mid ; 
    }
    cout<<"not found!!"<<endl;
    return;
    

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