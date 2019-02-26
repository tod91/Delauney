//
//  Sorting.cpp
//  PojectDelone
//
//  Created by Todor Ivanov on 5/25/17.
//  Copyright © 2017 Todor Ivanov. All rights reserved.
//

#include <stdlib.h>
#include <algorithm>
#include "Types.hpp"
#include "Sorting.hpp"

static void BottomUpMerge(Vertex3D* A, Vertex3D* B, const unsigned left, const unsigned mid, const unsigned right)
{
    unsigned l = left, r = mid;
    
    for(unsigned k = left; k < right; ++k)
    {
        if(l < mid && (r >= right || A[l] <= A[r]))
        {
            B[k] = A[l++];
        }
        else
        {
            B[k] = A[r++];
        }
    }
}


bool BottomUpMergeSort(Vertex3D* points, const unsigned numOfPoints)
{
    Vertex3D* helperArr = (Vertex3D*) malloc(sizeof(Vertex3D) * numOfPoints);
    if(!helperArr)
    {
        fprintf(stderr, "Error, cannot allocate enough memory for merge sort\n");
        return false;
    }
    
    for(unsigned runWidth = 1; runWidth < numOfPoints; runWidth *= 2)
    {
        for(unsigned i = 0; i < numOfPoints; i += 2 * runWidth)
        {
            BottomUpMerge(points, helperArr, i, std::min(i + runWidth, numOfPoints), std::min(i + 2 * runWidth, numOfPoints));
        }
        memcpy(points, helperArr, sizeof(float) * numOfPoints);
    }
    
    free(helperArr);
    return true;
}
