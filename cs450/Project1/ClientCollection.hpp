/*
ClientCollection.hpp
Eric Brewer
10/26/10
Kooshesh
CS450 - Operating Systems
Chat Program: ClientCollection class implementation -
*/

#ifndef _CLIENTCOLLECTION_HPP
#define _CLIENTCOLLECTION_HPP

#include <string>
using namespace std;
#include <vector>
class Client;

class ClientCollection{
public:
  ClientCollection();
  bool addClient( Client *client );
  bool deleteClient( string clientName );
  int numClients() { return _clients.size(); }
  Client *exists( string clientName );

private:
  vector<Client *> _clients;

};

#endif
