#ifndef vertex_hpp
#define vertex_hpp

class Vertex{

    public:

        // Constructor
        Vertex(int value, int tag);

        // get and set functions in vertex
        void set_vertex_value();
        int get_vertex_value();
        void print_this_vertex();
    };

#endif