#ifndef vertex_hpp
#define vertex_hpp

class Vertex{

    public:

    // Construtor
    Vertex(int value, int tag);

    // Funções get e set em vértice
    void set_vertex_value();
    int get_vertex_value();
    void print_this_vertex();
};

#endif