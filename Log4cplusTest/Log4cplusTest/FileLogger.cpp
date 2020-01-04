
#include "logger.h"


#include<log4cplus/fileappender.h>
using namespace log4cplus;
using namespace log4cplus::helpers;

int main2()
{
	SharedAppenderPtr _append(new FileAppender("Test.log"));
	_append->setName("filelogtest");

	Logger _logger = Logger::getInstance("test.subtestof_filelog");
	_logger.addAppender(_append);

	for (int i = 0; i < 5; ++i)
	{
		LOG4CPLUS_DEBUG(_logger, "Entering loop#" << i << "Endline#");
	}

	return 0;
}