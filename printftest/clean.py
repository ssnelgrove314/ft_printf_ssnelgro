import os
import re
import fnmatch
def find_files(directory, pattern):
	for root, dirs, files in os.walk(directory):
		for basename in files:
			if fnmatch.fnmatch(basename.lower(), pattern):
				filename = os.path.join(root, basename)
				yield filename

dir = '/test/'
for filename in find_files(dir, 'makefile'):
	with open(filename, 'r') as f:
		s = f.read()
		f.close()
		s = re.sub("-Wall|-Werror|-Wextra", "", s)
		s = re.sub("gcc", "gcc -w", s)
		with open(filename, 'w') as i:
			i.write(s)
