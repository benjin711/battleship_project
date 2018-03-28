# battleship_project
Technical University of Munich Battleship Project C++

Our task was to implement the game battleship with GUI and network in a team of three in an object oriented style. We used the QTCreater to create network and user interface.

The project was split into three parts: Florian Danner worked on the network, Verena Feierle worked on the GUI and I (Benjamin Jin) worked on the logic part of the game. 

I wrote the code in the following files: game.h, game.cpp, player.h, player.cpp, board.h, board.cpp, ship.h, ship.cpp. And helped writing the code in controlls.h and controlls.cpp as well. 

The file called Battleship is the executable and will open up a start window. In order to play against another player, he should download the files as well and open up the start window. 

Steps to start the game:
1) One of the players must decide to be the server and the other player will be the client
2) The server and client enter the same port (number above 1000) and the client will need to type in the ip adress of the server
3) The server clicks on "verbinden" first! Then the client clicks on "verbinden".
4) Klick start and you may place all your ships and start the game
