//
//  TriangulationContainer.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 6/10/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#include <new>
#include <math.h>
#include <stdio.h>
#include "TriangulationContainer.hpp"


TriangulationContainer::TriangulationContainer()
: head(NULL)
, alpha(0)
, beta (0)
, gamma(0)
{
}


TriangulationContainer::~TriangulationContainer()
{
    deleteTriangulation(head);
}


bool TriangulationContainer::AddInitialPoint(const Vertex2D& p)
{
    bool errCode = false;
    _GetBarycentricCoords(head->triangle, p);
    
    if(_IsInsideTriangle())
        errCode = _InitialThreeWaySplit(p);
    
    return errCode;
}


bool TriangulationContainer::AddPoint(const Vertex2D& p)
{
    Node* iterator = head;
    
    while(iterator->next != NULL)
    {
        _GetBarycentricCoords(iterator->next->triangle, p);
        
        if(_IsInsideTriangle())
        {
            threeWaySplit(iterator, p);
            break;
        }
        
        if(_LiesOnEdge())
        {
            fourWaySplit(iterator, p);
            break;
        }
        
        iterator = iterator->next;
    }
    
    return true;
}


bool TriangulationContainer::threeWaySplit(Node* parent, const Vertex2D& p)
{
    
    Node* first  = new Node;
    Node* second = new Node;
    Node* third  = new Node;
    
    // ne si chistish pametta i si opravi proverkata
    // ako edna allocaciq failne pametta shte e nekva schupena i kato i viknesh delete shte stane mazalo
    if(!first || !second || !third)
    {
        fprintf(stderr, "Error, cannot allocate memory for a Node\n");
        return false;
    }
    
    _CreateNewTriangle(first->triangle, parent->next->triangle.vertex[0], parent->next->triangle.vertex[1], p);
    _CreateNewTriangle(second->triangle, parent->next->triangle.vertex[1], parent->next->triangle.vertex[2], p);
    _CreateNewTriangle(third->triangle, parent->next->triangle.vertex[2], parent->next->triangle.vertex[0], p);
    
    
    Node* toBeDeleted = parent->next;
    
    parent->next = first;
    first->next  = second;
    second->next = third;
    third->next  = toBeDeleted->next;
    
    delete toBeDeleted;
    
    _SetEdges(first);
    _SetEdges(second);
    _SetEdges(third);
    _SetEdges(parent);

    return true;
}


bool TriangulationContainer::fourWaySplit(Node* parent, const Vertex2D& p)
{
    _TwoWaySplit(parent, p);
    
    
    Node* incidentTriangle = _GetIncidentTriangle(parent->next, parent->triangle.edge[0]);
    
    if(incidentTriangle != NULL)
        _TwoWaySplit(incidentTriangle, p);
    
    return true;
}

// Care for stack overflow
void TriangulationContainer::deleteTriangulation(Node* node)
{
    if(node != NULL)
        deleteTriangulation(node->next);
    
    delete node;
}
