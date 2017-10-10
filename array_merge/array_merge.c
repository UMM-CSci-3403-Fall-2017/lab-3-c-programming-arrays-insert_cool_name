#include<stdio.h>
#include<stdlib.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"

int get_count(int size, int* arr){
	//initialize vars	
	int holder = '\0';
        int count = 0;
        bool zeroesCounted = false;
	
	//iterate through, incrementing count for each unique value
	for(int i = 0; i < size; i++){
		//handle case of values matching our initial holder value
		if((arr[i] == 0) && (zeroesCounted == false) && (i != size-1)){
			count++;
			zeroesCounted=true;
		} if(arr[i] != holder){
                        count++;
                        holder = arr[i];
                }
        }

	return count;
}

void set_array(int uniqCount, int size, int* input, int* output) {
	//initialize vars and set first element to # of unique values	
	int holder = '\0';
        output[0] = uniqCount;
        int n = 1;
	bool zeroesCounted = false;

	//iterate through, setting output to unique values from input
        for(int v = 0; v < size; v++){
		//handle zero case
		if((input[v] == 0) && (zeroesCounted == false) && (v != size-1)){
			output[n] = input[v];
			n++;
			zeroesCounted=true;
		}
	       	if(input[v] != holder){
                        output[n] = input[v];
                        n++;
                        holder = input[v];
                }
        }
}	


int* array_merge(int num_arrays, int* sizes, int** values){
	//initialize vars
	int arrCount=0;
        int* temp;

        //get number of values and make an array of that size
	for(int i = 0; i < num_arrays; i++){
                arrCount+=sizes[i];
        }

        temp = (int*) calloc(arrCount + 1, sizeof(int));
  
	//iterate through and set this array to input values
	int counter = 0;
        for(int j = 0; j < num_arrays; j++){
                for(int q = 0; q < sizes[j]; q++){
                	temp[counter] = values[j][q];
                	counter++;
                }
        }
	
	//sort
        mergesort(arrCount, temp);
	
	//find amount of unique elements
	int count;
	count = get_count(arrCount, temp);
	
	//generate output array and populate it with count and unique values
        int* output;
        output = (int*) calloc(count + 1, sizeof(int));
	set_array(count, arrCount, temp, output);
	
	//free used memory and return result
	free(temp);
	return(output);
}
