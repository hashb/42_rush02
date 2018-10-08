#!/usr/local/bin/python3

import subprocess
from subprocess import Popen, PIPE, STDOUT
import os

COLLE_CMD = '../ex00/colle-2'
HERE = os.path.dirname(__file__)
# TEST_FILES = [f for f in os.listdir(HERE) if '.txt' in f]

TEST_FILES = [f for f in os.listdir(HERE) if 'rush03' in f]

TEST_FILES.sort()

subprocess.check_call(['./build_alt_resources.sh'])

def test_agains_files():
	for test_file in TEST_FILES:
		with open(os.path.join(HERE, test_file), 'rb') as test:
			p = Popen([COLLE_CMD], stdout=PIPE, stdin=PIPE, stderr=PIPE)
			stdout_data = p.communicate(input=test.read())[0]

		print(f">>> testing with file: {test_file}")
		print(stdout_data.decode('ascii'))


BOARD_SIZE = 20

bin_names = [f'./z_rush0{i}' for i in range (4)]

def sweep_parameter_space():
	for bin_name in bin_names:
		for height in range(BOARD_SIZE):
			for width in range(BOARD_SIZE):
				rush0 = Popen([bin_name, str(width), str(height)], stdout=PIPE)
				colle2 = Popen([COLLE_CMD], stdin=rush0.stdout, stdout=subprocess.PIPE)	
				stdout_data = colle2.communicate()[0]
				rush0.stdout.flush()
				the_output = stdout_data.decode('ascii')
				what_we_should_see = f"[rush-0{bin_name[-1]}] [{width}] [{height}]"

				if (width == 0 or height == 0):
					assert "Error" in the_output
				elif what_we_should_see not in the_output:
					print("\/\/\/\/\/\/\/\/")
					print("FAIL")
					print(the_output)
					print(f"height {height}\t width {width}\t bin name: {bin_name}")
					print('^^^^^^')
				# print(the_output)

if __name__ == '__main__':
	test_agains_files()
	# sweep_parameter_space()