//Aniya Ross
#include <stdio.h>
#include <stdlib.h>

//function to swap two elements of an array
void swap(int *element1, int *element2){
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;

}
//function to count number of sorts for each number using selection sort
void selectionSort(int arr[], int size){
    //declare & initalize variables
    int total = 0;
    int numSwaps[size], cloneArray[size], minIdx, temp;
    //initialize array tracking the number of times each element is swapped & array to store placement of original values
    for(int x = 0; x< size; x++){
        numSwaps[x] = 0;
        cloneArray[x] = arr[x];
    }
    

    
    //iterate through array
    for(int i = 0; i < size-1; i++){
        //find the minimum element in array
        minIdx = i;
        for(int j = i+1; j < size; j++)
            if(cloneArray[j] < cloneArray[minIdx])
                minIdx = j;
            
         if(cloneArray[i] != cloneArray[minIdx]){
            //swap the minimum element with the element at i

            swap(&cloneArray[i], &cloneArray[minIdx]);
        

          //increment array
            for(int y = 0; y < size; y++){
                if(arr[y] == cloneArray[i])
                    numSwaps[y]++;
                
                if(arr[y] == cloneArray[minIdx])
                    numSwaps[y]++;
            } 
            total++;
         }
        
        
    }

    //print the number of times each element was swapped
    for(int k = 0; k < size; k++){
      for(int p = 0; p < size; p++){
        if(cloneArray[k]==arr[p])
            printf("%d: swapped %d times\n", cloneArray[k], numSwaps[p]);
      }
    }

    printf("Total Swaps: %d\n", total);
}

//function to count number of sorts for each number using bubble sort
void bubbleSort(int arr[], int size){
    //declare and initialize variables
    int total = 0;
    int cloneArray[size], numSwaps[size];

    for(int x = 0; x < size; x++){
        numSwaps[x] = 0;
        cloneArray[x] = arr[x];
    }
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(cloneArray[j] > cloneArray[j+1]){
                swap(&cloneArray[j], &cloneArray[j+1]);
                //increment frequency array & total
                for(int y = 0; y < size; y++){
                    if(arr[y] == cloneArray[j])
                        numSwaps[y]++;
                    
                    if(arr[y] == cloneArray[j+1])
                        numSwaps[y]++;
                } 
                total++;
            }
        }
    }
    //printing array freqencies
    for(int p = 0; p < size; p++){
        for(int q  = 0; q < size; q++){
            if(cloneArray[p] == arr[q])
                printf("%d: swapped %d times\n", cloneArray[p], numSwaps[q]);
        }
    }
   
   //display total number of swaps, double check if its equivalent to sum of all swaps for each value divided by 2
    printf("\nTotal: %d\n", total);
}
int main(void){

    //declare and initialize two arrays 
    int array1[] = {97,16,45,63,13,22,7,58,72};
    int array2[] = {90,80,70,60,50,40,30,32,10};
    int size1 = sizeof(array1)/4;
    int size2 = sizeof(array2)/4;

    //sort each array using selection sort and display frequencies & total
    printf("Selection sort for array1: \n"); 
    selectionSort(array1, size1);
    printf("\nSelection sort for array2: \n");
    selectionSort(array2, size2);

    //sort each array using bubble sort and display frequencies & total
    printf("\nBubble sort for array 1: \n");
    bubbleSort(array1,size1);
    printf("\nBubble sort for array2: \n");
    bubbleSort(array2, size2);
    


    return 0;
}