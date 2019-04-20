#include <iostream>
typedef int data;

struct node {
    data value;
    node* next;
};

node *head = nullptr, *tail = nullptr;

int enqueue(data value) {
    node *t = (node*) malloc(sizeof(node));
    if (t == nullptr) {
        return -1;
    }
    t->value = value;
    t->next = nullptr;
    if(tail == nullptr) {
        head = tail = t;
    }
    else {
        tail->next = t;
        tail = t;
    }
    return 0;
}

int dequeue(data *p) {
    if (head == nullptr) {
        return -1;
    }
    node *n = head->next;
    *p = head->value;
    if (head == tail) {
        tail = nullptr;
    }
    free(head);
    head = n;
    return 0;
}

void print_queue() {
    node* h = head;
    int x = 1;
    while(h != nullptr) {
        printf("%d - %d\n", x++, h->value);
        h = h->next;
    }
}

int main() {
    printf("enqueue operation\n");
    enqueue(5);
    enqueue(1);
    enqueue(3);
    enqueue(4);
    enqueue(0);
    print_queue();
    printf("dequeue operation\n");
    int p;
    dequeue(&p);
    dequeue(&p);
    print_queue();
    return 0;
}
