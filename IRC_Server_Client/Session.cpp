#include "Session.h"

Session::Session(boost::asio::io_context& io, Chat* parentChat)
	: currentStatus(socketStatus::Unused),
	  socket(io),
	  parentChat(parentChat)
{
	// Startup: The thread will reference itself
	thread = new std::thread(Session::run, this);
}

void Session::run(Session* selfSession)
{
	// This function runs in its own thread.

	// start loop
	while (selfSession->getStatus == socketStatus::Unused)
	{
		std::this_thread::sleep_for(std::chrono_literals::ms(200));
	}

	// Connection made, receive.
	clientDisconnected = false;
	while (clienDisconnected == false)
	{
		try
		{
			std::string newMessage = selfSession->receiveMessage();
			parentChat->updateMessage(newMessage);
		}
		catch (std::exception& e)
		{
			clientDisconnected = true;
		}
	}

	//upon exit, setStatus and then rerun loop
	selfSession->setStatus(socketStatus::Unused);
	selfSession->run();
}

void Session::setStatus(socketStatus&& x)
{
	currentStatus = x;
}

socketStatus& Session::getStatus() const
{
	return currentStatus;
}

boost::asio::ip::tcp::socket& Session::getSocket()
{
	return &socket;
}

std::string Session::receiveMessage()
{
	//return into the chat.
	std::vector<char, 256> buffer;
	socket.receive(boost::asio::buffer(buffer)));
	return std::string(buffer.begin(), buffer.end());
}