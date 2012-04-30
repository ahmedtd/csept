/**
**  Author: Rachel Flores-Meath
**  Last Updated: March 20, 2012

**  General log file utilities.
**  Contains methods to open and close a log file, to append a pre-formatted
**    string to a log file, to append a string and result to a log file,
**    and to write to a previously closed log file
**  append_action_to_closed_log() is most useful for quick writes
**  The other methods are geared towards multiple writes in succession
**    (Really, they're there for modularity and efficiency)
**  open_log_file() is the only method that explicitly defines where the
**    log file is (i.e. log.txt in the current working directory)
**    The remaining methods rely on a file handler for modularity
**
**  WARNING: These methods are NOT THREAD-SAFE!
**    The application should not need to write to the log in a threaded state
**    If we decide it does, this library will be rewritten to reflect that
**/

#include <iostream>
#include <fstream>

using namespace std;

/*
*  Given a file stream, opens that filestream to log.txt
*  Throws log_fail_ex on failure
*/
void open_log_file(fstream &log)
{
  if (log.is_open())
  {
    throw log_fail_ex;
  }

  log.open("log.txt", ios::out | ios::app);
  
  if (!log.is_open())
  {
    throw log_fail_ex;
  }
}

/*
*  Given a file stream, cleanly closes the file
*/
void close_log_file(fstream& log)
{
  if (log.is_open())
  {
    log.close();
  }
  
  //If the log is already closed, we have nothing to worry about
}

/*
*  Given a (pre-formatted) string and file stream, appends the string to the log file
*  Places a timestamp at the start of the string
*  Places a newline at the end of the string if one is not at the end of the string
*  Throws log_fail_ex if the log is not open
*/
void append_raw_to_log(fstream& log, string s)
{
  if (!log.is_open())
  {
    throw log_fail_ex;
  }
  
  time_t current_time;
  time(&current_time);
  
  log << ctime(&current_time) << s;
  
  if (s[s.size() - 1] != '\n')
  {
    log << endl;
  }else
  {
    flush(log);
  }
  
  if (log.fail())
  {
    throw log_fail_ex;
  }
}


/*
*  Given a string containing an action that occurred and the result of that action, appends the string and the result to the log file
*  Places a timestamp at the start of the string
*  Places a newline at the end of the string
*  Throws log_fail_ex if the log is not open
*/
void append_action_to_log(fstream& log, string s, bool result)
{
  if (!log.is_open())
  {
    throw log_fail_ex;
  }
  
  time_t current_time;
  time(&current_time);
  
  //FIXME remove newline char at the end of ctime
  log << ctime(&current_time) << ": " << s;
  if (result)
  {
    log << " (SUCCESS)";
  }else
  {
    log << " (FAILURE)";
  }
  
  log << endl;
  
  if (log.fail())
  {
    throw log_fail_ex;
  }
}

/*
*  Given a string containing an action that occurred and the result of that action, appends the string and the result to the log file
*  Performs the following methods in order:
*    open_log_file(log)
*    append_action_to_log(log, s, result)
*    close_log_file(log)
*  Throws log_fail_ex if any failures occurred
*
*  This will be hugely inefficient if multiple writes to the log file
*  are needed in succession
*/
void append_action_to_closed_log(string s, bool result)
{
  try
  {
    fstream log;
    open_log_file(log);
  
    append_action_to_log(log, s, result);

    close_log_file(log);
  }catch(log_fail_exception e)
  {
    //Not necessary, but could be useful for later modifications
    throw log_fail_ex;
  }
}
