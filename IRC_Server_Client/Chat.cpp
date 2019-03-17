#include "Chat.h"

using namespace boost::asio;

Chat::Chat(boost::asio::io_context& io, int port, int socketCount)
	: io_context(io),
	  acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), port))
{
	// Using the arg socketCount for sockets
	for (int i; i < socketCount; ++i)
	{
		sessionList->push_back(Session(io, self));
	}

	acceptorThread = new std::thread(listen);
	// start new thread to send updates
};

void Chat::listen()
{
	// Intended to loop forever.
	for (auto eachSession : *sessionList)
	{
		if (eachSession.getStatus() == socketStatus::Unused)
		{
			acceptor.accept(eachSession.getSocket());
			eachSession.setStatus(socketStatus::Connected);
		}
	}
	// If sessionList is full, don't just hog the CPU
	std::this_thread::sleep_for(std::chrono_literals::ms(200));
};

void Chat::synch(Session& client)
{
	// todo

};

void Chat::updateMessage(std::string& message)
{
	messageListLock.lock();
	messageList.push_front(message);

	sendMessage(message);

	if (messageList.size() > 100)
	{
		messageList.pop_back();
	}
	messageListLock.unlock();
}

void Chat::sendMessage(std::string& message)
{
	using namespace boost::asio;
	for (auto eachSession : *sessionList)
	{
		write(eachSession.getSocket(), buffer(message));
	}
	
}