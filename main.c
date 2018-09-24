//
//  main.c
//  closestPair
//
//  Created by fast-algo on 22/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <time.h>

#include "geoDefs.h"
#include "funcTimer.h"
#include "mergeSort.h"
#include "naive-geo.h"
#include "fast-geo.h"

#define NUM_POINTS 10000
#define MIN_X -180.0
#define MAX_X 180.0
#define MIN_Y -85.0
#define MAX_Y 85.0

point *generateRandomPoints(point *thePoints, int numberOfPoints);

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    
    point *thePoints = malloc(NUM_POINTS * sizeof(point));
    generateRandomPoints(thePoints, NUM_POINTS);
    
    startFuncTimer(0);
    geoPair * minDistNaive = naive(thePoints, NUM_POINTS);
    stopFuncTimer(0);

    startFuncTimer(1);
    geoPair *minDist = closestPair(thePoints, NUM_POINTS);
    stopFuncTimer(1);
    
    printf("Closest Naive Points were: \n");
    printf("%d and %d\n", minDistNaive->pid1, minDistNaive->pid2);
    
    printf("Closest Fast Points were: \n");
    printf("%d and %d\n", minDist->pid1, minDist->pid2);
    
    if (minDist->distance == minDistNaive->distance)
        printf("Success: Naive Algo and Fast-Algo MATCH (MinDist = %lf)\n", minDist->distance);
    else printf("Error: Naive Algo(%lf) and Fast-Algo(%lf) gave different results.\n", minDistNaive->distance, minDist->distance);
    
    printf("Time Taken Naive Algorithm = %lf\n", getFuncTime(0));
    
    int preProcPortion = (int)(100.0 * getFuncTime(2) / getFuncTime(1));
    int searchPortion = (int)(100.0 * getFuncTime(3) / getFuncTime(1));
    
    printf("Time Taken Fast-Algo = %lf (%d%% pre-proc, %d%% search)\n", getFuncTime(1), preProcPortion, searchPortion);
    printf("Fast-Algo = %d times faster than brute force.\n", (int)(getFuncTime(0) / getFuncTime(1)));

    free(thePoints);
    return 0;
}

point *generateRandomPoints(point *thePoints, int numberOfPoints)
{
    memset(thePoints, 0, numberOfPoints * sizeof(point));
    for (int i = 0; i < numberOfPoints; i++)
    {
        thePoints[i].lat = MIN_X + 2 * (double)rand()/(double)(RAND_MAX / MAX_X);
        thePoints[i].lon = MIN_Y + 2 * (double)rand()/(double)(RAND_MAX / MAX_Y);
        thePoints[i].pid = i;
        //printPoint(thePoints[i]);
    }
    
    return thePoints;
}
