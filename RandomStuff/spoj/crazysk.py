t = int(raw_input())
i = 0
while i < t:
	i += 1
	s = raw_input()
	b = s.split(' ' )
	x = long(b[0])
	n = long(b[1])

	d = n - 1
	w = x % d
	temp = 0
	if w == 0:
		temp = x / d
		temp = temp - 1
	else:
		temp = x / d
	
	ans = x + temp

	print ans


