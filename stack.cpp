#include <iostream>
typedef int data;

struct node {
    data value;
    node* next;
};

node *head;

int push(data p) {
    node *t = (node *)malloc(sizeof(node));
    if (t == nullptr) {
        return -1;
    }
    t->value = p;
    t->next = nullptr;
    
    if (head == nullptr) {
        head = t;
    }
    else {
        t->next = head;
        head = t;
    }
    return 0;
}

int pop(data *p) {
    if (head == nullptr) {
        return -1;
    }
    node* next = head->next;
    *p = head->value;
    free(head);
    head = next;
    return 0;
}

void print_stack() {
    node* h = head;
    int x = 1;
    while(h != nullptr) {
        printf("%d - %d\n", x++, h->value);
        h = h->next;
    }
}

int main() {
    printf("push operation\n");
    push(4);
    push(2);
    push(5);
    push(0);
    print_stack();
    printf("after pop operation\n");
    data x;
    pop(&x);
    print_stack();
    return 0;
}
