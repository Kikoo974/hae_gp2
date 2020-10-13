#pragma once

class Node {
public:
	float key;
	Node* left = nullptr;   //obligé
	Node* right= nullptr;

	Node(){}
	Node(float value, Node* l =nullptr, Node*r = nullptr)
	{
		this->key = value;	
		this->right = r;
		this->left = l;
	}
	
	~Node() {
		delete left;
		delete right;
	}
	Node* Heapify(float newVal)  //Récurrence
	{
		if (newVal < key)
		{
			Node* nuNode = new Node(newVal);
			nuNode->left = this;
			return nuNode;
		}
		else {
			if (right == nullptr)
			{
				right = new Node(newVal);				
				return this;
			}						
			else if(left == nullptr)
			{
				left = new Node(newVal);
				return this;
			}
			else
			{
				
				left = left->Heapify(newVal);
				return this;
				
			}
		}
	}
	bool isoCs()
	{
		if (left == nullptr && right == nullptr)
			return true;
		else if (left == nullptr)
			return right->key >= key;
		else if (right == nullptr)
			return left -> key >= key;
		else
		{
			if (key >= left->key) return false;
			if (key >= right->key) return false;
			return left->isoCs() && right->isoCs();
		}
	}
	Node* remove(float val)  //rendre static car elle doit rendre this;
	{
		Node* cur = this;
		
		if (val == key) cur = cur-> deleteMin();
				
		if (cur == nullptr) return nullptr;

		if (cur->left) cur->left = cur->left->remove(val);
		if (cur->right) cur->right = cur->right->remove(val);
		
		return cur;
		
			
	}
	float getMin() {
		//la valeur la plus faible
		return key;
	}
	Node* deleteMin() {				
			
		Node* l = left;
		Node* r = right;

		right = nullptr;
		left = nullptr;
		delete(this);
	
		if (left == nullptr) return r;
		if (right == nullptr) return l;

		return Node::merge(r,l);
	}
	
	static Node* merge(Node* a0, Node* a1) {
		if (a0 == nullptr) return a1;
		if (a1 == nullptr) return a0;
		float val = a1->getMin();
		Node* cur = a0;
		cur = cur->Heapify(val);

		Node* l = a1->left;
		Node* r = a1->right;

		a1->left = nullptr;
		a1->right = nullptr;

		delete a1;
		
		cur = merge(cur, l);
		cur = merge(cur, r);
		return cur;
	}
	static Node* fromtab(float* t, int tLen)
	{
		if (!tLen) return nullptr;
		Node* root = new Node(t[0]);
		if (tLen > 1)
			for (int i = 1; i < tLen; i++)
				root->Heapify(t[i]);
	}
	static Node* fromTabRec(float* t, float tLen)
	{
		Node* cur = new Node(t[0]);
		if (tLen > 1)
			cur = merge(cur, fromTabRec(t + 1, tLen - 1));
		return cur;
	}
};