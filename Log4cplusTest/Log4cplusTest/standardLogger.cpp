
#include "logger.h"
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>

#include<chrono>
#include<thread>

using namespace log4cplus;
using namespace log4cplus::helpers;

int main1()
{
	// step1 Instantiate an append object
	SharedObjectPtr<Appender> _append(new ConsoleAppender());
	_append->setName("append for test");

	// step2: Instantiate an layout object
	std::string pattern = "%d{%m/%d/%y %H:%M:%S} - %m[%l]%n";

	// step3: Attach the layout object to the append object
	_append->setLayout(std::unique_ptr<Layout>(new PatternLayout(pattern)));

	// step4: Instantiate an logger object
	Logger _logger = Logger::getInstance("test");

	// step5: Attach the appender object to the logger
	_logger.addAppender(_append);

	// step6: Set a priority for the logger
	_logger.setLogLevel(ALL_LOG_LEVEL);

	LOG4CPLUS_DEBUG(_logger, "This is the first log message...");
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	LOG4CPLUS_WARN(_logger, "This is the second log message...");

	return 0;
}