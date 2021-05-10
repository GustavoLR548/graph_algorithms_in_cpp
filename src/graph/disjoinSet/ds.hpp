#ifndef ds_hpp
#define ds_hpp

#include<vector>

typedef struct DisjoinSets {

    private: 
        
        std::vector<std::pair<int,int>> nodes;

    public: 

        DisjoinSets(int n);

        int find(int index);

        void merge(int x,int y);

}DisjoinSets;

#endif 