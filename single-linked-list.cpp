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
    Node* temp = createNewNode(name, age);
    if(!head){

        head = tail = temp;
    }else if(age < head -> age){
        pushHead(name, age);
    }else if(age > tail -> age){
        pushTail(name, age);
    }else{
        Node* curr = head;
        while(curr -> next -> age < age){
            curr = curr -> next;
        }

        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void popHead(char name[], int age){
    if(head == NULL){
        printf("There's no node in this list!\n");
    }else if(head == tail){
        free(head);
    }
}

void printAll(){
    if(!head){
        printf("There's no node!\n");
    }else{
        Node* temp = head;
        while(temp != NULL){
            printf("%s %d -> ", temp -> name, temp -> age);
            temp = temp -> next;
        }

        printf("NULL\n");
    }
}

int main(){

    pushMid("Benny", 19);
    pushMid("Adidas", 90);
    pushMid("ynneB", 20);
    printAll();

    

    return 0;
}