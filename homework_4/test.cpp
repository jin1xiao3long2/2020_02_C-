#include "client.hpp"
#include <iostream>

void showServer()
{
    std::cout << "ServerName:   " << Client::getServerName() << std::endl;
    std::cout << "ClientNum :   " << Client::getClientNum() << std::endl;
}

int main()
{
    showServer();
    Client* c1 = new Client("myname");
    Client* c2 = new Client(*c1);
    showServer();
    Client* c3 = new Client("third one");
    Client::ChangeServerName("jjj.xxx.com");
	showServer();
	delete c2;
	showServer();

    return 0;
}
