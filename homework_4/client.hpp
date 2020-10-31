#pragma once
#include <string>

class Client final{


private:

    std::string _ClientName;
    static std::string ServerName;
    static unsigned ClientNum;
    

public:

    Client() = delete;

    Client(std::string ClientName): _ClientName(ClientName)
    {
        Client::ClientNum++;
    }

    ~Client()
    {
        Client::ClientNum--;
    }

    Client(const Client& c);

    Client operator=(const Client &c);

public:

    std::string getClientName() const
    {
        return this->_ClientName;
    }

public:

    static void ChangeServerName(std::string _ServerName) 
    {
        Client::ServerName = _ServerName;
    }

    static std::string getServerName()
    {
        return Client::ServerName;
    }
    
    static int getClientNum()
    {
    	return ClientNum;
	}



};



