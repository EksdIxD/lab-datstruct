#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    char name[100];
    int age;
    Node* next;
}*head = NULL, *tail = NULL;

Node* createNewNode(char name[], int age){
    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode -> name, name);
    newNode -> age = age;

    return newNode;
}

void pushHead(char name[], int age){
    Node* temp = createNewNode(name, age);

    if(!head){
        head = tail = temp;
    }else{
        temp -> next = head;
        head = temp;
    }
}

int main(){

    

    return 0;
}