#include<string.h>
#include<fstream>
#include"graph/graph.cpp"


//Defining a method to clear the terminal while in the program
#ifdef linux
#define clear() std::system("clear")
#else
#define clear() system("CLS")
#endif

void test(int argc, char *argv[]);

int main(int argc, char *argv[]) {

    clear();

    if(argc <= 2) {
        std::cerr << "[ERROR]: Not enough paramaters!\n"<< std::endl;
        return 0;
    }

    if(strcmp(argv[1],"test") == 0) {
        test(argc,argv);
        return 0;
    }

    int n = std::atoi(argv[1]);
    
    std::ofstream results("results.txt");

    if(strstr(argv[2],".txt") == NULL) {
        std::cerr << "[ERROR]: \"" << argv[2] << "\" is not a text file path \n"<< std::endl;
        return 0;
    }

    clock_t sum;

    for (int j = 0 ; j < n ; j++ ) {
        Graph* teste = new Graph(argv[2]);

        teste->print();
        
        clock_t time = clock();
        if(strcmp(argv[3],"kruskal") == 0) 
            teste->kruskal();
        else 
            teste->depth_first_search(0);
        
        time = clock() - time;

        sum += time;
    }

    double total_time = ((double)sum)/((CLOCKS_PER_SEC/1000));

    results << "path: " << argv[2] << std::endl;
    results << "Total time: " << total_time << "s" << std::endl;
    results << "Average time : " << total_time/n << "s" << std::endl;

    return 0;
}

//Function only used for outside testing 
void test(int argc, char *argv[]) {

    Graph* teste = new Graph(argv[2]);
    teste->print();
    counter n = teste->kruskal();
    std::cout << "\nnum_cycles = " << n << std::endl;
}

