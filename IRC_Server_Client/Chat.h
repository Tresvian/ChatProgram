#pragma once
#include "boost/asio.hpp"
#include <vector>
#include "Session.h"
#include <deque>
#include <memory>
#include <atomic>
#include <mutex>
/*
io_context created at main
acceptor is our port
sessionList is all the sessions with sockets, a shared_ptr
	for future reasons.
messageList is the current messages to send
acceptorThread is the thread that the acceptor will listen and pass
	the incoming connections per unused session.
*/

class Chat
{
private:
	boost::asio::io_context& io_context;
	boost::asio::ip::tcp::acceptor acceptor;
	std::atomic<bool>* endProgramIndicator;

	std::vector<Session> sessionList;

	std::mutex messageListLock;
	std::deque<std::string> messageList;

	std::thread* acceptorThread;

public:
	Chat(boost::asio::io_context io, int port, int socketCount,
		 std::atomic<bool>* endProgramIndicator);

	void listen(Chat* selfChat);

	void resynch(Session& client);
	void updateMessage(std::string& message);
	void sendMessage(std::string& message);
private:
	void wait(Chat* selfChat);
};

