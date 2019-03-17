#include "Chat.h"

using namespace boost::asio;

Chat::Chat(boost::asio::io_context* io, int port, int socketCount)
	: io_context(io),
	  acceptor(*io, ip::tcp::endpoint(ip::tcp::v4(), port))
{
	for (int i; i < socketCount; ++i)
	{
		sessionList->push_back(Session(io));
	}
};

void Chat::connect(Session& client)
{
	

};