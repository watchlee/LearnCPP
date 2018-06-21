// LearnCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, string> mix_tuple;
void learn_vector() {
	cout << "Learing how to use vector" << endl;

	vector<double> numbers(0);
	cout << " Number: " << numbers.size() << endl;
	
	int capacity = numbers.capacity();
	cout << "Capacity : " << numbers.capacity() << endl;
	//collect data to vector
	for (int i = 0; i < 100; i++ ) {
		if (numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			cout << "Capacity : " << capacity << endl;
		}
		numbers.push_back(i);
	}
	//use iterator to print out info
	for (vector<double>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}
	cout << "Before clear" << endl;
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity : " << numbers.capacity() << endl;

	cout << "After clear, only size will clear" << endl;
	numbers.clear();
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity : " << numbers.capacity() << endl;

	//row in the grid
	cout << "using vector to store vector = 2d array" << endl;
	vector< vector<int> > grid(3, vector<int>(4, 7));
	
	for (int row = 0; row < grid.size(); row++) {
		for (int col = 0; col < grid[row].size(); col++) {
			cout << grid[row][col] << " "<<flush;
		}
		cout << endl;
	}


	//using tuple in vector	
	

	//vector<tuple<int, int, string> > tuple_vector;
	cout << "using vector to store tuple or pair data" << endl;
	cout << "tuple value : age, money, name\n";
	vector<mix_tuple> tuple_vector;
	tuple_vector.push_back(mix_tuple(12,2312352,"John"));
	tuple_vector.push_back(mix_tuple(11,1454345,"Dante"));
	tuple_vector.push_back(mix_tuple(25,123523232,"Mansion"));
	for (vector<tuple<int, int, string>>::iterator it = tuple_vector.begin(); it != tuple_vector.end(); it++) {
		cout << get<0>(*it) << "\t" << get<1>(*it) << "\t" << get<2>(*it) << endl;
	}
	
	//pop value from the begin of vector
	cout << "pop data from vector" << endl;
	mix_tuple temp;
	while (!tuple_vector.empty()) {
		temp = tuple_vector.front();
		tuple_vector.erase(tuple_vector.begin());
		cout << get<0>(temp) << "\t" << get<1>(temp) << "\t" << get<2>(temp) << endl;
	}
	
	fgetc(stdin);

}

#include <list>
void practice_list() {
	//todo list : create menu to add and remove data
	list<int> numbers;
	
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	list<int>::iterator it = numbers.begin();
	it++;
	numbers.insert(it, 100);
	cout << "Elements: " << *it << endl;

	list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	eraseIt = numbers.erase(eraseIt);
	cout << "Element:" << *eraseIt << endl;
	
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		if (*it == 2) {
			numbers.insert(it, 1234);
		}
		if (*it == 1) {
			it = numbers.erase(it);
		}
	}

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}
	fgetc(stdin);


}

#include<map>
//map is key value
void
learn_map() {
	map<string, int> ages;
	ages["Mike"] = 40;
	ages["Roi"] = 20;
	ages["Vicky"] = 30;
	/*ToDo menu system
	*/
	/*
	pair<string, int> addToMap("Peter", 100);
	ages.insert(addToMap);
	*/
	ages.insert(make_pair("PPP", 100));
	
	if (ages.find("Vicky") != ages.end()) {
		cout << ages["Vicky"] << endl;
	}
	else {
		cout << " Key not found" << endl;
	}
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++ ) {
		//what does pair mean?
		pair<string, int> age = *it;
		cout << age.first << ": " << age.second << endl;
	}

	/*
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		cout << it->first << ":\t" << it->second << endl;
	}
	*/

	//My example 
	//using age as key to find names ( Exists many people have same age )
	cout << "Using age as key to find multiple people" << endl;
	map<int, vector<string> >names;
	names[50].push_back("mike");
	names[20].push_back("Jackal");
	names[10].push_back("micky");
	names[30].push_back("Dante");
	names[10].push_back("Dante");
	names[9].push_back("Dante");
	names[30].push_back("Dante");
	names[30].push_back("Dante");
	
	for (map<int, vector<string>>::iterator it = names.begin(); it != names.end(); it++) {
		pair<int, vector<string>> name = *it;
		cout << "Age :" << name.first << endl;
		cout << "Size : " << name.second.size() << endl;
	}
	for (map<int, vector<string>>::iterator it = names.begin(); it != names.end(); it++) {
		pair<int, vector<string>> name = *it;
		for (vector<string>::iterator sit = name.second.begin(); sit != name.second.end(); sit++)
		{
			cout << "Name:" << *sit<< endl;
		}
	}

	fgetc(stdin);
}

