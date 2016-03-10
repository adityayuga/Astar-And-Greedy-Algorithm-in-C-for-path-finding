#ifndef ASTAR_H_INCLUDED
#define ASTAR_H_INCLUDED
#include "City.h"
#include "Map.h"

struct AstarNode{
    City* current;
    AstarNode* parent;
    float gx;
    float hx;
};

class Astar{
private:
    AstarNode* _startNode;
    City* _goal;
    vector<AstarNode*> _successor;
    vector<AstarNode*> _frontier;
    vector<City*> _visited;
    string _path ="";
    int _iterasi;
    bool _isGreedy;
    float _cost;


    void cetakFrontier();
    void cetakSuccessor();
    void cetakVisited();

    void emptySuccessor();

    float searchHX(AstarNode*);
    float searchGX(AstarNode*,AstarNode*);
    bool searchFrontier(City*);
    bool searchVisited(City*);
    void searchChild(AstarNode*);
    void sortFrontier();
    string pathConstruction(AstarNode*);
    string run();

public:
    Astar(City* start, City* goal, bool isGreedy);
    void execute();

};

#endif // GREEDY_H_INCLUDED
