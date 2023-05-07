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

        node* createNode(int myKey){
            node *n = (node*) malloc(sizeof(node)); // in C++, we need to cast the return of malloc()
            n->key = myKey;
            n->next = NULL;
            n->prev = NULL;
            return n;
        }
};

int main(){
    List list;

    list.listInsert(list.createNode(1));
    list.listInsert(list.createNode(2));
    list.listInsert(list.createNode(3));
    list.listInsert(list.createNode(4));
   
    list.printList();
    return 0;
}