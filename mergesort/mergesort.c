#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mergesort.h"

//based on mergesort model from Nic Mcphee's Mergesort.java

bool needsSorting(int rangeSize){
	return rangeSize >= 2;
}

void merge(int values[], int start, int mid, int end){
	
	//still needs memory management
	int rangeSize;
        rangeSize = end - start;
	int target[rangeSize];
	int firstInd;
	firstInd = start;
	int secondInd;
	secondInd = mid;
	int copyInd = 0;

	while(firstInd < mid && secondInd < end) {
		if(values[firstInd] < values[secondInd]){
			target[copyInd] = values[firstInd];
			++firstInd;
		} else {
			target[copyInd] = values[secondInd];
			++secondInd;
		}
		
		++copyInd;
	}

	while(firstInd < mid){
		target[copyInd] = values[firstInd];
		++copyInd;
		++firstInd;
	}
	
	while(secondInd < end){
		target[copyInd] = values[secondInd];
		++copyInd;
		++secondInd;
	}

	int i;

	for(i = 0; i < rangeSize; ++i){
		values[i + start] = target[i];
	}
}
		
void mergesort(int values[], int start, int end){
        //still needs memory management
	int rangeSize;
        rangeSize = end - start;
	if(needsSorting(rangeSize)){
		int mid;
	        mid = (start + end) / 2;
		mergesort(values, start, mid);
		mergesort(values, mid, end);
		merge(values, start, mid, end);	
	}
}
