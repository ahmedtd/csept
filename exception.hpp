#include <exception>

using namespace std;

//Thrown when the log file fails to perform some write operation or is closed
class log_fail_exception: public exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Failure writing to the log file";
    }
} log_fail_ex;

//Thrown when a property cannot be found
class property_fail_exception: public exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Failure writing to the log file";
    }
} property_fail_ex;

//Thrown when cin fails
class cin_fail_exception: public exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Failed to read from standard input";
    }
} cin_fail_ex;
