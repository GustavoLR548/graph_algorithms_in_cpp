#include "graph.hpp"
#include<iostream>
#include<fstream>
#include <array> 
/*
* Implementing the graph class
*  v0.1
*/

    // Start the graph with the 'min' size of Matrix
    Graph::Graph() {

        //Starting the matrix with EMPTY value
        weight default_value = EMPTY;
        this->graph          = new Matrix<weight>(3,default_value);

        this->vertices = 0;
        this->edges    = 0;
    }

    // Start the graph matrix with a set size
    Graph::Graph(counter v) {

        //Starting the matrix with EMPTY value##
        weight default_value = EMPTY;
        this->graph          = new Matrix<weight>(v,default_value);
    
        this->edges    = 0;
        this->vertices = 0;

        for(int i =0 ; i < v; i++) 
            add_vertex();
    }

    Graph::Graph(const char* path) {

        //First step: read the file with the graph vertices
        weight default_value = EMPTY;

        this->edges    = 0;
        this->vertices = 0;

        int num_vertices;
        std::string line;
        std::vector<std::string> adjs; 
        std::ifstream graph_adjs(path);

        //The first line is the number of vertices
        getline(graph_adjs,line);
        num_vertices = std::atoi(line.c_str());
        this->graph  = new Matrix<weight>(num_vertices,default_value);

        for(int i =0 ; i < num_vertices; i++) 
            add_vertex();

        //Read all of the graph adjs
        while(getline(graph_adjs,line)) adjs.push_back(line);
        graph_adjs.close();

        for(counter i = 0; i < adjs.size(); i++) {
            int delimiter_pos= adjs.at(i).find(",");
            
            counter start = std::atoi(adjs.at(i).substr(0,delimiter_pos).c_str());
            counter end   = std::atoi(adjs.at(i).substr(delimiter_pos+1,adjs.at(i).size()).c_str());

            add_edge(start,end);
        }
    } 

    Graph::~Graph() {
        free(this->graph);
    }

    //Return the number of vertices the graph has
    counter Graph::vertices_num() {
        return this->vertices;
    }

    //Return the number of edges the graph has
    counter Graph::edges_num() {
        return this->edges;
    }

    counter Graph::add_vertex() {
        counter result = -1;
        counter pos    = this->vertices;

       // std::cout<< "[Graph]: verifying if there is enough space..." << std::endl;

        if(!has_space()) 
            this->graph->expand_matrix(1,EMPTY);

       //std::cout<< "[Graph]: Ok! Inserting on matriz..." << std::endl;

        this->graph->insert(pos,pos,pos);
        result = this->vertices;
        this->vertices++;

       // std::cout<< "[Graph]: Inserting in adj list..." << std::endl;

        std::vector<counter> it;
        this->adj.push_back(it);
        
       // std::cout<< "[Graph]: Adding vertex process is finished with success!" << std::endl;

        return result;
    }

    bool Graph::has_space(){
        bool result = false;

        if(this->vertices < this->graph->get_number_of_columns()) {
            result = true;
        }

        return result;
    }

    // Add a new Edge to the graph and return if the operation was a success
    bool Graph::add_edge(counter first, counter last, weight value) {
        bool result = false;

        if(has_vertex(first) && has_vertex(last)) {
            this->graph->insert(value,first,last);
            this->graph->insert(value,last,first);
            this->edges++;

            add_adj(first, last);
            add_adj(last, first);
            result = true;
        }

        return result;
    }

    bool Graph::has_vertex(counter id){
        bool result = false;

        if(id < this->graph->get_number_of_columns()) 
            result = true;

        return result;
    }

    void Graph::add_adj(counter first, counter last) {
        auto it = &this->adj.at(first);
        it->push_back(last);
    }

    void Graph::print() {

        std::cout << "Number of vertices: " << this->vertices << std::endl;
        std::cout << "Number of edges   : " << this->edges << std::endl; 

        std::cout << "\nLists of Adjs:\n"; 

        for(int i = 0; i < adj.size(); i++) {
            std::vector<counter> it = this->adj.at(i);
            std::vector<counter> :: iterator v;
            std::cout << "v[" << i << "] :"; 
            for(v = it.begin(); v != it.end() ;++v) {
                std::cout << ' ' << *v; 
            }
            std::cout << '\n'; 
        } 

        std::cout << "\nMatriz of Adjs:\n"; 

        this->graph->print(); 
    }

    counter Graph::depth_first_search(counter first) {
        std::vector<counter> colour;
        counter n_cycles = 0; //store the number of cycles in the graph

        //Mark all vertices as : "NOT VISITED"
        for(int i = 0; i < this->vertices; i++)
            colour.push_back(WHITE);

        //Loop through all vertices in the graph
        for(counter i = 0; i < this->vertices; i++) 

            //if the curr vertex hasn't been visited
            if(colour.at(i) == WHITE) 

                //visiting current vertex
                //Obs: I'm sending a pointer to the 
                //memory address of the 'colour' std::vector
                //so that all recursive calls to 'visit_vertex'
                //can update when a vertex is visited
                n_cycles += visit_vertex(i,-1,&colour);

        return n_cycles;
    }

    counter Graph::visit_vertex (counter index,counter parent, std::vector<counter>* colour) {

        int n_cycles = 0;

        //If a vertex has already been fully visited
        if(colour->at(index) == RED) 
            return 0;

        //If the vertex hasn't been completely visited
        //it means it has found a cycle
        if(colour->at(index) == YELLOW) {
            n_cycles++;
            return n_cycles;
        }

        //Mark current vertex as visited
        colour->at(index) = YELLOW;

        //Start adj std::vector
        std::vector<counter> curr_vertex_adj = this->adj.at(index); 

        //Loop through adj std::vector of the curr_vertex
        for(int i = 0 ; i < curr_vertex_adj.size(); i++) {

            if(curr_vertex_adj.at(i) == parent) 
                continue;
            
            n_cycles += visit_vertex(curr_vertex_adj.at(i),index,colour);
        }
        
        //Mark vertex as completed
        colour->at(index) = RED;

        return n_cycles;
    }