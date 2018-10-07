#!/usr/local/bin/python3

import subprocess

DO_OP_CMD = './do-op'

EX00 = """
o--o
|  |
|  |
o--o
"""

CASES = [
	(('1','+','1'), b'2\n'),
	(('42amis', '-', '-20toto12'), b'62\n'),
	(('1', 'p', '1'), b'0\n'),
	(('1','+','toto3'), b'1\n'),
	(('toto3', '+', '4'), b'4\n'),
	(('foo', 'plus', 'bar'), b'0\n'),
	(('25', '/', '0'), b'Stop : division by zero\n'),
	(('25', '%', '0'), b'Stop : modulo by zero\n'),
	(('25', '+', '5', '6'), b''),
	((''), b''),
]

for (input, expected_output) in CASES:
	output = subprocess.check_output([DO_OP_CMD] + list(input))
	if expected_output != output:
		print(f"Fail.  input: {input}\t expected output: {expected_output}\t actual output: {output}")
	else:
		print("pass")
