#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printlist(struct node* p) {
    printf("\n");
    while(p != NULL) {
        if (p->next != NULL)
            printf("|%d| -> ", p->data);
        else
            printf("|%d| \n", p->data);
        p = p->next;
    }
    printf("\n");
}

void addnode (struct node** head, int data) {
    struct node* new_node = malloc(sizeof(struct node));
    printf("\n");
    printf("Enter the new value: ");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    printf("New list:\n");
    printlist(*head);
}

void searchnode (struct node* head, int data) {
    printf("\n");
    printf("What value do you want to search for? ");
    scanf("%d", &data);
    printf("\n");

    struct node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            printf("Value %d found in the list.\n", data);
            return;
        }
        current = current->next;
    }
    printf("Value %d not found in the list.\n", data);
}

void deletenode (struct node** head, int data) {
    printf("\n");
    printf("What value do you want to delete? ");
    scanf("%d", &data);
    printf("\n");

    struct node* current = *head;
    struct node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list.\n", data);
        return;
    }

    if (previous == NULL) {
        *head = current->next; // Delete the head node
    } else {
        previous->next = current->next; // Bypass the node to delete it
    }
    
    free(current);
    printf("Value %d deleted from the list.\n", data);
    printf("New list:\n");
    printlist(*head);
}

int main() {

    int data;

    struct node* head;
    struct node* node1 = NULL;
    node1 = malloc(sizeof(struct node));
    struct node* node2 = NULL;
    node2 = malloc(sizeof(struct node));
    struct node* node3 = NULL;
    node3 = malloc(sizeof(struct node));

    head = node1;

    // assegno dei valori inziali ai nodi ed imposto i next
    printf("List initialization\n");
    printf("Enter the first value: ");
    scanf("%d", &data);
    node1->data = data;
    node1->next = node2;
    printf("Enter the second value: ");
    scanf("%d", &data);
    node2->data = data;
    node2->next = node3;
    printf("Enter the third value: ");
    scanf("%d", &data);
    node3->data = data;
    node3->next = NULL;

    printlist(head); // stampa la lista

    
    
    int choice;
    int active = 1;
    while (active == 1) {
        printf("\n");
        printf("What do you want to do?\n");
        printf("1. Add a new value\n");
        printf("2. Search a value\n");
        printf("3. Delete a value\n");
        printf("4. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Aggiungi un nodo alla lista
                addnode(&head, data);
                break;
            case 2:
                // Cerca un nodo nella lista
                searchnode(head, data);
                break;
            case 3:
                // Elimina un nodo dalla lista
                deletenode(&head, data);
                break;
            case 4:
                active = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

}