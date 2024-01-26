# Ceng315
Selected computer algorithms: sorting, searching, string processing and graph algorithms. Algorithm design and analysis techniques. Time and computational complexities of algorithms. Introduction to NP-completeness, parallelization of algorithms, linear and dynamic programming.

# THE2
Your librarian friend is planning to digitize the catalog of the local library and needs your help. He gives a list of strings to be shown in the online catalog and asks you to sort them in a dictionary-like order. You decide to help him by writing a program that uses the Radix Sort algorithm to sort the given strings.

**Problem**

In this exam, I am asked to sort the given string array arr with Radix Sort in ascending or descending order depending on the boolean variable ascending and return the number of iterations done in the loops of the Counting Sort algorithm (I need to use Counting Sort as a subroutine in the Radix Sort). Size is the number of elements in the string array.

# THE4
You decided to start a new life on a deserted island with your friend Isabelle. Your goal is to fill the island with buildings that have predetermined plot dimensions. For this, you need to divide the land into rectangular plots with the given dimensions, leaving the least possible m^2 of unusable land. 
Isabelle tells you the dimensions of the island. She also tells you the dimensions of the rectangular plots that you can divide the land into. Any piece of land (the whole island or the already divided plots of the land) can be divided either horizontally or vertically into two rectangular plots with integer dimensions, dividing completely through that land. This is the only way to divide the land, and divided plots cannot be joined together. Since the buildings to be placed in these plots cannot be rotated, the dimensions of the plots also cannot be rotated. You can create zero or more plots with each given dimension. A piece of land is unusable if it is not of any of the desired dimensions after all dividing operations are completed. 

**Problem**
In this exam, I am asked to calculate the most efficient way of dividing the land given the dimensions of the land X and Y, and the dimensions of the plots in a 2D array of booleans, then return the m^2 of unusable land by completing the divide_land() function defined.

**X, Y:** dimensions X x Y of the total rectangular land of the island.  
**possible_plots:** a 2D array of booleans, where each value stands for the existence of a possible plot with the indices of
the array cell as dimensions (for example, if possible_plot[2][3] == true, then 2 x 3 is a possible plot dimension that can be used)  
**to return:** m^2 of unusable land, meaning the land that does not belong to any plot after all the dividing operations.

# THE5

Your friend is writing a new compiled programming language called Smurf. He believes that it will be one of the best programming languages ever. He has almost finished implementing the compiler but is struggling with one last issue.
In Smurf, programmers can write their codes into multiple files and can import other files or libraries. Before the compiler compiles a file, the files that the file to be compiled depends on must be already compiled. Therefore, the compiler should know the compilation order of files. Also, for some programs, compilation may not be possible because of cyclic dependencies (an example of cyclic dependency, two programs may be trying to import each other). In the case of cyclic dependency, the compiler should warn the user by giving the sets of files that cause the cyclic dependency. You offer to help your friend by writing a function to help this compiling process.

**Problem**

In this exam, I am expected to implement the run function. If the program I am trying to compile is compilable, I should assign true to the isCompilable variable, and assign the order of compilation shown by the file IDs to the compileOrder variable. If it is not compilable due to cyclic dependencies, I should assign the IDs of cyclic dependent files to the cyclicDependencies variable, a vector including vectors for each cyclic-dependent file group.

**dependencyMatrix:** Square matrix with dimensions FxF, where F is the number of files. If dependencyMatrix[i][j] is 1, then file j is dependent on file i. Otherwise, it is 0.  
**isCompilable:** If compilation is possible, you should assign true, otherwise false.  
**compileOrder:** If compilation is possible, you should assign compilation order to this variable.    
**cyclicDependencies:** If compilation is not possible, you should find cyclic-dependent file groups and update this vector to include the file groups by their IDs. Cyclic-dependent file group is a group of files  
that each file in the group is directly or indirectly dependent on every other file in the group.

# THE6
You, an AI hater, recently learned that an AI model discovered new molecule structures equivalent to 800 years' worth of knowledge[1][2], and you are extremely annoyed by this news. While on an anger rant, you claim that you can write a basic program to find new optimal structures by yourself. Your chemist friends dare you to do so. They also offer to check the validity of your program, if you also write them another program that helps with their project.  

You come up with an idea to find new molecule structures: If we have a graph where each vertex is an atom and each edge is the energy of the bond between the two atoms, maybe a new possible molecule structure can be found by selecting the edges with lowest energy bonds, without creating a cycle. Your chemist friends tell you this is most definitely a wrong approach, but you insist on trying.

Additionally, your chemist friends need a program to find the longest chain in a given molecule, so you agree to also write that program for them.

Problem

This exam consists of two parts, graded independently.

**> PART1** 

I need to complete the function find_stucture() which returns the total bond energy of the found molecule:

**bond_energies:** a bidirectional graph represented by an adjacency list, where the vertices (v) are atoms, edges are bonds,  
and weights (w) of edges are the energies of the bonds. In other words, an entry in the adjacency list for vertex v0 is <v1, w>, which represents an edge between v0-v1 with a weight of w.  
**lowest_energy_structure:** the found molecule structure represented as an adjacency list, with the same format as bond_energies. You are expected to find the structure and assign it to this argument.  
There is at most one bond with two atoms with only one weight value, i.e. there is at most one undirected edge between any two vertices in the graph, meaning at most one weight value for each pair. Undirectionality is shown in the adjacency list by adding two mirror entries for each edge for ease of implementation.  
Vertices are represented as integers starting from 0, and the maximum number of vertices in the graph is 1000.    
Weights are represented as integers starting from 1, and the maximum weight value is 100.  
**return value is the total bond energy of the lowest_energy_structure.**

**> PART2**

I need to complete the function find_longest_chain() which returns the number of the atoms in the longest chain of the given molecule.

**molecule_structure:** a graph with the same representation and limits as the bond_energies and lowest_energy_structure arguments of PART 1. Additionally, it is guaranteed that the structure is a connected, acyclic, undirected graph, with all edges having the same weight (i.e. weights are not important). Undirectionality is shown in the adjacency list by adding two mirror entries for each edge for ease of implementation.  
**chain:** a vector of integers, where each integer maps to a vertex ID in the found longest chain. The vector should follow the order of the chain. The validity of the chain will be checked by the tester to see if consecutive vertices in the vector have edges between them or not.  
**return value** is the total number of atoms in the longest chain of the molecule. The longest chain is defined as the count of vertices on the path between the two farthest vertices in the graph, including the start and end vertices.  


