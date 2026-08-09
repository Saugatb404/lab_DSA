#include<bits/stdc++.h>

using namespace std;



int Partation(vector<int>& v, int lb, int ub){

    int pivot = v[lb];
    int start = lb;
    int end = ub;

    while(start < end){

        while(start <= ub && v[start] <= pivot)
            start++;

        while(v[end] > pivot)
            end--;

        if(start < end)
            swap(v[start], v[end]);
    }

    swap(v[lb], v[end]);

    return end;
}

void QuickSort(vector<int>&v, int lb , int ub){
    if(lb<ub){
        int ploc = Partation(v,lb,ub);
        QuickSort(v,lb,ploc-1);
        QuickSort(v,ploc+1,ub);
    }
}


int main(){
    vector<int> v = {5, 8, 2, 9, 1, 7,10, 4, 17, 12, 1, 6, 4};
    int n = v.size();

    //sorting
    QuickSort(v,0,v.size()-1);


    

    
    
    for(int val : v){
        cout<<val<<" , ";
    }

return 0;
}