/*********************************************************************
** Program Filename: SearchSort.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/06/2015
** Description:      Encapsulation to run easier automated testing of
**                   arrays. Can read from source files and conduct
**                   various searches and sort an array read from file.
** Input:            Needs a filename to read int values from
** Output:           Searches arrays and returns index of values, also
**                   sorts the array and can print to file or return string
********************************************************************/

#ifndef SSHILLYER_SEARCHSORT_HPP
#define SSHILLYER_SEARCHSORT_HPP

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

class SearchSort
{
private:
  int* values;
  int size;
  std::string source_file;
public:
  SearchSort(std::string filename);
  bool read_values(std::string filename);
  int linear_search(int key);
  int binary_search(int key);
  int selection_sort();
  void write_file(std::string);
  std::string to_string();
  std::string get_filename()
  {
    return source_file;
  }
};

#endif
