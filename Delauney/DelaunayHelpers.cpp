//
//  DelaunayHelpers.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/25/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//
#include <stdlib.h>
#include "Delaunay.hpp"


bool Delaunay::GetFileInput(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    
    if(!file)
    {
        fprintf(stderr, "Error, cannot open file %s\n", fileName);
        return false;
    }
    
    if(fscanf(file, "%u", &numOfPoints) != 1)
    {
        fprintf(stderr, "Error, fscanf fail.\n");
        fclose(file);
        return false;
    }
    
    points = (Vertex3D*) malloc (sizeof(Vertex3D) * numOfPoints);
    if(!points)
    {
        fprintf(stderr, "Error, cannot allocate memory\n");
        return false;
    }
    
    for(int i = 0; i < numOfPoints; ++i)
    {
        if(fscanf(file, "%f %f %f", &points[i].x, &points[i].y, &points[i].height) != 3)
        {
            fprintf(stderr, "Warning, unsuccessful read of points at index [%d] from file %s\n",i ,fileName);
        }
    }
    
    fclose(file);
    return true;
}


bool Delaunay::SplitPointsArray()
{
    heights = (float*) malloc(sizeof(float) * numOfPoints);
    if(!heights)
    {
        fprintf(stderr, "Error, cannot allocate memory for the heights.\n");
        return false;
    }
    
    // allocating 2 more points for the outermost triangle
    coords = (Vertex2D*) malloc(sizeof(Vertex2D) * (numOfPoints + 2));
    if(!coords)
    {
        fprintf(stderr, "Error, cannot allocate memory for the coords array.\n");
        free(heights);
        return false;
    }
    
    //TODO make a check for matching points
    for (size_t i = 0; i < numOfPoints; ++i)
    {
        coords[i] = points[i];
        heights[i] = points[i].height;
    }
    
    free(points);
    points = NULL;
    
    return true;
}
