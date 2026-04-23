// Date: 4/22/2026
// Name Mr.lad
// Program generates 200 random integers in range [0,49]
// stores them in a linked list,
// sorts them using bubble sort,
// prints them in rows of 5,
// removes all multiple data nodes from the list,
// and prints again

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Declaration of the list struct type
//Stores an integer data value and a pointer 
// to the next and former node in the list
typedef struct double_linked_list{
    int data ;
     struct double_linked_list* FORMER ; 
     struct double_linked_list* NEXT;
    }d_list;

    
//Name: create_list
//Input: integer value
//Output: pointer to new list node
//Description: 
// Allocates and initializes a new node
d_list* create_list(int d){
    d_list* head = malloc(sizeof(d_list));
    head -> data = d;
    head -> FORMER = NULL;
    head -> NEXT = NULL;
    return head;
}

//Name: add_to_front
//Input: integer value, pointer to list
//Output: new head pointer
//Description: 
// Inserts a node at the front of the list
d_list* add_to_front(int d, d_list* h){
    d_list* head = create_list(d);
    if (h == NULL){
        return head;
    }
    h -> FORMER = head;
    head -> NEXT = h;
    return head;
}

//Name: sort_list
//Input: pointer to list, size of list
//Output: none
//Description: 
// sorts linked list using bubble sort (recursive passes)
void sort_list(d_list*h,int size){
    d_list* original_h = h;
    while (h != NULL && h->NEXT != NULL && size > 1){
         int i;
         for ( i = 0 ; i<size-1 && h->NEXT !=NULL ; i++){
             d_list* nex = h -> NEXT;
            if (h-> data > nex -> data){
                int temp = nex -> data;
                nex -> data = h -> data;
                h->data = temp;
            }
            h = nex;
        }
        h = original_h;
        size--;
    }
}

//Name: array_to_list
//Input: integer array, size of array
//Output: pointer to head of list
//Description: 
// Converts array into linked list and sorts it
d_list* array_to_list(int d[], int size){
    d_list* head = create_list(d[0]);
    int i;
    for (i = 1; i<size; i++){
        head = add_to_front(d[i],head);
    }
    sort_list(head,size);
    return head;
}

void gen_array(int data[],int size){
    unsigned short t = time(NULL);
    srand(t);
    int i;
    for (i=0; i< size; i++){
        data[i] = rand()%50;
    }
}

//Name: print_list
//Input: pointer to list, title string
//Output: none
//Description: 
// Prints linked list in rows of 5 elements
void print_list(d_list* h, char *title){
    printf("%s\n",title);
    int count = 0;
    while (h != NULL){
        printf("%d : ",h-> data);
        h = h-> NEXT;
        count++;
        if (count == 5){
            count = 0;
            printf("\n");
        }
    }
}

//Name: free_list
//Input: pointer to head of linked list
//Output: none
//Description: 
// frees all dynamically allocated nodes in the linked list
// to prevent memory leaks
void free_list(d_list* head){
    d_list* temp;
    while (head != NULL){
        temp = head;
        head = head -> NEXT;
        free(temp);

    }
}
//Name: remove_miltiples
//Input: pointer to sorted doubled linked list
//Output: none
//Description:
// Recives sorted lists, removes data multiples through NEXT,
// and connects the NEXT and FORMER pointers accordingly. 
void remove_multiples(d_list* h){
    while (h != NULL && h->NEXT !=NULL){
        d_list* nex = h-> NEXT;
        if (h-> data == nex->data){
            h-> NEXT = nex -> NEXT;
            if (nex -> NEXT !=NULL){
                 nex -> NEXT -> FORMER = h;
            }
            nex->NEXT = NULL;
            nex ->FORMER = NULL;
            free(nex); 
        }
      else{
         h = h-> NEXT;
    }
    }
}

//Name: print_list
//Input: pointer to list, title string
//Output: none
//Description: 
// Creates array, converts to list, sorts, prints it
// removes data multiples, and prints again.
int main(){
    const int SIZE = 200;
    d_list* head = NULL;
    int data[SIZE];
    gen_array(data,SIZE);
    head = array_to_list(data,SIZE);
    print_list(head,"200 element list with multiples:");
    printf("\n\n");

    remove_multiples(head);
    print_list(head,"After multiple reduction");
    printf("\n\n");
    free_list(head);
    return 0;
}