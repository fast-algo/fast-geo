//
//  naive-geo.c
//  Naive Geo
//
//  Created by fast-algo on 22/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>

#include "naive-geo.h"

geoPair * naive(point *thePoints, int numberOfPoints)
{
    geoPair *closestPair = malloc(sizeof(geoPair));
    memset(closestPair, 0, sizeof(geoPair));
    closestPair->distance = MAXFLOAT;

    for (int i = 0; i < numberOfPoints - 1; i++)
    {
        for (int j = i+1; j < numberOfPoints; j++)
        {
            double dist = GET_GEO_DIST(thePoints[i], thePoints[j]);
            if (dist < closestPair->distance)
            {
                closestPair->distance = dist;
                closestPair->pid1 = thePoints[i].pid;
                closestPair->pid2 = thePoints[j].pid;
            }
        }
    }
    return closestPair;
}