void test_outputFile( string name) {
	ofstream outfile;
	outfile.open(name);
	

	if (outfile.is_open()) {
		outfile << "This is the example to test output file!" << endl;
		outfile.close();
	}
}

void test_inputFile(string name) {
	ifstream inputfile;
	inputfile.open(name);
	if (!inputfile.is_open())
		return;

	while (inputfile) {
		string line;
		//getline(inputfile, line);
		inputfile >> line;
		inputfile >> ws;
		if (!inputfile)
			break;
		cout << line << endl;
	}
}

#pragma pack(push, 1)

struct Person
{
	char name[50]; //
	int age; //4bytes
	double weight;//8bytes
};
#pragma pack(pop)

void learn_struct(){
	Person someone = { "Jacal", 16, 52.2 };

	///Write binary file
	string fileName = "test.bin";
	ofstream outfile;
	//need to specify the format of data
	//when using fstream, also need to specify ios::out|ios::binary

	outfile.open(fileName, ios::binary);
	if (outfile.is_open())
	{
		//casting??
		outfile.write(reinterpret_cast<char *>(&someone), sizeof(Person) );
		outfile.close();
	}
	else {
		cout << "can't create the file :" + fileName << endl;
	}
	
	Person someelse = {};
	///read binary file
	ifstream inputFile;
	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open()) {
		inputFile.read(reinterpret_cast<char *>(&someelse), sizeof(Person));
		inputFile.close();
	} 	else {
		cout << "can't read the file :" + fileName << endl;
	}

	cout << someelse.name<<" "<<someelse.age<<" "<<someelse.weight << endl;


}


class _Person {

private:
	string name;
	int age;
	int *money;

public:
	_Person() :name(""), age(0), money(0) { 
		this->money = new int(0);
	}

	_Person(string name, int age, int money) : name( name ), age( age ){
		this->money = new int(money);
		
	}
	

	//copy constructor
	_Person(const _Person &copy) {
		cout << "Copy constructor running!" << endl;
		name = copy.name;
		age = copy.age;
		//money = copy.money;
		money = new int;
		*money = *copy.money;
	}

	void setMoney(int money) {
		*this->money = money;
	}
	void setName(string Name){
		name = Name;
	}

	void setAge( int Age ){
		age = Age;
	}
	
	//when use Object as key, we don't want anything to change it
	//so must use const
	void print() const {
		cout << "name :" << name << "\tage:" << age << "\tmoney: " << *money << endl;
	}

	//when use Object as map key, map must use something to do comparsion
	//for custom Class, it must provide operator to do comparsion
	//Also, use const to prevet another object to change it
	//If only use member name to do comparsion, some object has 
	//different age and money still be viewed as same object.
	//So we should consider all members to do comparsion

	bool operator<(const _Person &other) const {
		if (name == other.name && age == other.age)
			return *this->money < *other.money;
		else if (name== other.name) 
			return age < other.age;
		else 
			return name < other.name;
	}

};


