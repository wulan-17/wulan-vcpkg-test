#ifndef __LOGTEST__H__
#define __LOGTEST__H__

#include <string>
#include <sstream>

using namespace std;

class LogTest
{
public:
    static void testLog(const char* file, int lineno, const string &nameStr, const string &argStr);
    
    template<typename ...Args>
    static string getArgs(Args && ...args);
};

template<typename ...Args>
static string getArgs(Args && ...args)
{
    stringstream argsStream;
	((argsStream << args << ", "), ...);
    return argsStream.str();
}

#define TEST_LOG(...) LogTest::testLog(__FILE__, __LINE__, #__VA_ARGS__, getArgs(__VA_ARGS__));

#endif