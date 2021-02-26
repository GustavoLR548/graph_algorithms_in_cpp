#include<iostream>
#include<string>
#include "utils/matrix.cpp"

int main() {
    /*
    Matrix<std::string>* m = new Matrix<std::string>();
    m->print();
    m->insert("teste",0,1);
    m->print();
    std::cout << m->get(0,1) << std::endl;
    */
    Matrix<int>* n = new Matrix<int>();
    n->print();
    n->insert(2,1,0);
    n->insert(5,0,0);
    n->insert(3,0,1);
    n->insert(1,1,1);
    n->print();

    n->expand_matrix(2);
    n->print();

    return 0;
}