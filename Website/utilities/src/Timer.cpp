#include "Timer.h"
#include <ostream>
#include <thread>

void Timer::updateDuration() {
	++_time.sec;
	if (_time.sec.wasReset())
		++_time.min;
	if (_time.min.wasReset())
		++_time.hr;
	if (_time.hr.wasReset())
		++_time.day;
}

void Timer::updateDisplay() {
	sprintf_s(_display, "%04dd:%02dh:%02dm:%02ds", _time.day(), _time.hr(), _time.min(), _time.sec());
}

void Timer::advanceTime() {
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);
	updateDuration();
	updateDisplay();
}

std::ostream& operator<<(std::ostream& os, const Timer& timer) {
	return os << timer._display;
}
