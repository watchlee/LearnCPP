// LearnCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include<algorithm>

#include "testAlgo.h"

using namespace std;
void learn_template();
void learn_template_lambda();
void learn_template_vector();
void unordered_set_begin();
void unordered_set_insert();
void unordered_set_loopAndPop();
void insert_unordered_map();
void learn_ascii();
void learn_continue();
void learn_copy_vectors();
void reverse_order_loop();
void learn_bit_function();
typedef tuple<int, int, string> mix_tuple;

//learning how to sort vector by userdefined class
class Test_Vector
{
public:
	Test_Vector();
	Test_Vector(int age, std::string name) : _age(age), _name(name) {}
	void show();
	friend bool comp(const Test_Vector &a, const Test_Vector &b);
private:
	int _age;
	std::string _name;
};

void Test_Vector::show() {
	cout << "Name : " << this->_name << " Age : " << this->_age << endl;
}


bool comp(const Test_Vector &a, const Test_Vector &b) {
	//return a._name < b._name;
	return a._age < b._age;
}


void sorting_defined_vector() {
	vector<Test_Vector> tests;
	tests.push_back(Test_Vector(365, "Dante"));
	tests.push_back(Test_Vector(34, "James"));
	tests.push_back(Test_Vector(1, "Vicky"));
	tests.push_back(Test_Vector(21, "Dae"));
	tests.push_back(Test_Vector(34, "Jawwmes"));
	tests.push_back(Test_Vector(1123, "Vicxwky"));
	
	//for sorting elements in userdefined class, it must give a way to compare element due to compiler doesn't know
	//how to sort such elements by what kind of order
	sort(tests.begin(), tests.end(), comp);
	//without give a way to sort data, compiler will report error
	//sort(tests.begin(), tests.end());
	for (auto it : tests) {
		it.show();
	}
	fgetc(stdin);

}

typedef tuple<double,double,double> threeTuple;

bool comp3(const threeTuple &a, const threeTuple &b) {
	//return a._name < b._name;
	const auto &aV = std::get<2>(a);
	const auto &bV = std::get<2>(b);
	return aV < bV;
}
bool comp2(const threeTuple &a, const threeTuple &b) {
	//return a._name < b._name;
	const auto &aV = std::get<1>(a);
	const auto &bV = std::get<1>(b);
	return aV < bV;
}

bool comp1(const threeTuple &a, const threeTuple &b) {
	//return a._name < b._name;
	const auto &aV = std::get<0>(a);
	const auto &bV = std::get<0>(b);
	return aV < bV;
}

void sorting_tuple_vector() {
	vector<threeTuple> tuple_vector;
	tuple_vector.push_back(threeTuple(0.1, 111.5, 54.9));
	tuple_vector.push_back(threeTuple(0.9, 4.5, 6.9));
	tuple_vector.push_back(threeTuple(0.45, 66.5, 877.9));
	tuple_vector.push_back(threeTuple(0.32, 42.5, 12.9));
	tuple_vector.push_back(threeTuple(0.65, 33.5, 0.9));

	sort(tuple_vector.begin(), tuple_vector.end(), comp1);
	for (auto it : tuple_vector ) {
		cout << " " << std::get<0>(it) << " " << std::get<1>(it) << " "<< std::get<2>(it) << endl;
	}
	std::cout << std::endl;
	sort(tuple_vector.begin(), tuple_vector.end(), comp2);
	for (auto it : tuple_vector ) {
		cout << " " << std::get<0>(it) << " " << std::get<1>(it) << " "<< std::get<2>(it) << endl;
	}
	std::cout << std::endl;
	sort(tuple_vector.begin(), tuple_vector.end(), comp3);
	for (auto it : tuple_vector ) {
		cout << " " << std::get<0>(it) << " " << std::get<1>(it) << " "<< std::get<2>(it) << endl;
	}
	fgetc(stdin);

}
//--------------------------------------------------//
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

	const auto data = tuple_vector.back();
	auto a1 = std::get<0>(data);
	auto a2 = std::get<1>(data);
	auto a3 = std::get<2>(data);

	cout << a1 << " " << a2 << " " << a3 << endl;
	fgetc(stdin);
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

void learn_find_vector() {
	std::vector<int> ID;
	cout << ID.size() << endl;
	const int size = ID.size() ? ID.size() : 100;
	std::vector<int> ID2( size );
	cout << ID2.size() << endl;
	ID2[1] = 1;
	fgetc(stdin);
}

//learn how to copy multiple vectors to a vector.
void learn_copy_vectors() {
	std::vector<std::string> vec1 = { "Dante", "Vergil", "Wendy", "Hudson", "Jacak" };
	std::vector<std::string> vec2 = { "Trump", "Donald", "Reaven","Trash","Waston","Freak" };
	std::vector<std::string> vec3;
	//vec3.insert(vec3.end(), vec1.begin(), vec1.end());
	vec3 = vec1;
	vec3.insert(vec3.end(), vec2.begin(), vec2.end());
	/*vec3.resize(vec1.size());
	std::copy(vec1.begin(), vec1.end(), vec3.begin());*/
	for (const auto &it : vec3) {
		std::cout << it << std::endl;
	}

	fgetc(stdin);
}

