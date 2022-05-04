#include <iostream>
using namespace std;

class Stack {
    public:
        int top = -1;
        int* S;
        
        Stack(int n){
            S = new int[n];
        }

        bool stackEmpty(){
            if(top == -1)
                return true;
            else return false;
        }

        void push(int x){
            top = top + 1;
            S[top] = x;
        }
        
        int pop(){
            if(stackEmpty())
                return -1; // "underflow"
            else{
                top = top - 1;
                return S[top + 1];
            }
        }

        // Printing
        void printStack(){
            int i = 0;
            while(i <= top){
                cout<<"S["<<i<<"] -> "<<S[i]<<endl;
                i++;
            }
        }
};

int main(){
    
    int n = 10; // sizeOfArray
    Stack S(n);

    // Loading
    for(int i=0; i<n; i++)
        S.push(i);

    S.printStack();
    cout<<"************ pop ************ "<<S.pop()<<endl;
    S.printStack();

    return 0;
}