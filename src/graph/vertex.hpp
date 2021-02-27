#ifndef vertex_hpp
#define vertex_hpp

using vertex_value = int32_t;
using vertex_tag =  int32_t;

class Vertex {
    vertex_value value;
    vertex_tag tag;

    public:

        // Construtor
        Vertex(vertex_value value, vertex_tag tag);

        // Functions get and set 
        void set_vertex_value(vertex_value value);
        int get_vertex_value();

        // Print value of the current vertex
        void print_this_vertex();

};

#endif