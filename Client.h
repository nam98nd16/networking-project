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
#include "scene.h"

#define PORT 30696
#define MAX 80
#define SA struct sockaddr

using namespace std;

QT_FORWARD_DECLARE_CLASS(QObject);


class scene;
class MyRect;

class Client: public QObject
{
    Q_OBJECT

public:
    Client(scene *s);
 //   Client(MyRect *rect);
    void createNewClient(scene *s);


private:

    //Socket stuff
    int sockfd;
    // int clientSock;
    struct sockaddr_in servaddr, cli;
    // char buff[256];
    char buff[10];
  //  scene *new_s;
    MyRect *rect;

  private:
    static void ListClients();
    static void SendToAll(char *message);
    static int FindClientIndex(Client *c);

public slots:
    void sendNewPostionToServer(char *s);
    void sendBulletSignalToserver(char *s);

signals:
//    void serverCreateNewPlayer(scene *s);
    void serverCreateNewPlayer(MyRect *rect);

    void serverUpdateNewPosClient(char *s);
    void serverUpdateBulletClient(char *s);
    void serverCreateEnemy();
};

#endif // CLIENT_H
