#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

typedef struct node
{
    int key;
    struct node *next;
    struct node *prev;
}
node;

class List {

    node *head = NULL;

    public:
        
        void push_from(int myKey){
            node *n = (node*) malloc(sizeof(node)); // cast return of malloc()
            n->key = myKey;
            n->next = NULL;
            n->prev = NULL;            

            listInsert(n);
        }

        void listInsert(node *x){
            x->next = head;
            if(head != NULL){
                head->prev = x;
            }
            head = x;
            x->prev = NULL;
        }

        void printList(){
            for(node *tmp = head; tmp!=NULL; tmp = tmp->next){
                cout<<tmp->key<<endl;
            }
            graphList();
        }

        void freeList(){
            while (head != NULL){
                node *tmp = head->next;
                free(head);
                head = tmp;
            }
        }

        // Create and save the input.dot file for the Graph
        void graphList(){
            ofstream myfile("input.dot");            
            if( myfile.is_open() ){
                myfile << "digraph {\n";
                for(node *tmp = head; tmp!=NULL; tmp = tmp->next){                    
                    if( tmp->next == NULL){
                        cout<<tmp->key<<" -> "<<"NULL"<<endl;
                        myfile<<tmp->key<<" -> "<<"NULL"<<" \n";                        
                    }else{
                        cout<<tmp->key<<" -> "<<(tmp->next)->key<<endl;
                        myfile<<tmp->key<<" -> "<<(tmp->next)->key<<" \n";
                    }
                }
                myfile << "} \n";
                myfile.close();
            }else{
                cout<<"Unable to open file. \n";
            }
        }

};

int main(){
    List list;

    list.push_from(1);
    list.push_from(2);
    list.push_from(3);
    list.push_from(4);

    list.printList();
    list.freeList();
    return 0;
}