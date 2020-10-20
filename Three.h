#pragma once

#include<iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <utility>
#include <fstream>
#include <cassert>
#include <cstdlib>
using namespace std;

//Узел в графе
namespace Three_nsp {

	struct Node
	{
		std::vector<Node*>arr;
		int lvl;
		std::pair<int, int>number;

	};
// Вспомогательный класс для подсчета излов на  уровне 
	class NumberofNodesatLevel {
	public:
		NumberofNodesatLevel():_high_lvl(0){}

		void adding_node_to_lvl(int lvl);
		
		int get_amount_of_nodes_in_lvl(int lvl)const { return _array_of_number_nodes[lvl - 1]; }

		int get_high_lvl()const;

	private:
		int _high_lvl;
		std::vector<int> _array_of_number_nodes;
	};

// Вспомогательный класс для подсчета случайных значений числа m
	class CountOfRandomValue
	{
	public:

		CountOfRandomValue():_zero(0) ,  _one(0) ,  _two(0),  _three(0) , _four (0) {}
		double expected_value()const;
		void adding_counter(int key);
		int get_amount_of_random_number(int key)const;
		
	private:
		int _zero;
		int _one;
		int _two;
		int _three;
		int	_four;
	};

	class Three
	{
	public:
		typedef std::size_t size_type;
		Three();
		Three(size_type N);
		Three(size_type N, int link);
		~Three() {};
		size_type get_size()const;
		void printTree3()const;
		Node* create_Node(int value, int parent, int l);
		void print_Three()const;
		void print_Three_2()const;
		int find_max_lvl()const;
		double count_end_vertex()const;
		double alfa()const;
		double expected_val()const;
		queue<Node*> create_new_queue(queue<Node*>& list_node);
		void print_three_in_file(string)const;
		void print_end_vertex(string )const;
		int count_lvl()const;
		
	private:
		Node* head;
		NumberofNodesatLevel nodes_in_lvl;
		CountOfRandomValue cnt_rand_val;
		size_type cnt_node;
	};
}