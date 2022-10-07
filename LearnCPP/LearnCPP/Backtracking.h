#include <vector>
/*backtracking common property:
    If the problem can only be solved by listing all possibles configurations, and each configuration only be tried once. 
*/
class Backtracking
{
public:
	Backtracking();
	virtual ~Backtracking();

public:
	//-----------Permutations
	void showAllArray(std::vector<int> array);
	void printPermutations(std::vector<int> array, std::vector<bool> used,int length, int index);
	void permutations(size_t size);
	void permutations();

	//-----------KnightTour
	void show2DArray(std::vector<int> array);
	void KnightTourMain();
	bool KnightTour( int x, int y, int move);
	bool KnightTourCheck();
	bool DirectCheck(int x, int y);

	//-----------CircularTour
	void buildCircular( int numPertolPumps, std::vector<int> inputData );
	bool circularTour(int curNode, int totalPertol, std::pair<int, int> nextNode, const int direction);
	void circularTourMain();
	bool checkGas(const int curOil, const int costOil );

private:
	size_t size;
	std::vector<int> array;
	std::vector<bool> used;
	int chessboard[8][8];
	std::vector<std::pair<int, int >> direction;

	//-----------CircularTour
	std::vector<int> _nodePertol;
	std::vector<std::pair<int, int>> _left;
	std::vector<std::pair<int, int>> _right;
	std::vector<bool> _visit;
	int startNode;
};
