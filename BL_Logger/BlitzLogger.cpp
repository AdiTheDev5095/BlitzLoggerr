#include <iostream>
#include "BlitzLogger.h"

using namespace std;
using namespace Blitz_Logger;

int main() {
	int a = 1001;
	const char* name = "Blitz";



	LOG_TRACE("Logger initialized by User : %d : %s ", a, name);
	LOG_INFO("Logger initialized by User : %d : %s ",a,name);
	LOG_WARN("Logger initialized by User : %d : %s ", a, name);
	LOG_ERROR("Logger initialized by User : %d : %s ", a, name);
	LOG_FATAL("Logger initialized by User : %d : %s ", a, name);

	

	return 0;
}