import math
while 1:
	s = raw_input()
	b = s.split(' ')
	x = int (b[0])
	y = int (b[1])

	if x == 0 and y == 0:
		break
	print pow(x, y)

