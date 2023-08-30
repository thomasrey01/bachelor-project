# RUG Bachelor project

## Efficient map representation of warehouse inventory for cycle counting and autonomous systems

This work represents a proof of concept to an efficient map representation and inventory updating to ultimately be used in an autonomous drone. 

### Compiling and running
The C++ version used in this project is C++ 17.
To compile first create and run the Makefile using:
```
cmake .
make
```
Then run the compiled binary with:
```
./inventory ./data/shelves.csv
```
During the runtime, the CLI can be interacting with by basic user input. Type "help" for a list of possible inputs.

### Changing the map
To change the map, first please consult the Floorplan.pdf file. The ./scripts/config.yaml file. Make the changes accordingly and rerun the python script with:
```
python3 ./scripts/populate_csv.py
```

The modules used in the script come by default with python 3.10. Any errors occurring from running the script should be solved with a new installation of python 3.
