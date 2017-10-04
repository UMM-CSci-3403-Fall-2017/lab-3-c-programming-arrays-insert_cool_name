#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mergesort.h"

//based on mergesort model from Nic Mcphee's Mergesort.java

// function to check if our current section is large enough to still need sorting
bool needsSorting(int rangeSize){
	return (rangeSize >= 2);
}

void merge(int values[], int start, int mid, int end){	
	//initialize var and get value range
	int rangeSize;
        rangeSize = end - start;
	
	//make array and allocate space for it
	int* target;
	target = (int*) calloc(rangeSize+1,sizeof(int));
	
	//initialize index vars
	int first, second;
	first = start;
	second = mid;
	int copy = 0;

	//iterate through array, comparing vars and setting destination array
	while(first < mid && second < end) {
		if(values[first] < values[second]){
			target[copy] = values[first];
			++first;
		} else {
			target[copy] = values[second];
			++second;
		}
		++copy;
	}

	while(first < mid){
		target[copy] = values[first];
		++copy;
		++first;
	}
	
	while(second < end){
		target[copy] = values[second];
		++copy;
		++second;
	}
	
	//add null terminator
	target[rangeSize]='\0';
	
	//set array to correct values
	int i;
	for(i = 0; i < rangeSize; ++i){
		values[i + start] = target[i];
	}
	
	//free allocated memory
	free(target);
}
		
void sort(int values[], int start, int end){
	//sets range, and if large enough it splits and sorts elements recursively
	int rangeSize;
        rangeSize = end - start;
	if(needsSorting(rangeSize)){
		int mid;
	        mid = (start + end) / 2;
		sort(values, start, mid);
		sort(values, mid, end);
		merge(values, start, mid, end);	
	} 
}

void mergesort(int size, int values[]){
	//determine index vars, and calls sort
	int start = 0;
	int end;
	end = size;
	sort(values, start, end);
}
