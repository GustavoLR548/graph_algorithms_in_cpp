#include "vertex.hpp"
#include <iostream>

Vertex::Vertex(vertex_value value, vertex_tag tag) {
    this->value = value;
    this->tag = tag;
}

void Vertex::set_vertex_value(vertex_value value) {
    this->value = value;
}

int Vertex::get_vertex_value() {
    return this->value;
}

void Vertex::print_this_vertex() {
    std::cout << this->value << "";
}
