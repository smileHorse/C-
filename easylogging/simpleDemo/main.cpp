
#include "easylogging/easylogging++.h"
// ** FOLLOWING LINE SHOULD BE USED ONCE AND ONLY ONCE IN WHOLE APPLICATION **
// ** THE BEST PLACE TO PUT THIS LINE IS IN main.cpp RIGHT AFTER INCLUDING easylogging++.h **
_INITIALIZE_EASYLOGGINGPP

SUB(print, (const std::string& input))
	std::cout << input << std::endl;
END_SUB

FUNC(int, sum, (int x, int y))
	RETURN(x + y);
END_FUNC(0)

int main()
{
	// Load configuration from file
	easyloggingpp::Configurations confFromFile("myconfiguration_file");
	// Re-configures all the loggers to current configuration file
	easyloggingpp::Loggers::reconfigureAllLoggers(confFromFile);

	easyloggingpp::Configurations defaultConf;
	defaultConf.setToDefault();
	// Only business logger uses default configurations
	easyloggingpp::Loggers::reconfigureLogger("business", defaultConf);

	easyloggingpp::Loggers::enablePerformanceTracking();
	
	print("this is test");
	int result = sum(1, 2);
	LINFO << "Sum of 1 and 2 is " << result; 
	BINFO << "Sum of 1 and 2 is " << result; 

	return 0;
}