#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <ctime>
#include "windows.h"
#include "List_Three.h"
#include <sstream>
#include "StreamTable.h"

using namespace std;

using Three_nsp::Three;
using Three_nsp::List_Three;
using Three_nsp::Node;

void printStreamTable1(const List_Three* list)
{
	StreamTable st(std::cout);
	st.AddCol(5);
	st.AddCol(10);
	st.AddCol(10);
	st.AddCol(10);

	//разкомментировать, если столбцы имеют одинаковую толщину
	//st.Clear();
	//st.SetCols(4, 10);

	//st.SetVisible(1, false);//столбцы можно скрывать

	st.MakeBorderExt(true);
	st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
	st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

	//заголовок и значения выводятся одинаково
	st << "№" << "size" << "end_vertex" << "Alfa";
	//enum { nr = 10 };
	for (int i = 0; i < list->size(); i++) {
		st <<i << list->at(i)->get_size() << list->at(i)->count_end_vertex() << list->at(i)->alfa();
	}
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");




	Three d(200, 4);
	double a=d.alfa();

	List_Three* list=new List_Three;
	Three* derevo;
		for (int i = 0; i < 400; ++i)
		{
			derevo = new Three_nsp::Three(200);
			list->push_back(derevo);
		}
		double t = 0;
	printStreamTable1(list);
	


	cout << "alfa= ";
	cout << list->midlle_Alfa();
	return 0;

}
