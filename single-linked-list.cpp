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

void pushTail(char name[], int age){
    Node* temp = createNewNode(name, age);

    if(!head){
        head = tail = temp;
    }else{
        tail -> next = temp;
        tail = temp;
    }
}

void pushMid(char name[], int age){
    ;
}

void printAll(){
    if(!head){
        printf("There's no node!\n");
    }else{
        Node* temp = head;
        while(temp != NULL){
            printf("Name : %s\nAge : %d\n\n", temp ->name, temp -> age);
            temp = temp -> next;
        }
    }
}

int main(){

    pushHead("Benny", 19);
    pushTail("Adidas", 20);
    pushHead("ynneB", 90);
    printAll();

    

    return 0;
}