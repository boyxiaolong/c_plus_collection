#include <stdio.h>

struct Node
{
    int element;
    Node* next;
};

typedef Node* PtrNode;
typedef PtrNode List;
typedef PtrNode Postion;

bool isEmpty(List head){
    if (NULL == head) {
        return false;
    }
    return head->next == NULL;
}

bool isLast(List head){
    return isEmpty(head);
}

Postion find(List head, int value){
    if (NULL == head) {
        return NULL;
    }
    
    Postion p = head->next;
    while(p){
        if (p->element == value) {
            return p;
        }
        p = p->next;    
    }
    return NULL;
}

Postion findPrevious(List head, int value){
    if (NULL == head) {
        return NULL;
    }
    
    Postion p = head;
    while(p->next){
        if (p->next->element == value) {
            return p;
        }
        p = p->next;    
    }
    
    return NULL;
}
void deleteList(List head, int value){
    Postion p = findPrevious(head, value);
    if (p) {
        Postion todelNode = p->next;
        if (todelNode) {
            p->next = todelNode->next;
            delete todelNode;
        }
    }
}

int main()
{
    printf("");
}