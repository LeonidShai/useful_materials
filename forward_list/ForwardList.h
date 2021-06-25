#ifndef LIST_H
#define LIST_H

template<typename T>
class ForwardList
{
public:
	ForwardList()
	{
		size = 0;
		head = nullptr;
	}

	~ForwardList()
	{
		clear();
	};

	void push_back(T data)
	{
		if(!head){
			head = new Node<T>(data);
		} else {
			Node<T>* current = this->head;

			while(current->next){
				current = current->next;
			}
			current->next = new Node<T>(data);
		}
		size++;
	}

	void insert(T data, int index)
	{
		if(index == 0){
			push_front(data);
		} else {
			Node<T>* prev = this->head;

			for(int i = 0; i < index-1; i++){
				prev = prev->next;
			}

			Node<T>* newNode = new Node<T>(data, prev->next);
			prev->next = newNode;

			size++;
		}
	}

	void push_front(T data)
	{
		head = new Node<T>(data, head);
		size++;
	}

	void pop_front()
	{
		Node<T>* temp = head;

		head = head->next;
		delete temp;
		size--;
	}

	void removeAt(int index)
	{
		if(index == 0){
			pop_front();
		} else {
			Node<T>* prev = this->head;
			for(int i = 0; i < index-1; i++){
				prev = prev->next;
			}

			Node<T>* toDelete = prev->next;
			prev->next = toDelete->next;

			delete toDelete;
			size--;
		}
	}

	void pop_back()
	{
		removeAt(size-1);
	}

	void clear()
	{
		while(size != 0){
			pop_front();
		}
	}

	int getSize() const
	{
		return size;
	}

	T& operator[](const int index)
	{
		int count = 0;
		Node<T>* current = this->head;

		while(current){
			if(count == index){
				return current->data;
			} else {
				current = current->next;
				count++;
			}
		}
	}

private:
	
	template<typename C>
	class Node
	{
	public:
		Node* next;
		C data;

		Node(C data=C(), Node* next = nullptr):data(data), next(next)
		{};
	};

	Node<T>* head;
	int size;
};

#endif // LIST_H