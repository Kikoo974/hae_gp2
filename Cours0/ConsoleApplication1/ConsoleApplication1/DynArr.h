#pragma once
#include <functional>
template <typename T>
class DynArr
{
public :
	T* data = nullptr;
	size_t alloSize = 0;

	DynArr(int _size)
	{
		this->alloSize = _size;
		//data = new T[_size];
		data = (T*) malloc(_size*sizeof(T));

		for (int i = 0; i < _size; i++)
			data[i] = {};
	}
	virtual ~DynArr() {
		//delete data[];
		free(data);
		
	}
	T & Get(int idx)
	{
		if (idx < 0 || idx >= alloSize)
			throw "asset : out of bounds;";
		

		return data[idx];
	}
	void Set(int idx, const T& type)
	{
		if (idx < 0) 
			throw "asset : out of bounds;";
		if (idx >= alloSize)
		{
			int newSize = idx + 1;
			resize(newSize);
		}
		data[idx] = type;
	}
	int GetSize()
	{
		return alloSize;
	}
	void resize(int newAllocSize)
	{
		if (newAllocSize < alloSize)  //Si la taille ne change pas ok
			return;
		int alloSizeByte = newAllocSize * sizeof(T);
		data = (T*)realloc(data, newAllocSize); //On reallou a la bonne taille

		for (int i = alloSize; i < newAllocSize; i++) //On met a 0 les element supp
		{
			data[i] = {};
		}

		//On change la taille
		alloSize = newAllocSize;
	}
	void Reverse()
	{
	
		for (int i = 0; i <= (int)alloSize / 2; i++)
		{
			T tmp = data[i];
			data[i] = data[alloSize-i-1];
			data[alloSize - i-1] = tmp;
		}
	}
	int lenght()
	{
		return alloSize;
	}
	void push_back(const T& elem)
	{
		
		Set(lenght(), elem);


	}
	void append(const DynArr<T>& arr)
	{
		//ajouter les element d'un autre tableau à celui ci
		//pour chaque élément de arr
		//mettre cet element dans le tableau
		for (int i=0; i < arr.lenght(); i++)
		{
			push_back(arr.data[i]);
		}
	}
	void iter(std::function<void(T)> _iter)
	{
		for (int i = 0; i < lenght(); i++)
			_iter(data[i]);
		
	}
};