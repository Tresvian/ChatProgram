#pragma once
#include "boost/asio.hpp"

enum Status { Unused, Connected };

class Session
{
private:
	Status currentStatus;
	boost::asio::ip::tcp::socket socket;

public:
	Session(boost::asio::io_context* io);
	void setStatus(Status x);
	void beginListen();
};

