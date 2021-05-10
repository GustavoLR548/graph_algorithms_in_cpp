#include "ds.hpp"

    DisjoinSets::DisjoinSets(int n) {
        
        for(int i = 0; i < n ; i++) 
            this->nodes.push_back({0,i});
        
    }

    int DisjoinSets::find(int index) {

        if(index != this->nodes.at(index).second)

            this->nodes.at(index).second = find(this->nodes.at(index).second);
        
        return this->nodes.at(index).second;
    }

    void DisjoinSets::merge(int x,int y) {

        x = find(x);
        y = find(y);

        if(this->nodes.at(x).first > this->nodes.at(y).first)
            this->nodes.at(y).second = x;
        else 
            this->nodes.at(x).second = y;

        if(this->nodes.at(x).first == this->nodes.at(y).first)
            this->nodes.at(y).first++;
            
    }