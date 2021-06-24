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

	~ForwardList(){};

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