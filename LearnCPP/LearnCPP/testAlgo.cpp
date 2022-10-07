#include "stdafx.h"
#include "testAlgo.h"

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include<random>

#include "LinkedList.h"
#include "sorting.h"
#include "Backtracking.h"
using namespace std;
using namespace std::chrono;
#define SHOW_RESULT

void timer_record(int);

//TIMER
static high_resolution_clock::time_point start;// = high_resolution_clock::now();
static high_resolution_clock::time_point stop;// = high_resolution_clock::now();
void timer_record(int option) {
	switch (option) {
		case 1:
			start = high_resolution_clock::now();
			break;
		case 2:
			stop = high_resolution_clock::now();
			duration<double> time_span = duration_cast<duration<double>>(stop - start);
			cout << "Times :\t" << time_span.count() << "\tseconds"<<endl;
			break;
	}
}

//--------------------------------------------------------------------------------//


void printArray(vector<int> array) {
	for ( vector<int>::iterator iter = array.begin(); iter!=array.end(); ++iter )
		cout << *iter << " ";
	cout << endl;
}



//reference book C++ Primer
vector<int> get_randVec()
{
	// because engines and distributions retain state, they usually should be
	// defined as static so that new numbers are generated on each call
	// using time(0), which returns time can cause the program get different sequence each time
	static default_random_engine e(time(0));
	uniform_int_distribution<unsigned> n(1, 20);
	unsigned int times = n(e);
	static uniform_int_distribution<int> u(-10000, 10000);
	vector<int> ret;
	for (size_t i = 0; i < times; ++i)
		ret.push_back(u(e));
	return ret;
}

//using STL to shuffle the vector
void Shuffle(vector<int>& array) {
	random_shuffle(array.begin(), array.end());
	cout << "After shuffled" << endl;
	printArray(array);
}

