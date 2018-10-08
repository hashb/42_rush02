#!/usr/local/bin/python3

from subprocess import Popen, PIPE, STDOUT
import os

COLLE_CMD = '../ex00/colle-2'
HERE = os.path.dirname(__file__)
# TEST_FILES = [f for f in os.listdir(HERE) if '.txt' in f and '3' in f]

TEST_FILES = [f for f in os.listdir(HERE) if 'rush03_1_5.txt' in f]



TEST_FILES.sort()

for test_file in TEST_FILES:
	with open(os.path.join(HERE, test_file), 'rb') as test:
		p = Popen([COLLE_CMD], stdout=PIPE, stdin=PIPE, stderr=PIPE)
		stdout_data = p.communicate(input=test.read())[0]

	print(f">>> testing with file: {test_file}")
	print(stdout_data.decode('ascii'))

