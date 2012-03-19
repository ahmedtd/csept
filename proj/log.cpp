/**
**  Author: Rachel Flores-Meath
**  Last Updated: March 19, 2012

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
*  Returns false on failure
*/
bool open_log_file(fstream &log)
{
  if (log.is_open())
  {
    return false;
  }

  log.open("log.txt", ios::out | ios::app);
  
  if (log.is_open())
  {
    return true;
  }else
  {
    return false;
  }
}

/*
*  Given a file stream, cleanly closes the file
*/
void close_log_file(fstream log)
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
*  Returns false if the log is not open
*/
bool append_raw_to_log(fstream log, string s)
{
  if (!log.is_open())
  {
    return false;
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
    return false;
  }
}


/*
*  Given a string containing an action that occurred and the result of that action, appends the string and the result to the log file
*  Places a timestamp at the start of the string
*  Places a newline at the end of the string
*  Returns false if the log is not open
*/
bool append_action_to_log(fstream log, string s, bool result)
{
  if (!log.is_open())
  {
    return false;
  }
  
  time_t current_time;
  time(&current_time);
  
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
    return false;
  }
}

/*
*  Given a string containing an action that occurred and the result of that action, appends the string and the result to the log file
*  Performs the following methods in order:
*    open_log_file(log)
*    append_action_to_log(log, s, result)
*    close_log_file(log)
*  Returns false if any failures occurred
*
*  This will be hugely inefficient if multiple writes to the log file
*  are needed in succession
*/
void append_action_to_closed_log(string s, bool result)
{
  fstream log;
  if (!open_log_file(log))
  {
    return false;
  }
  
  if (!append_action_to_log(log, s, result))
  {
    return false;
  }

  close_log_file(log))
}

int main()
{
  return 0;
}
