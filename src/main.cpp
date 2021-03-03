#include<iostream>
#include<map>
#include<string>
#include<vector>

#include"utils/frontend/menu_options.cpp"
#include"utils/matrix/matrix.cpp"
#include"graph/graph.cpp"
#include"graph/vertex.cpp"

//Defining a method to clear the terminal while in the program
#ifdef linux
#define clear() std::system("clear")
#else
#define clear() system("CLS")
#endif

//functions
void menu();

int main() {
    
    clear();
    //menu();

    Graph* teste = new Graph(0,0,true,false);
    Vertex* a = new Vertex(22);
    Vertex* b = new Vertex(3);
    Vertex* c = new Vertex(111);

    teste->add_vertex(a);
    teste->add_vertex(b);
    teste->add_vertex(c);

    teste->add_edge(b,a,365);

    teste->print_vertices();
    teste->print_edges();

    return 0;
}

void menu() {

    MenuOptions* m = new MenuOptions();
    Operation operation;
    short choice    = 0;

    do {
        
        m->print_current_menu();
        std::cout << "\n" << "->";

        std::cin >> choice;
        clear();

        operation = m->interpret_user_input(choice);

        if(operation == Operation::Error) {
            std::cout << "This option is invalid, or do not exist!\nPlease, try again!" << std::endl;

        } else if(operation != Operation::Quit && operation != Operation::Procced) {
            std::cout << operation << "aqui?" << std::endl;
        }

    } while(operation != Operation::Quit);

    std::cout << "Thanks for using the program!\nHave a nice day :)" << std::endl;
}
