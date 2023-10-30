#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    Node* next;
};

Node* Ctor() {
    Node* head = (Node*) calloc(1, sizeof(Node));
    head->value = -1;
    head->next = NULL;

    return head;
}

void Push(int number, Node* head) {

    Node* new_el = (Node*) calloc(1, sizeof(Node));
    new_el->value = number;
    Node* tmp = (Node*) calloc(1, sizeof(Node));

    tmp->value = head->value;
    head->value = new_el->value;
    new_el->value = tmp->value;

    tmp->next = new_el;
    new_el->next = head->next;
    head->next = tmp->next;

    free(tmp);

}

void Pop(Node* head) {

    Node* new_el = head->next;
    Node* tmp = (Node*) calloc(1, sizeof(Node));

    tmp->value = head->value;
    head->value = new_el->value;
    new_el->value = tmp->value;

    tmp->next = new_el->next;
    new_el->next = head->next;
    head->next = tmp->next;

    free(tmp);
    free(new_el);

}

int Back(Node* head) {

    if (head->next == NULL){
        printf("error ");
        return 404;
    }

    return head->value;
}

void Operations(char* str, Node* head) {
            if (strcmp("push", str) == 0) {
                int elem;
                scanf("%d", &elem);
                Push(elem, head);
            }

            if (strcmp("pop", str) == 0) Pop(head);

            if (strcmp("back", str) == 0) {
                printf("%d", Back(head));
            }

            if (strcmp("exit", str) == 0) {
                printf("bye");
                exit(0);
            }
        }

int main() {

    Node* head = Ctor();

    while (1) {

        char str[10];
        scanf("%s", str);
        Operations(str, head);

    }

}
