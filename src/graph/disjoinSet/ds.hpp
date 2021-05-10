#ifndef ds_hpp
#define ds_hpp

#include<vector>

typedef struct DisjoinSets {

    private: 
        
        //Group of parent nodes and their ranks
        std::vector<std::pair<int,int>> nodes;

    public: 

        //Start the disjoinSets with a size of 'n'
        DisjoinSets(int n);

        //Find the parent of 'index'
        int find(int index);

        //Merge set x with y
        void merge(int x,int y);

}DisjoinSets;

#endif 