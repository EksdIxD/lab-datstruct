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

void insertMinHeap(int number){
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

void insertMaxHeap(int number){
    //Masukin value ke dalam array
    heap[size] = number;
    
    //Check terhadap parent
    int index = size;
    while(index != 0 && heap[getParent(index)] < heap[index]){
        swap(&heap[getParent(index)], &heap[index]);
        index = getParent(index);
    }

    size++;
}

int getLeftChild(int pos){
    return pos * 2 + 1;
}

int getRightChild(int pos){
    return pos * 2 + 2;
}

void minHeap(int pos){
    int lowest = pos;
    int left = getLeftChild(pos);
    int right = getRightChild(pos);

    if(left < size && heap[left] < heap[lowest]){
        lowest = left;
    }

    if(right < size && heap[right] < heap[lowest]){
        lowest = right;
    }

    if(lowest != pos){
        swap(&heap[lowest], &heap[pos]);
        minHeap(lowest);
    }
}

void maxHeap(int pos){
    int highest = pos;
    int left = getLeftChild(pos);
    int right = getRightChild(pos);

    if(left < size && heap[left] > heap[highest]){
        highest = left;
    }

    if(right < size && heap[right] > heap[highest]){
        highest = right;
    }

    if(highest != pos){
        swap(&heap[highest], &heap[pos]);
        minHeap(highest);
    }
}

void deleteMinHeap(){
    heap[0] = heap[size - 1];
    size--;
    minHeap(0);
}

void deleteMaxHeap(){
    heap[0] = heap[size - 1];
    size--;
    maxHeap(0);
}

void printAll(){
    for(int i = 0; i < size; i++){
        printf("%d. %d\n", i + 1, heap[i]);
    }
}

int main(){

    // printf("Insert Min heap :\n");
    // insertMinHeap(10);
    // insertMinHeap(5);
    // insertMinHeap(3);
    // insertMinHeap(11);
    // insertMinHeap(2);
    // printAll();
    // puts("");



    printf("Insert Max heap :\n");
    insertMaxHeap(10);
    insertMaxHeap(5);
    insertMaxHeap(3);
    insertMaxHeap(11);
    insertMaxHeap(2);
    printAll();
    puts("");

    // deleteMinHeap();
    // printAll();

    return 0;
}
