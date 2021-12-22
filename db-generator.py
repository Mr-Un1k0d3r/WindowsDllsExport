import sys
import glob

for name in glob.glob(sys.argv[1] + "/*"):
    path = name.replace(sys.argv[1], "").replace(".txt", "")
    for line in open(name).readlines():
        if not line == "":
            print "insert into exports values ('%s', '%s');" % (path, line.strip().encode("ascii"))