void learn_custom_object_as_map_key() {
	//when using custom Object as map key, each function that custom Object should not change the key
	//and need to create an operator to do comparsion
	map<_Person, int> people;
	people[_Person("Mike", 20, 1000)] = 40;
	people[_Person("Mike", 10, 1000)] = 50;
	people[_Person("Mike", 40, 10000)] = 50;
	people[_Person("Mike", 50, 50000)] = 50;
	people[_Person("Jacky", 45, 1234)] = 23;
	people[_Person("Dante", 12, 5232)] = 50;
	for (map<_Person,int>::iterator it = people.begin(); it != people.end(); it++) {
		it->first.print();
		cout << it->second<<"\n"<< flush;
	}
	fgetc(stdin);
}

void learn_custom_object_as_map_value() {
	map<int, _Person> people;
	people[0] = _Person("Mike", 20,1000);
	people[50] = _Person("Jack", 59,23222);
	people[3] = _Person("trump", 43,1235);
	people.insert(make_pair(55, _Person("Dante", 55,1235)));
	people.insert(make_pair(55, _Person("Bob", 25,1253)));
	for (map<int, _Person>::iterator it = people.begin(); it != people.end(); it++) {
		cout << it->first << " : " << flush;
		it->second.print();
	}

	
	fgetc(stdin);
}


#include<sstream>
void test_fstream_output(std::ostream &output) {
	output << "hello" << endl;
	output.flush();

}


void learn_ostringstream() {
	std::ostringstream os;
	test_fstream_output(os);
	os.str("");
	os.clear();
	string temp = os.str();
	std::cout << temp << std::endl;
	fgetc(stdin);

}


#include<unordered_map>
#include<algorithm>
void lear_unordermap() {
	/*
	you can do like this:


	std::unordered_map<KeyType, MapType> unordered;
	std::vector<KeyType> keys;

	keys.reserve (unordered.size());
	for (auto& it : unordered) {
	keys.push_back(it.first);
	}
	std::sort (keys.begin(), keys.end());
	for (auto& it : keys) {
	std::cout << unordered[it] << ' ';
	}
	*/

	//Learing how to use unordered_map to store, unordered_map is hash_table
	//it cost O(1) on searching value
	//Due to unordered_map is unlike map, which elements is sorted. It must sort by youself


	cout << "Using age as key to find multiple people" << endl;

	//stored data in unordered_map type
	unordered_map<int, vector<string> >names;
	names[50].push_back("mike");
	names[20].push_back("Jackal");
	names[10].push_back("micky");
	names[30].push_back("Dante");
	names[10].push_back("Ate");
	names[9].push_back("DDB");
	names[30].push_back("Michal");
	names[30].push_back("WTF");

	cout << "before sorting" << endl;

	for (unordered_map<int, vector<string>>::iterator it = names.begin(); it != names.end(); it++) {
		pair<int, vector<string>> name = *it;
		cout << "Ages:" << name.first << endl;
		for (vector<string>::iterator sit = name.second.begin(); sit != name.second.end(); sit++)
		{
			cout << "Name:" << *sit<< endl;
		}
	}
	
	//actually unordered_map names doesn't be sorted, only vector<int> keys is sorted by integer.
	//Due to unordered_map is hash_table, by using sorted vector<int> keys to search unordered_map names,
	//still can find out ordered data
	std::vector<int> keys;
	keys.reserve(names.size());
	for (auto& it : names)
		keys.push_back(it.first);

	std::sort(keys.begin(), keys.end());
	cout << "After sorting" << endl;
	for (auto& it : keys) {
		cout << "Ages:" << it << endl;
		for (vector<string>::iterator pit = names[it].begin(); pit != names[it].end(); pit++) {
			cout << "Names:" << *pit << endl;
		}
		
	}

	//learning 
	unordered_map< string, int> strtoint;
	strtoint["hello"] = 0;
	strtoint["hello"]++;
	for( auto &it : strtoint )
	cout << it.first << " " << it.second << endl;

}



int main()
{
	//practice_list();
	//learn_map();
	//lear_unordermap();
	//test_outputFile("test");
	//test_inputFile("test");

	//learn_vector();

	learn_custom_object_as_map_value();
	learn_custom_object_as_map_key();
	//learn_ostringstream();
		

	return 0;
}

