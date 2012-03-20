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
