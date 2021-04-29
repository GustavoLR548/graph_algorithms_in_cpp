#include<string.h>
#include<fstream>
#include"graph/graph.cpp"


//Defining a method to clear the terminal while in the program
#ifdef linux
#define clear() std::system("clear")
#else
#define clear() system("CLS")
#endif

int main(int argc, char *argv[]) {

    clear();

    if(argc <= 2) {
        std::cerr << "[ERROR]: Not enough paramaters!\n"<< std::endl;
        return 0;
    }

    int n = std::atoi(argv[1]);
    
    std::ofstream results("results.txt");

    for(int i = 2; i < argc; i++) {

        if(strstr(argv[i],".txt") == NULL) {
            std::cerr << "[ERROR]: \"" << argv[i] << "\" is not a text file path \n"<< std::endl;
            return 0;
        }

        clock_t sum;

        for (int j = 0 ; j < n ; j++ ) {
            Graph* teste = new Graph(argv[i]);

            teste->print();
            
            clock_t time = clock();
            teste->depth_first_search(0);
            time = clock() - time;

            sum += time;
        }
        double total_time = ((double)sum)/((CLOCKS_PER_SEC/1000));

        results << "Graph[" << i - 2 << "]" << std::endl;
        results << "path: " << argv[i] << std::endl;
        results << "Total time: " << total_time << "s" << std::endl;
        results << "Average time : " << total_time/n << "s" << std::endl;
    }
    
    return 0;
}

