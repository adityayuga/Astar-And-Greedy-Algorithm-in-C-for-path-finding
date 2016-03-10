#include "Astar.h"
#include <cstdlib>

/*struct AstarNode
    City* current;
    AstarNode* parent;
    float gx;
    float hx;
*/

/* Astar
    AstarNode* _startNode;
    City* _goal;
    vector<AstarNode*> _successor;
    vector<AstarNode*> _frontier;
    vector<City*> _visited;
    string _path ="";
*/

Astar::Astar(City* start, City* aGoal, bool isGreedy){
    this->_goal = aGoal;
    this->_startNode = new AstarNode();
    _startNode->current = start;
    _startNode->parent = NULL;
    _startNode->gx = 0;
    _startNode->hx = searchHX(_startNode);
    _iterasi = 0;
    _isGreedy = isGreedy;
    _cost = 0;
}

void Astar:: cetakFrontier()
{
    cout << "Frontier: " << endl;

    //jika frontier kosong
    if(_frontier.empty())
    {
        cout << "-" << endl << endl;
        return;
    }

    for(int i=0;i<_frontier.size();i++)
    {
        cout << _frontier[i]->current->getName() << " (h(x)=" << _frontier[i]->hx;
        if(!_isGreedy)
            cout << " ,g(x)=" << _frontier[i]->gx << " , total = " << _frontier[i]->hx + _frontier[i]->gx;
        cout <<")" << endl;
    }
    cout << endl;
}

void Astar:: cetakSuccessor()
{
    cout << "Successor: " << endl;

    //jika successor kosong
    if(_successor.empty())
    {
        cout << "-" << endl << endl;
        return;
    }

    for(int i=0;i<_successor.size();i++)
    {
        cout << _successor[i]->current->getName() << " (h(x)=" << _successor[i]->hx;
        if(!_isGreedy)
            cout << " ,g(x)=" << _successor[i]->gx << " , total = " << _successor[i]->hx + _successor[i]->gx;
        cout <<")" << endl;
    }
    cout << endl;
}

void Astar:: cetakVisited()
{
    cout << "Visited: " << endl;

    //jika visited kosong
    if(_visited.empty())
    {
        cout << "-" << endl << endl;
        cout << "================================================================" << endl << endl;
        return;
    }

    for(int i=0;i<_visited.size();i++)
    {
        cout << _visited[i]->getName() << endl;
    }
    cout << endl;
    cout << "================================================================" << endl << endl;
}

void Astar::emptySuccessor()
{
    while(!_successor.empty())
    {
        _successor.pop_back();
    }
}

//jarak anak ke goal
float Astar:: searchHX(AstarNode* asal)
{
    return asal->current->distanceTo(_goal);
}

//gx dari nilai gx yang sudah sudah ditambah gx anak
float Astar:: searchGX(AstarNode* anak,AstarNode* bapak)
{
    return (bapak->gx) + (bapak->current->to(anak->current));
}

//jika ditemukan, return true
bool Astar:: searchFrontier(City* city)
{
    for(int i=0;i<_frontier.size();i++)
    {
        if(_frontier[i]->current == city)
        {
            return true;
        }
    }
}

//jika ditemukan, return true
bool Astar:: searchVisited(City* city)
{
    for(int i=0;i<_visited.size();i++)
    {
        if(_visited[i] == city)
        {
            return true;
        }
    }
}

//cari anak, masukkan ke vector anak
void Astar:: searchChild(AstarNode* node)
{
    int ukuran = (node->current->getWaypointList()).size();
    for(int i=0;i<ukuran;i++)
    {
        //cek apakah calon child sudah ada di visited maupun frontier atau belum
        if((searchFrontier((node->current->getWaypointList())[i])))
        {
            continue;
        }
        else if((searchVisited((node->current->getWaypointList())[i])))
        {
            continue;
        }
        else{
            //buat objek astarnode untuk anak baru
            AstarNode* newChild = new AstarNode();
            newChild->parent = node;
            newChild->current = (node->current->getWaypointList())[i];

            //cari hx dan gx
            newChild->gx = searchGX(newChild, node);
            newChild->hx = searchHX(newChild);

            /*
            if(_isGreedy)
                newChild->gx=0;
            */

            //masukkan ke daftar anak dari node
            this->_successor.push_back(newChild);

        }
    }
}

void Astar::sortFrontier(){
    for(int i=0; i<_frontier.size()-1; i++){
        for(int j=i+1; j<_frontier.size(); j++){
            if(!_isGreedy){
                if((_frontier.at(i)->hx+_frontier.at(i)->gx)>(_frontier.at(j)->hx+_frontier.at(j)->gx)){
                    AstarNode *temp=_frontier.at(i);
                    _frontier.at(i)=_frontier.at(j);
                    _frontier.at(j)=temp;
                }
            }
            else{
                if((_frontier.at(i)->hx) > (_frontier.at(j)->hx)){
                    AstarNode *temp=_frontier.at(i);
                    _frontier.at(i)=_frontier.at(j);
                    _frontier.at(j)=temp;
                }
            }
        }
    }
}

string Astar::pathConstruction(AstarNode* currentNode)
{
    //selama belum ketemu start city
    if(currentNode->parent == NULL)
    {
        return (currentNode->current)->getName();
    }
    else{
        return pathConstruction(currentNode->parent) + " -> " + (currentNode->current)->getName();
    }
}

//progress
//funsgi run dimulai dari iterasi ke dua
string Astar:: run()
{
    cout << "Iterasi ke-" << _iterasi << " :" <<endl;

    //masukkan frontier ke visited
    _visited.push_back(_frontier[0]->current);
    _frontier.erase(_frontier.begin());

    //masukkan successor ke frontier
    //cek apakah punya successor atau tidak
    if(!_successor.empty())
    {
        for(int i=0;i<_successor.size();i++)
        {
            _frontier.push_back(_successor[i]);
        }

        //frontier di sorting
        sortFrontier();
        //hapus daftar successor
        emptySuccessor();
    }

    if(_frontier.empty())
    {
        //cetak frontier,successor,visited
        cetakFrontier();
        cetakSuccessor();
        cetakVisited();
        return "Path Not Found";
    }
    else if(_frontier[0]->current==_goal)
    {
        //cetak frontier,successor,visited
        cetakFrontier();
        cetakSuccessor();
        cetakVisited();

        return "Path : " + pathConstruction(_frontier[0]);
    }
    else
    {
        //cari successor (anak)
        searchChild(_frontier[0]);

        //cetak frontier,successor,visited
        cetakFrontier();
        cetakSuccessor();
        cetakVisited();

        _iterasi++;
        //panggil fungsi run kembali ke iterasi berikutnya
        return run();
    }
}
void Astar::execute()
{
    cout << endl << "Iterasi ke-" << _iterasi << " :" <<endl;

    if(_startNode->current==_goal){
        cout << "Start node equals to goal node" << endl;
        return;
    }

    _frontier.push_back(this->_startNode);
    searchChild(this->_startNode);

    //cetak frontier,successor,visited
    cetakFrontier();
    cetakSuccessor();
    cetakVisited();

    _iterasi++;

    cout << run() << endl;
    cout << "Total cost: " << _frontier[0]->gx << endl;
}

