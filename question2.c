#include <stdio.h>
#include <stdlib.h>


#include <string.h>


typedef struct stack {
    char* data;
    int top;
    int capacity;
} stack;

void initialize(stack* s) {
    s->data = (int*)malloc(sizeof(int)*100);
    if (s->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = 100;
}

int isEmpty(stack* s) {
    return (s->top == -1);
}

int isFull(stack* s) {
    return (s->top == s->capacity - 1);
}

void push(stack* s, char value) {
    if (isFull(s)) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    s->top = (s->top + 1) % s->capacity;
    s->data[s->top] = value;
}

char pop(stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1;
    }
    char value = s->data[s->top];
    s->top = (s->top - 1 + s->capacity) % s->capacity;
    return value;
}

char peek(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek element.\n");
        return -1;
    }
    return s->data[s->top];
}

void cleanup(stack* s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}


int isPalindrome(char *str) {
    struct stack s;
    int len = strlen(str);
    initialize(&s); // Efficiently using memory

    for (int i = 0; i < len;i++){
        char c = str[i];
        push(&s,c);
    }

    for (int i = 0; i < len; i++) {
        char ch = pop(&s);
        if (ch != str[i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // IS
}

int main() {


    printf("isPalindrome(%s) %s\n", "racecar", isPalindrome("racecar")==1?"True":"False");
    printf("isPalindrome(%s) %s\n", "pop", isPalindrome("pop")==1?"True":"False");
    printf("isPalindrome(%s) %s\n", "test", isPalindrome("test")==1?"True":"False");
    return 0;
}