void mergeSortWay(std::vector<int> array) {
	//using call by reference to process array by the called function
	Shuffle(array);
	cout << "mergeSort result" << endl;
	timer_record(1);
	mergeSort(array, 0, array.size());

	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void quickSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "quickSort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	quickSort2(array, 0, array.size() );
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void ShellSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "shellsort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	shellSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void InsertionSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "InsertionSort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	insertionSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

void SelectionSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "selection sort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	selectionSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}

/* example
void algorithmWay(std::vector<int> array ) {
	cout << "xxxx sort result" << endl;
	timer_record(1);
	timer_record(2);
#ifdef SHOW_RESULT
	printArray(array);
	fgetc(stdin);
#endif
}
*/


void BubbleSortWay(std::vector<int> array) {
	Shuffle(array);
	cout << "bubble sort result" << endl;
	//quickSort(array, 0, array.size() - 1);
	timer_record(1);
	bubbleSort(array);
	timer_record(2);
#ifdef SHOW_RESULT 
	printArray(array);
	fgetc(stdin);
#endif
}


void countingSortWay(std::vector<int> array) {
	//std::vector<int> tempArray = { 123, 654, 876, 123, 123, 7677, 4, 534, 467, 9, 345, 161781, 4, 78, 678, 1345, 136, 3568879, 6, 4, 52, 42, 68, 9, 789 };
	Shuffle(array);
	cout << "counting sort result" << endl;
	timer_record(1);
	countingSort(array);
	timer_record(2);
#ifdef SHOW_RESULT
	printArray(array);
	fgetc(stdin);
#endif
}

void Sorting_run() {
	
	vector<int> array = get_randVec();
	cout << "Original Order: " << endl;
	printArray(array);
	cout << endl;

	BubbleSortWay(array);

	SelectionSortWay(array);

	ShellSortWay(array);

	InsertionSortWay( array);

	mergeSortWay(array);

	quickSortWay(array);

	countingSortWay(array);
}

/*
let p_i =  [ p_0, p_1, p_2, ... , p_n ], where i <=n is dimension for A
let A_i's product = p_i-1 * p_i, where 1<=i<=n
let m[i,j] be the optimal cost for A_i to A_j, where 1<=i<j.
let s[i,j] be the index which generated such optimal cost for A_i to A_j.
m[i,j] = { min { m(i, k) + m ( k+1, j ) + p_i-1 * p_k * p_j }, where i<=k<j, or 0 if i == j }
*/

void printOptOrder(const vector< vector<uint32_t>> s, uint32_t i, uint32_t j) {
	if (i == j) {
		cout << " A" << i ;
	}
	else {
		cout << "(";
		printOptOrder(s, i, s[i][j]);
		printOptOrder(s, s[i][j] + 1, j);
		cout << ")";
	}
}

void matrixChainOrder(const vector<uint32_t> p, uint32_t i, uint32_t j) {
	const auto length = p.size();
	vector< vector<uint32_t> > m(length, vector<uint32_t>(length, 0));
	vector< vector<uint32_t> > s(length, vector<uint32_t>(length, 0));

	const auto n = length - 1;
	cout << n << endl;
    for (uint32_t count= 2; count<=n; ++count) {
		for (uint32_t idx= 1; idx<= n- count + 1; idx++) {
			uint32_t idx2= idx+ count-1;
			m[idx][idx2] = UINT32_MAX;
			for (uint32_t k = idx; k <= idx2-1; k++) {
				uint32_t value = m[idx][k] + m[k + 1][idx2] + p[idx2]*p[idx - 1]*p[k];
				if (value < m[idx][idx2]) {
					m[idx][idx2] = value;
					s[idx][idx2] = k;
				}
			}
		}
	}

	cout << "S:" << endl;
	for (uint32_t idx = 0; idx < length; ++idx) {
		for (uint32_t idx2 = 0; idx2 < length; ++idx2) {
			cout << s[idx][idx2] << " ";
		}
		cout << endl;
	}

	cout << "M:" << endl;
	for (uint32_t idx = 0; idx < length; ++idx) {
		for (uint32_t idx2 = 0; idx2 < length; ++idx2) {
			cout << m[idx][idx2] << "\t";
		}
		cout << endl;
	}
	cout << m[i][j] << endl;
	printOptOrder(s, i, j);
	cout << endl;
}

void solution() {
	/*the solution can reference CLRS Figuer15.5 */
	vector<uint32_t> p = { 30,35,15,5,10,20,25 };
	matrixChainOrder(p, 1, 6);
	matrixChainOrder(p, 2, 5);
}

void printArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void printallAnswer(int array[], int n, int i) {
	if (i == n) {
		printArray(array, n);
		return;
	}
	/*
	array[i] = 0;
	printallAnswer(array, n, i + 1);

	array[i] = 1;
	printallAnswer(array, n, i + 1);
	*/
	bool flag = true;
	for (int index = 1; index <= n; index++) {
		flag = true;
		array[i] = index;
		for (int index2 = i - 1; index2 >= 0; index2--) {
			if (array[i] == array[index2] )
				flag = false;
		}
		if (!flag)
			continue;
		printallAnswer(array, n, i + 1);
	}
}


void printallAnswer2(bool used[], int array[], int n, int i) {
	if (i == n) {
		printArray(array, n);
		return;
	}
	for (int index = 1; index <= n; index++) {
		if (!used[index]) {
			used[index] = true;
			array[i] = index;
			printallAnswer(array, n, i + 1);
		}
	}
}

void backtracking() {
	const int number = 4;
	int array[number] = { 0 };
	bool used[number+1] = { false };
	
	//printallAnswer(array, number, 0);
	printallAnswer2(used, array, number, 0);
}

void testLinkedList() {
	LinkedList linkedList;
	linkedList.push(10);
	linkedList.push(9);
	linkedList.push(5);
	linkedList.push(2);
	linkedList.pushFront(22);
	linkedList.show();

	const auto node = linkedList.find(5);
	linkedList.pushAfter(node, 23);
	linkedList.show();

}


void testAlgo::show()
{

	/*Todo:
		1.Replace <int> to T
		2.Added feature StdRandom.shuffle 
	*/
	
	
	//Sorting_run();
	//solution();
	//backtracking();
	//Backtracking backtracking;
	//backtracking.permutations(5);

	//backtracking.KnightTourMain();
	//backtracking.circularTourMain();
	testLinkedList();
	cout << "Done" << endl;
	fgetc(stdin);
}



