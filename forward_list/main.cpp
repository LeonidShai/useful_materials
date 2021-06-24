#include <iostream>
#include "ForwardList.h"

using namespace std;


int main()
{
	ForwardList<int> flst;
	flst.push_back(5);

	cout << flst.getSize() << endl;

	flst.push_back(7);
	flst.push_back(2);
	cout << flst.getSize() << endl;

	int numbersCount = 5;
	for(int i = 0; i < numbersCount; i++){
		flst.push_back(rand()%10);
	}

	for(int i = 0; i < flst.getSize(); i++){
		cout << "flst[" << i << "]: " << flst[i] << endl;
	}
	return 0;
}