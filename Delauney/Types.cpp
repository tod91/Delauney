//
//  GraphicTypes.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/17/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include "Types.hpp"

bool Vertex3D::operator<=(const Vertex3D& point2)
{
    if(x <= point2.x)
        return true;
    else
        return false;
}


Vertex2D& Vertex2D::operator=(const Vertex3D& point)
{
    x = point.x;
    y = point.y;
    return *this;
}

Vertex2D& Vertex2D::operator=(const Vertex2D& point)
{
    x = point.x;
    y = point.y;
    return *this;
}

bool Vertex2D::operator==(const Vertex2D& point)
{
    if(x == point.x && y == point.y)
        return true;
    return false;
}

bool Vertex2D::operator!=(Vertex2D& point)
{
    if(x != point.x && y != point.y)
        return true;
    return false;
}


bool Edge::operator==(Edge& edge)
{
    if((point1 == edge.point1 && point2 == edge.point2) || (point2 == edge.point1 && point1 == edge.point2))
        return true;
    
    return false;
}
 

bool Edge::operator!=(Edge& edge)
{
    if(point1 != edge.point1 && point2 != edge.point2)
        if(point1 != edge.point2 && point2 != edge. point1)
            return true;
    
    return false;
}


bool Triangle::edgeInTriangle(Edge& arg)
{
    if(arg == edge[0] || arg == edge[1] || arg == edge[2])
        return true;
    
    return false;
}
