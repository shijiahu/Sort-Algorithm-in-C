//
//  main.c
//  Sort
//
//  Created by shijia hu on 2/20/17.
//  Copyright © 2017 shijia hu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void exchange(int i, int j, int *array){
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void exchangeSort(int *array, int n){
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i+1; j<n ; j++ ) {
            if (array[j] < array[i]) {
                exchange(i, j, array);
            }
        }
        if (n<=20) {
            printf("After executing one step, the result is:\n");
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }

    printf("The sorted array is:\n");
    
    for (int k = 0; k < n; k++) {
        if (k == n-1) {
            printf("%d\n",array[k]);
            break;
        }
        printf("%d ", array[k]);
    }
}

void insertionSort(int *array, int n){
    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = array[i];
        if(temp < array[i-1])
        {
            for (j = i-1; j >= 0 && temp < array[j]; j--) {
                array[j+1] = array[j];
            }
            array[j+1] = temp;
        }
        
        if (n<=20) {
            printf("After executing one step, the result is:\n");
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }
    printf("The sorted array is:\n");
    
    for (int k = 0; k < n; k++) {
        if (k == n-1) {
            printf("%d\n",array[k]);
            break;
        }
        printf("%d ", array[k]);
    }
}

void merge(int *array, int first, int second, int *temparray1, int *temparray2){
    int i=0,j=0,k=0;
    while (i<=first-1 && j<=second-1) {
        if(temparray1[i]<temparray2[j]){
            array[k++] = temparray1[i];
            i++;
        }else{
            array[k++] = temparray2[j];
            j++;
        }
    }
    if (i>first-1) {
        for (int m = j ; m < second ; m++) {
            array[k++] = temparray2[m];
        }
    }else{
        for (int n = i ; n < first ; n++) {
            array[k++] = temparray1[n];
        }
    }
}



void mergeSort(int *array, int n, int flagflagflag, int nn){

    if(n>1){
        int temparray1[500] ;
        int temparray2[500] ;
        int first = n/2;
        int second = n - first;
    
        for (int i = 0; i < first; i++) {
            temparray1[i] = array[i];
        }
        int k = 0;
    
        for (int j = first; j < n; j++) {
            temparray2[k++] = array[j];
        }
        
        
        
        mergeSort(temparray1, first, flagflagflag,nn);
        mergeSort(temparray2, second, flagflagflag,nn);
        merge(array, first, second, temparray1, temparray2);
        
        if (nn>20) {
            flagflagflag = 1;
        }else if (nn <=20 && flagflagflag==0) {
            printf("After executing one step, the result is:\n");
            printf("The first part is:\n");
            for (int i = 0; i<first; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
            printf("The second part is:\n");
            for (int i = first; i<n; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
            printf("The array is:\n");
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }

        }
        
    }
}


int ranPartition(int *array, int low, int high){
    int p = rand()%(high-low+1)+low;
    int pivot = array[p];
    exchange(p, low, array);
    
    int i,j,pivotpoint;
    j = low;
    
    for (i = low+1 ; i <= high; i++) {
        if (array[i] < pivot) {
            j++;
            exchange(i, j, array);
        }
    }
    pivotpoint = j;
    exchange(low, pivotpoint, array);
    return pivotpoint;
}



void ranQuickSort(int *array, int low, int high, int flagflag, int n){

    if (low < high) {
        int pivotpoint = ranPartition(array, low, high);
        
        
        ranQuickSort(array, low, pivotpoint - 1,flagflag,n);
        ranQuickSort(array, pivotpoint + 1, high,flagflag,n);
        if (n > 20) {
            flagflag = 1;
        }else if ((n) <=20 && flagflag==0) {
            printf("pivotpoint is %d\n",pivotpoint);
            printf("After executing one step, the result is:\n");
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }
}




int main(int argc, const char * argv[]) {
    // insert code here...
    while(1){
        printf("*****************************************************\n");
        printf("************* 1   exchange sort         *************\n");
        printf("************* 2   insertion sort        *************\n");
        printf("************* 3   merge sort            *************\n");
        printf("************* 4   randomized quick sort *************\n");
        printf("*****************************************************\n\n");


        int number;
        int flagflagflag = 0;
        int flagflag = 0;
        
        while (1) {
            printf("Please select a sorting algorithm(1-4):\n");
            scanf("%d", &number);
            if (number != 1 && number != 2 & number != 3 & number != 4) {
                printf("Wrong number of selection!\n");
            }else{
                break;
            }
        }

        int n,nn;
        int arr[1002] = {0};

        while (1) {
            printf("Please enter the number of input data n(0-1000):\n");
            scanf("%d", &n);
            if (n >= 0 && n <= 1000) {
                break;
            }else{
                printf("Wrong Number!\n");
            }
        }


        printf("You got an array for %d integers:\n", n);
        srand(time(0));
        
        
        if (n <= 20) {
            for (int i = 0; i<n; i++) {
                arr[i] = rand()%16;
                for (int j = 0; j<arr[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int i = 0; i<n; i++) {
                if (i == n-1) {
                    printf("%d\n",arr[i]);
                    break;
                }
                printf("%d ", arr[i]);
            }
            
        }else{
            for (int i = 0; i < n; i++) {
                
                arr[i] = rand() % 32668;
                if (i == n-1) {
                    printf("%d\n",arr[i]);
                    break;
                }
                printf("%d ", arr[i]);
            }
        }
        
        
        switch (number) {
            case 1:
                exchangeSort(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                break;
            case 3:
                flagflagflag = 0;
                nn = n;
                mergeSort(arr, n, flagflagflag,nn);
                
                printf("The sorted array is:\n");
                
                for (int k = 0; k < n; k++) {
                    if (k == n-1) {
                        printf("%d\n",arr[k]);
                        break;
                    }
                    printf("%d ", arr[k]);
                }
                break;
            case 4:
                flagflag = 0;
                ranQuickSort(arr, 0, n-1, flagflag, n);
                printf("The sorted array is:\n");
                
                for (int k = 0; k < n; k++) {
                    if (k == n-1) {
                        printf("%d\n",arr[k]);
                        break;
                    }
                    printf("%d ", arr[k]);
                }
                break;
            default:
                break;
        }
        
        printf("Input any character to continue or input N to exit:");
        char icontinue;
        scanf("\n%c",&icontinue);
        if (icontinue =='N' || icontinue =='n') {
            break;
        }
        
    }
    return 0;
}
