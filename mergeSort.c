//
//  mergeSort.c
//  MergeSort
//
//  Created by fast-algo on 9/18/18.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "mergeSort.h"

// Merge Sort code modified slightly to handle the GPS point type instead of sorting integers.
// Also, the code can sort by X coordinate or Y coordinate.

void splitX(point *theData, int theLen);
void mergeX(point *leftData, int leftLen, point *rightData, int rightLen);

void splitY(point *theData, int theLen);
void mergeY(point *leftData, int leftLen, point *rightData, int rightLen);

point *temp = NULL;

void mergeSort(point *coords, int numberOfPoints, int sortAxis)
{
    temp = malloc(numberOfPoints * sizeof(point));
    memset(temp, 0, numberOfPoints * sizeof(point));

    if (sortAxis == lat)
        splitX(coords, numberOfPoints);
    else if (sortAxis == lon)
        splitY(coords, numberOfPoints);

    free(temp);
}

void splitX(point *theData, int theLen)
{
    if (theLen == 1)
        return;
    
    point *leftData = theData;
    int leftLen = theLen / 2;
    point *rightData = &leftData[leftLen];
    int rightLen = theLen - leftLen;
    
    splitX(leftData, leftLen);
    splitX(rightData, rightLen);
    mergeX(leftData, leftLen, rightData, rightLen);
}

void mergeX(point *leftData, int leftLen, point *rightData, int rightLen)
{
    int i = 0, j = 0, k = 0;
    int totLen = leftLen + rightLen;

    while ( (i < leftLen) && (j < rightLen) )
    {
        if (leftData[i].lat <= rightData[j].lat)
            memcpy(&temp[k++], &leftData[i++], sizeof(point));
        else if (rightData[j].lat <= leftData[i].lat)
            memcpy(&temp[k++], &rightData[j++], sizeof(point));
    }
    
    memcpy(&temp[k], &leftData[i], (leftLen - i) * sizeof(point));
    memcpy(&temp[k], &rightData[j], (rightLen - j) * sizeof(point));
    
    memcpy(leftData, temp, totLen * sizeof(point));
}

void splitY(point *theData, int theLen)
{
    if (theLen == 1)
        return;
    
    point *leftData = theData;
    int leftLen = theLen / 2;
    point *rightData = &leftData[leftLen];
    int rightLen = theLen - leftLen;
    
    splitY(leftData, leftLen);
    splitY(rightData, rightLen);
    mergeY(leftData, leftLen, rightData, rightLen);
}

void mergeY(point *leftData, int leftLen, point *rightData, int rightLen)
{
    int i = 0, j = 0, k = 0;
    int totLen = leftLen + rightLen;
    
    while ( (i < leftLen) && (j < rightLen) )
    {
        if (leftData[i].lon <= rightData[j].lon)
            memcpy(&temp[k++], &leftData[i++], sizeof(point));
        else if (rightData[j].lon <= leftData[i].lon)
            memcpy(&temp[k++], &rightData[j++], sizeof(point));
    }
    
    memcpy(&temp[k], &leftData[i], (leftLen - i) * sizeof(point));
    memcpy(&temp[k], &rightData[j], (rightLen - j) * sizeof(point));
    
    memcpy(leftData, temp, totLen * sizeof(point));
}
