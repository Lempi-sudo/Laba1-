#include "Three.h"
namespace Three_nsp {

	Three::Three():nodes_in_lvl(),cnt_node(1),cnt_rand_val()
	{
		head = new Node();
		head->number.first = 1;
		head->number.second = 0;
		head->lvl = 1;
		nodes_in_lvl.adding_node_to_lvl(1);
		

	}

	
	Three::Three(size_type N, int link) :Three() // конструктор для детерминированного дерева на N вершинах с числом потомков = link 
	{
		queue<Node*> list_node;
		list_node.push(head);
		while (cnt_node < N)
		{
			Node* tmp;
			tmp = list_node.front();
			for (size_t i = 0; i < link; i++)
			{
				tmp->arr.push_back(create_Node(++cnt_node, tmp->number.first, tmp->lvl + 1));
				nodes_in_lvl.adding_node_to_lvl(tmp->lvl + 1);
				list_node.push(tmp->arr.back());
			}

			list_node.pop();
		}
		
		queue<Node*> new_list_node=create_new_queue(list_node);
		
		while (!new_list_node.empty())
		{
			Node* temp;
			temp = new_list_node.front();
			for (size_t i = 0; i < link; i++)
			{
				temp->arr.push_back(create_Node(++cnt_node, temp->number.first, temp->lvl + 1));
				nodes_in_lvl.adding_node_to_lvl(temp->lvl + 1);
			}
			new_list_node.pop();

		}
	}

	Three::Three(size_type N) :Three() //конструктор для случайного дерева на N вершинах
	{
		queue<Node*> list_node;
		list_node.push(head);
		while (cnt_node < N)
		{
			int value_edge;
			value_edge = (rand() % 5);
			Node* tmp;
			if (list_node.empty()) {
				break;
			}
			else {
				tmp = list_node.front();
			}
			if (cnt_node == 1)
			{
				value_edge = (rand() % 4 + 1);
				cnt_rand_val.adding_counter(value_edge);
				for(size_t i = 0; i < value_edge; i++)
				{

					tmp->arr.push_back(create_Node(++cnt_node, tmp->number.first, tmp->lvl + 1));
					nodes_in_lvl.adding_node_to_lvl(tmp->lvl + 1);
					list_node.push(tmp->arr.back());
				}
			}
			else if (cnt_node != 1 && cnt_node < 10 && list_node.size() == 1)
			{
				value_edge = (rand() % 4 + 1);
				cnt_rand_val.adding_counter(value_edge);
				for (size_t i = 0; i < value_edge; i++)
				{
					tmp->arr.push_back(create_Node(++cnt_node, tmp->number.first, tmp->lvl + 1));
					nodes_in_lvl.adding_node_to_lvl(tmp->lvl + 1);
					list_node.push(tmp->arr.back());
				}

			}
			else
			{
				cnt_rand_val.adding_counter(value_edge);
				for (size_t i = 0; i < value_edge; i++)
				{

					tmp->arr.push_back(create_Node(++cnt_node, tmp->number.first, tmp->lvl + 1));
					nodes_in_lvl.adding_node_to_lvl(tmp->lvl + 1);
					list_node.push(tmp->arr.back());
				}
			}
			list_node.pop();
		}
		queue<Node*> new_list_node=create_new_queue(list_node);
		while (!new_list_node.empty())
		{
			int val_edge = rand() % 5;
			cnt_rand_val.adding_counter(val_edge);
			Node* temp;
			temp = new_list_node.front();
			for (size_t i = 0; i < val_edge; i++)
			{
				temp->arr.push_back(create_Node(++cnt_node, temp->number.first, temp->lvl + 1));
				nodes_in_lvl.adding_node_to_lvl(temp->lvl + 1);
			}
			new_list_node.pop();

		}
	}



	double Three::expected_val()const
	{
		return this->cnt_rand_val.expected_value();
	}

	Three::size_type Three::get_size()const
	{
		return this->cnt_node;
	}


	double Three::alfa()const
	{
		double all_node = this->cnt_node;
		double end_node = this->count_end_vertex();
		double res = all_node / end_node;
		return res;
	}

	Node* Three::create_Node(int value, int parent, int level)
	{
		Node* tmp = new Node();
		tmp->number.second = parent;
		tmp->number.first = value;
		tmp->lvl = level;
		return tmp;
	}

