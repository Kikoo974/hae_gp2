#pragma once

template <typename T>
class Arr
{
public:
	T* data = nullptr;
	int size = 0;
	Arr(int _size) {
		this->size = _size;
		data = new T[_size];
		
		for (int i = 0; i < _size; i++)
			data[i] = {};  //demaander a c++ de mettre un truc
		
	}
	virtual ~Arr()
	{
		delete[] data;
		cout << "deleted" << endl;
	}
	T & Get(int idx)
	{
		
		
		if (idx >= size) throw "out of bounds maj";
		if (idx < 0) throw "out of bounds min";
		
	    return data[idx];
	}
	
	void Set(int idx, T velta)
	{
		if (idx >= size) throw "out of bounds maj";
		if (idx < 0) throw "out of bounds min";
		data[idx] = velta;
		
	}

	


};