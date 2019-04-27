#include "Roster.h"

#include <cstdlib>
#include <fstream>
#include <cassert>

Roster::Roster() {
  // initialize to empty array

  this->numStudents = 0;
  for (int i=0; i<ROSTER_MAX; i++) {
    this->students[i] = NULL;
  }

}

void Roster::resetRoster() {
 // To avoid memory leaks:
  //  Recycle memory for all allocated students on roster
  
  while (this->numStudents > 0) {
    delete this->students[this->numStudents - 1];
    this->numStudents --;
  }

}

void Roster::addStudentsFromFile(std::string filename) {
  std::ifstream ifs; // the stream we will use for the input file
  ifs.open(filename);
  
  if (ifs.fail()) {
    std::cerr << "Could not open input file: "
	      << filename << std::endl;
    exit(2); 
  }

  // ifs is an instance of ifstream
  // ifstream inherits from istream, 
  //   i.e. ifs is-a istream

  this->addStudentsFromStream(ifs);

}

void Roster::addStudentsFromStream(std::istream &is) {

  this->resetRoster();

  std::string thisLine;
  // Try to read past the header line.
  getline(is,thisLine);
  if ( is.eof() || is.fail() ) {
    std::cerr << "Unable to read first line of input stream" << std::endl;
    exit(3);
  }

  getline(is,thisLine);
  while (  !is.eof() && !is.fail() ) {
    // If we get here, it means the most recent attempt to read succeeded!
    // So do something with thisLine
    
    Student *sPtr = new Student(thisLine);
    this->students[this->numStudents] = sPtr;
    this->numStudents++;
    
    // try to read another line
    getline(is,thisLine);
  } // end while

}

int Roster::getNumStudents() const {

       	return this->numStudents; // stub
}

Student Roster::getStudentAt(int index) const { 
  return *(this->students[index]); 
}

std::string Roster::toString() const {
  std::string result = "{\n";
  for (auto i = 0; i < getNumStudents(); i++)
  {
	 result += this->students[i]->toString();
	 if(i + 1 >= getNumStudents())
		 result += "\n";
	 else
		 result += ",\n";
  } 

//  result += "STUB!!!!";   // @@@ RESTORE THIS 

  result += "}\n";
  return result;

}

void Roster::sortByPerm() {
  	for (auto i = this->getNumStudents()-1; i > 0; i--)
	{
		int max = 0;
		int maxIndex = 0;
		for (auto j = 0; j < i; j++)
		{
			if(this->students[j]->getPerm() > max)
			{
				max = this->students[j]->getPerm();
				maxIndex = j;
			}
		}
		Student temp = *(this->students[i]);
		*(this->students[i]) = *(this->students[maxIndex]);
		*(this->students[maxIndex]) = temp;
	}
	// SELECTION SORT
  // stub does nothing
}

int Roster::indexOfMaxPermAmongFirstKStudents(int k) const {
	int maxIndex = 0;
	for (auto i = 0; i < k; i++)
	{
		if(this->students[i]->getPerm() > this->students[maxIndex]->getPerm())
		{
			maxIndex = i;
		}
	}

  return maxIndex; // STUB
}

void Roster::sortByPermHelper(int k) {
  // swaps max perm from [0..k-1] with elem [k-1]


  int im = indexOfMaxPermAmongFirstKStudents(k);
	  Student temp = *(this->students[im]);
          *(this->students[im]) = *(this->students[k-1]);
          *(this->students[k-1]) = temp;


  // now swap the pointers between index im and index k-1

  // THIS IS STILL A STUB !!!
  
}
