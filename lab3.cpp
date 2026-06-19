// stack push and pop operation using array

#include<iostream>

using namespace std;

class stack{
    int top;
    int size;
    int* arr;

    public:
         

        stack(int a){
            size = a;
            top = -1;
            arr = new int[size];
        }

        void push(int value){
            if( top >= size-1 ){
                cout << "stack overflow!!!"<< endl;
                return ;
            }
            else{
                arr[++top] = value;
            }
        }
        void pop(){
            if(top == -1 ){
                cout << "stack underflow!!!"<<endl;
                return ;
            }
            else {
                top--;
            }
            
        }

        void display (){
            if (top == -1){
                cout << "empty stack!!!"<<endl;
                return ;
            }
            else{
                for(int i=0 ; i<=top ; i++){
                    cout << arr[i] << "  ";
                }
            }
        }
        ~stack(){

            delete[] arr;
        }
};

int main(){
    int n;
    cout << "enter size of the stack : ";
    cin >> n;
    int arr[n];
    stack s(n) ;
    s.pop();
    s.push(4);
    s.display();
    return 0;
}