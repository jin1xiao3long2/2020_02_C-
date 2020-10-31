#include "client.hpp"



unsigned Client::ClientNum = 0;
std::string Client::ServerName = "aaa.bbb.com";




Client::Client(const Client& c): _ClientName(c._ClientName)
{
    ClientNum++;
}

Client Client::operator=(const Client &c)
{
    if(this != &c)
        _ClientName = c._ClientName;
    return *this;
}



