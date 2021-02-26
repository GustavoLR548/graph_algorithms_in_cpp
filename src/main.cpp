#include<iostream>
#include<map>
#include<string>
#include<list>

#ifdef linux
#define clear() std::system("clear")
#else
#define clear() system("CLS")
#endif

void menu();
void printMenu(std::list<std::string> texts);

std::map<int,std::list<std::string>> menu_text{
    {0,{"1 - Unweighted targeted graph","2 - Unweighted untargeted graph","3 - Weighted untargeted graph","4 - Weighted targeted graph","0 - exit"}}
};
int main() {
    
    clear();
    menu();
    return 0;
}

void menu() {

    short menuIndex = 0;
    short choice    = 0;

    do {
        printMenu(menu_text[menuIndex]);
        std::cout << "\n" << "->";
        std::cin >> choice;
        clear();

    } while(choice != 0);
}

void printMenu(std::list<std::string> texts) {
    std::list <std::string> :: iterator text; 
    for(text = texts.begin(); text != texts.end(); ++text) 
        std::cout << '\n' << *text; 
    std::cout << '\n'; 
}
