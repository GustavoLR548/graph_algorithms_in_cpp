#include<iostream>
#include<string>
#include "utils/matrix.cpp"

int main() {

    Matrix<std::string>* m = new Matrix<std::string>();
    m->print();
    m->insert("teste",0,1);
    m->print();
    std::cout << m->get(0,1) << std::endl;

    Matrix<int>* n = new Matrix<int>();
    n->print();
    n->insert(2,0,1);
    n->print();
    std::cout << n->get(0,1) << std::endl;
}