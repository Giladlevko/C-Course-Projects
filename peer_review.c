// IF THIS IS NOT EMPTY THIS IS A WORK OF ANOTHER 
// FOR MY COURSE I NEED TO REVIEW OTHERS' CODE. 
// I USE THIS FILE TO CHECK, 
// AND PASTE / DELETE THEIR CODE
//
//################################################################################################################################################################################################################
//################################################################################################################################################################################################################


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure
typedef struct element {
    char name[20];
    char symbol[5];
    float weight;
    struct element* next;
} element;

// Function to create node
element* createNode(char name[], char symbol[], float weight) {
    element* newNode = (element*)malloc(sizeof(element));

    strcpy(newNode->name, name);
    strcpy(newNode->symbol, symbol);
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

// Function to append node
void append(element** head, char name[], char symbol[], float weight) {

    element* newNode = createNode(name, symbol, weight);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    element* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print list
void printList(element* head) {

    printf("\nFirst 10 Elements of Periodic Table\n");
    printf("-----------------------------------------\n");
    printf("%-12s %-8s %-10s\n",
           "Name", "Symbol", "Weight");
    printf("-----------------------------------------\n");

    element* temp = head;

    while (temp != NULL) {

        printf("%-12s %-8s %-10.3f\n",
               temp->name,
               temp->symbol,
               temp->weight);

        temp = temp->next;
    }
}

// Main function
int main() {

    element* head = NULL;

    char name[20];
    char symbol[5];
    float weight;

    printf("Enter first 10 elements:\n");

    for (int i = 0; i < 10; i++) {

        printf("\nElement %d\n", i + 1);

        printf("Enter Name: ");
        scanf("%s", name);

        printf("Enter Symbol: ");
        scanf("%s", symbol);

        printf("Enter Atomic Weight: ");
        scanf("%f", &weight);

        append(&head, name, symbol, weight);
    }

    printList(head);

    return 0;
}
