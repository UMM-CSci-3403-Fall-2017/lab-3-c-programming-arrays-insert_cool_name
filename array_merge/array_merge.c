#include<stdio.h>
#include<stdlib.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	int thisSize=0;
	int counter = 0;
        int* temp;

	temp = (int*) calloc(thisSize + 1, sizeof(int));
	for(int i = 0; i < num_arrays; i++){
                for(int q=0; q<sizes[i]; q++){
        	       	temp[counter] = values[i][q];
			thisSize++;
			counter++;
                }
        }
        
        mergesort(thisSize, temp);
        
	int holder = '\0';
        int theCount = 0;
        	
	for(int i = 0; i < thisSize; i++){
                if(temp[i] != holder){
                        theCount++;
                        holder = temp[i];
                }
        }

        int* output;
        output = (int*) calloc(theCount + 1, sizeof(int));
        
	int secondHolder = '\0';
        output[0] = theCount;
        int n = 1;
        for(int v = 0; v < thisSize; v++){
                if(temp[v] != secondHolder){
                        output[n] = temp[v];
                        n++;
                        secondHolder = temp[v];
                }

        }

	/*
        for(int n = 0; n <= theCount; n++){
                printf("element [%i] is %i\n",n,output[n]);
        }
	*/

	free(temp);
	return(output);
}
