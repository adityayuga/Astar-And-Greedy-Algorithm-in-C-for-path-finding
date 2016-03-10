#ifndef CITY
#define CITY
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

class City{
private:
    string city_name;
    float xCoordinate;
    float yCoordinate;
    vector<City*> waypointList;
    vector<float> waypointDistance;
public:
    City(string, float, float);
    string getName();
    float getX();
    float getY();
    vector<City*> getWaypointList();
    vector<float> getWaypointDistance();
    int searchWaypoint(City *city);
    float searchWaypointWithDistance(City *city);
    float to(City *city);
    float distanceTo(City *city);
    void showWaypointList();
    void addWaypoint(City* city);
    void addWaypointWithDistance(City* city, float distance);
    void removeWaypoint(City* city);
};

#endif // CITY
