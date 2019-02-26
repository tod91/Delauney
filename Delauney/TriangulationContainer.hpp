//
//  TriangulationContainer.hpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/10/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#ifndef TriangulationContainer_hpp
#define TriangulationContainer_hpp

//#include <stdio.h>
#include "Types.hpp"


class TriangulationContainer
{
public:
    
    TriangulationContainer();
    ~TriangulationContainer();
    
    bool  AddInitialPoint(const Vertex2D& point);
    bool  AddPoint(const Vertex2D& point);
    
    Node* head;
    
private:// Helper Methods
    void  _CreateNewTriangle(Triangle& triangle, const Vertex2D& p1, const Vertex2D& p2, const Vertex2D& p3);
    void  _GetBarycentricCoords(const Triangle&, const Vertex2D& p);
    bool  _IsInsideTriangle();
    bool  _LiesOnEdge();
    bool  _InitialThreeWaySplit(const Vertex2D& p);
    bool  _TwoWaySplit(Node* parentNode, const Vertex2D& p);
    void  _SetIncidentTriangle(Node* first, Node* second, Edge& edge);
    void  _FindInsidentTriangle(Edge& edge);
    void  _SetEdges(Node* first);
    Node* _GetIncidentTriangle(const Node* node, Edge& edge);
    
private:
    bool  threeWaySplit(Node* node, const Vertex2D& p);
    bool  fourWaySplit(Node* node, const Vertex2D& p);
    void  deleteTriangulation(Node* node);
    //void setIncidentTriangle(Node* parent, Node* first, Node* second, Node* third) ;
    
    float alpha;
    float beta;
    float gamma;
};
#endif /* TriangulationContainer_hpp */
