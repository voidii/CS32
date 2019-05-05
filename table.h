//
//  table.h
//  S19 - Lab04
//
#ifndef table_h
#define table_h
#include <vector>
#include "entry.h"
#include <string>

// Note: Your hash table must be implemented using an array of
// std::vector<Entry> as stated in the instructions.

class Table
{
	public:
		Table(unsigned int max_entries = 100);
		Table(unsigned int entries, std::istream& input);
		~Table();
		void put(unsigned int key, std::string data);
  		void put(Entry e);
		std::string get(unsigned int key) const;
		bool remove(unsigned int key);
		std::ostream& operator<< (std::ostream& out, const Table& t);

	private:
		std::vector<Entry>* head;
	        int HashFunc(int key);	
};




#endif /* table_h */
