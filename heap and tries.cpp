#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int heap[20];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getParent(int pos){
   return (pos - 1) / 2;
}

void insert(int number){
    //Masukin value ke dalam array
    heap[size] = number;
    
    //Check terhadap parent
    int index = size;
    while(index != 0 && heap[getParent(index)] > heap[index]){
        swap(&heap[getParent(index)], &heap[index]);
        index = getParent(index);
    }

    size++;
}

void printAll(){
    for(int i = 0; i < size; i++){
        printf("%d. %d\n", i + 1, heap[i]);
    }
}

int main(){

    insert(10);
    insert(5);
    insert(3);
    insert(11);
    insert(2);

    printAll();

    return 0;
}
