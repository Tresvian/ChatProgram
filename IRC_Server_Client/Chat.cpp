#include "Chat.h"

using namespace boost::asio;

Chat::Chat(boost::asio::io_context io, int port, int socketCount,
	       std::atomic<bool>* endProgramIndicator)
	: io_context(io),
	  acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), port)),
	  endProgramIndicator(endProgramIndicator)
{
	// Using the arg socketCount for sockets
	for (int i; i < socketCount; ++i)
	{
		sessionList.push_back(Session(io, this));
	}

	 std::thread acceptorThread(listen, this);

	 std::thread idleThread(wait, this);
};

void Chat::listen(Chat* selfChat)
{
	// runs in its own thread

	// Intended to loop forever.
	for (auto eachSession : selfChat->sessionList)
	{
		if (eachSession.getStatus() == socketStatus::Unused)
		{
			acceptor.accept(eachSession.getSocket());
			eachSession.setStatus(socketStatus::Connected);
		}
	}
	// If sessionList is full, don't just hog the CPU
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(200ms);
};

void Chat::resynch(Session& client)
{
	//todo for requesting clients
}

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
	for (auto eachSession : sessionList)
	{
		write(eachSession.getSocket(), buffer(message));
	}
	
}

void Chat::wait(Chat* selfChat)
{
	//runs in its own thread.
	while (selfChat->endProgramIndicator == false)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(5s);
	}
}