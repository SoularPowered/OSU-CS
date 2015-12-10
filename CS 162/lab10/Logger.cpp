/*********************************************************************
** Program Filename: Logger.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             11/27/2015
** Description:      A Logging class to write timestamps to a file
** Input:            Filenames and strings
** Output:           Can return timestamps and write files
********************************************************************/
#include "Logger.hpp"

/*********************************************************************
** Function:         log()
** Description:      Writes time stamp information to a file
** Parameters:       Filename, the action done, and Description as strings
** Pre-Conditions:   None
** Post-Conditions:  File will exist with this information appended
********************************************************************/
bool Logger::log(std::string filename, std::string action, std::string description)
{
  std::fstream log_file(filename.c_str(), std::ios::app | std::ios::out);
  log_file << current_time() << ". Click Time: " << get_clicks() << "(" << action << ") " << description << "\r\n";

  return true;
}


/*********************************************************************
** Function:         current_time()
** Description:      Returns a time stamp in form of a string.
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  .
** Source:           Adapted from stackoverflow.com "How to get
**                   current time and date in C++?"
********************************************************************/
const std::string Logger::current_time()
{
  std::time_t now = time(0);
  struct tm tstruct;
  char buf[80];

  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%X", &tstruct);

  return buf;
}


/*********************************************************************
** Function:         get_clicks()
** Description:      Returns an integer representing the time, used
**                   to measure time between function calls
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  None
** Source:           Adapted from cplusplus.com/reference/ctime/clock
********************************************************************/

int Logger::get_clicks()
{
  clock_t t = clock();
  return t;
}
