#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int counter = 0;
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
        counter += 1;
    }

    if(number < curr -> number){
        curr -> left = insertNewNode(curr -> left, number);
    }else if(number > curr -> number){
        curr -> right = insertNewNode(curr -> right, number);
    }

    return curr;
}   

// Node* searchNode(Node* curr, int number){
//     counter -= 1;
//     if(number == curr -> number && counter >= 1){
//         printf("Number %d found!\n", curr -> number);
//     }else if(counter <= 0){
//         printf("Number not found!\n");
//         return curr;
//     }

//     if(number < curr -> number){
//         curr -> left = searchNode(curr -> left, number);
//     }else if(number > curr -> number){
//         curr -> right = searchNode(curr -> right, number);
//     }
//     return curr;
// }

Node* searchNode(Node* curr, int number){
    if(curr == NULL){
        return curr;
    }

    if(number < curr -> number){
        curr -> left = searchNode(curr -> left, number);
    }else if(number > curr -> number){
        curr -> right = searchNode(curr -> right, number);
    }
    return curr;
}

Node* deleteNode(Node* curr, int number){
    if(curr == NULL){
        return curr;
    }

    if(number < curr -> number){
        curr -> left = deleteNode(curr -> left, number);
    }else if(number > curr -> number){
        curr -> right = deleteNode(curr -> right, number);
    }else if(number == curr -> number){
        if(curr -> left == NULL && curr -> right == NULL){
            free(curr);
            return NULL;
        }else if(curr -> left != NULL || curr -> right != NULL){
            
        }
            
    }


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



int main(){
    Node* root = NULL;
    root = insertNewNode(root, 100);
    insertNewNode(root, 50);
    insertNewNode(root, 10);
    insertNewNode(root, 75);
    insertNewNode(root, 150);

    // if(searchNode(root,87) != NULL){
    //     printf("Found!\n");
    // }else{
    //     printf("Not found!\n");
    // }

    inOrder(root);
    puts("NULL");
    preOrder(root);
    puts("NULL");
    postOrder(root);
    puts("NULL");

    return 0;
}