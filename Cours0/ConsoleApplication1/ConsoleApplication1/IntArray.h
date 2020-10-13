#pragma once

class IntArray
{
public:
	int size = 0;
	int* data=nullptr;
	IntArray(int _size)
	{
		this->size = _size;
		data = (int*)malloc(_size*sizeof(int));
		/*for (int i = 0; i < _size; i++)
			data[i] = {};*/
	}
	IntArray(const IntArray& arr)
	{
		int size = arr.size;
		data = (int*)malloc(size * sizeof(int));
		this->size = size;
		for (int i = 0; i < size; i++)
			data[i] = arr.data[i];
	}
	~IntArray()
	{
		free(data);
	}
	void resize(int newSize)
	{
		if (newSize < size)
			return;
		int newAlloSize = newSize * sizeof(int);
		data = (int*)realloc(data, newAlloSize);
		for (int i = size; i < newAlloSize; i++) 
		{
			data[i] = {};
		}

		size = newAlloSize;
	}
	int & Get(int idx)
	{
		if (idx < 0) throw "Nop";
		if (idx >= size) throw "Nop";
		return data[idx];
	}
	int & operator()(int idx)
	{
		return data[idx];
	}
	int & operator[](int idx)
	{
		return data[idx];
	}
	void Set(int value, int idx)
	{
		if (idx < 0) throw "Nop";
		if (idx >= size) resize(idx + 1);
		data[idx] = value;
	}
	static IntArray iota(int sx)
	{
		IntArray arr(sx);
		for (int i = 0; i < sx; i++)
			arr(i) = i;
		return arr;
	}
	static IntArray random(int sx)
	{
		IntArray arr(sx);
		for (int i = 0; i < sx; i++)
			arr(i) = rand();
		return arr;
	}

	//faire une recherche linéaire
	//renvoie -1 si pas trouvé
	//renvoie la pose si trouvée
	//int(search(int key)
	int search(int key)  //par itération
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == key)
				return i;
		}
		return -1;
	}

	//rpush back
	void push_back(int elem)
	{
		int pos = size;
		resize(size + 1);
		data[pos] = elem;
	}
	int searchRec(int key, int pos = 0) //par récurrence
	{
		if (pos >= size) return -1;
		if (data[pos] == key)
			return pos;
		return searchRec(key, pos + 1);
		
	}
	void push_front(int elem)
	{

		int a = size;
		resize(size + 1);
		for (int i = a; i >= 0; i--)
		{
			data[i] = data[i - 1];
		}		
		data[0] = elem;
	}
	void insert(int pos, int val)
	{
		int oldSize = size;
		if (pos > size)
			push_back(val);
		if (pos == 0)
			push_front(val);
		resize(size + 1);
		for (int i = oldSize; i >= pos; i--)
		{
			data[i] = data[i-1];
		}
		data[pos] =  val;
	}
	int searchInsertionPos(int key)  //dans le cas ou il est trié
	{
		int idx = 0;
		while (key >= data[idx])
		{
			idx++;
		}
		//push_back(key);
		return idx;
	}
	int searchInsertionPosRec(int key, int pos = 0)
	{
		if (pos >= size) return size;
		else if (data[pos] >= key) return pos;
		else return searchInsertionPosRec(key, pos + 1);
	} 
	
	bool isSortedIter()
	{
		for (int i = 0; i < size-1; i++)
		{
			if (data[i] > data[i + 1])
				return false;
		}
		return true;
	}
	bool isSortedRec(int pos = 0)
	{
		if (pos >= size-1) return true;
		
		if (data[pos] <= data[pos + 1])
			return isSortedRec(pos+1);
		return false;
	}
	/*IntArray IntArray::sort(int* data, int dataSize)
	{
		IntArray arr;
		arr.resize(dataSize);
		for (int i = 0; i < dataSize; i++)
		{
			int val = data[i];
			int pos = searchInsertionPosRec(val);
			arr.insert(pos, val);
		}
		return arr;
		
	}*/
	static void triParInsertion(int* data, int dataSize)
	{
		int j = 0;
		for (int i = 2; i < dataSize; i++)
		{
			j = i;
			while (j > 0 && data[j] < data[j - 1])
			{
				int tmp = data[j];
				data[j] = data[j - 1];
				data[j] = tmp;
				j = j - 1;
			}
		}
		
	}
	bool binarySearch(int key, int start=0, int end)
	{
		if (start < 0) throw "wtf";
		if (end >= size) return  "wtf";
		if (end < start)return false;
		
		int middle = (start + end+1) / 2;

		if (data[start] == key) return true;
		if (data[end] == key) return true;
		if (data[middle] == key) return true;

		if (data[middle] < key) return binarySearch(key, start, middle-1);
		if (data[middle] > key) return binarySearch(key, middle + 1, end);
		
	}
};