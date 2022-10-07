#include "stdafx.h"
#include "Backtracking.h"
#include <iostream>


Backtracking::Backtracking()
{
}

void Backtracking::showAllArray(std::vector<int> array) {
	for (const auto data : array) {
		std::cout << data << " ";
	}
	std::cout << std::endl;
}

void Backtracking::printPermutations(std::vector<int> array, std::vector<bool> used, int length, int i) {
	if (i== length) {
		showAllArray( array);
		return;
	} 

	for (int index = 1; index <= length; index++) {
			
		if (!used[index]) {
			used[index] = true;
			array[i] = index;
			printPermutations(array, used,length, i + 1);
			used[index] = false;
		}
	}
}

void Backtracking::permutations(size_t size) {
	if (size <= 5) {
		this->size = size;
		array.resize(this->size, 0);
		used.resize(this->size + 1, false);
		printPermutations(this->array, this->used, this->size, 0);
	}
}

void Backtracking::permutations() {
	if ( this->size <= 5 )
		printPermutations(this->array,this->used,this->size, 0);
}

//undone 4/10/2019

//Given an empty 8x8 chessboard, the knight starting from first point of chessboard
//would visit each square only onces by following the rule of chess.
void Backtracking::KnightTourMain() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j)
			this->chessboard[i][j] = 0;
	}
	this->direction.push_back(std::make_pair<int, int>(-1, 2));
	this->direction.push_back(std::make_pair<int, int>(2, 1));
	this->direction.push_back(std::make_pair<int, int>(1,2));
	this->direction.push_back(std::make_pair<int, int>(-2, 1));
	this->direction.push_back(std::make_pair<int, int>(-2, -1));
	this->direction.push_back(std::make_pair<int, int>(-1, -2));
	this->direction.push_back(std::make_pair<int, int>(1, -2));
	this->direction.push_back(std::make_pair<int, int>(2, -1));
	//up-right : [-2][+1]		
	//up-left : [-2][-1]
	//down-right: [+2][+1]
	//down-left: [+2][-1]
	//right-up: [-1][+2]
	//right-down:[+1][+2]
	//left-up: [-1][-2]
	//left-down: [+1][-2]

	if (!KnightTour(0, 0, 1)) {
		std::cout << " No solution\n";
	} else {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				std::cout << chessboard[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}
	//1.starting from one of direction, once this direction can't reach change to next.
	//2.stop once all direction can reach and chessboard is all filled with move number 
}

bool Backtracking::KnightTour( int x, int y ,int move) {
	if (move  == 64) {
		return true;
	}

	for (const auto& direct : direction) {
		const auto next_x = x+ direct.first;
		const auto next_y = y + direct.second;
		std::cout << next_x << " " << next_y << std::endl;
		if (DirectCheck(next_x, next_y)) {
			chessboard[next_x][next_y] = move;
			if (KnightTour(next_x, next_y, move + 1)) {
				return true;
			}
			else {
				chessboard[next_x][next_y] = 0;
			}
		}
	}

	return false;

	
}
bool Backtracking::DirectCheck( int x, int y ) {

	return ( (x < 8 && x>=0 && y < 8 && y>=0 ) && !chessboard[x][y] )  ? true : false;
}
bool Backtracking::KnightTourCheck() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (!chessboard[i][j]) {
				return false;
			}
		}
	}

	return true;

}

//-----------CircularTour
void Backtracking::buildCircular(const int numPertolPumps, std::vector<int> inputData) {
	_nodePertol.resize(numPertolPumps, 0);
	_left.resize(numPertolPumps, std::pair<int,int>(0,0));
	_right.resize(numPertolPumps, std::pair<int,int>(0,0));
	_visit.resize(numPertolPumps, false);

	for (int index = 0; index < numPertolPumps; ++index) {
		const int edge = inputData[(index*2) + 1];
		const int value = inputData[(index * 2)];

		int nextNode = index + 1;
		if (index == numPertolPumps - 1) {
			nextNode = 0;
		}
		_nodePertol[index] = value;
		_right[index] = std::pair<int, int>(nextNode, edge);
		_left[nextNode] = std::pair<int, int>(index, edge);
	}


}

bool Backtracking::checkGas(const int curOil, const int costOil) {
	return (curOil - costOil) >= 0 ? true : false;
}
bool Backtracking::circularTour(int curNode, int totalPertol, std::pair<int,int> nextNode, const int direction ) {
#ifdef DEBUG
	std::cout << curNode << " " << "->" << nextNode.first << " v:" << totalPertol << " cost:"<<nextNode.second<<std::endl;
#endif
	if (checkGas(totalPertol, nextNode.second)) {
		if (curNode == startNode && _visit[curNode] ) 
			return true;
		else {
			_visit[curNode] = true;
		}
		
		auto next = _left[nextNode.first];
		if (direction)
			next = _right[nextNode.first];
		
		const auto remainedOil = totalPertol + _nodePertol[nextNode.first] - nextNode.second;

		if (circularTour(nextNode.first, remainedOil , next, direction ))
			return true;
	}

	return false;
}

void Backtracking::circularTourMain() {
	//------Default case
#ifdef DEFAULT
	const int numPertolPumps = 4;
	std::vector<int> inputData{ 4, 6, 6, 5, 7, 3, 4, 5 };
#endif

	const int numPertolPumps = 13;
	std::vector<int> inputData{ 87, 27, 40, 95, 71, 96, 79, 35, 2, 68, 3,98 , 93, 18, 57, 53, 81, 2, 42, 87, 90, 66, 20, 45, 30, 41 };
	buildCircular(numPertolPumps, inputData);
	
	for (int nodeIndex = 0; nodeIndex < numPertolPumps; ++nodeIndex) {
		const auto leftNode = _left[nodeIndex];
		const auto rightNode = _right[nodeIndex];
		const auto pertol = _nodePertol[nodeIndex];
		
		startNode = nodeIndex;
		_visit[startNode] = false;
		if (circularTour(nodeIndex, pertol, rightNode,1))
			std::cout << "Right start at :" << nodeIndex << std::endl;
		std::cout << "--------------" << std::endl;

		startNode = nodeIndex;
		_visit[startNode] = false;
		if (circularTour(nodeIndex, pertol, leftNode, 0))
			std::cout << "Left start at :" << nodeIndex << std::endl;
		std::cout << "--------------" << std::endl;
		
	}
#ifdef DEBUG
	for (int index = 0; index < numPertolPumps; ++index) {
		std::cout << "Node[" << index << "] = " << _nodePertol[index] << " right: " << _right[index].first << " cost: " << _right[index].second << " left: "
			<< _left[index].first << " cost: " << _left[index].second << std::endl;
	}
#endif // DEBUG

}
Backtracking::~Backtracking()
{
}
