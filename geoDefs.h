//
//  geoDefs.h
//  GeoDefs
//
//  Created by fast-algo on 16/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#ifndef geoDefs_h
#define geoDefs_h

#include <stdio.h>

#define R 6372.8
#define TO_RAD (3.1415926536 / 180)

// Choose either standard (x,y) plane distance calculation
// or GPS coordinate distance calculation
//
//#define GET_GEO_DIST(p1,p2) getPlaneDistance(p1,p2)
#define GET_GEO_DIST(p1,p2) getHaversineDistance(p1,p2)
//

enum axis
{
    lat = 1,
    lon = 2
};

typedef struct
{
    double lat;
    double lon;
    int pid;
} point;

typedef struct
{
    int pid1;
    int pid2;
    double distance;
} geoPair;

void initGeoPair(geoPair *thePair);
double getPlaneDistance(point p1, point p2);
double getHaversineDistance(point p1, point p2);
void printPoint(point p);

#endif /* geoDefs_h */
