#ifndef menu_options_hpp
#define menu_options_hpp

#include<iostream>
#include<fstream> 
#include<vector>
#include<string>

#define EXIT_STATUS 0
#define END_OF_CUR_LIST "<end>"

enum Operation{Procced=1,Error=-1,Quit=-2};

class MenuOptions {

    private:
        //Atributes
        std::vector<std::vector<std::string>> texts; //A list, of list of texts
        int current_text_index;

        bool is_valid_choice(short choice);

    public: 
    //Constructor 1: Get all of the menu options in the file inside "path"
        MenuOptions(std::string path = "texts.txt");
        Operation change_current_menu(short user_choice);
        void print_current_menu();
        int get_current_menu_index();
        bool quit_program(short user_choice);
};

#endif