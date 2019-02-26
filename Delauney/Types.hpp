//
//  GraphicTypes.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 2/17/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef Types_hpp
#define Types_hpp

#define NULL 0


struct Triangle;
struct Node;


struct Vertex3D
{
    bool  operator<=(const Vertex3D& point2);
    
    float x;
    float y;
    float height;
};


struct Vertex2D
{
    Vertex2D& operator=(const Vertex3D& point);
    Vertex2D& operator=(const Vertex2D& point);
    bool      operator==(const Vertex2D& point);
    bool      operator!=(Vertex2D& point);
    
    float x;
    float y;
};


class Edge
{
public:
    Edge(): incidentTriangle1(NULL), incidentTriangle2(NULL){}
    
    bool operator==(Edge& edge);
    bool operator!=(Edge& edge);
    
    Node*    incidentTriangle1;
    Node*    incidentTriangle2;
    
    Vertex2D point1;
    Vertex2D point2;
};

class Triangle
{
public:
    bool edgeInTriangle(Edge&);
    
    bool operator!=(const Triangle& triangle);

    //goes: left, bottom, right; (counterclockwise order)
    Edge     edge[3];
    Vertex2D vertex[3];
    
};


struct Node
{
    Triangle triangle;
    Node*    next;
};

#endif /* Types_hpp */