void learn_double_loop_vector() {
	std::vector<int> array;
	for (int i = 0; i < 10; ++i) {
		array.push_back(i);
	}
	
	//using two iterator to loop vector
	for (vector<int>::iterator it = array.begin(); it != array.end(); ++it) {
		for (vector<int>::iterator it2 = it + 1; it2 != array.end(); ++it2) {
			cout << *it << " " << *it2 << endl;
		}
	}
	fgetc(stdin);
	
}

bool myfunction(int i, int j) { return (i < j); }
void learn_stl_binary_search() {
	int myints[] = { 1,2,3,4,5,4,3,2,1 };
	std::vector<int> v(myints, myints + 9);                         // 1 2 3 4 5 4 3 2 1
	// using default comparison:
	std::sort(v.begin(), v.end());

	for (auto it : v) {
		std::cout << it << "\t";
	}
	cout << endl;


	std::cout << "looking for a 3... ";
	if (std::binary_search(v.begin(), v.end(), 3))
		std::cout << "found!\n"; else std::cout << "not found.\n";

	// using myfunction as comp:
	std::sort(v.begin(), v.end(), myfunction);

	std::cout << "looking for a 6... ";
	if (std::binary_search(v.begin(), v.end(), 6, myfunction))
		std::cout << "found!\n"; else std::cout << "not found.\n";
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

//using map to record each student's all score for learning map<string, vector<int> > scores
void map_complex_data_type() {
	map< string, vector<int> > scores;
	scores["John"].push_back(90);
	scores["John"].push_back(20);
	scores["John"].push_back(60);

	scores["Dick"].push_back(25);
	scores["Dick"].push_back(65);
	scores["Dick"].push_back(66);

	for (map<string, vector<int> >::iterator it = scores.begin(); it != scores.end(); ++it) {
		string name = it->first;
		vector<int> scoreList = it->second;
		//the way to loop data in vector
		for (vector<int>::iterator it2 = scoreList.begin(); it2 != scoreList.end(); ++it2) {
			cout << *it2 << endl;
		}
		cout <<"--------------------" <<endl;
		for (auto scoreIt : it->second) {
			cout << scoreIt << " "<<flush;
		}
		cout <<"\n--------------------" <<endl;
		
	}

	fgetc(stdin);
}
//-----------------------------------------------------------------------------//
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
//reference it http://www.cplusplus.com/reference/map/map/
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

//#include <map>
//using map library to call multimap
void learn_multimap() {
	std::cout << sizeof(multimap<int, vector<int>>::value_type) << std::endl;
	std::cout << "Size of multimap: " << sizeof(multimap<int, vector<int>>) << std::endl;

	multimap<int, vector<int>> test;
	test.insert(make_pair(1, 1));
	test.insert(make_pair(2, 1));
	test.insert(make_pair(3, 1));
	for (multimap<int, vector<int>>::iterator it = test.begin(); it != test.end(); ++it) {
		for( int j =0; j < 50; ++j)
			it->second.push_back(j);
	}
	size_t total= 0;
	for (multimap<int, vector<int>>::iterator it = test.begin(); it != test.end(); ++it) {
		for (vector<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			std::cout << it->first << " " << *it2 << endl;
		}
	}
	std::cout << "Size of vector<int> :" << sizeof(vector<int>::value_type) << endl;
	for (multimap<int, vector<int>>::iterator it = test.begin(); it != test.end(); ++it) {
		std::cout <<"Size of each vector : "<< sizeof(vector<int>::value_type)*it->second.size() << " size:"<< it->second.size()<<std::endl;
		total += sizeof(vector<int>::value_type) * it->second.size();
	}


	total+= sizeof(multimap<int, vector<int>>::value_type) * test.size();
	std::cout << "Total size = " << total << endl;
	std::cout << "Size of multimap :"<<sizeof(multimap<int, vector<int>>::value_type) << endl;
	std::cout << sizeof(multimap<int, vector<int>>::value_type) * test.size() << endl;


	std::cout << sizeof(multimap<int,pair<int, int>>) << endl;
	std::cout << sizeof(multimap<int,pair<int, int>>::value_type) << endl;

	multimap<int, string> lookup;
	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Jackal"));
	lookup.insert(make_pair(30, "Ray"));
	lookup.insert(make_pair(20, "Bob"));
	
	//normal way to print out data
	for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}


	//also can use find() to print out, by using find()
	for (multimap<int, string>::iterator it = lookup.find(20); it != lookup.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

	std::cout << std::endl;
	//the first iterator is point to the start of range, and the second iterator is point to the off of the end of the map
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
	for (multimap<int, string>::iterator it = its.first; it != its.second; ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}


	//C++11 provides new feature "auto", it can help to reduce the code
	std::cout << std::endl;
	auto cx11_its= lookup.equal_range(30);
	//the first iterator is point to the start of range, and the second iterator is point to the off of the end of the map
	for (multimap<int, string>::iterator it = cx11_its.first; it != cx11_its.second; ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}



	fgetc(stdin);
	
}

class Test
{
public:
	Test( int id, string name) : id(id),name(name){}

	void print() const{
		std::cout << "Id: " << id << " " << name << std::endl;
	}

	//custom object used by library must add following operation to help the library to determine the order

	bool operator<(const Test &other ) const {
		if (name == other.name)
			return id < other.id;
		else
			return name < other.name;
	}

private:
	int id;
	string name;

};

#include<set>
void learn_sets() {
	set<int> numbers;
	numbers.insert(10);
	numbers.insert(2);
	//duplicated insert elements doesn't increase the size of set when the set already exists same element
	//each element in set is unique and the set is sorted
	//set is good to use to remove duplicated elements and sorted them, if you only want to store each different
	//element only once.
	numbers.insert(50);
	numbers.insert(50);
	numbers.insert(70);

	for (set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		std::cout << *it << std::endl;
	
	//set<int>::iterator itFind = numbers.find(10);
	auto itFind = numbers.find(10);
	set<int>::iterator itFind2 = numbers.find(2);

	if (itFind != numbers.end())
		std::cout << "Found : " << *itFind << std::endl;

	if (numbers.count(50)) {
		std::cout << numbers.count(50) << std::endl;
	}

	//	Given custom object
	set<Test> tests;
	tests.insert(Test(1, "Jac"));
	tests.insert(Test(2, "Qui"));
	tests.insert(Test(3, "Bobb"));
	tests.insert(Test(23, "Bobb"));

	for (set<Test>::iterator it = tests.begin(); it != tests.end(); ++it) {
		it->print();
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


//---------------------------learn unordered_map-------------------------------------//
#include<unordered_map>

const unordered_map<string, int> fixedHash = { {"Hello",2}, {"Jack",4} };
class Car {
private:
	string name;
	int price;
public:
	Car(string name, int price):name(name), price(price){}
	Car():name(""),price(0){}

	//copy constructor
	Car(const Car &copy) {
		name = copy.name;
		price = copy.price;
	}

	void show() const {
		std::cout << this->name << "\t" << this->price << std::endl;
	}
	bool operator<(const Car &other) const {
		return name < other.name;
	}
};

//passing unordered_map arguments by reference
void referenceUnorderedMap(std::unordered_map<int,int> &test) {
	test[0] = 1;
}


void pass_unorderedMap() {
	std::unordered_map<int, int> test;
	referenceUnorderedMap(test);
	for (auto it : test) {
		cout << it.first<<" "<<it.second << endl;
	}
	fgetc(stdin);
}

void learn_unordermap() {
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
	for (auto& it : names) {
		for (vector<string>::iterator sit = it.second.begin(); sit != it.second.end(); sit++) {
			cout << *sit << endl;
		}
		keys.push_back(it.first);
	}
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
	cout << strtoint["hello"] << endl;
	for( auto &it : strtoint )
	cout << it.first << " " << it.second << endl;

	//testing fixed unorderedmap
	cout << "Static UnorderedMap:\n";
	cout<< fixedHash.at("Hello") << endl;
	fgetc(stdin);
}

//how to copy value from unodered_map to anothe unordered_map
void copy_unordered_map() {
	unordered_map<int, uint8_t> ID;
	ID[1] = 15;
	ID[3] = 15;
	ID[5] = 15;
	ID[6] = 15;
	ID[10] = 15;
	for (auto it : ID) {
		cout << it.first << " " << +it.second << endl;
	}
	unordered_map<int, uint8_t> ID2;
	unordered_map<int, uint8_t> ID3;
	int index = 0;
	for (auto it : ID) {
		//ID2[index++] = it.second;
		ID2[index++] = ID.at(it.first);
		auto ptr = ID.at(it.first);
		cout << "ass" << +ptr << endl;
	}
	auto test = ID[11];
	cout << test << endl;
	ID2.swap(ID);	
	ID.swap(ID3);
	for (auto it : ID) {
		cout << it.first << " " << +it.second << endl;
	}
	fgetc(stdin);
	
}

//can reference this solution, when using class as unordered_map key, it needs two functions hash function and comparsion.
//https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
void learn_custom_object_as_unorder_map_key() {
	//unordered_map< Car,int> Customer;
	/*
	Customer[Car("BMW X4", 2000000)] = "Hans";
	Customer[Car("Camry", 1000000)] = "Jack";
	Customer[Car("Audi", 3000000)] = "Scar";
	for (unordered_map<Car, string>::iterator it = Customer.begin(); it != Customer.end(); ++it) {
		std::cout << it->second << std::endl;
	}
	*/

}

//learn shared_ptr, If multiple shared_pointers point to same value, which means they point to same object instead of allocation new object for each pointer seperately
//It will free the memory of object once no any pointers point to.
void learn_shared_pointer_with_vector() {
	//first at all try to create a shared_pointer vector
	std::shared_ptr<std::vector<int>> sharedIntVector;
	std::vector<int> test;
	test.push_back(1);
	test.push_back(22);
	test.push_back(33);
	sharedIntVector =  std::make_shared<std::vector<int>>(test);
	std::shared_ptr<std::vector<int>> sharedIntVector2(sharedIntVector);
	std::cout << &test << " " << sharedIntVector << " " << sharedIntVector2 << std::endl;
	
}

unordered_map<int, std::vector<std::tuple<double, double, uint8_t>> *> globalMap;
//const auto defaultT = std::tuple<double, double, uint8_t>(0.0, 1.0, 3);
//std::vector<std::tuple<double, double, uint8_t>> tupVec;
void learn_global_memory_pointer() {
	std::cout << "global pointer map" << std::endl;
	for (const auto data : globalMap) {
		std::cout << data.first << ":" << std::endl;
		std::cout << data.second << std::endl;
		auto *vec = data.second;
		for (std::vector<std::tuple<double, double, uint8_t>>::iterator it = vec->begin(); it != vec->end(); it++) {
			const auto speedValue = unsigned(std::get<2>(*it));
			std::cout << std::get<0>(*it) << " " << std::get<1>(*it) << " " << speedValue << std::endl;
		}
	}

}
using Key = std::hash<std::string>;
using KeyPointer = std::unique_ptr<size_t>;
using KeyMap = std::vector<KeyPointer>;
void learn_unique_memory_ptr() {
	KeyMap _keyMap;
	_keyMap.resize(5);
	size_t keyLog = Key{}("12345");
	size_t keyLog2= Key{}("54321");
	std::cout << "first key = " << keyLog << " second key = " << keyLog2 << std::endl;
	_keyMap[0] = std::make_unique<size_t>(keyLog);
	_keyMap[1] = std::make_unique<size_t>(keyLog2);
	_keyMap[2] = std::make_unique<size_t>(keyLog);
	_keyMap[3] = std::make_unique<size_t>(keyLog2);
	_keyMap[4] = std::make_unique<size_t>(keyLog);
	std::cout << "unique pointer map " << std::endl;

	size_t index = 0;
	for (KeyMap::iterator it = _keyMap.begin(); it != _keyMap.end(); it++) {
		std::cout << " Index = " << index << " value = " << *it << " "<<*it->get()<< std::endl;
		index++;
	}


}

void copy_pointer_vector(std::vector<std::tuple<double,double,uint8_t> > *tempVec ) {
	const auto defaultT= std::tuple<double, double, uint8_t>(0.0, 2.0, 10);
	std::vector<std::tuple<double, double, uint8_t>> tupVec;
	tupVec.push_back(defaultT);
	tupVec.swap(*tempVec);
}
//try to store pointer item in unordered_map 
void learn_unordered_map_pointer() {
	unordered_map<int, std::vector<std::tuple<double, double, uint8_t>> *> tupleMap;
	const auto defaultT= std::tuple<double, double, uint8_t>(0.0, 1.0, 3);
	static std::vector<std::tuple<double, double, uint8_t>> tupVec;
	tupVec.push_back(defaultT);
	std::vector<std::tuple<double, double, uint8_t>> *pointerVec;
	pointerVec = &tupVec;
	tupleMap[0]= &tupVec;
	tupleMap[1]= &tupVec;
	tupleMap[2]= &tupVec;

	
	globalMap[0] = pointerVec;
	globalMap[1] = pointerVec;
	globalMap[2] = pointerVec;
	copy_pointer_vector(&tupVec);
	std::vector<std::tuple<double, double, uint8_t>> secondTupVec;
	secondTupVec.push_back(std::make_tuple(0.0,0.5,3));
	secondTupVec.push_back(std::make_tuple(0.5,0.6,2));
	secondTupVec.push_back(std::make_tuple(0.6,1.0,4));
	tupleMap[3] = &secondTupVec;
	//globalMap[3] = &tupVec;

	for (const auto data : tupleMap) {
		std::cout << data.first << ":" << std::endl;
		std::cout << data.second << std::endl;
		auto *vec = data.second;
		for (std::vector<std::tuple<double,double,uint8_t>>::iterator it = vec->begin(); it != vec->end(); it++) {
			const auto speedValue = unsigned(std::get<2>(*it));
			std::cout << std::get<0>(*it)<<" "<<std::get<1>(*it)<<" "<<speedValue<<std::endl;
		}
	}
	std::cout << "--------------------------" << std::endl;
		

	unordered_map<int, std::vector<Car> *> map;
	const Car car("BMW", 200000);
	std::vector<Car > defaultCar;
	defaultCar.push_back(car);
	map[0] = &defaultCar;
	map[1] = &defaultCar;
	std::vector<Car > test;
	test.push_back(Car("Carmy", 123));
	test.push_back(Car("army", 3233));
	test.push_back(Car("rmy", 4123));
	test.push_back(Car("rmy", 415123));
	map[2] = &test;
	for (const auto data : map) {
		std::cout << data.first << ":" << std::endl;
		std::cout << data.second << std::endl;
		auto *vec = data.second;
		for (std::vector<Car>::iterator it = vec->begin(); it != vec->end(); it++) {
			it->show();
		}
	}

}

//---------------------------learn unordered_map-------------------------------------//
//---------------------------default parameter in function and class-----------------//
uint8_t testingCalculate(const uint8_t numberA, const uint8_t numberB = 2) {
	return numberA + numberB;
}
 void learn_default_parameter_function_call() { //given number = 12
	uint8_t numberA = 12;
	std::cout << unsigned(testingCalculate(numberA)) << std::endl;
	fgetc(stdin);
}

vector<int> global;
void learn_lambda() {

	for (int i = 0; i < 100; ++i) {
		global.push_back(i);
	}
	auto isOk = [&](const int id, vector<int> &temp) ->void{
		auto cid = global.at(id);
		if (cid)
			temp.push_back(cid);
	};

	vector<int> temp;
	isOk(10,temp);
	isOk(11,temp);
	cout << temp.size() << endl;
	for (auto it : temp) {
		cout << it << endl;
		if (it == temp.back())
			cout << "\nthis is end\n";
	}
	fgetc(stdin);
	
}

void learn_lambda_call_by_ref() {
	auto test = [&](const int id, size_t weight) {
		if (id < 10) {
			weight = 10;
		};
		return false;
	};

	int id = 9;
	size_t weight = 0;
	test(id, weight);
	cout << weight << endl;
	fgetc(stdin);
}

//using unordered_set library
void learn_unordered_set()
{
	unordered_set_begin();
	unordered_set_insert();

	unordered_set_loopAndPop();
}

//using auto as pointer to modify value
void learn_auto_pointer()
{
	unsigned int number = 100;
	auto &pointer = number;
	std::cout << "pointer:" << pointer << " number:" << number << std::endl;
	pointer = 10;
	std::cout << "pointer:" << pointer << " number:" << number << std::endl;


	fgetc(stdin);
}

/*this practice is to contruct a table that can be used in project
  This is a issue table that can tell how many  and employee should and can handle
  Construct a table that contain { ID, # of car, # of employee, Vector containing how many car should be fixed}*/
#include <ctime>
void initialize_table(std::unordered_map<int, std::tuple<int, int, std::vector<int>>> &table, int ID) {
	srand(time(NULL));
	int car = (rand() % 20)+1; 
	int employee = (rand()%100)+1;
	int carId = rand() % 100000 + 1;
	table[ID] = std::make_tuple(car, employee, std::vector<int>{carId});

}

void insert_data_table(std::unordered_map<int, std::tuple<int, int, std::vector<int>>> &table, int ID) {
	srand(time(NULL));
}
void practice_implement() {
	//using hash map to access data, the problem is how to store vector into tuple???
	std::unordered_map<int, std::tuple<int, int, std::vector<int> > > table;
	initialize_table(table, 12);
	auto temp = table[12];


	/*after update*/
	cout << "Cars: "<<std::get<0>(temp)  << endl;
	cout << "Employee: "<<std::get<1>(temp)  << endl;
	for (auto it : std::get<2>(temp)) {
		cout << it<<" ";
	}
	cout << endl;

	auto find = table.find(12);
	if (find != table.end()) {
		cout << "Found data in table" << endl;
		srand(time(NULL));
		int cars = (rand() % 10) + 1;
		for (int i = 0; i < cars; ++i) {
			int rand_number = (rand() % 100000) + 1;
			cout << "Store number " << rand_number << endl;
			std::get<0>(temp) += 1;
			std::get<2>(temp).push_back(rand_number);
		}
	}
	
	/*after update*/
	cout << "Cars: "<<std::get<0>(temp)  << endl;
	cout << "Employee: "<<std::get<1>(temp)  << endl;
	for (auto it : std::get<2>(temp)) {
		cout << it<<" ";
	}
	cout << endl;

	fgetc(stdin);
}


using TEST_VEC = std::tuple<int, int, string>;
using TEST_VEC_PTR = std::tuple<int, int, string> *;
std::vector<TEST_VEC_PTR> globalVec;
std::vector<std::vector<TEST_VEC>::iterator> globalVecIter;

TEST_VEC *getPtr( const size_t index)
{
	return globalVec[index];
}

void pointer_to_vec()
{
	std::vector<TEST_VEC> vec;
	vec.push_back(TEST_VEC(0, 1, "ax"));
	vec.push_back(TEST_VEC(1, 2, "mx"));
	vec.push_back(TEST_VEC(2, 3, "lx"));
	vec.push_back(TEST_VEC(3, 4, "vx"));
	const auto &size = vec.size();



	/*consider iterator */
	//std::cout << &vec.begin() << std::endl;
	globalVecIter.push_back(vec.begin());
	globalVecIter.push_back(vec.begin());
	globalVecIter.push_back(vec.begin());
	std::cout << "Consider iterator: " << std::endl;
	//std::vector<std::vector<TEST_VEC>::iterator> globalVecIter
	globalVecIter[1]++;
	globalVecIter[2] = globalVecIter[1];
	globalVecIter[2]++;
	for (const auto &iter : globalVecIter) {
		auto data = iter;
		while ( data != vec.end()) {
			std::cout << " Value :" << std::get<0>(*data) << " " << std::get<1>(*data) << " " << std::get<2>(*data) ;
			data++;
		}
		std::cout<<"\n";

	}
	vec.emplace_back(TEST_VEC(5, 10, "vx"));
	//std::cout << &vec.begin() << std::endl;
	globalVecIter.clear();
	globalVecIter.push_back(vec.begin());
	globalVecIter.push_back(vec.begin());
	globalVecIter.push_back(vec.begin());
/*
	for (const auto &iter : globalVecIter) {
		auto data = iter;
		while (data != vec.end()) {
			std::cout << " Value :" << std::get<0>(*data) << " " << std::get<1>(*data) << " " << std::get<2>(*data);
			data++;
		}
		std::cout << "\n";
	}
	*/
	std::cout << "End" << std::endl;
	/*------------------*/

	
	unordered_map<int, TEST_VEC *> test;
	test[0] = vec.data();
	std::vector<TEST_VEC>::iterator iter;
	std::vector<TEST_VEC>::iterator iter2;
	std::vector<TEST_VEC>::iterator iter3;
	iter = vec.begin();
	iter2 = vec.begin();
	iter3 = vec.begin();
	std::cout << "vec iter end" << std::endl;
	TEST_VEC *p = test[0];
	TEST_VEC *p2 = test[0];
	TEST_VEC *p3 = test[0];
	p2++;
	p3 = p2;
	p3++;
	std::cout << "Value :" << std::get<0>(*p) << " " << std::get<1>(*p) << " "<<std::get<2>(*p) << std::endl;
	std::cout << "Value :" << std::get<0>(*p2) << " " << std::get<1>(*p2) << " "<<std::get<2>(*p2) << std::endl;
	std::cout << "Value :" << std::get<0>(*p3) << " " << std::get<1>(*p3) << " "<<std::get<2>(*p3) << std::endl;

	iter2++;
	iter3 = iter2;
	iter3++;
	std::cout << "Value :" << std::get<0>(*iter) << " " << std::get<1>(*iter) << " "<<std::get<2>(*iter) << std::endl;
	std::cout << "Value :" << std::get<0>(*iter2) << " " << std::get<1>(*iter2) << " "<<std::get<2>(*iter2) << std::endl;
	std::cout << "Value :" << std::get<0>(*iter3) << " " << std::get<1>(*iter3) << " "<<std::get<2>(*iter3) << std::endl;
	while (iter != vec.end()) {

		std::cout << "Value :" << std::get<0>(*iter) << " " << std::get<1>(*iter) << " " << std::get<2>(*iter) << std::endl;
		iter++;
	}

	unordered_map<int, std::vector<TEST_VEC> > newTest;
	newTest[0] = vec;
	newTest[0].push_back(TEST_VEC(0, -1, "cx"));
	globalVec.push_back(newTest[0].data());
	//TEST_VEC *ap = newTest[0].data();
	TEST_VEC *ap = getPtr(0);
	TEST_VEC *ap2 = ap;
	while (std::get<1>(*ap) != -1) {
		std::cout << "new Value :" << std::get<0>(*ap) << " " << std::get<1>(*ap) << " " << std::get<2>(*ap) << std::endl;
		ap++;
	}
//	ap = getPtr(0);
	while (std::get<1>(*ap2) != -1) {
		std::cout << "new Value :" << std::get<0>(*ap2) << " " << std::get<1>(*ap2) << " " << std::get<2>(*ap2) << std::endl;
		ap2++;
	}
}

int main()
{

	//practice_list();
	//learn_map();
	//map_complex_data_type();
	//learn_unordermap();
	//copy_unordered_map();
	//insert_unordered_map();
	//learn_custom_object_as_unorder_map_key();
	//test_outputFile("test");
	//test_inputFile("test");

	//learn_vector();

	//reverse_order_loop();
	//learn_find_vector();
	//learn_copy_vectors();
	//learn_double_loop_vector();
	//sorting_defined_vector();
	//sorting_tuple_vector();
    
	//learn_stl_binary_search();

	//learn_custom_object_as_map_value();
	//learn_custom_object_as_map_key();
	//learn_ostringstream();
	
	//learn_multimap();
	//learn_sets();

	//learn_default_parameter_function_call();
	//learn_lambda();
	//learn_lambda_call_by_ref();

	//learn_unordered_set();
	//pass_unorderedMap();

	//learn_unordered_map_pointer();
	//learn_global_memory_pointer();
	//learn_shared_pointer_with_vector();
	//learn_unique_memory_ptr();

	//pointer_to_vec();
	//learn_auto_pointer();

	//practice_implement();
	//learn_ascii();

	//learn_continue();

	//learn_bit_function();

	//learn_template();
/*--------------testing algorithm and data structure------------------------*/
	testAlgo test;
	test.show();

	return 0;
}

enum class testBit : uint8_t {
	FLAG = 0,
	FLAG2 = 1 << 0,
	FLAG3 = 1 << 1,
	FLAG4 = 1 << 2

};


using UType = std::underlying_type<testBit>::type;

UType value( const testBit bit ) {
	return static_cast<UType>(bit);
}

testBit type(const UType value) {
	return static_cast<testBit>(value);
}


void learn_data_packing()
{

struct data1 {
	double a;
	double b;
	double c;
	int aa;
	uint8_t bb;
};

struct data2 {
	int aa;
	double a;
	double b;
	double c;
	uint8_t bb;
};

	std::cout << "size of data= " << sizeof(data1) << std::endl;
	std::cout << "size of data2= " << sizeof(data2) << std::endl;
}
void learn_bit_function()
{
	int *_ptr{ nullptr };
	std::cout << "size of testBit = " << sizeof(testBit) << std::endl;
	std::cout << "size of ptr= " << sizeof(_ptr) << std::endl;
	testBit bit{ testBit::FLAG };
	//bit =  type (value(  bit ) | value(testBit::FLAG2));
	bit = static_cast<testBit>(static_cast<std::underlying_type<testBit>::type>(testBit::FLAG2) | static_cast<std::underlying_type<testBit>::type>(bit));
	bit = static_cast<testBit>(static_cast<std::underlying_type<testBit>::type>(testBit::FLAG3) | static_cast<std::underlying_type<testBit>::type>(bit));
	bit = static_cast<testBit>(static_cast<std::underlying_type<testBit>::type>(testBit::FLAG4) | static_cast<std::underlying_type<testBit>::type>(bit));
	std::cout << "bit=" << unsigned(value(bit)) << std::endl;

	std::cout << "bit & FLAG2 =" << bool(value(bit) & value(testBit::FLAG2) )<< std::endl;
	bit = type(value(bit) & ~value(testBit::FLAG2));
	std::cout << "remove flag2 bit=" << unsigned(value(bit)) << std::endl;
	std::cout << "bit & FLAG2 =" << bool(value(bit) & value(testBit::FLAG2) )<< std::endl;
	bit = testBit::FLAG;
	std::cout << "bit=" << unsigned(value(bit)) << std::endl;
	cout << ( true ^ true )<< endl;
	cout << ( true ^ false)<< endl;
	cout << ( false^ true )<< endl;
	cout << ( false^ false)<< endl;
	
	const uint8_t flag = 1 << 0;
	const uint8_t flag2 = 1 << 1;
	const uint8_t flag3 = 1 << 2;
	const uint8_t flag4 = 1 << 3;
	bool signal = false, power = false;
	uint8_t sum = 0;
	std::cout << unsigned(value( testBit::FLAG )) << std::endl;
	std::cout << unsigned(value( testBit::FLAG2 )) << std::endl;
	std::cout << unsigned(value( testBit::FLAG3 ) )<< std::endl;
	std::cout << unsigned(value( testBit::FLAG4 )) << std::endl;

	
	uint8_t sum2 = 0;
	sum2 = sum2 | value (testBit::FLAG) ;
	sum2 = sum2 | value (testBit::FLAG2) ;
	sum2 = sum2 | value (testBit::FLAG3) ;
	sum2 = sum2 | value (testBit::FLAG4) ;


	if (sum2 & 1) {
		std::cout << "has setting digital option high prority:" << unsigned(sum2) << std::endl;
	}
	signal = true;
	if (signal) {
		sum |= flag;
	} 

	if (power) {
		sum |= flag2;

	}
	sum |= flag3;
	std::cout << "current value:" << unsigned(sum2)<<" "<<unsigned(sum) << std::endl;

	if (sum & flag) {
		std::cout << unsigned(sum) << " == flag "  << std::endl;
	}

	if (sum & flag2) {
		std::cout << unsigned(sum) << " == flag2 " << std::endl;
	}
	if (sum & flag3) {
		std::cout << unsigned(sum) << " == flag3 " << std::endl;
	}
	if (sum & flag4) {
		std::cout << unsigned(sum) << " == flag4 " << std::endl;
	}

	/*
	switch (sum) {
	case ( flag ):
		std::cout << unsigned(sum) << " == flag "  << std::endl;
		break;
	case ( flag2 ):
		std::cout << unsigned(sum) << " == flag2 " << std::endl;
		break;
	case ( flag3 ):
		std::cout << unsigned(sum) << " == flag3 " << std::endl;
		break;
	case ( flag4 ):
		std::cout << unsigned(sum) << " == flag4 " << std::endl;
		break;
	default:
		std::cout << unsigned(sum) << " is exceeds and error out" << std::endl;
		break;
	};*/

}

//a type parameter can be used to name the return type or
//a function parameter type, and for variable declarations or casts inside the function
//body

//when using it as retrun type
template <typename T> T foo(T* pointer ) {
	T temp = *pointer;
	return temp;
}

template <typename T>void swapT(T* val, T* val2) {
	T temp = *val;
	*val = *val2;
	*val2 = temp;
}

template<typename T > int compare(const T& value1, const T& value2) {
	//if value1 > value2
	if (std::less<T>()(value1, value2)){ return false; }
	else {
		return true;
	}
}

//keywords typename or class have same meaning
template<typename T, typename U>  T calc(const T&, const U&) {

}
/*nontype parameter A template parameter that represents a value.Template
arguments for nontype template parameters must be constant expressions.*/

template<unsigned N, unsigned M>
int compareTwo(const char(&p1)[N], const char(&p2)[M]) {
	std::cout << "N = " << N << "\nM = " << M << std::endl;
	return std::strcmp(p1, p2);
}

//class template
template< typename T > class Blob {
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	//constructor
	Blob();
	Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T&& t) { data->push_back(std::move(t)); }
	void pop_back();
	T& back();
	T& operator[](size_type i);

private:

	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string& msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
 void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

 void learn_template_class() {
	 std::cout << "\tlearn template class" << std::endl;
	 Blob<std::string> test = { "aa","bb","cc" };
	 for (size_t index = 0; index < test.size(); ++index) {
		 std::cout << test[index] << std::endl;
	 }

}

void learn_template_swap() {
	//swap built-in variable
	int val = 2, val2 = 3;
	std::cout << val << " " << val2 << std::endl;
	swapT(&val, &val2);
	std::cout << val << " " << val2 << std::endl;
	double dv = 2.5, dv2 = 3.6;
	std::cout << dv << " " << dv2<< std::endl;
	swapT(&dv, &dv2);
	std::cout << dv << " " << dv2<< std::endl;
	//swap class or vector
	Test_Vector vec = Test_Vector(365, "Dante");
	Test_Vector vec2 = Test_Vector(14, "James");
	vec.show();
	vec2.show();
	swapT(&vec, &vec2);
	vec.show();
	vec2.show();

	//nontype parameter
	std::cout << " practice nontype parameter" << std::endl;
	std::cout << compareTwo("hwe", "qwewwww") << std::endl;
	std::cout << compareTwo("www", "www") << std::endl;
	std::cout << compareTwo("hwe", "qwe") << std::endl;

}

void learn_template_vector() {
	int value = 10, value2 = 20;
	std::cout <<value<<" > "<<value2<<" ? "<< compare(value, value2) << std::endl;
	float fv = 16.3, fv2= 12.1;
	std::cout <<fv<<" > "<<fv2<<" ? "<< compare(fv, fv2) << std::endl;
	double dv= 10, dv2= 10;
	std::cout <<dv<<" > "<<dv2<<" ? "<< compare(dv, dv2) << std::endl;
	dv= 10.1111111111111, dv2= 9.999999999999999999999999;
	std::cout <<dv<<" > "<<dv2<<" ? "<< compare(dv, dv2) << std::endl;
	dv2= 10.1111111111111, dv= 9.999999999999999999999999;
	std::cout <<dv<<" > "<<dv2<<" ? "<< compare(dv, dv2) << std::endl;
}

void learn_template_lambda() {
}

void learn_template() {
	learn_template_swap();
	learn_template_vector();
	learn_template_class();
	fgetc(stdin);

}

void learn_continue() {
	//continue statment only works for a loop 
	for (int index = 0; index < 20; ++index) {
		cout << index<< " ";
		for (int second = 0; second < 10; ++second) {
			if (second % 2 == 0) {
				if ( index % 2 == 0 )
				continue;
			}
			cout << second<< " ";
		}
		cout << endl;
	}
	fgetc(stdin);
}

void hashtable_ascii();
void learn_ascii() {
	std::cout << "Learning how to convert char to ascii number" << std::endl;
	std::cout << "Enter a char:" << std::endl;

	char c;
	std::cin >> c;

	std::cout << "Char=" << c << " ascii:" << size_t(c) << std::endl;
	hashtable_ascii();
	fgetc(stdin);
}

void hashtable_ascii() {
	std::cout << "Learning how to use ascii number as key for hashtable" << std::endl;
	std::cout << "This methond can't avoid duplicated sum from different alphabets" << std::endl;
	std::unordered_map<int, std::vector<string>> ascii_table;
	std::vector<std::string> data = {"eat", "tea", "tan", "ate", "nat", "bat" };
	for (auto it : data) {
		int sum = 0;
		for (int count = 0; count < it.length(); count++) {
			std::cout << it[count] << " "; 
			sum += int(it[count]);
		}
		std::cout <<"Sum:"<<sum<< std::endl;
		ascii_table[sum].push_back( it );
	}

	for (auto it : ascii_table) {
		for (auto sit : it.second) {
			std::cout << sit << " ";
		}
		std::cout << std::endl;
	}
	
};

#include <unordered_set>
//learing how to keep looping data and delete it after read.
void unordered_set_loopAndPop() {
	std::unordered_set<std::string> myset =
	{ "Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune", "Hans", "Lorry","Hans", "Mercury" };

	while (!myset.empty() ) {
		const auto data = myset.begin();
		std::cout << "show data:" <<*data << std::endl;
		myset.erase(data);
	}

	fgetc(stdin);
}

void reverse_order_loop() {
	std::vector<int>testVector;;
	testVector.push_back(1);
	testVector.push_back(2);
	testVector.push_back(3);
	testVector.push_back(4);
	testVector.push_back(5);
	testVector.push_back(6);
	for (const auto &iter : testVector) {
		std::cout << iter << std::endl;
	}

	auto iter = testVector.end();
	do {
		std::advance(iter, -1);
		std::cout << *iter << std::endl;
	} while (iter != testVector.begin());
}
void unordered_set_begin() {
	std::unordered_set<std::string> myset =
	{ "Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune", "Hans", "Lorry","Hans", "Mercury" };

	std::cout << "myset contains:";
	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;

	std::cout << "myset's buckets contain:\n";
	for (unsigned i = 0; i < myset.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains:";
		for (auto local_it = myset.begin(i); local_it != myset.end(i); ++local_it)
			std::cout << " " << *local_it;
		std::cout << std::endl;
	}
	fgetc(stdin);
}

#include <array>
void unordered_set_insert() {
	std::unordered_set<std::string> myset = { "yellow","green","blue" };
	std::array<std::string, 2> myarray = { "black","white" };
	std::string mystring = "red";
	std::string mystring2 = "wwwewew";

	myset.insert(mystring);                        // copy insertion
	myset.insert(mystring + "dish");                 // move insertion
	myset.insert(myarray.begin(), myarray.end());  // range insertion
	myset.insert({ "purple","orange" });           // initializer list insertion

	auto check = myset.insert(mystring);
	if (check.second == true) {
		std::cout << mystring << " is first inserted" << std::endl;
	}
	else {
		std::cout << mystring << " is already inserted" << std::endl;

	}

	auto check2 = myset.insert(mystring2);
	if (check2.second == true) {

		std::cout << mystring2 << " is first inserted" << std::endl;
	}
	else {
		std::cout << mystring2 << " is already inserted" << std::endl;
	}

	std::cout << "myset contains:";
	for (const std::string& x : myset) std::cout << " " << x;
	std::cout << std::endl;
	fgetc(stdin);
}


void insert_unordered_map() {
	std::unordered_map<int, std::string> test;
	test[13] = "hello";
	auto found = test.insert(std::make_pair<int, std::string>(12, "dante"));
	//std::cout << found<< std::endl;
	fgetc(stdin);
	

}
