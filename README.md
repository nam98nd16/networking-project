# networking-project
This is project i make to practise knowledge about multithreading and socket programming.

# How to run
Into server folder, run make.

Because the Makefile has some errors(I am trying to fix them), so after run "make" command, you must compile to make a "chat" file in "bin" folder.

g++ -Wall -g -o ./bin/chat ./obj/main.o ./obj/mythread.o ./obj/server.o ./obj/client.o -lpthread.
Run the server : ./bin/chat.
