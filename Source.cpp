#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <ctime>
#include "windows.h"
#include "List_Three.h"

using namespace std;

using Three_nsp::Three;
using Three_nsp::List_Three;
using Three_nsp::Node;




int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");




	Three d(200, 4);

	List_Three* list=new List_Three;
	Three* derevo;
	try {
		for (int i = 0; i < 40; ++i)
		{
			derevo = new Three_nsp::Three(200);
			list->push_back(derevo);
		}
	}
	catch (char *str)
	{
		cout << *str;
	}
	cout << "ok"<<endl;
	cout << "size= ";
	for (int i = 0; i < list->size(); ++i)
	{
		cout << list->at(i)->get_size() << " , ";
	}

	cout << endl;

	cout << "count_end_vertex= ";
	for (int i = 0; i < list->size(); ++i)
	{
		cout << list->at(i)->count_end_vertex()<<" , ";
	}

	cout << endl;
	cout << "alfa= ";
	double alfa = 0;
	cout << endl;
	for (int i = 0; i < list->size(); ++i)
	{
		alfa += list->at(i)->alfa();
	}
	double res = alfa / list->size();
	cout << res;
	return 0;

}