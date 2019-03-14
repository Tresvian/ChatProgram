#include <string>
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include "boost/asio.hpp"


int StartListening(int& tickRate, std::atomic<bool> &endProgramIndicator, std::atomic<bool>& endProgramIndicatorResult)
{
	boost::asio::io_context io_context;

	boost::asio::ip::tcp::socket socket(io_context);

	// Sleep timer set by tickRate
	std::chrono::duration<int, std::milli> duration(tickRate);
	std::this_thread::sleep_for(duration);
	return 0;
}