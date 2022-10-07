#pragma once
class learnTemplate
{
	template<typename T>
	class vector {
	private:
		int size;
		T* elem;
		int space;
	public:
		vector() : size{ 0 }, elem{ nullptr }, space{ 0 }{}
		explicit vector(int s) : size{ s }, elem{ new T[s] }, space{ s }
		{
			for (int i = 0; i < this->size; ++i)
				elem[i] = 0;
		}

		vector(const vector&);
		vector& operator=(const vector&);
		~vector() { delete[] elem; }
		T& operator[](int n)const { return elem[n]; }
		int Size() const { return size; }
		int capacity() const { return space; };
		void resize(int newsize);
		void push_back(const T& d);
		void reserve(int newalloc);
	};
public:
	learnTemplate();
	void run();

private:
	

};

