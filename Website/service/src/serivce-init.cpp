#include <future>
#include "WebInitializer.h"
#include "Timer.h"


int main(int argc, char** argv) {
	try {
		Timer timer;
		
		cppcms::service srv(argc, argv);
		srv.applications_pool().mount(cppcms::applications_factory<WebInitializer>());

		try {
			auto serviceThread = std::async(std::launch::async, [&]() { srv.run(); });
			std::cout << "Web Service running\n\n";
			using namespace std::chrono_literals;
			while (serviceThread.wait_for(0us) != std::future_status::ready) {
				std::cout << "Up Time: " << std::flush;
				std::cout << timer << '\r';
				timer.advanceTime();
			}
			serviceThread.get();
			std::cout << std::endl;
			return EXIT_SUCCESS;
		}
		catch (const std::exception& e) {
			std::cerr << "\nRuntime Error:\n	" << e.what() << '\n';
			std::cerr << "\nThe application terminated with an error.\nPress Enter to close the process." << std::endl;
			std::cin.get();
			return EXIT_FAILURE;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Initialization Error:\n	" << e.what() << '\n';
		std::cerr << "\nThe application terminated with an error.\nPress Enter to close the process." << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}
}