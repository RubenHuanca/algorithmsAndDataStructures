#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

template <class T>
class Node {
    public:
        T key;
        Node *next;
        Node *prev;
        Node(T myKey){
            key = myKey;
            // next = NULL;
            // prev = NULL;
        }
};

template <class T>
class List {

    Node<T> *head = NULL;

    public:
        
        void push_from(T myKey){
            Node<T> *n = new Node<T>(myKey);
            listInsert(n);
        }

        void listInsert(Node<T> *x){
            x->next = head;
            if(head != NULL){
                head->prev = x;
            }
            head = x;
            x->prev = NULL;
        }

        void printList(string file){
            for(Node<T> *tmp = head; tmp!=NULL; tmp = tmp->next){
                cout<<tmp->key<<endl;
            }
            graphList(file);
        }

        void freeList(){
            while (head != NULL){
                Node<T> *tmp = head->next;
                delete head;
                head = tmp;
            }
        }

        // Create and save the input.dot for the Graph
        void graphList(string file){
            ofstream myfile(file);
            if( myfile.is_open() ){
                myfile << "digraph { \n";
                for(Node<T> *tmp = head; tmp!=NULL; tmp = tmp->next){
                    if( tmp->next == NULL){
                        cout<<tmp->key<<" -> "<<"NULL"<<endl;
                        myfile<<tmp->key<<" -> "<<"NULL"<<" \n";                        
                    }else{
                        cout<<tmp->key<<" -> "<<(tmp->next)->key<<endl;
                        myfile<<tmp->key<<" -> "<<(tmp->next)->key<<" \n";
                    }
                }
                myfile << "}";
                myfile.close();
            }else{
                cout<<"Unable to open file. \n";
            }
        }

};

int main(){

    List<int> list;
    list.push_from(1);
    list.push_from(2);
    list.push_from(3);
    list.push_from(4);
    list.printList("input.dot");
    list.freeList();

    List<string> list2;
    list2.push_from("first");
    list2.push_from("second");
    list2.push_from("third");
    list2.push_from("fourth");    
    list2.printList("input2.dot");
    list2.freeList();
    
    // To generate a Graph from input.dot and input2.dot
    // system("dot -Tsvg input.dot > output.svg && dot -Tsvg input2.dot > output2.svg");
    return 0;
}