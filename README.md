# RUG Bachelor project
## Leveraging optimal transport for real time 3D map building

### Coordinates from floor plan

The 2D (x,z) coordinates from the floor plan start from the top left shelf. Since there are no known labels from the floor plan yet, upper left most is label A01-01-01, it probably is wrong but for initial mapping, we consider it to be correct. This will be updated later.

Almost all shelves line up (except one row) on the left side. There is no direct measurement of an entire row, instead we can only estimate, overall distance / number of shelves.

Distance = 55000. # of shelves = 15.
Length of every shelf: 3666
Width of every shelf: 1100

Face 0: facing in positive Z. Face 1: facing in negative Z

Only first "grouping" (A) of aisles show measurements between aisles.

### Database flow
    if database is empty then: 
        Init database from csv - all y values will be 0 except maybe the face
    else:
        Use database from sqlite file
    
    instead of keeping all of the map in memory, load the portions of 3 at a time and work from them.


### To be improved section

floor plan has no measurement from top left edge of room to beginning of top left shelf. It has some measurements that could be calculated for the distance but some points don't allign so there will be some innacuracies.