	void Three::printTree3()const
	{
		queue<Node*> list_node;
		Node* p = head;
		list_node.push(p);
		int old_lvl = list_node.front()->lvl;
		cout << "lvl " << old_lvl << ":   ";
		while (!list_node.empty())
		{
			int new_lvl = list_node.front()->lvl;
			if (old_lvl != new_lvl)
			{
				cout << endl;
				cout << "lvl " << new_lvl << ":   ";
				old_lvl = new_lvl;
			}
			cout << "  [ №" << list_node.front()->number.first << " #" << list_node.front()->number.second << " ]  ";

			Node* t = list_node.front();
			for (int i = 0; i < t->arr.size(); i++)
			{
				list_node.push(t->arr[i]);
			}
			list_node.pop();
		}

	}
	void Three::print_Three()const
	{
		queue<Node*> list_node;
		Node* p = head;
		list_node.push(p);
		int old_lvl = list_node.front()->lvl;
		cout << "lvl " << old_lvl << ": ";
		while (!list_node.empty())
		{
			int new_lvl = list_node.front()->lvl;
			if (old_lvl != new_lvl)
			{
				cout << endl;
				cout << "lvl " << new_lvl << ": ";
				old_lvl = new_lvl;
			}
			cout << "--" << list_node.front()->number.first;

			Node* t = list_node.front();
			for (int i = 0; i < t->arr.size(); i++)
			{
				list_node.push(t->arr[i]);
			}
			list_node.pop();
		}
	}
	void Three::print_Three_2()const
	{
		queue<Node*> list_node;
		Node* p = head;
		list_node.push(p);
		int old_lvl = list_node.front()->lvl;
		cout << "lvl " << old_lvl << ":";
		while (!list_node.empty())
		{
			int new_lvl = list_node.front()->lvl;
			if (old_lvl != new_lvl)
			{
				cout << "lvl " << new_lvl << ":";
				old_lvl = new_lvl;
			}

			cout << list_node.front()->number.first << "  (number_child :" << list_node.front()->arr.size() << ")   ";
			Node* tmp = list_node.front();

			Node* t = list_node.front();
			for (int i = 0; i < t->arr.size(); i++)
			{
				list_node.push(t->arr[i]);
			}
			list_node.pop();
			cout << endl;
		}
	}

	//возвращает число равное глубине дерева 
	int Three::find_max_lvl()const //возвращает число равное глубине дерева 
	{
		Node* tmp = head;
		queue<Node*> list_node;
		list_node.push(tmp);
		int max_lvl = 0;
		while (!list_node.empty())
		{
			if (list_node.front()->lvl > max_lvl)
			{
				max_lvl = list_node.front()->lvl;
			}
			Node* t = list_node.front();
			for (int i = 0; i < t->arr.size(); i++)
			{
				list_node.push(t->arr[i]);
			}
			list_node.pop();
		}
		return max_lvl;
	}
	// возвращает количество виcячих узлов
	double Three::count_end_vertex()const // возвращает количество вичячих узлов
	{
		double count = 0;
		Node* tmp = head;
		queue<Node*> list_node;
		list_node.push(tmp);
		while (!list_node.empty())
		{
			Node* t = list_node.front();
			for (int i = 0; i < t->arr.size(); i++)
			{
				list_node.push(t->arr[i]);
			}
			if (list_node.front()->arr.empty())
			{
				count++;
			}
			list_node.pop();
		}
		return count;
	}



	void CountOfRandomValue::adding_counter(int key)
	{
		switch (key)
		{
		case 0:++_zero; break;
		case 1:++_one; break;
		case 2:++_two; break;
		case 3:++_three; break;
		case 4:++_four; break;
		default:
			throw "invalid number";
			break;
		}
	}

	int CountOfRandomValue::get_amount_of_random_number(int key)const
	{
		switch (key)
		{
		case 0:return _zero;
		case 1:return _one;
		case 2:return _two;
		case 3:return _three;
		case 4:return _four;
		default:
			throw "invalid number";
			break;
		}
	}

	double CountOfRandomValue::expected_value()const
	{
		double cnt_value = _zero + _one + _two + _three + _four;
		double tmp = 1 * _one + 2 * _two + 3 * _three + 4 * _four;
		double res = tmp / cnt_value;
		return res;
	}

	void NumberofNodesatLevel::adding_node_to_lvl(int lvl)
	{
		if (lvl > _high_lvl)
		{
			if (lvl - _high_lvl > 1) throw "very big lvl";
			_array_of_number_nodes.push_back(1);
			_high_lvl = lvl;
		}
		else
		{
			++_array_of_number_nodes[lvl - 1];
		}
	}

	queue<Node*> Three::create_new_queue(queue<Node*>& list_node)
	{
		int max_lvl = this->find_max_lvl();
		queue<Node*> new_list_node;
		while (!list_node.empty())
		{
			if (list_node.front()->lvl == (max_lvl - 1))
			{
				new_list_node.push(list_node.front());
				list_node.pop();
			}
			else
			{
				list_node.pop();
			}
		}
		return new_list_node;
	}



}