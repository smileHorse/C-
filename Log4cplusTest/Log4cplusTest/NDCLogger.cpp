
#include "logger.h"

#include <log4cplus/consoleappender.h>
#include <log4cplus/ndc.h>
using namespace log4cplus;
using namespace log4cplus::helpers;

int main()
{
	log4cplus::Initializer initializer;

	SharedAppenderPtr _appender(new ConsoleAppender());
	_appender->setLayout(std::unique_ptr<Layout>(new TTCCLayout()));

	log4cplus::Logger logger = log4cplus::Logger::getInstance("NDCLogger");
	logger.addAppender(_appender);

	LOG4CPLUS_DEBUG(logger, "This is the first log");

	NDC& ndc = log4cplus::getNDC();
	ndc.push("ur ndc string");
	LOG4CPLUS_DEBUG(logger, "this is a ndc test");
	ndc.pop();

	LOG4CPLUS_DEBUG(logger, "There should be no ndc");

	NDCContextCreator creator("second urc string");
	LOG4CPLUS_DEBUG(logger, "this is a second ndc test");
	
	return 0;
}