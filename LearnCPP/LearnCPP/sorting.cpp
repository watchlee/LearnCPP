#include "stdafx.h"
#include "sorting.h"
#include <algorithm>
#include <iostream>

void shellSort(std::vector<int> &array) {
	//Stuck	
	int N = array.size();
	int h = 1;
	while (h < (N / 3))
		h = 3 * h + 1;
	while (h >= 1) {
		for (int i = h; i < N; i++) {
			for (int j = i; j >=h && array[j] < array[j - h]; j -= h) {
				int temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
			}
		}
		h = h / 3;
	}
}

void insertionSort(std::vector<int> &array) {
	for (int UnsortedIndex = 1; UnsortedIndex < array.size(); UnsortedIndex++) {
		int SortedIndex = 0;
		
		
		/*int temp = array[UnsortedIndex];
		for (SortedIndex = UnsortedIndex; SortedIndex > 0 && array[SortedIndex- 1] > temp; SortedIndex--)
			array[SortedIndex] = array[SortedIndex - 1];
		array[SortedIndex] = temp;
		*/

		for (SortedIndex = UnsortedIndex; SortedIndex > 0 && array[SortedIndex] < array[SortedIndex - 1]; SortedIndex--) {
			int temp = array[SortedIndex];
			array[SortedIndex] = array[SortedIndex - 1];
			array[SortedIndex - 1] = temp;
		}

	}
}


void merge(std::vector<int> &array, int start, int middle, int end) {
	//what the heck is it?
	if (array[middle - 1] <= array[middle])
		return;

	int i = start;
	int j = middle;
	int tempindex = 0;

	std::vector<int> temp;
	//merge two blocks to one
	while (i < middle && j < end) {
		//compare tow blocks, determine which block's element is small and put it into vector 
		temp.push_back(array[i] <= array[j] ? array[i++] : array[j++]);
		tempindex++;
	}

	//after combined, copy temp data to original array
	int temp_des = start + tempindex, temp_source = i;
	for (int times = 0; times < (middle - i); times++)
	{
		array[temp_des++] = array[temp_source++];
	}

	temp_des = start;
	for (int times = 0; times < tempindex; times++) {
		array[temp_des++] = temp[times];
	}


}

void mergeSort(std::vector<int> &array, int start, int end) {
	if ( ( end - start ) < 2) // while only one element need to sort, stop!
		return;
	//using divide and conquer algorithm to solve the probelm
	int middle = (start + end) / 2;
	//keep dividing until only one element
	mergeSort( array, start, middle);
	mergeSort(array, middle, end);
	merge(array, start, middle, end);
}

int min(int x, int y) {
	return x < y ? x : y;
}

void mergeSort_iteration(std::vector<int> &array) {

	int start1, end1, start2, end2;
	std::vector<int> temp;
	for (int times = 1; times < array.size(); times = 2 * times) {
		for (int offset = 0; offset < array.size(); offset += 2 * times) {
			start1 = offset;
			end1 = min(offset + times, array.size());
			start2 = end1;
			end2 = min(offset + (times * 2), array.size());
			while (start1 < end1 && start2 < end2)
				temp.push_back(array[start1] < array[start2] ? array[start1++] : array[start2++]);
			//put remain elements into temp array
			while (start1 < end1)
				temp.push_back(array[start1++]);
			while (start2 < end2)
				temp.push_back(array[start2++]);

		}
		//using vector::assign to copy temp array to array
		array.assign(temp.begin(), temp.end());
		temp.clear();
	}
}

void selectionSort(std::vector<int> &array) {

	for (int i = 0; i < array.size(); i++) {
		int smallestIndex = i;
		for (int j = i; j < array.size(); j++) {
			if (array[smallestIndex] > array[j])
				smallestIndex = j;
		}

		int temp = array[i];
		array[i] = array[smallestIndex];
		array[smallestIndex] = temp;
	}

}

void bubbleSort(std::vector<int> &array) {
	for (int count = 0; count < array.size(); count++)
	{
		for (int count2 = 0; count2 < array.size()-count-1; count2++) {
			if (array[count2] > array[count2+1]) {
				int temp = array[count2];
				array[count2] = array[count2+1];
				array[count2 + 1] = temp;
			}
		}
	}
}

void quickSort(std::vector<int> &array, int left, int right) {
	int i = left, j = right;
	int temp;
	int pivot = array[(left + right )/ 2];
	while (i <= j) {
		while (array[i] < pivot) i++;
		while (array[j] > pivot) j--;
		if (i <= j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(array, left, j);
	if (i < right)
		quickSort(array, i, right);
}

int partition(std::vector<int>&array, int left, int right) {
	int i = left, j = right;
	int pivot = array[left];
	//why it can work? Due to pivot is temporary stored array[left]
	while (i < j) {
		while (i < j && array[--j] >= pivot);
		if (i < j) {
			array[i] = array[j];
		}
		while (i < j && array[++i] <= pivot);
		if (i < j)
			array[j] = array[i];
	}
	array[j] = pivot;
	return j;
}


void quickSort2(std::vector<int>&array, int left, int right) {
	if ((right- left) < 2)
		return;
	int pivotIndex = partition(array, left, right);
	quickSort2(array, left, pivotIndex);
	quickSort2(array, pivotIndex+1, right);
	
}


/*the counting sort is not like others sorting algorithm*/
void countingSort2(std::vector<int> &array, int min, int max) {
	/*there is a limit for counting sort*/
	/*its size is depend on the input
	* if the input number is too huge 
	* then sorting can not be used
	*/
	std::cout << "MAX:" << max << " MIN:" << min << std::endl;
	std::vector<int> countArray;
	countArray.resize((max - min) + 1);
	for (int i = 0; i < array.size(); i++) {
		countArray[array[i] - min] ++;
	}

	int j = 0;
	for (int i = min; i <= max; ++i) {
		while (countArray[i - min] > 0) {
			array[j++] = i;
			countArray[i - min] --;
		}
	}
}


/*find max and min to pass*/
void countingSort(std::vector<int> &array) {
	auto min = *std::min_element(array.begin(), array.end());
	auto max = *std::max_element(array.begin(), array.end());
	countingSort2(array, min, max);
}
