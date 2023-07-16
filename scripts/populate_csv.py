import csv
import yaml

with open('../data/shelves.csv', 'w', encoding='UTF8') as f:
    writer = csv.writer(f)
    header = ['Tag', 'x0', 'x1', 'y0', 'y1', 'Face']
    writer.writerow(header)

    def write_row(height, x, y, length_shelf, face, num_shelves, num_rows):
        temp_x = x
        temp_y = y
        for _ in num_rows:
            for _ in num_shelves:
                row = ['Tag Placeholder', str(temp_x), str(temp_x+length_shelf), str(temp_y), str(temp_y+height), str(face)]
                writer.writerow(row)
            temp_y += height

with open('./config.yaml') as f:
    x = 0
    y = 0
    file = None
    data_map = yaml.safe_load(f)
    height = data_map["shelf_height"]
    num_groups = data_map['num_groups']
    num_rows = data_map['num_rows']
    for i in range(num_groups):
        shelf = "group" + str(i)
        num_shelves = data_map[shelf]["number_shelves"]
        length_shelf = data_map[shelf]["length"] / num_shelves
        is_uneven = data_map[shelf]["uneven"]["case"]
        if is_uneven:
            position = data_map[shelf]["uneven"]["position"]
            if position == "first":
                write_row(height, x, y, length_shelf, 0, num_shelves, num_rows)
            else:
                write_row(height, x, y, length_shelf, 1, num_shelves, num_rows)
            
        
