//
//  table.h
//  S19 - Lab04
//
#ifndef table_h
#define table_h
#include "entry.h"
#include <iostream>
#include <fstream>
#include <vector>

// Note: Your hash table must be implemented using an array of
// std::vector<Entry> as stated in the instructions.

class Table
{
	public:
		Table();
		Table(unsigned int max_entries = 100);
		Table(unsigned int entries, std::istream& input);
		void put(unsigned int key, std::string data);
  		void put(Entry e);
		std::string get(unsigned int key) const;
		bool remove(unsigned int key);
		friend std::ostream& operator<< (std::ostream& out, const Table& t);

	private:
		unsigned int size_of_table;
		std::vector<Entry>* data_of_table;
	    unsigned int HashFuncs(int key);	
};
void quicksort(Entry a[], int size);
void switch_piv(Entry a[], int size, int& pivotIndex);



#endif /* table_h */
