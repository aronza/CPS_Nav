//
// Created by Arda on 5/8/2018.
//

#ifndef PX4_ROUTE_H
#define PX4_ROUTE_H

//#include <geometry_msgs/PoseStamped.h>



class Route {
private:
    float foci;
    float verti;
    /*
    struct Point{
        float x;
        float y;
        float z;
    };
     std::queue<Point> wpoints;
     */
    queue <geometry_msgs::PoseStamped> wpoints;


public:
    //Class Constructor
    Route();

    //Alternative Constructor;
    Route(float fociIn, float vertiIn);

    //Shows the next point on route.
    geometry_msgs::PoseStamped nextPoint();

    //Pop the front value
    void pop();

    //Prints the route
    void print();

    //Returns isEmpty value of queue
    bool isEmpty();

};
#endif //PX4_ROUTE_H
