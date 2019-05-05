#include <iostream>
#include <vector>
#include "table.h"

using namespace std;

table::Table(unsigned int max_entries = 100)
{
	this->head = new vector<Entry>(100);
	for (auto i = 0; i < 100; i++)
	{
		(*head)[i] = Entry();
	}

}

table::Table(unsigned int entries, std::istream& input)
{
//	new vector<Entry>* htable(entries);
	this -> head = new vector<Entry>(entries);
	for (auto i = 0; i < entries; i++)
	{
		Entry e();
		e >> input;
		(*head)[i].put(e);
	}
}

table::~Table()
{
	for(int i = 0; i < 100; i ++)
	{
		(*head)[i] = NULL;
	}
	delete this->head;
}

void table::put(unsigned int key, std::string data)
{
	(*head)[key].set_data(data);
	(*head)[key].set_key(key);
}

void table::put(Entry e)
{
	(*head)[e.get_key()].set_data(e.get_data());
	(*head)[e.get_key()].set_key(e.get_key());
}

std::string table::get(unsigned int key) const
{
	return (*head)[key].get_data();
}

bool table::remove(unsigned int key)
{
	(*head)[key].set_data("");
	return (*head)[key].get_data() == "";
}

