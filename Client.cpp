#include "Client.h"
#include "scene.h"

#include <unistd.h>

#include <QApplication>
#include <QDebug>

Client::Client(scene *s)
{
    MyRect *player = new MyRect(this);
    this->rect = player;
    QObject::connect(this, &Client::serverCreateNewPlayer, s, &scene::sceneAddPlayer);
    QObject::connect(this, &Client::serverUpdateNewPosClient, player, &MyRect::NewPos);
    QObject::connect(this, &Client::serverUpdateBulletClient, player, &MyRect::handleBullet);
}

//Client::Client(MyRect *rect)
//{
//      QObject::connect(this, &Client::serverUpdateNewPosClient, rect, &MyRect::NewPos);
//      QObject::connect(this, &Client::serverUpdateBulletClient, rect, &MyRect::handleBullet);
//}

void Client::createNewClient(scene *s)
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
            printf("socket creation failed...\n");
            exit(0);
    }
    else
    {
        printf("Socket successfully created..\n");
    }
    bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

        // connect the client socket to server socket
    if (::connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else{
        printf("connected to the server..\n");
    //    this->new_s = s;
        emit serverCreateNewPlayer(this->rect);
    }
}


void Client::sendNewPostionToServer(char *s)
{
    char buff[MAX];
    strcpy(buff, s);
//    strcpy(this->buff, s);
//    qDebug() << this->buff;
//    qDebug() << buff;

    write(sockfd, buff, sizeof(buff));
    //       printf("From Server : %s", buff);
       //    qDebug() << buff << endl;

    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    //           if (read(sockfd, buff, sizeof(buff)) == 0) {
    //                exit(EXIT_FAILURE);
    //           }

 //   qDebug() << buff << endl;

    if (strcmp(buff, "Client n.0:LEFT") == 0 || strcmp(buff, "Client n.0:RIGHT") == 0
               || strcmp(buff, "Client n.0:UP") == 0 || strcmp(buff, "Client n.0:DOWN") == 0) {
        emit serverUpdateNewPosClient(buff);
    }
}

void Client::sendBulletSignalToserver(char *s)
{
    char buff[MAX];
    strcpy(buff, s);


    write(sockfd, buff, sizeof(buff));
    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
//    qDebug() << buff << endl;

    if (strcmp(buff, "Client n.0:BULLET") == 0) {
        emit serverUpdateBulletClient(buff);
    }
}

void Client::sendDeathPlayerInfoToServer(char *s)
{
    char buff[MAX];
    strcpy(buff, s);

 //   qDebug() << buff << endl;


    write(sockfd, buff, sizeof(buff));
    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));

    if (strcmp(buff, "Client n.0:BULLET") == 0) {
        emit serverAssertPlayerDeath(buff);
    }

}

