#include <future>
#include "MainController.h"
#include "Timer.h"

std::string runService(cppcms::service& srv) {
	try {
		srv.run();
		return std::string();
	}
	catch (const std::exception& e) {
		return e.what();
	}
}

int main(int argc, char** argv) {
	try {
		Timer timer;
		cppcms::service srv(argc, argv);
		srv.applications_pool().mount(
			cppcms::applications_factory<MainController>()
		);
		auto serviceThread = std::async(std::launch::async, [&]() { return runService(srv); });
		std::cout << "Web Service running\n";
		using namespace std::chrono_literals;
		while (serviceThread.wait_for(0us) != std::future_status::ready) {
			std::cout << "Up Time: " << std::flush;
			std::cout << timer << '\r';
			timer.advanceTime();
		}
		std::cout << std::endl;
		auto e_message = serviceThread.get();
		if (!e_message.empty()) {
			throw std::runtime_error(e_message);
		}
		return EXIT_SUCCESS;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Runtime Error:\n	" << e.what() << '\n';
		std::cerr << "\nThe application terminated with an error.\nPress Enter to close the process." << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}
	catch (const std::exception& e) {
		std::cerr << "Initialization Error:\n	" << e.what() << '\n';
		std::cerr << "\nThe application terminated with an error.\nPress Enter to close the process." << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}
}