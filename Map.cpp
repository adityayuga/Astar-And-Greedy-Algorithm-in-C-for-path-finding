#include "Map.h"


//vector<City> cityList;

int Map::searchCity(City* city){
    for(int i = 0; i<cityList.size(); i++){
        if(cityList.at(i)->getName()==city->getName())
            return i;
    }
    return -1;
}
void Map::addCity(City* city){
    if(searchCity(city)!=-1){
        cerr << city->getName() <<" is already in the map." << endl;
        return;
    }
    if(cityList.empty()){
        cityList.push_back(city);
    }
    else{
            if(city->getName()>cityList.at(cityList.size()-1)->getName()){
                cityList.push_back(city);
            }
            else if(city->getName()<cityList.at(0)->getName()){
                cityList.insert(cityList.begin(),city);
            }
            else{
                for(int i=0; i<cityList.size()-1;i++){
                    if(city->getName()>cityList.at(i)->getName() && city->getName()<cityList.at(i+1)->getName()){
                        cityList.insert(cityList.begin()+i+1,city);
                    }
                }
            }
    }
    cout << city->getName() << " is added on the map." << endl;
}
void Map::removeCity(City *city){
    int index = searchCity(city);
    if(index==-1){
        cerr << city->getName() <<" is already in the map." << endl;
        return;
    }
    cityList.erase(cityList.begin()+index);
}
City* Map::city(int index){
    if(index>=cityList.size() || index<0){
        cerr << "out of bound." << endl;
        return NULL;
    }
    return cityList.at(index);
}
City* Map::city(string name){
    for(int i = 0; i<cityList.size(); i++){
        if(cityList.at(i)->getName()==name)
            return cityList.at(i);
    }
    cerr << "not found." << endl;
    return NULL;

}
void Map::showCityList(){
    cout << "Showing city list: " << endl;
    for(int i=0; i<cityList.size(); i++){
        cout << setw(3) << left << i <<". ";
        cout << setw(15)<< left << cityList.at(i)->getName() << right;
        cout << " x:" << setw(3) << left << cityList.at(i)->getX();
        cout << " y:" << setw(3) << left << cityList.at(i)->getY();
        cout << endl;
    }
    cout << endl;
}

float Map::distance(string &a, string &b){
    if(a==b){
        return 0;
    }

    City *ca = city(a);
    City *cb = city(b);

    if(ca==NULL || cb==NULL){
        cerr << "Distance search between " << a << " and " << b <<" error." << endl;
        return -1;
    }

    float d = sqrtf(ca->getX()*ca->getX()+ca->getY()*ca->getY());
    return d;
}
