/*********************************************************************
** Program Filename: Logger.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/27/2015
** Description:      A Logging class to write timestamps to a file
** Input:            Filenames and strings
** Output:           Can return timestamps and write files
********************************************************************/
#ifndef SSHILLYER_LOGGER_HPP
#define SSHILLYER_LOGGER_HPP

#include <string>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <time.h>

class Logger
{
public:
  static bool log(std::string filename, std::string action, std::string description);
  static const std::string current_time();
  static int get_clicks();
};

#endif
