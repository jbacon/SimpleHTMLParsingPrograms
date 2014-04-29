#include <stdexcept>
#include <string>

using namespace std;

class TreeException : public logic_error
{
public:
	TreeException(const string& message = "") : logic_error(message.c_str())
	{ }
};