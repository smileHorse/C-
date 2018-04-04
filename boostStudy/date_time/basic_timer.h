#ifndef BASIC_TIMER_H
#define BASIC_TIMER_H

#include <boost/timer.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

using namespace boost;
using namespace boost::posix_time;

template<typename Clock = microsec_clock>
class basic_timer
{
public:
	basic_timer(std::ostream& os = std::cout)
		: m_os(os)
	{
		restart();
	}

	void restart()
	{
		_start_time = Clock::local_time();
	}

	time_duration elapsed() const
	{
		return Clock::local_time() - _start_time;
	}

	~basic_timer()
	{
		try
		{
			std::istream::fmtflags old_flags = m_os.setf(std::istream::fixed, std::istream::floatfield);
			std::streamsize old_prec = m_os.precision(2);
			m_os << elapsed() << std::endl;
			m_os.setf(old_flags);
			m_os.precision(old_prec);
		}
		catch(...){}
	}

private:
	ptime _start_time;
	std::ostream& m_os;
};

typedef basic_timer<microsec_clock> ptimer;
typedef basic_timer<second_clock> sptimer;
#endif