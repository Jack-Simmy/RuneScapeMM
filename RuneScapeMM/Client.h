#pragma once
#include <Windows.h>
#include <string>
#include <vector>
#include <WinSock2.h>

class Client
{
public:
	Client();
	~Client();

	void connectToServer(std::string& host, int port);
	void sendData(const std::string& data);
	std::vector<double> receiveData(); // prices get pushed into the returning vector need to figure out how to recieve data

private:

};

Client::Client()
{
}

Client::~Client()
{
}