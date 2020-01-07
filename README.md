# Flight-Simulator

# Programing Project - 1st Mile Stone
# Flight Simulator 2020

#An Interpenter FlightGear's Flight Simulator in c++

# description about the project:
In this program, we interpret a file text that contains commands which will run the flight gear simulator.After the commands are bieng interpreted thye are being excuted.
The Interpreter serves both as a client and as a server for the simulator. In addition, the interpreter recieves data from the simulator and then updates the data it holds accordingly if necessary. Furthermore, information is being sent to the simulator and the simulator updates its status accordingly.

The server and the client are being programmed by our project, we simulate the communication between them.
There is a thread that reads the data from the server, during that time we send commands to the server.
The commands are beieng excuted according to the requirements in the text from the simulator, preceeded by the interpretation of the text to commands.

# WORKSPACE:
The project was written using clion in c++. It was designed on a linux operating system.

# HOW to run the program:
You can compile this program using using the following command: "‫‪g++‬‬ ‫‪-std=c++14‬‬ ‫‪*.cpp‬‬ ‫‪-Wall‬‬ ‫‪-Wextra‬‬ ‫‪-Wshadow‬‬ ‫‪-Wnon-virtual-dtor‬‬ ‫‪-pedantic‬‬ ‫‪-o‬‬‫‪ a.out‬‬ ‫‪-pthread‬‬" and run it with the command:"./a.out file_name"
whereas the file_name is the name of the text file you would like to interpret, for example fly.txt.

Reside the text file  alongside the main.cpp file( and all the others).

Moreovere, you should open the flightgear simulator and click on: setting_>additional setting and write the following lines in order to open and connect to the correct port of the open server:
--generic=socket,out,10,127.0.0.1,5400,generic_small
--telnet=socket,in,10,127.0.0.1,5402,tcp

Furthermore, you should reside the "generic_small.xml" file in the protocol folder. note that it is important to run the program before entering the simulator in order to enable correct connection flow.
  


# TEAM
NAME: Shani Cattan
ID: 313588386

NAME: Mevaseret David
ID:206835019












