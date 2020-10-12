#pragma once
#include<iostream>
#include <vector>
#include"Three.h"

using namespace std;

namespace Three_nsp {
	class List_Three :public vector<Three*>
	{
	public:
		double midlle_Alfa() const;
	
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
}
