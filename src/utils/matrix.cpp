#include<string>
#include<iostream>

template <typename T>
class Matrix {

    private: 

    //Nested class Cell, to store an element within each point in the array
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
        }

        T getElement() {
            return this->element;
        }

    };

    Cell* first;
    short number_of_columns;
    short number_of_rows;

    public: 

    //Constructor 1: no size specified, creating 3x3 matrix
    Matrix() {
        this->number_of_columns = 3;
        this->number_of_rows    = 3;
        buildMatrix();
    }

    //Constructor 2: creating a NxN matrix
    Matrix(short n) {
        if(n < 3) {
            n = 3;
        }
        else {
            this->number_of_columns = this->number_of_rows = n;
        }

        buildMatrix();
    }

    //Constructor 3: creating a CxR matrix
    Matrix(short c, short r) {

        if( c < 3 || r < 3 ) {
            if( c < 3) {
                c = 3;
            }
            if ( r < 3) {
                r = 3;
            }
        }
        else {
            this->number_of_columns = c;
            this->number_of_rows    = r;
        }

        buildMatrix();
    }

    private: 

    //Creating linked cells to the first cell of the Matrix
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

        //reset the pointer to link to the first cell
        tmp = this->first;

        //Deploy consecutive rows of cells in the Matrix
        for (int i = 0; i < c;i++) {

            //Start the first element 
            Cell* tmp2 = new Cell();
            tmp->down = tmp2;
            tmp2->up  = tmp;

            for(int j = 0; j < r; j++) {
                Cell* tmp3  = new Cell();

                //Linking cells horizontally
                tmp2->right = tmp3;
                tmp3->left  = tmp2;

                //Linking cells vertically
                tmp2->up->right->down = tmp3;
                tmp3->up = tmp2->up->right;

                //Moving the pointer to the right, to continue to create the row
                tmp2 = tmp2->right;
            }

            //After creating a row, go to the next one
            tmp = tmp->down;
        }
    }

    public:

    //Print the Matrix using std::cout
    void print() {
        for(Cell* i = this->first; i != NULL ; i = i->down ) {
            for(Cell* j = i; j != NULL ; j = j->right ) 
                std::cout << std::to_string(j->getElement()) << " " ;
            
            std::cout << "\n" ; //Add spacing in between the columns
        }
    }


};