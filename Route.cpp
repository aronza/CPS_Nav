//
// Created by Arda on 5/8/2018.
//
#include <geometry_msgs/PoseStamped.h>
#include <queue>
#include <iostream>
#include "Route.h"
#include <math.h>
#define FLIGHT_ALTITUDE 0.5f
#define SCAN_RADIUS 50.0

//Class Constructor
Route::Route():foci(0),verti(0){}

//Alternative Constructor;
Route::Route(float fociIn, float vertiIn):foci(fociIn),verti(vertiIn){
    geometry_msgs::PoseStamped pose;
    pose.pose.position.z = FLIGHT_ALTITUDE;

    double k = 50;//Directly proportional to amount of circles in spiral
    double s = 5;//Invertly proportional to the distance between each point

    double dt = 1;
    double t = 0;
    while(t<k){
        pose.pose.position.x = (foci*t*cos(t))/k;
        pose.pose.position.y = (verti*t*sin(t))/k;
        wpoints.push(pose);

        t+= M_PI/(dt*s);
        dt = t/M_PI + 1;
    }
}

geometry_msgs::PoseStamped Route::nextPoint(){
    if(!wpoints.isEmpty()){
        geometry_msgs::PoseStamped nWayPoint = wpoints.front();
        return nWayPoint;
    }else{
        geometry_msgs::PoseStamped pose;
        std::cout<<"No more Waypoints left"<<std::endl;
        return pose;
    }
}

void Route::pop(){
    if(!wpoints.isEmpty()) {
        wpoints.pop();
    }else{
        std::cout<<"No more Waypoints left"<<std::endl;
    }
}

void Route::print(){
    if(!wpoints.isEmpty()){
        for(size_t i =0;i<4;i++) {
            float x = wpoints.front().pose.position.x;
            float y = wpoints.front().pose.position.y;
            float z = wpoints.front().pose.position.z;
            std::cout << "Waypoint "<<(i+1)<<": ("<<x<<" , "<<y<<" , "<<z<<")"<<std::endl;
            wpoints.pop();
        }
    }
}

bool Route::isEmpty(){
    return wpoints.isEmpty();
}


