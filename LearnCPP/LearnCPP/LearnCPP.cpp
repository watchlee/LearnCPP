// LearnCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include<algorithm>

using namespace std;
void unordered_set_begin();
void unordered_set_insert();

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

void learn_find_vector() {
	std::vector<int> ID;
	cout << ID.size() << endl;
	const int size = ID.size() ? ID.size() : 100;
	std::vector<int> ID2( size );
	cout << ID2.size() << endl;
	ID2[1] = 1;
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

//---------------------------learn unordered_map-------------------------------------//
//---------------------------default parameter in function and class-----------------//
uint8_t testingCalculate(const uint8_t numberA, const uint8_t numberB = 2) {
	return numberA + numberB;
}

void learn_default_parameter_function_call() {
	//given number = 12
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

//using unordered_set library
void learn_unordered_set()
{
	unordered_set_begin();
	unordered_set_insert();
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

int main()
{

	//practice_list();
	//learn_map();
	//learn_unordermap();
	//copy_unordered_map();
	//learn_custom_object_as_unorder_map_key();
	//test_outputFile("test");
	//test_inputFile("test");

	//learn_vector();
	//learn_find_vector();
	//learn_double_loop_vector();
    
	//learn_stl_binary_search();

	//learn_custom_object_as_map_value();
	//learn_custom_object_as_map_key();
	//learn_ostringstream();
	
	//learn_multimap();
	//learn_sets();

	//learn_default_parameter_function_call();
	//learn_lambda();

	//learn_unordered_set();
	pass_unorderedMap();

	//learn_auto_pointer();
	return 0;
}

#include <unordered_set>
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

	myset.insert(mystring);                        // copy insertion
	myset.insert(mystring + "dish");                 // move insertion
	myset.insert(myarray.begin(), myarray.end());  // range insertion
	myset.insert({ "purple","orange" });           // initializer list insertion

	std::cout << "myset contains:";
	for (const std::string& x : myset) std::cout << " " << x;
	std::cout << std::endl;
	fgetc(stdin);
}