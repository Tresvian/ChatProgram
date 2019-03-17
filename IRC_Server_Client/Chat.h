#pragma once
#include "boost/asio.hpp"
#include <vector>
#include "Session.h"
#include <deque>
#include <memory>

class Chat
{
private:
	boost::asio::io_context* io_context;
	boost::asio::ip::tcp::acceptor acceptor;
	std::shared_ptr<std::vector<Session>> sessionList;
	std::shared_ptr<std::deque<std::string>> messageList;
public:
	Chat(boost::asio::io_context* io, int port, int socketCount);

	void connect(Session& client);

	void resynch(Session& client);
};

