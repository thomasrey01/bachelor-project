# RUG Bachelor project
## Leveraging optimal transport for real time 3D map building

### Database flow
    if database is empty then: 
        Init database from csv - all y values will be 0 except maybe the face
    else:
        Use database from sqlite file
    
    instead of keeping all of the map in memory, load the portions of 3 at a time and work from them.
