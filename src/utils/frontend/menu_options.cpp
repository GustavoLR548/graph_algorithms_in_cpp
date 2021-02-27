#include<iostream>
#include<fstream> 
#include<list>
#include<string>

//A organizer for menu options 
//V 0.1
class MenuOptions {

    //Atributes
    private:
        std::list<std::list<std::string>> texts; //A list, of list of texts
        int current_texts_index;

    public: 

    //Constructor 1: 
    MenuOptions(std::string path = "texts.txt") {

        current_texts_index = 0;

        //File pointer to the contents inside "path"
        std::ifstream all_text(path);

        //Current line at the file
        std::string curr_line;

        getline (all_text, curr_line); //jump the first line
        std::list<std::string> tmp;    //temporary list for storing lines read in the file

        while(getline (all_text, curr_line)) { //while the file still have lines to be read
            if(curr_line.size() <= 1) { //Signal for the program to stop 

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

    //Printing current menu of the list
    void print_current_menu() {
        
        std::list<std::list<std::string>> :: iterator current_text_list;
        current_text_list = texts.begin();

        std::advance(current_text_list, current_texts_index);

        std::list <std::string> :: iterator text;
        for(text = current_text_list->begin(); text != current_text_list->end() ;++text) {
            std::cout << '\n' << *text; 
        }
        std::cout << '\n'; 
    }
};