#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int myArray[],int index1,int index2,int numberOfSwaps[]){
    int tmp = myArray[index1];
    myArray[index1]=myArray[index2];
    myArray[index2]=tmp;
}
int * bubbleSort(int myArray[], int numberOfElements,int numberOfSwaps[]){
    for(int i=0;i<numberOfElements;i++){
        for(int j=1;j<numberOfElements-i;j++){
            if(myArray[j]<myArray[j-1]){
                swap(myArray,j,j-1,numberOfSwaps);
                numberOfSwaps[i]++;
            }
        }
    }
    return numberOfSwaps;
}


int main(){
    int myArray[]={97,16,45,63,13,22,7,58,72};


    int totalSwaps=0;
    int numberOfElements = sizeof(myArray)/sizeof(int);
    int *numberOfSwaps=malloc(numberOfElements*sizeof(int));
    memset(numberOfSwaps,0,numberOfElements*sizeof(int));
    bubbleSort(myArray,numberOfElements,numberOfSwaps);
    printf("Number of Swaps: ");
    for(int i = 0; i < numberOfElements; i++){
        printf("%d ", numberOfSwaps[i]);
        totalSwaps+=numberOfSwaps[i];
    }
    printf("\nSorted Array:    ");
    for(int i = 0; i < numberOfElements; i++){
        printf("%d ", myArray[i]);
    } 
    printf("\nTotal Swaps:     %d", totalSwaps);
}