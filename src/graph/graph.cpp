#include "graph.hpp"
#include<iostream>
#include <bits/stdc++.h>
#include <array> 
/*
* Implementing the graph class
*  v0.1
*/

    // Start the graph with the 'min' size of Matrix
    Graph::Graph() {

        //Starting the matrix with EMPTY value
        weight default_value = EMPTY;
        this->graph          = new Matrix<weight>(default_value);

        this->vertices = 0;
        this->edges    = 0;
    }

    // Start the graph matrix with a set size
    Graph::Graph(counter v) {

        //Starting the matrix with EMPTY value
        weight default_value = EMPTY;
        this->graph          = new Matrix<weight>(default_value);
        
        this->vertices = 0;
        this->edges    = 0;
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

        has_space();

        this->graph->insert(pos,pos,pos);
        result = this->vertices;
        this->vertices++;

        std::vector<counter> it;
        this->adj.push_back(it);
        
        return result;
    }

    bool Graph::has_space(){
        bool result = false;

        if(this->vertices == this->graph->get_number_of_columns()) {
            this->graph->expand_matrix(1,EMPTY);
            result = true;
        }

        return result;
    }

    // Add a new Edge to the graph and return if the operation was a success
    bool Graph::add_edge(counter first, counter last, weight value) {
        bool result = false;

        if(search_vertex(first) && search_vertex(last)) {
            this->graph->insert(value,first,last);
            this->graph->insert(value,last,first);
            result = true;
            this->edges++;

            add_adj(first, last);
            add_adj(last, first);
        }

        return result;
    }

    // Checks if the vertex exist
    bool Graph::search_vertex(counter id) {
        bool resp = false;

        if (this->graph->get(id,id) != EMPTY) 
            resp = true;
        
        return resp;
    }

    void Graph::add_adj(counter first, counter last) {
        auto it = this->adj.at(first);
        it.push_back(last);

        std::replace(this->adj.begin(), this->adj.end(), this->adj.at(first), it);
    }

    void Graph::print() {

        std::cout << "Number of vertices: " << this->vertices << std::endl;
        std::cout << "Number of edges   : " << this->edges << std::endl; 

        std::cout << "\nAdj:\n"; 

        for(int i = 0; i < adj.size(); i++) {
            std::vector<counter> it = this->adj.at(i);
            std::vector<counter> :: iterator v;
            std::cout << "v[" << i << "] :"; 
            for(v = it.begin(); v != it.end() ;++v) {
                std::cout << ' ' << *v; 
            }
            std::cout << '\n'; 
        }
        std::cout << '\n'; 

        this->graph->print(); 
    }

    bool Graph::depth_first_search(counter first) {
        std::vector<counter> colour;

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
                visit_vertex(i,&colour);

        return true;
    }

    void Graph::visit_vertex (counter index, std::vector<counter>* colour) {
        //Mark current vertex as visited
        colour->at(index) = YELLOW;

        //Start adj std::vector
        std::vector<counter> curr_vertex_adj = this->adj.at(index); 

        //Loop through adj std::vector of the curr_vertex
        for(auto i = curr_vertex_adj.begin() ; i != curr_vertex_adj.end(); i++) 

            //if adj vertex hasn't been visited
            if(colour->at(*i) == WHITE)

                //recursive call to 'visit_vertex'
                visit_vertex(colour->at(*i),colour);
        
        //Mark vertex as completed
        colour->at(index) = RED;
    }

    bool Graph::breadth_first_search() {
        std::vector<counter> colour;

        //Mark all vertices as : "NOT VISITED"
        for(int i = 0; i < this->vertices; i++)
            colour.push_back(WHITE);

        //Start the queue with the first vertice of the graph
        std::vector<counter> queue;
        queue.push_back(0);

        //While the queue is not empty
        while(queue.size() > 0) {

            //Remove the first element of the queue 
            //and store it in a variable
            counter curr_vert = *queue.begin();
            queue.erase(queue.begin());

            //If the element is not visited
            if(colour.at(curr_vert) != WHITE) {

                //Mark as visited
                colour.at(curr_vert) = YELLOW;

                //Start adj std::vector
                std::vector<counter> curr_vertex_adj = this->adj.at(curr_vert); 

                //Loop through adj std::vector of the curr_vertex
                for(auto i = curr_vertex_adj.begin() ; i != curr_vertex_adj.end(); i++) 

                    //if adj vertex hasn't been visited
                    if(colour.at(*i) == WHITE)
                        //mark to be visited in the next iterations of the loop
                        queue.push_back(*i);

                //mark the curr_vertex as completed
                colour.at(curr_vert) = RED;
            }
        }

        return true;
    }