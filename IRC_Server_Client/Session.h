#pragma once
#include "boost/asio.hpp"
#include "Chat.h"
#include <thread>
#include <mutex>
#include <vector>
#include <deque>

/*
Construct with the io_context ref, messageList* to add messages,
	and messageListLock* for making sure its sequantially added
	into the list.
	then begin a thread with run()

run() will loop forever, accepting/waiting.
	Upon client disconnection, sets the session's status
	into Unused again. Starts run() again.

*/

enum socketStatus { Unused, Connected };

class Session
{
private:
	socketStatus                          currentStatus;
	boost::asio::ip::tcp::socket          socket;
	std::thread*                          thread;
	Chat*                                 parentChat;

public:
	Session(boost::asio::io_context& io, Chat* parentChat);

	void                          run(Session* selfSession);

	void                          setStatus(socketStatus&& x);
	socketStatus&                 getStatus() const;
	boost::asio::ip::tcp::socket& getSocket();
	void                          receiveMessage();
};