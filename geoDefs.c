//
//  geoDefs.c
//  GeoDefs
//
//  Created by fast-algo on 16/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#include <math.h>
#include <memory.h>
#include "geoDefs.h"

void initGeoPair(geoPair *thePair)
{
    memset(thePair, 0, sizeof(geoPair));
    thePair->distance = MAXFLOAT;
}

double getPlaneDistance(point p1, point p2)
{
    double dist = sqrt(pow(p2.lat - p1.lat, 2) + pow(p2.lon - p1.lon, 2));
    return dist;
}

double getHaversineDistance(point p1, point p2)
{
    double dx, dy, dz;
    double th1 = p1.lat * TO_RAD;
    double ph1 = (p1.lon - p2.lon) * TO_RAD;
    double th2 = p2.lat * TO_RAD;
    
    dz = sin(th1) - sin(th2);
    dx = cos(ph1) * cos(th1) - cos(th2);
    dy = sin(ph1) * cos(th1);
    return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}

void printPoint(point p)
{
    printf("Point(%d): (%lf, %lf)\n", p.pid, p.lat, p.lon);
}
