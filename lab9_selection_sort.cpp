#include<bits/stdc++.h>

using namespace std;

void SelectionSort(vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        int minpos = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minpos]) {
                minpos = j;
            }
        }

        if (minpos != i) {
            swap(v[i], v[minpos]);
        }
    }
    for(int x : v){
        cout<<" "<<x<<" ";
    }
}

int main(){
    vector<int> v = {2,4,1,3,0,10,80, 54,27,100,60,99,45,90};
    SelectionSort(v);

    return 0;
}