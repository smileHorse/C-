
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

int main0()
{
	// Initialization and deinitialization.
	log4cplus::Initializer initializer;

	log4cplus::BasicConfigurator config;
	config.configure();

	log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));
	LOG4CPLUS_WARN(logger, LOG4CPLUS_TEXT("Hello, world!"));
	LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("��ã��й�!"));

	return 0;
}