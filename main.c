#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* getEndOfLinkedList(node* head) {
    if (head==NULL) return NULL;
    if (head->next==NULL)return head;

    return getEndOfLinkedList(head->next);

}
void insertAtEnd(node** head, int value) {
    node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        node* current = getEndOfLinkedList(*head);
        current->next = newNode;
    }
}

void printNode(node* head) {
    if (head==NULL)return;
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAfterN(node* target, int M, int N) {
    if (target == NULL) return;//End of node, break loop or head NULL

    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = M;
    newNode->next = NULL;


    if (target->data == N) { //Target matches insert after
        newNode->next = target->next;
        target->next = newNode;
    }
    insertAfterN(target->next, M, N); //Continues to next node
}

int main() {
    int arr[] = {3, 6, 4, 6, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);


    node *head = NULL;
    for (int i = 0; i < size; i++) {
        insertAtEnd(&head, arr[i]);
    }

    printNode(head);

    insertAfterN(head, 200, 6);
    printNode(head);

    return 0;
}
