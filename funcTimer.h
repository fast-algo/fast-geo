//
//  funcTimer.h
//  handylibs
//
//  Created by fast-algo on 16/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#ifndef funcTimer_h
#define funcTimer_h

#include <stdio.h>

#define NUM_FUNC_TIMERS 20

void startFuncTimer(int id);
void stopFuncTimer(int id);
double getFuncTime(int id);

#endif /* funcTimer_h */
