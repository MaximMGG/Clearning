#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *teil = NULL;

void link(int data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    if(head == NULL) {
        head = new;
        teil = new;
    }else {
        teil->next = new;
        teil = new;
    }
}

void printLinks() {
    Node *track = head;
    while (track != NULL) {
        printf("%d\n", track->data);


        track = track->next;
    }

}

int main() {

    link(12);
    link(21213);
    link(4554);

    printLinks();


    return 0;
}
