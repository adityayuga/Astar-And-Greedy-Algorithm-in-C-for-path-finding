#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED
#include "City.h"
#include "Map.h"

struct BFSNode{
    City* current;
    BFSNode* parent;
    float gx;
    //float hx;
};

class BFS{
private:
    BFSNode* _startNode;
    City* _goal;
    vector<BFSNode*> _successor;
    vector<BFSNode*> _frontier;
    vector<City*> _visited;
    string _path ="";
    int _iterasi;
    bool _isGreedy;
    float _cost;


    void cetakFrontier();
    void cetakSuccessor();
    void cetakVisited();

    void emptySuccessor();

    //float searchHX(BFSNode*);
    float searchGX(BFSNode*,BFSNode*);
    bool searchFrontier(City*);
    bool searchVisited(City*);
    void searchChild(BFSNode*);
    void sortFrontier();
    string pathConstruction(BFSNode*);
    string run();

public:
    Astar(City* start, City* goal, bool isGreedy);
    void execute();

};


#endif // BFS_H_INCLUDED
