#include "client.h"
#include "scene.h"

#include <unistd.h>

#include <QApplication>
#include <QDebug>

Client::Client(MyRect *rect)
{
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sockfd == -1) {
//            printf("socket creation failed...\n");
//            exit(0);
//    }
//    else
//    {
//        printf("Socket successfully created..\n");
//    }
//    bzero(&servaddr, sizeof(servaddr));

//        // assign IP, PORT
//    servaddr.sin_family = AF_INET;
//    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//    servaddr.sin_port = htons(PORT);

//        // connect the client socket to server socket
//    if (::connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
//        printf("connection with the server failed...\n");
//        exit(0);
//    }
//    else{
//        printf("connected to the server..\n");
//    }

//     MyRect *r = new MyRect();

      QObject::connect(this, &Client::sentNewPosClient, rect, &MyRect::NewPos);

//    Client *c = new Client();
//    c->createNewClient();
//    QObject::connect(this, &MyRect::sendToClient, c, &Client::sendToServer);
}

void Client::createNewClient()
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
    }
}


void Client::sendToServer(char *s)
{
    char buff[MAX];
    strcpy(buff, s);
//    strcpy(this->buff, s);
//    qDebug() << this->buff;
//    qDebug() << buff;
  //  bzero(buff, sizeof(buff));

           write(sockfd, buff, sizeof(buff));
    //       printf("From Server : %s", buff);
       //    qDebug() << buff << endl;

                   bzero(buff, sizeof(buff));
           read(sockfd, buff, sizeof(buff));
           qDebug() << buff << endl;

           if (strcmp(buff, "Client n.0:LEFT") == 0 || strcmp(buff, "Client n.0:RIGHT") == 0
                   || strcmp(buff, "Client n.0:UP") == 0 || strcmp(buff, "Client n.0:DOWN") == 0) {
         //       setPos(() - 10, y());
                emit sentNewPosClient(buff);
          //      qDebug() << buff;
           }

           if ((strncmp(buff, "exit", 4)) == 0) {
               printf("Client Exit...\n");
           }
//           if (read(sockfd, buff, sizeof(buff)) == 0) {
//                exit(EXIT_FAILURE);
//           }
}

