#include <iostream>
#include <stdlib.h>
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

        void listInsert(node *x){
            x->next = head;
            if(head != NULL){
                head->prev = x;
            }
            head = x;
            x->prev = NULL;
        }
        
        void push_from(int myKey){
            node *n = (node*) malloc(sizeof(node)); // cast return of malloc()
            n->key = myKey;
            n->next = NULL;
            n->prev = NULL;            

            listInsert(n);
        }

        void printList(){
            for(node *tmp = head; tmp!=NULL; tmp = tmp->next){
                cout<<tmp->key<<endl;
            }
            
            freeList();
        }

        void freeList(){
            while (head != NULL){
                node *tmp = head->next;
                free(head);
                head = tmp;
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
    return 0;
}