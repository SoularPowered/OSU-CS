/*********************************************************************
 ** Program Filename: Person.hpp		[HEADER]
 ** Author:           Shawn Hillyer
 ** Date:             11/20/2015
 ** Description:      Simple class to represent people with an integer
 **                   id; used in a LineSimulator class
 ** Input:            Id for the constructor
 ** Output:           Can return the id of the person.
 ** NOTE:             Using only a header file to keep all functions
 **                   in-line; very simplistic class.
 ********************************************************************/
#ifndef SSHILLYER_PERSON_HPP
#define SSHILLYER_PERSON_HPP

class Person
{
private:
  int id;
public:
  // Constructor. Takes an integer to set the "id"
  Person(int id)
  {
    this->id = id;
  }
  // Accessor - getter. Returns the id.
  int get_id()
  {
    return id;
  }
};

#endif
