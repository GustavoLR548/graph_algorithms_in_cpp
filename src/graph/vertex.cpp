#include "vertex.hpp"
#include <iostream>

Vertex::Vertex(vertex_value value) {
    this->value = value;
}

void Vertex::set_vertex_value(vertex_value value) {
    this->value = value;
}

int Vertex::get_vertex_value() {
    return this->value;
}

void Vertex::set_vertex_tag(vertex_tag tag) {
    this->tag = tag;
}

int Vertex::get_vertex_tag() {
    return this->tag;
}

void Vertex::print_this_vertex() {
    std::cout << this->value << "";
}
