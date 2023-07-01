import csv
import yaml

# with open('./data/shelves.csv', 'w', encoding='UTF8') as f:
#     writer = csv.writer(f)
#     header = ['Tag', 'x0', 'x1', 'y0', 'y1']
#     writer.writerow(header)

with open('./config.yaml') as f:
    data_map = yaml.safe_load(f)
    num_groups = data_map['number_groups']
    for i in range(num_groups):
        print("so")
    