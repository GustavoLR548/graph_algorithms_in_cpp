#include<iostream>
#include<map>
#include<string>
#include<list>

#include"utils/frontend/menu_options.cpp"

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
    menu();
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
