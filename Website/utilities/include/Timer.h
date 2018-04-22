#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

class Timer {

private:

	template<unsigned MAX = 0>
	class Unit {
		private:
			unsigned _value = 0;
			bool _reset = false;
		public:
			Unit(unsigned value) : _value(value) {}
			Unit& operator++ () {
				_value++;
				if constexpr(MAX > 0) {
					_reset = false;
					if (_value == MAX) {
						_value = 0;
						_reset = true;
					}
				}
				return *this;
			}
			unsigned operator()() const {
				return _value;
			}
			inline bool wasReset() const {
				return _reset;
			}
	};

	struct Time {
		Unit<60> sec = 0;
		Unit<60> min = 0;
		Unit<24> hr = 0;
		Unit<> day = 0;
	} _time;

	static constexpr unsigned DUR_RES = 21;

	char _display[DUR_RES] = "0000d:00h:00m:00s";

	void updateDuration();

	inline void updateDisplay();

public:

	Timer() = default;

	void advanceTime();

	friend std::ostream& operator<< (std::ostream& os , const Timer& timer);

};

#endif
