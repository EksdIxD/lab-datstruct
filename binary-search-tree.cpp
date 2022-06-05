#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int number;
    Node *left, *right;
};

Node* createNewNode(int number){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode -> number = number;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

Node* insertNewNode(Node* curr, int number){
    if(curr == NULL){
        return createNewNode(number);
    }

    if(number < curr -> number){
        curr -> left = insertNewNode(curr -> left, number);
    }else if(number > curr -> number){
        curr -> right = insertNewNode(curr -> right, number);
    }

    return curr;
}   

void inOrder(Node* curr){
    if(curr != NULL){
        inOrder(curr -> left);
        printf("%d -> ", curr -> number);
        inOrder(curr -> right);
    }
}

void preOrder(Node* curr){
    if(curr != NULL){
        printf("%d -> ", curr -> number);
        preOrder(curr -> left); 
        preOrder(curr -> right);
    }   
}

void postOrder(Node* curr){
    if(curr != NULL){
        postOrder(curr -> left);
        postOrder(curr -> right);
        printf("%d -> ", curr -> number);
    }   
}



int main() {
    Node* root = NULL;
    root = insertNewNode(root, 100);
    insertNewNode(root, 50);
    insertNewNode(root, 10);
    insertNewNode(root, 75);
    insertNewNode(root, 150);

    inOrder(root);
    puts("NULL");
    preOrder(root);
    puts("NULL");
    postOrder(root);
    puts("NULL");

    return 0;
}