//Date: 4/24/2026
//Name: Mr.lad
//Program: Binary Tree Construction and Inorder Traversal
//
// General Algorithm:
// 1. Open input file containing integer data.
// 2. Read first integer
//    which represents the number of elements.
// 3. Allocate an array of that size.
// 4. Read remaining integers into the array.
// 5. Recursively construct a binary tree 
//    from the array using index rules:
//      left child = 2*i + 1
//      right child = 2*i + 2
// 6. Traverse the tree using inorder traversal:
//      left subtree → root → right subtree
// 7. Print node values during traversal.
// 8. Free all allocated memory in postorder:
//      left subtree → right subtree → root.

#include <stdio.h>
#include <stdlib.h>

//Type: DATA
//Description: 
// Defines the type stored 
// in each node of the binary tree.
// Currently set to int for integer values.
typedef int DATA ;


//Struct: node
//Fields:
// d-> value stored in node
// left-> pointer to left child
// right-> pointer to right child
// Description: 
// Represents a single node in a binary tree.
struct node{
	DATA d;
	struct node *left;
	struct node *right;
};

//Type: NODE
//Description: 
// Alias for struct node to simplify code usage.
typedef struct node NODE;

//Type: BTREE
//Description: 
// Pointer to a NODE, 
// representing the root of a binary tree.
typedef NODE	*BTREE;

//Name: read_int_amount
//Input:
// FILE *fptr - pointer to input file
// int *amount - pointer to variable that stores array size
//Output: none
//Description: 
// Reads the first integer from the file and stores it
// as the number of elements in the array.
void read_int_amount(FILE *fptr,int* amount){
    fscanf(fptr,"%d",amount);
    printf("amount is: %d\n\n",*amount);
}

//Name: print_data
//Input: 
// int data[] - array of integers
// int size - number of elements in array
//Output: none
//Description: 
// Prints all elements of the integer array 
// to the screen.
void print_data(int data[], int size){
    int i;
    for(i = 0 ; i < size; i++){
        printf("element %d  is: %d",i, data[i]);
        printf("\n\n");
    }
}

//Name: read_int_data
//Input: 
// FILE *fptr - pointer to input file
// int size - number of integers to read
// int data[] - array to store integers
//Output: none
//Description: 
// Reads integers from the file into the array and
// prints the array values.
void read_int_data(FILE *fptr,int size,int data[]){
    int i;
    for (i = 0; i<size; i++){
        fscanf(fptr,"%d",&data[i]);
    }
    print_data(data,size);
}


//Name: inorder
//Input: 
// BTREE root - pointer to root of binary tree
//Output: none
//Description: 
// Traverses the binary tree in inorder sequence
// (left subtree, root, right subtree) and prints values.
void inorder(BTREE root){
	if (root != NULL){
		inorder(root -> left);
		printf("%d " , root -> d); 
		inorder(root -> right);
	}

}


//Name: new_node
//Input: none
//Output: 
// BTREE - pointer to newly allocated node
//Description: 
// Allocates memory for a new tree node and returns
// a pointer to it.
BTREE new_node(void){
	return(malloc(sizeof(NODE)));
}


//Name: init_node
//Input: 
// DATA d1 - value for node
// BTREE p1 - pointer to left child
// BTREE p2 - pointer to right child
//Output: BTREE - initialized node pointer
//Description: 
// Creates a new node, stores the given value, and
// connects the left and right child pointers.
BTREE init_node(DATA d1,BTREE p1,BTREE p2){
	BTREE t;
	t = new_node();
	t -> d = d1;
	t -> left = p1;
	t -> right = p2;
	return t;
}


//Name: create_tree
//Input: 
// DATA a[] - array containing tree values
// int i - current index in array
// int size - number of elements in array
//Output: 
// BTREE - pointer to root of created subtree
//Description:
// Recursively builds a binary tree from the array
// using index relationships:
// left child = 2*i + 1
// right child = 2*i + 2
BTREE create_tree(DATA a[],int i, int size){
	if (i >= size){
		return NULL;
	}
	else{
		return(init_node(a[i],
			create_tree(a,2*i +1, size),
			create_tree(a,2*i+2,size)));
	}
}


//Name: free_btree
//Input:
// BTREE root - pointer to root of binary tree
//Output: none
//Description: 
// Recursively frees all nodes in the binary tree 
// using postorder traversal
// (left subtree, right subtree, root).
// Prints the value of each node 
// before releasing its memory.
void free_btree(BTREE root){
    if (root !=NULL){
        free_btree(root -> left);
        free_btree(root -> right);
        printf("freed node with data %d \n",root -> d);
        free(root);
    }
    

}


//Name: main
//Input: none
//Output: returns 0
//Description: 
// Opens the input file, reads the array size and values,
// builds the binary tree, performs inorder traversal,
// prints the results, frees the tree,
// and closes the file.
int main(){
    FILE *fptr;
    fptr = fopen("int_data_for_btree.txt","r");
	int size = 0;
    read_int_amount(fptr,&size);
    int data[size];
    read_int_data(fptr,size,data);
	BTREE b;
	b = create_tree(data,0,size);
    printf("Binary in inorder format:\n");
	inorder(b);
    printf("\n\n");
    free_btree(b);
	printf("\n\n");
    fclose(fptr);
}