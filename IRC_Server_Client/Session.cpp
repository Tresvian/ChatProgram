#include "Session.h"

Session::Session(boost::asio::io_context* io)
	: currentStatus(Status::Unused), socket(*io)
{
	beginListen();
};

void Session::setStatus(Status x)
{
	currentStatus = x;
};

void Session::beginListen()
{

}