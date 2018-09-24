# fast-geo
Fast algorithms for geo-location related calculations.

Some thoughts (and implementations) on performing location-based calculations at scale.
Consider a mobile app which has access to location data from users. A requirement for a certain feature is to always be able to identify the minimum distance between any two users and which users they are, in real-time.

Starting with the naive brute-force approach which is an O(n^2) problem.
Then trying a divide & conquer approach to get the minimum distance. This is O(nlog(n)).
The closest pair algorithm is pretty complicated to implement but it's one of my favourites.

I included two different distance calculation functions, one for straight-forward (x,y) plane calculations and the other for GPS-based (lat,long) calculations using the Haversine method. A #define determines which distance method is used.

Some basic enhancements to the functions enable not just finding the minimum distance but identifying which two points are involved.

The pre-processing step for implementing the closest pair algorithm is to sort the points separately by X and Y (or lat and long) coordinates. When using standard plane distance method (which is quicker) the pre-processing accounts for about 20% of the overall algorithm time. When using the Haversince distance method (slower) the pre-processing accounts for about 6% of the overall time.

In either case, maintaining a linked list of points in sorted order would provide another significant boost to the performance.

Most of the source code is included, I've held back the implementation of the fast-algorithm as this has been licensed for use in commercial applications.

All benchmarks are on:
* 2-core 3GHz i7 Mac Laptop
* 16 GB RAM

Here performance boost is measured on fast-algo vs. native-algo for the same number of points and the same configuration (plane/haversine).

| Approach | Number of Points | Total Time | Performance Boost |
| :------- | :------:  | :------: | :---------------: |
| Naive-Algo (Plane) | 10,000 | 0.924 sec | 1X          |
| Fast-Algo (Plane) | 10,000 | 0.011 sec   | 84X       |
| Naive-Algo (Haversine) | 10,000 | 5.44 sec | 1X          |
| Fast-Algo (Haversine) | 10,000 | 0.045 sec   | 121X       |

| Naive-Algo (Plane) | 50,000 | 22.11 sec | 1X          |
| Fast-Algo (Plane)  | 50,000 | 0.055 sec   | 404X       |
| Naive-Algo (Haversine) | 50,000 | 128 sec | 1X          |
| Fast-Algo (Haversine)  | 50,000 | 0.21 sec   | 609X       |

| Naive-Algo (Plane) | 100,000 | 89 sec | 1X        |
| Fast-Algo (Plane)  | 100,000 | 0.11 sec   | 798X       |
| Naive-Algo (Haversine) | 100,000 | 503 sec | 1X       |
| Fast-Algo (Haversine)  | 100,000 | 0.406 sec   | 1239X   |

As you can see, for a real-world application with 100,000 or more users, the faster algorithm makes the difference between something that takes prohibitively long (8 minutes) to something that runs in a fraction of a second (0.4 sec) and would appear perfectly real-time to a user.

