// Date: 4/21/2026
// Name Mr.lad
// Program generates 100 random integers,
// stores them in a linked list,
// sorts them using bubble sort,
// and prints them in rows of 5.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Declaration of the list struct type
//Stores an integer data value and a pointer to the next node in the list
typedef struct list{int data; struct list *next;}list;

void sort_list(list* h,int size);

//Name: is_empty
//Input: pointer to list
//Output: 1 if empty, 0 otherwise
//Description: checks if list pointer is NULL
int is_empty(const list *l){return (l == NULL);}

//Name: create_list
//Input: integer value
//Output: pointer to new list node
//Description: 
// Allocates and initializes a new node
list* create_list(int d){
        list* head = malloc(sizeof(list));
        head -> data = d;
        head -> next = NULL;
        return head;
}

//Name: add_to_front
//Input: integer value, pointer to list
//Output: new head pointer
//Description: 
// Inserts a node at the front of the list
list* add_to_front(int d,list* h){
        list* head = create_list(d);
        head -> next = h;
        return head;
}

//Name: array_to_list
//Input: integer array, size of array
//Output: pointer to head of list
//Description: 
// Converts array into linked list and sorts it
list* array_to_list(int d[], int size){
        list* head = create_list(d[0]);
        int i;
        for (i = 1; i< size; i++){
                head = add_to_front(d[i],head);
        }
	sort_list(head,size);
        return head;
}

//Name: sort_list
//Input: pointer to list, size of list
//Output: none
//Description: sorts linked list using bubble sort (recursive passes)
void sort_list(list*h,int size){
	if (h == NULL || h->next == NULL || size <= 1){
		return;
	}
	int i;
	list* original_h = h;
	for (i=0;i<size-1 && h -> next != NULL;i++){
		list* nex = h->next;
		if (h->data > nex->data){
			int temp = nex -> data;
			nex -> data = h -> data;
			h -> data = temp;
		}
		h = nex;
	}
	sort_list(original_h,size-1);
}


//Name: print_list
//Input: pointer to list, title string
//Output: none
//Description: 
// Prints linked list in rows of 5 elements
void print_list(list*h,char *title){
        printf("%s\n", title);
	int count = 0;
        while (h != NULL){
                printf("%d :",h -> data);
                h = h -> next;
				count++;
				if (count == 5){
				count = 0;
				printf("\n");
		}


        }
}
//Name: gen_array
//Input: integer array, size of array
//Output: none
//Description: 
// Fills array with random values
void gen_array(int data [],int size){
	unsigned short t = time(NULL);
	srand(t);
	int i;
	for (i = 0; i<size; i++){
		data[i] = rand();
	}
}

//Name: free_list
//Input: pointer to head of linked list
//Output: none
//Description: frees all dynamically allocated nodes in the linked list to prevent memory leaks
void free_list(list* head){
	list* temp;
	while (head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
}

//Name: main
//Input: none
//Output: returns 0
//Description:
// Creates array, converts to list, sorts and prints it
int main(){
        list *head = NULL;
        int data[100];
       	gen_array(data,100);
        head = array_to_list(data,100);
        print_list(head,"100 element list");
        printf("\n\n");
		free_list(head);
        return 0;
}
