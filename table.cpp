#include <iostream>
#include <vector>
#include "table.h"

using namespace std;

table::Table(unsigned int max_entries = 100)
{
	size_of_table = max_entries;
//	this->array_of_vector = new vector<Entry>(100);
	data_of_table = new vector<Entry> [size_of_table1];

}

table::Table(unsigned int entries, std::istream& input)
{
	size_of_table = entries*3;
//	new vector<Entry>* htable(entries);
	data_of_table = new vector<Entry>[size_of_table];
	Entry temp;
	for (auto i = 0; i < entries; i++)
	{
		input >> temp;
		this->put(temp);
	}
}

int Table::Hashfuncs(int key)const
{
	return key%size_of_table;
}


void Table::put(unsigned int key, std::string data)
{
	Entry e(key, data);
	int t = 1;
	int index_of_data = Hashfuncs(key);
	for(int i = 0; i < data_of_table[index_of_table].size(); i++)
	{
		if(data_of_table[index_of_table][i].get_key() == key)
		{
			t = 0;
			data_of_table[index_of_table][i] = e;
		}
	}
	if(t)
	{
		data_of_table[index_of_table].push_back(e);
	}
}

void table::put(Entry e)
{
        int t = 1;
        int index_of_data = Hashfuncs(e.get_key());
        for(int i = 0; i < data_of_table[index_of_data].size(); i++)
        {
                if(data_of_table[index_of_data][i].get_key() == e.get_key())
                {
                        t = 0;
                        data_of_table[index_of_data][i] = e;
                }
        }
        if(t)
        {
                data_of_table[index_of_data].push_back(e);
        }

}

std::string table::get(unsigned int key) const
{
	for(int i = 0; i < data_of_table[Hashfuncs(key)].size(); i++)
        {
                if(data_of_table[index_of_data][i].get_key() == key)
                {
                  	return data_of_table[index_of_data][i].get_data();
			//      data_of_table[index_of_data][i] = e;
                }
        }
	return "";
}

bool table::remove(unsigned int key)
{
	for(int i = 0; i < data_of_table[Hashfuncs(key)].size(); i++)
        {
                if(data_of_table[index_of_data][i].get_key() == key)
                {
                        data_of_table[index_of_data][i].erase(index_of_data][i].begin() + i);
                        return true;
                }
        }
        return false;
}

void Table:: switch_piv(Entry a[], int size, int& pivotIndex)
{
 	 Entry pivot = a[0];
 	 int left = 1;		 
 	 int right = size - 1; 
 	 Entry temp;

 	 while (left <= right)
	 {
   		 while (left < size && a[left] <= pivot)
		 {
   		   left++;
  		 }

  	 	 while (a[right] > pivot)
		 {
		      right--;
	   	 }

    
   		 if (left < right)
		 {
     			 temp = a[left];
     			 a[left] = a[right];
     			 a[right] = temp;
   		 }
  	}

 
 	 pivotIndex = right;
 	 temp = a[0];
 	 a[0] = a[pivotIndex];
 	 a[pivotIndex] = temp;
}

void quicksort(Entry a[], int size)
{
	 int pivotIndex;
 	 int leftSize;		
 	 int rightSize;		

 	 if (size > 1) 
	 {
   		 partition(a, size, pivotIndex);
   		 leftSize = pivotIndex;
   		 rightSize = size - leftSize - 1;
   		 quicksort(a, leftSize);
   		 quicksort((a + pivotIndex + 1), rightSize);
 	 }
}

ostream& operator<< (ostream& out, const Table& t)
{
	Entry *a = new Entry[t.tsize];
 	int count = 0;
 	for (int i = 0; i < t.tsize; i++)
        {
		for (int j = 0; j < t.content[i].size(); j++)
       		{
		     a[count] = t.content[i][j];
 		     count++;
  	 	}
	}
 	sort(a, count);

  	for (int i = 0; i < count; i++)
       	{
      		out<<a[i]<<endl;
 	} 
 	 return out;
}

	










