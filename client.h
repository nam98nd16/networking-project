#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <QObject>

#include "MyRect.h"

#define PORT 30696
#define MAX 80
#define SA struct sockaddr

using namespace std;

class Client: public QObject
{
    Q_OBJECT

public:
    Client(MyRect *rect);
    void createNewClient();


private:

    //Socket stuff
    int sockfd;
    // int clientSock;
    struct sockaddr_in servaddr, cli;
    // char buff[256];
    char buff[10];

  private:
    static void ListClients();
    static void SendToAll(char *message);
    static int FindClientIndex(Client *c);

public slots:
    void sendToServer(char *s);
  //  void sendToServer(char *s);

signals:
    void sentNewPosClient(char *s);

};

#endif // CLIENT_H
