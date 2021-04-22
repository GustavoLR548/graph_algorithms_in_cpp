#include<iostream>
#include<map>
#include<string>
#include<vector>

#include"graph/graph.cpp"


//Defining a method to clear the terminal while in the program
#ifdef linux
#define clear() std::system("clear")
#else
#define clear() system("CLS")
#endif

int main() {
    
    clear();
    //menu();

    Graph* teste = new Graph(10);

    teste->add_edge(0,1);
    teste->add_edge(0,2);
    teste->add_edge(1,4);
    teste->add_edge(1,2);
    teste->add_edge(1,3);
    teste->add_edge(3,5);
    teste->add_edge(5,6);
    teste->add_edge(5,7);
    teste->add_edge(5,8);
    teste->add_edge(7,8);
    teste->add_edge(8,9);

    teste->print();

    teste->breadth_first_search();
    return 0;
}

