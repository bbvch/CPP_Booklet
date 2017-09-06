import glob
import os

if not os.path.exists("./examples"):
	os.makedirs("./examples")

for f in glob.glob("source/*.cc"):
	f_in = open(f)
	
	lines = f_in.readlines()
	examples = {}
	current_example = None
	for l in lines:
		
		if l.startswith("//@"):
			prefix, num = l.strip().split('@')
			if current_example is not None and num != current_example:
				print "Error: Previous example did not end"
			elif current_example is None:
				current_example = num
				if current_example not in examples:
					examples[current_example] = []
					print "Starting example " + str(current_example)
				else:
					print "Continuing example " + str(current_example)
			elif current_example == num:  #end
				current_example = None
			else:
				print "I forgot to implement something"
		elif current_example is not None:
			if not l.startswith("#ifdef") and not l.startswith("#endif"): #filter out non-compilation warnings
				examples[current_example].append(l)
	
	f_in.close()
	if len(examples) > 0:
		for k in examples:
			bname = os.path.basename(f)
			f_out = open("examples/example_" + str(k) + "_chapter_" + bname, 'w+')
			f_out.writelines(examples[k])
			f_out.close()
