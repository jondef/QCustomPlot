import os

content = {} # file name: content
current_file = ""

with open('qcustomplot.cpp', 'r') as fh:
	for line in fh:
		if "including file " in line:
			current_file = line.split("\'")[1]
		elif "end of " in line:
			current_file = ""

		# append line
		if current_file != "":
			try:
				content[current_file] += line
			except KeyError:
				content[current_file] = line

for file, fc in content.items():
	try:
		f = open(file, "w")
	except FileNotFoundError:
		os.mkdir(os.path.join(os.getcwd(),os.path.dirname(file)))
		f = open(file, "w")
	f.write(fc)
	f.close()


