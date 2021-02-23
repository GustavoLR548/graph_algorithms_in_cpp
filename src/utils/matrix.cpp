#include<string>
#include<iostream>

template <typename T>
class Matrix {

    private: 

    class Cell {

        private:

        T element;

        public:

        Cell* left;
        Cell* right;
        Cell* up;
        Cell* down;

        Cell() {
            this->left    = NULL;
            this->right   = NULL;
            this->up      = NULL;
            this->down    = NULL;
            this->element = nullptr;
        }

        T getElement() {
            return this->element;
        }

    };

    Cell* first;
    short number_of_columns;
    short number_of_rows;

    public: 

    Matrix() {
        this->number_of_columns = 3;
        this->number_of_rows    = 3;
        buildMatrix();
    }

    Matrix(short n) {
        this->number_of_columns = this->number_of_rows = n;
        buildMatrix();
    }

    Matrix(short c, short r) {
        this->number_of_columns = c;
        this->number_of_rows    = r;
        buildMatrix();
    }

    private: 

    void buildMatrix() {

        //Creating the first element
        this->first = new Cell();
        Cell* tmp = this->first;

        // -1 because the first element was already created
        short r = this->number_of_rows    - 1;
        short c = this->number_of_columns - 1;

        //Generate the first row of cells in the Matrix
        for (int i = 0; i < r; i++) { 
            Cell* tmp2 = new Cell();

            tmp->right = tmp2;
            tmp2->left = tmp;

            tmp = tmp->right;
        }

        //reset the pointer to the first cell
        tmp = this->first;

        //Deploy consecutive rows of cells in the Matrix
        for (int i = 0; i < c;i++) {

            //Start the first element
            Cell* tmp2 = new Cell();
            tmp->down = tmp2;
            tmp2->up  = tmp;

            for(int j = 0; j < r; j++) {
                Cell* tmp3 = new Cell();
                tmp2->right = tmp3;
                tmp3->left = tmp2;
                tmp2->up->right->down = tmp3;
                tmp3->up = tmp2->up->right;

                tmp2 = tmp2->right;
            }
            tmp = tmp->down;
        }
    }

    public:

    void print() {
        for(Cell* i = this->first; i != NULL ; i = i->down ) {
            for(Cell* j = i; j != NULL ; j = j->right ) 
                std::cout << std::to_string(j->getElement()) << " " ;
            
            std::cout << "\n" ; //Add spacing in between the columns
        }
     }
};