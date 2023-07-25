import csv
import yaml

class WriteCSV:
    def __init__(self, path:str):
        self.file = open(path, 'w', encoding="UTF-8")
        self.facility = "A"
        self.aisle = "01"
        self.column = "01"
        self.height = "1"
        self.writer = csv.writer(self.file)
        header = ['Tag', 'x0', 'x1', 'y0', 'y1', 'z', 'Face']
        self.writer.writerow(header)
    
    def next_tag(self):
        height = int(self.height)
        column = int(self.column)
        
        if height == 4 and column == 15:
            aisle = int(self.aisle)
            aisle += 1
            self.aisle = ""
            if aisle < 10:
                self.aisle = "0"
            self.aisle += str(aisle)
            self.column = "01"
            self.height = "1"
            height = 1
        
        if height == 4:
            self.height = "1"
            self.column = ""
            column += 1
            if column < 10:
                self.column = "0"
            self.column += str(column)
        else:
            height += 1
            self.height = str(height)
        
            
        

    
    def write_row(self, height, x, y, length_shelf, face, num_shelves, num_rows, z):
        temp_x = x
        temp_y = y
        for _ in range(num_rows):
            for _ in range(num_shelves):
                tag = self.facility + self.aisle + "-" + self.column + "-" + self.height
                row = [ tag,
                        str(round(temp_x, 1)),
                        str(round(temp_x+length_shelf, 1)),
                        str(round(temp_y, 1)),
                        str(round(temp_y+height, 1)),
                        str(round(z, 1)),
                        str(round(face, 1))
                    ]
                self.writer.writerow(row)
                self.next_tag()
                temp_x += length_shelf
            temp_y += height
    
    def close(self):
        self.file.close()
    

with open('./config.yaml') as f:
    x = 0
    y = 0
    z = 0
    writer = WriteCSV("../data/shelves.csv")
    data_map = yaml.safe_load(f)
    height = data_map["shelf_height"]
    num_groups = data_map['num_groups']
    num_rows = data_map['num_rows']
    shelf_width = data_map["shelf_width"]
    for i in range(num_groups):
        group = "group" + str(i)
        aisle_spacing = data_map[group]["aisle_spacing"]
        num_shelves = data_map[group]["number_shelves"]
        length_shelf = data_map[group]["length"] / num_shelves
        is_uneven = data_map[group]["uneven"]["case"]
        z += data_map[group]["padding"]
        if is_uneven:
            position = data_map[group]["uneven"]["position"]
            if position == "first":
                writer.write_row(height, x, y, length_shelf, 0, num_shelves, num_rows, z)
        num_subgroups = data_map[group]["num_subgroups"]
        for j in range(num_subgroups):
            subgroup = "subgroup" + str(j)
            number_aisles = data_map[group][subgroup]["number_aisles"]
            for _ in range(number_aisles):
                writer.write_row(height, x, y, length_shelf, 1, num_shelves, num_rows, z)
                z += data_map[group][subgroup]["aisle_gap"] + 2 * shelf_width
                writer.write_row(height, x, y, length_shelf, 0, num_shelves, num_rows, z)
            z += aisle_spacing
    writer.close()
                
            
        
        

            
        
