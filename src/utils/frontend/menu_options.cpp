#include"menu_options.hpp"

    //Constructor 1: Get all of the menu options in the file inside "path"
    MenuOptions::MenuOptions(std::string path) {

        current_text_index = 0;

        //File pointer to the contents inside "path"
        std::ifstream all_text(path);

        //Current line at the file
        std::string curr_line;

        std::vector<std::string> tmp;    //temporary list for storing lines read in the file

        while(getline (all_text, curr_line)) { //while the file still have lines to be read
            if(curr_line.compare(END_OF_CUR_LIST) == 0) { //Signal for the program to stop 
                //... and add the current list 
                texts.push_back(tmp);
                tmp.clear();
                continue;
            }

            tmp.push_back(curr_line);
        }

        //Add final element to the list.
        texts.push_back(tmp);
        all_text.close(); //close file
    }

    int MenuOptions::get_current_menu_index() {
        return this->current_text_index;
    }

    //Printing current menu of the list
    void MenuOptions::print_current_menu() {
        
        std::vector<std::string> current_text_list = texts.at(current_text_index);

        //Printing the entire content in the list of strings
        std::vector <std::string> :: iterator text;
        for(text = current_text_list.begin(); text != current_text_list.end() ;++text) {
            std::cout << '\n' << *text; 
        }
        std::cout << '\n'; 
    }

    Operation MenuOptions::change_current_menu(short user_choice) {

        Operation result;

        if(!is_valid_choice(user_choice)) {
            result = Operation::Error;

        } else {

            if(user_choice == EXIT_STATUS) {
                if(quit_program(user_choice)) {
                    result = Operation::Quit;

                } else {
                    result = Operation::Procced;
                    current_text_index = user_choice;
                }
            } else {

                if(current_text_index == 0) {
                    result = Operation::Procced;
                    current_text_index = user_choice;

                } else {
                    result = Operation((current_text_index*10)+user_choice);
                }
            }
        }
        
        return result;
    }

    bool MenuOptions::is_valid_choice(short user_choice) {
        return (user_choice < texts.at(current_text_index).size() && user_choice >= 0 && user_choice < texts.size() ) ;
    }

    bool MenuOptions::quit_program(short user_choice) {
        return(user_choice == EXIT_STATUS && current_text_index == 0);
    }