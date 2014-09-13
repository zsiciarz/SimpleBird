#!/usr/bin/env python

build_number = 0
with open("build_num.txt", "r") as f:
	contents = f.read()
	f.close()

build_number = int(contents) + 1
print build_number

with open("build_num.txt", "w") as f:
	f.write(str(build_number))
	f.close()