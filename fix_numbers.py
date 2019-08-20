import glob
import os
import re

for f in glob.glob("./src/*.cc"):
    filename = os.path.basename(f)
    m = re.search('([0-9_]+)([a-z_]+\.cc)', filename)
    number = m.group(1)[:-1].replace("_", ".")

    in_file = open(f, 'r')
    lines = in_file.readlines()
    in_file.close()
    found_annotation = False
    out_file = open(f, 'w')
    for l in lines:
        m = re.search("Example for section ([0-9]\.[0-9]+[\.0-9]*)", l)

        if m:
            found_annotation = True

        if m and m.group(1) != number:
            print("example number in file of " + filename +
                  "differs from filename. Annotation: " + m.group(1) + " filename " + number)

            l = l.replace(m.group(1), number)
        out_file.write(l)
    out_file.close()

    if not found_annotation:
        print(filename + " is missing annotation")
