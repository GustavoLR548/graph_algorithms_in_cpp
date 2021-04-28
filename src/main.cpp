#include<iostream>
#include<fstream>
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

    //First step: read the file with the graph vertices
    int num_vertices;
    std::string line;
    std::vector<std::string> adjs; 
    std::ifstream graph_adjs("graph.txt");

    //The first line is the number of vertices
    getline(graph_adjs,line);
    num_vertices = std::atoi(line.c_str());

    //Read all of the graph adjs
    while(getline(graph_adjs,line)) adjs.push_back(line);
    graph_adjs.close();
    
    clear();

    Graph* teste = new Graph(num_vertices);

    for(counter i = 0; i < adjs.size(); i++) {
        int delimiter_pos= adjs.at(i).find(",");
        
        counter start = std::atoi(adjs.at(i).substr(0,delimiter_pos).c_str());
        counter end   = std::atoi(adjs.at(i).substr(delimiter_pos+1,adjs.at(i).size()).c_str());

        teste->add_edge(start,end);
    }

    teste->print();
    
    clock_t tempo = clock();
    counter n_cycles = teste->depth_first_search(0);
    tempo = clock() - tempo;
    std::cout << "Número de ciclos: " << n_cycles << std::endl;
    std::cout << "Tempo total: " <<((double)tempo)/((CLOCKS_PER_SEC/1000)) << std::endl;
    
    return 0;
}

