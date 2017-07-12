# NetRecursion
This was a project from my Introduction to Computing III (C++) course. The assignment was to find a path between two nodes using a list of their adjacencies. 


This program was set up using a Header file, .cpp file, and a Driver. 
I used a struct called "node" which stored the elements position, an array of its adjacent nodes, the number of nodes adjacent(used to traverse the adjacencies) and a boolean "visited".

The class contained functions to help traverse the network to find any path. There were two main functions used to make this project work.  One built the network by reading the nodes and their adjacencies from a file. The other was a recursive algorithm to find a path.
The buildNetwork function has a node array in its parameter, which it uses to initialize the network from the text file. 
After the network is initialized, the findPath function takes an integer for its current position and the integer that it is searching for within its parameters. It sets the current node's visited boolean to true, then deos checks and recursive calls to find whether or not there is a path between the two nodes. If a path is found, the nodes' positions are printed out to have the path in reverse. 

The driver adds user input to get a start node and end node. It uses the functions to build the network and then begin the recursive calls to determine if a path can be found. It then asks the user for more start and end nodes, and if a valid range is given a reset method is called to get the network back into working shape. 

This project was more fun than I thought it would be. After using the given network textfile, I created my own to further test its capabilities. So long as the files are set up with the same format, you can have as large of a network as you wish and still be able to find a path between nodes if any exist.
