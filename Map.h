#ifndef MAP_H
#define MAP_H

#include "City.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>

class Map{
private:
    vector<City*> cityList;
    int searchCity(City* city);
public:
    void addCity(City* city);
    void removeCity(City *city);
    City* city(int index);
    City* city(string name);
    void showCityList();
    float distance(string&, string&);
};


#endif // MAP_H
