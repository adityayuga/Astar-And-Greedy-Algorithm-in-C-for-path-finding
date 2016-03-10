#include "City.h"
#include "cmath"
using namespace std;


City::City(string name,float x,float y){
    this->city_name=name;
    this->xCoordinate=x;
    this->yCoordinate=y;
}

int City::searchWaypoint(City *city){ //done
    for(int i=0; i<waypointList.size(); i++){
            if(waypointList.at(i)==city)
                return i;
    }
    return -1;
}

float City::searchWaypointWithDistance(City *city){//done
    int index=searchWaypoint(city);
    if (index==-1){
        return -1.00;
    }
    else{
        return waypointDistance.at(index);
    }
}


vector<City*> City::getWaypointList(){//done
    return waypointList;
}

vector<float> City::getWaypointDistance(){//done
    return waypointDistance;
}

string City::getName(){//done
    return city_name;
}
float City::getX(){//done
    return xCoordinate;
}
float City::getY(){//done
    return yCoordinate;
}
void City::addWaypoint(City* city){//done
    if(this==city){
        cerr << this->getName() << " cannot add waypoint to itself." << endl;
        return;
    }
    float citiesDistanceX = this->getX()-city->getX();
    float citiesDistanceY = this->getY()-city->getY();
    float citiesDistance= citiesDistanceX*citiesDistanceX + citiesDistanceY*citiesDistanceY;
    addWaypointWithDistance(city, sqrtf(citiesDistance));
}
void City::addWaypointWithDistance(City* city, float distance){//done
    if(city==NULL){
        cerr << this->getName() << " cannot add. City pointer is NULL." << endl;
        return;
    }
    if(this==city){
        cerr << this->getName() << " cannot add waypoint to itself." << endl;
        return;
    }
    if(waypointList.size()==0){
        waypointList.push_back(city);
        waypointDistance.push_back(distance);
        cout << this->getName() <<" is linked to "<< city->getName() << endl;
    }
    else{
            if(searchWaypoint(city)!=-1){
                cerr << this->getName() <<" is already have a waypoint to " << city->getName() << endl;
                return;
            }
            if(city->getName()>waypointList.at(waypointList.size()-1)->getName()){//done
                waypointList.insert(waypointList.end(),city);
                waypointDistance.insert(waypointDistance.end(),distance);
            }
            else if(city->getName()<waypointList.at(0)->getName()){
                waypointList.insert(waypointList.begin(),city);
                waypointDistance.insert(waypointDistance.begin(),distance);
            }
            else{
                for(int i=0; i<waypointList.size()-1;i++){
                    if(city->getName()>waypointList.at(i)->getName() && city->getName()<waypointList.at(i+1)->getName()){
                        waypointList.insert(waypointList.begin()+i+1,city);
                        waypointDistance.insert(waypointDistance.begin()+i+1,distance);
                    }
                }
            }
            cout << this->getName() <<" is linked to "<< city->getName() << endl;
    }
}
void City::removeWaypoint(City* city){//done
    if(city==NULL){
        cerr << this->getName() << " cannot remove. City pointer is NULL." << endl;
        return;
    }
    if(waypointList.empty()){
        cerr << "This city doesn't have any waypoint" << endl;
        return;
    }
    int index = searchWaypoint(city);
    if(index!=-1){
        waypointList.erase(waypointList.begin()+index);
        waypointDistance.erase(waypointDistance.begin()+index);
        cout << this->getName() << " unlinked " << city->getName() << endl;
    }
    else{
        cerr << "Waypoint does not exists." << endl;
    }
}

void City::showWaypointList(){//done
    for(int i=0; i<waypointList.size(); i++){
            cout << waypointList.at(i)->getName() << " " << waypointDistance.at(i) << endl;
    }
}

float City::to(City *city){
    return waypointDistance.at(searchWaypoint(city));
}

float City::distanceTo(City *city){
    float citiesDistanceX = this->getX()-city->getX();
    float citiesDistanceY = this->getY()-city->getY();
    return sqrtf(citiesDistanceX*citiesDistanceX+citiesDistanceY*citiesDistanceY);
}
