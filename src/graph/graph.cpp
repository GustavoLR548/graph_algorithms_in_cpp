#include "graph.hpp"
#include "disjoinSet/ds.cpp"

#include<iostream>
#include<fstream>
#include <array> 
#include<bits/stdc++.h>
/*
* Implementing the graph class
*  v0.1
*/

    // Start the graph with the 'min' size of Matrix
    Graph::Graph() {

        //Starting the matrix with EMPTY value
        weight default_value = EMPTY;

        this->vertices = 0;
        this->edges    = 0;
    }

    // Start the graph matrix with a set size
    Graph::Graph(counter v) {

        //Starting the matrix with EMPTY value##
        weight default_value = EMPTY;
        
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

        for(int i =0 ; i < num_vertices; i++) 
            add_vertex();

        //Read all of the graph adjs
        while(getline(graph_adjs,line)) adjs.push_back(line);
        graph_adjs.close();

        for(counter i = 0; i < adjs.size(); i++) {

            if(adjs.at(i).size() == 0) 
                continue;
            
            int delimiter_pos= adjs.at(i).find(",");
            int delimiter_pos2= adjs.at(i).find(",",delimiter_pos+1);
            
            counter start = std::atoi(adjs.at(i).substr(0,delimiter_pos).c_str());
            counter end   = std::atoi(adjs.at(i).substr(delimiter_pos+1,delimiter_pos2).c_str());
            weight w      = std::atoi(adjs.at(i).substr(delimiter_pos2+1,adjs.at(i).size()).c_str());

            add_edge(start,end,w);
        }
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

       //std::cout<< "[Graph]: Ok! Inserting on matriz..." << std::endl;

        result = this->vertices;
        this->vertices++;

       // std::cout<< "[Graph]: Inserting in adj list..." << std::endl;

        std::vector<counter> it;
        this->adj.push_back(it);
        
       // std::cout<< "[Graph]: Adding vertex process is finished with success!" << std::endl;

        return result;
    }

    // Add a new Edge to the graph and return if the operation was a success
    bool Graph::add_edge(counter first, counter last, weight value) {
        bool result = false;

        if(has_vertex(first) && has_vertex(last)) {
            this->edges++;

            this->edges_weights.push_back({value,{first,last}});
            add_adj(first, last);
            add_adj(last, first);
            result = true;
        }

        return result;
    }

    bool Graph::has_vertex(counter id){
        bool result = false;

        if(id < this->adj.size()) 
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
            std::cout << "v[" << i << "] :"; 
            for(auto j = this->adj.at(i).begin(); j != this->adj.at(i).end() ;++j) {
                std::cout << ' ' << *j; 
            }
            std::cout << '\n'; 
        } 

        std::cout << "\nLists of edges:\n"; 

        for(auto i = edges_weights.begin(); i != edges_weights.end(); i++) 
            std::cout<< "edges: " << i->second.first << "," << i->second.second << "\t weight: " << i->first << std::endl;
        

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

    counter Graph::kruskal() {

        std::sort(edges_weights.begin(), edges_weights.end());
        counter n_cycles = 0;

        DisjoinSets ds(this->vertices);
    
        for (auto it=edges_weights.begin(); it!=edges_weights.end(); it++) {
            int source      = it->second.first;
            int destination = it->second.second;
    
            int set_u = ds.find(source);
            int set_v = ds.find(destination);

            if (set_u != set_v) 
                ds.merge(set_u, set_v);
            else 
                n_cycles++;

        }


        return n_cycles;
    }