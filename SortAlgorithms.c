#include <stdio.h>

// fonction swap pour echanger les valeurs de 2 variables

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

//fonction length pour calculer le longeueur d'un tableau

int length(int totalSize, int elementSize) {
  return totalSize / elementSize;
}

//fonction display pour afficher les elements d'un tableau

void display(int arr[], int totalSize, int elementSize){
    for(int i=0; i<length(totalSize, elementSize); i++) printf("%d\n", arr[i]); 
}

//Fonction de Tri à bulles

void bubbleSort(int arr[], int totalSize, int elementSize){
    for(int i=0; i<length(totalSize, elementSize); i++) 
        for(int j=i; j<length(totalSize, elementSize); j++) 
            if(arr[i] > arr[j]) 
                swap(&arr[i], &arr[j]);
}

//Fonction de Tri en selection

void selectionSort(int arr[], int totalSize, int elementSize){
    for(int i=0; i<length(totalSize, elementSize); i++){
        int minIndex = i;
        for(int j=i+1; j<length(totalSize, elementSize); j++) if(arr[j] <= arr[minIndex]) minIndex = j;
        swap(&arr[i], &arr[minIndex]);
    }
}

//Fonction de Tri en insertion

void insertionSort(int arr[], int totalSize, int elementSize){
    for(int i=1; i<length(totalSize, elementSize); i++){
        int element = arr[i];
        int j = i -1;

        while( j>= 0 && element < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = element;
    }
}

//Fonction partition est utilisé dans l'algorithme de Tri rapide pour diviser le tableau en 2 sous-tableaux selon un pivot ou les elements du tableau à gauche est inferieur au elements du tableau à droite

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int i = start, j = end;

    while(i<j){

        do{
            i++;
        }while(arr[i] <= pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i<j) swap(&arr[i], &arr[j]);
    }

    swap(&arr[j], &arr[start]);
    return j;
}

//Fonction du Tri rapide

void quickSort(int arr[], int start, int end){
    if(start < end){
        int j = partition(arr, start, end);
        quickSort(arr, start, j);
        quickSort(arr, j+1, end);
    }
}




int main(){
    int arr[] = {42, 5, 17, 8, 23, 11, 3, 19, 7, 14, 29, 2, 6, 10, 16, 31, 9, 4, 12, 1};

    //bubbleSort(arr);
    //selectionSort(arr);
    //insertionSort(arr);
    //quickSort(arr, 0, length(sizeof(arr), sizeof(arr[0])));
    

    display(arr, sizeof(arr), sizeof(arr[0]));
    return 0;
} 
