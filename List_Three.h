#pragma once
#include<iostream>
#include <vector>
#include"Three.h"
#include <fstream>
#include <cassert>

using namespace std;

namespace Three_nsp {
	class List_Three :public vector<Three*>
	{
	public:
		double midlle_Alfa() const;
		void input_file(string filename)const;
	
	};

	double List_Three::midlle_Alfa() const
	{
		double A = 0;
		for (int i = 0; i < this->size(); ++i)
		{
			A += this->at(i)->alfa();
		}
		double midlle_Alfa = A / this->size();
		return midlle_Alfa;
	}

	void List_Three::input_file(string filename)const
	{
		ofstream outfile;
		outfile.open(filename);
		assert(outfile);

		outfile << "¹\t" << "size\t" << "end_vertex\t" << "Alfa\n";
		//enum { nr = 10 };
		for (int i = 0; i < this->size(); i++) {
			outfile << i+1<<"\t" << this->at(i)->get_size() << "\t" << this->at(i)->count_end_vertex() << "\t" <<fixed<< this->at(i)->alfa() << "\n";
		}
		cout << "FILE RECORDED";

		outfile.close();

	}
}
