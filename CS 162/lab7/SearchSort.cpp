/*********************************************************************
** Program Filename: SearchSort.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             11/06/2015
** Description:      Encapsulation to run easier automated testing of
**                   arrays. Can read from source files and conduct
**                   various searches and sort an array read from file.
** Input:            Needs a filename to read int values from
** Output:           Searches arrays and returns index of values, also
**                   sorts the array and can print to file or return string
********************************************************************/

#include "SearchSort.hpp"


/*********************************************************************
** Function:         SearchSort()
** Description:      Constructor. Reads values from file.
** Parameters:       string: filename to read from
** Pre-Conditions:   valid file must exist in same folder
** Post-Conditions:  Array will be initialized and size will be set
**                   to match size of the array; if file couldn't be
**                   found, message printed to screen.
********************************************************************/
SearchSort::SearchSort(std::string filename)
{
  this->size = 0;
  if (!read_values(filename))
    std::cout << "Couldn't open " << filename << "\n";
}


/*********************************************************************
** Function:         read_values()
** Description:      Reads values from a file, filename, into array
** Parameters:       string: filename
** Pre-Conditions:   file must exist
** Post-Conditions:  Returns true if file was succesfully opened/read
**                   Also array will be initialized with values
********************************************************************/
bool SearchSort::read_values(std::string filename)
{
  const bool SUCCESS = true;
  // Remember the filename fed and open file, return false if failed
  this->source_file = filename;
  std::ifstream in_file(filename.c_str());
  if (!in_file)
  {
    return !SUCCESS;
  }

  // If file exists, then read values into a vector and count elements
  else
  {
    int in_value;
    std::vector<int> values;

    while (in_file >> in_value)
    {
      values.push_back(in_value);
      this->size++;
    }

    // Allocate  memory for this->values and copy vector elements into this->values
    this->values = new int[this->size];
    for (int i = 0; i < this->size; i++)
    {
      this->values[i] = values[i];
    }

    // Close file and return success
    in_file.close();
    return SUCCESS;
  }
}



/*********************************************************************
** Function:         linear_search()
** Description:      Basic linear search algorithm based on Gaddis text
** Parameters:       integer: key to search for
** Pre-Conditions:   data should be read into array before calling
** Post-Conditions:  Returns -1 if not found, first index of key if found
********************************************************************/
int SearchSort::linear_search(int key)
{
  bool found = false;
  int position = -1;
  int index = 0;

  while (index < this->size && found == false)
  {
    if (this->values[index] == key)
    {
      found = true;
      position = index;
    }
    index++;
  }

  return position;
}



/*********************************************************************
** Function:         binary_search()
** Description:      Basic binary search algorithm based on Gaddis text
** Parameters:       integer: key to search for
** Pre-Conditions:   data should be read into array before calling
**                   data must be sorted
** Post-Conditions:  Returns -1 if not found, first index of key if found
********************************************************************/
int SearchSort::binary_search(int key)
{
  int first = 0,           // Shifts up if value in top half
      last = (this->size - 1),  // shifts down if value in bottom half
      position = -1;       // Index of value (if not found -1)
  bool found = false;

  while (found == false && first <= last)
  {
    int middle = (first + last) / 2;
    // Case 1: the value is at index 'middle'
    if (this->values[middle] == key)
    {
      found = true;
      position = middle;
    }

    // Case 2: key might be in upper half of subscript range
    else if (this->values[middle] < key)
    {
      first = middle + 1;
    }

    // Case 3: key might be in lowe half of subscript range
    else
    {
      last = middle - 1;
    }
  }
  return position;
}



/*********************************************************************
** Function:         selection_sort()
** Description:      Simple selection sort based on Gaddis text
** Parameters:       None
** Pre-Conditions:   Objects array should be initialized
** Post-Conditions:  Array will be sorted in ascending order
********************************************************************/
int SearchSort::selection_sort()
{
  int start_scan, min_index, min_value;

  // Scan starting at every element of the array
  for (start_scan = 0; start_scan < (this->size - 1); start_scan++)
  {
    min_index = start_scan;
    min_value = this->values[start_scan];

    // Scan the subset of the array
    for (int index = start_scan+1; index < this->size; index++)
    {
      // Remember the lowest value
      if (this->values[index] < min_value)
      {
        min_value = this->values[index];
        min_index = index;
      }
    }
    // Swap current scans first value with value in lowest index
    this->values[min_index] = this->values[start_scan];
    this->values[start_scan] = min_value;
  }
}


/*********************************************************************
** Function:         write_file()
** Description:      Writes result of the sort to file
** Parameters:       A filename to write to
** Pre-Conditions:   None
** Post-Conditions:  filename will exist with the array values printed
********************************************************************/
void SearchSort::write_file(std::string filename)
{
  std::fstream out_file(filename.c_str(), std::ios::out | std::ios::app);

  out_file << this->source_file << " sorted: " << "\n";
  out_file << to_string();
  out_file << "\n";
}


/*********************************************************************
** Function:         to_string()
** Description:      returns a string with all of the values in whatever
**                   their current order is
** Parameters:       None
********************************************************************/
std::string SearchSort::to_string()
{
  std::ostringstream output;
  for (int i = 0; i < this->size; i++)
  {
    output << this->values[i];
    output << ((i != this->size - 1) ? (", ") : ("\n"));
  }
  return output.str();
}
