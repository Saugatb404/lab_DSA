#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&v , int lb , int mid , int ub){
    int i=lb;
    int j = mid+1;
    int k;//for new list
    vector<int>temp;
    while(i<=mid && j<=ub){
        
        if(v[i]<v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }

         while(i <= mid){
        temp.push_back(v[i]);
        i++;
    }

    while(j <= ub){
        temp.push_back(v[j]);
        j++;
    }

    }
    for(int k = lb; k <= ub; k++){
        v[k] = temp[k - lb];
    }

}

void MergeSort(vector<int>&v , int lb , int ub){
    if(lb < ub){
        int mid = (lb+ub)/2;
        MergeSort(v, lb , mid);
        MergeSort(v,mid+1 , ub);
        Merge(v, lb , mid , ub );
    }
}

int main(){
    vector<int> v = {5, 8, 2, 9, 1, 7};
    int n = v.size();

    //sorting
    MergeSort(v,0,v.size()-1);

    for(int val : v){
        cout<<val<<" , ";
    }

return 0;
}