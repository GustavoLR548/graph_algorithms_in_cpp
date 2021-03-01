#include"cell.hpp"

template <typename T>
Cell<T>::Cell() {
    this->left    = nullptr;
    this->right   = nullptr;
    this->up      = nullptr;
    this->down    = nullptr;
}

template <typename T>
T Cell<T>::getElement() {
    return this->element;
}

template <typename T>
void Cell<T>::setElement(T element) {
    this->element = element;
}
