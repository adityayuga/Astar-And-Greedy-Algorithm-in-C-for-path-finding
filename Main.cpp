#include<iostream>
#include<string>
#include<cstdlib>
#include "City.h"
#include "Map.h"
#include "Astar.h"

using namespace std;

int main(){
    bool greedy=false;
    Map Romania;
    City *newCity;
    cout << "INITIALIZING" << endl << "============" << endl;
    cout << "ADDING CITIES TO MAP:" << endl;
    newCity = new City("Oradea",2.7,6.5);
    Romania.addCity(newCity);
    newCity = new City("Zerind",2.2,5.7);
    Romania.addCity(newCity);
    newCity = new City("Arad",0.9,5);
    Romania.addCity(newCity);
    newCity = new City("Timisoara",1,3.5);
    Romania.addCity(newCity);
    newCity = new City("Lugoj",2.2,2.9);
    Romania.addCity(newCity);
    newCity = new City("Mehadia",2.3,2.2);
    Romania.addCity(newCity);
    newCity = new City("Dobreta",2.2,1.4);
    Romania.addCity(newCity);
    newCity = new City("Sibiu",3,4.2);
    Romania.addCity(newCity);
    newCity = new City("Rimnicu Vilcea",3.3,3.6);
    Romania.addCity(newCity);
    newCity = new City("Craiova",3.8,1.1);
    Romania.addCity(newCity);
    newCity = new City("Fagaras",4.7,4.2);
    Romania.addCity(newCity);
    newCity = new City("Pitesti",4.9,2.8);
    Romania.addCity(newCity);
    newCity = new City("Bucharest",6.2,2);
    Romania.addCity(newCity);
    newCity = new City("Giurgiu",5.8,0.9);
    Romania.addCity(newCity);
    newCity = new City("Neamt",6.3,5.9);
    Romania.addCity(newCity);
    newCity = new City("Iasl",7.6,5.3);
    Romania.addCity(newCity);
    newCity = new City("Vaslui",8.1,4.2);
    Romania.addCity(newCity);
    newCity = new City("Urziceni",7.2,2.3);
    Romania.addCity(newCity);
    newCity = new City("Hirsova",8.6,2.4);
    Romania.addCity(newCity);
    newCity = new City("Eforie",9,1.3);
    Romania.addCity(newCity);
    cout << "ADDING FINISHED" << endl << endl;

    Romania.showCityList();
    Romania.city("Oradea")->addWaypoint(Romania.city("Zerind"));
    Romania.city("Oradea")->addWaypoint(Romania.city("Sibiu"));
    Romania.city("Zerind")->addWaypoint(Romania.city("Arad"));
    Romania.city("Arad")->addWaypoint(Romania.city("Zerind"));
    Romania.city("Arad")->addWaypoint(Romania.city("Sibiu"));
    Romania.city("Arad")->addWaypoint(Romania.city("Timisoara"));
    Romania.city("Timisoara")->addWaypoint(Romania.city("Arad"));
    Romania.city("Timisoara")->addWaypoint(Romania.city("Lugoj"));
    Romania.city("Lugoj")->addWaypoint(Romania.city("Timisoara"));
    Romania.city("Lugoj")->addWaypoint(Romania.city("Mehadia"));
    Romania.city("Mehadia")->addWaypoint(Romania.city("Lugoj"));
    Romania.city("Mehadia")->addWaypoint(Romania.city("Dobreta"));
    Romania.city("Dobreta")->addWaypoint(Romania.city("Mehadia"));
    Romania.city("Dobreta")->addWaypoint(Romania.city("Craiova"));
    Romania.city("Craiova")->addWaypoint(Romania.city("Dobreta"));
    Romania.city("Craiova")->addWaypoint(Romania.city("Rimnicu Vilcea"));
    Romania.city("Craiova")->addWaypoint(Romania.city("Pitesti"));
    Romania.city("Rimnicu Vilcea")->addWaypoint(Romania.city("Pitesti"));
    Romania.city("Rimnicu Vilcea")->addWaypoint(Romania.city("Craiova"));
    Romania.city("Rimnicu Vilcea")->addWaypoint(Romania.city("Sibiu"));
    Romania.city("Pitesti")->addWaypoint(Romania.city("Rimnicu Vilcea"));
    Romania.city("Pitesti")->addWaypoint(Romania.city("Craiova"));
    Romania.city("Pitesti")->addWaypoint(Romania.city("Bucharest"));
    Romania.city("Sibiu")->addWaypoint(Romania.city("Oradea"));
    Romania.city("Sibiu")->addWaypoint(Romania.city("Rimnicu Vilcea"));
    Romania.city("Sibiu")->addWaypoint(Romania.city("Fagaras"));
    Romania.city("Fagaras")->addWaypoint(Romania.city("Sibiu"));
    Romania.city("Fagaras")->addWaypoint(Romania.city("Bucharest"));
    Romania.city("Bucharest")->addWaypoint(Romania.city("Fagaras"));
    Romania.city("Bucharest")->addWaypoint(Romania.city("Pitesti"));
    Romania.city("Bucharest")->addWaypoint(Romania.city("Giurgiu"));
    Romania.city("Bucharest")->addWaypoint(Romania.city("Urziceni"));
    Romania.city("Urziceni")->addWaypoint(Romania.city("Vaslui"));
    Romania.city("Urziceni")->addWaypoint(Romania.city("Bucharest"));
    Romania.city("Urziceni")->addWaypoint(Romania.city("Hirsova"));
    Romania.city("Hirsova")->addWaypoint(Romania.city("Urziceni"));
    Romania.city("Hirsova")->addWaypoint(Romania.city("Eforie"));
    Romania.city("Vaslui")->addWaypoint(Romania.city("Urziceni"));
    Romania.city("Vaslui")->addWaypoint(Romania.city("Iasl"));
    Romania.city("Iasl")->addWaypoint(Romania.city("Vaslui"));
    Romania.city("Iasl")->addWaypoint(Romania.city("Neamt"));
    Romania.city("Neamt")->addWaypoint(Romania.city("Iasl"));
    cout << "=======================" << endl << "INITIALIZATION FINISHED" << endl;

    while(1){
        system("pause");
        system("cls");

        cout << "====== A* AND GREEDY BEST FIRST SEARCH FOR ROMANIAN MAP ======" << endl;
        cout << "Beta Version 1.2" << endl;
        cout << "Created by:" << endl;
        cout << "Alan Darmasaputra (71130012)" << endl;
        cout << "Aditya Yuga Pradhana (71130013)" << endl << endl;

        cout << "Untuk mengganti mode greedy:";
        cout << endl;
        cout << "Ketik 'greedy [on/off]' greedy is ";
        if(greedy)
            cout << "on";
        else
            cout << "off";
        cout << endl << endl;
        cout << "Untuk mencari rute:";
        cout << endl;
        cout << "Ketik [KOTAASAL][spasi][KOTATUJUAN]";
        cout << endl << endl;
        cout << "Untuk melihat daftar kota:";
        cout << endl;
        cout << "Ketik 'show map'";
        cout << endl << endl;
        cout << "Untuk keluar dari program:";
        cout << endl;
        cout << "Ketik 'exit'";
        cout << endl << endl;

        string s1,s2;
        cin >> s1;
        if(s1 == "exit"){
            break;
        }
        cin >> s2;

        if(s1=="greedy" && s2 == "on"){
            greedy=true;
        }
        else if(s1=="greedy" && s2 == "off")
        {
            greedy=false;
        }
        else if(s1=="show" && s2=="map"){
            Romania.showCityList();
            cout << endl;
        }
        else if(Romania.city(s1)!=NULL && Romania.city(s2)!=NULL){
            Astar *AstarSearch= new Astar(Romania.city(s1),Romania.city(s2),greedy);
            AstarSearch->execute();
        }
        else{
            cout << "input error" << endl;
        }
        cout << endl;
    }
    return 0;

}
