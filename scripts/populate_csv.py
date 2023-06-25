import csv

with open('./data/shelves.csv', 'w', encoding='UTF8') as f:
    writer = csv.writer(f)
    header = ['Tag', 'x0', 'x1', 'y0', 'y1']
    writer.writerow(header)

    # num_groups = 
