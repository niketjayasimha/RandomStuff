x = int(raw_input())
digits = ''
if not x:
	digits = '0'
else:
	while x != 0:
		x, rem = divmod(x, -2)
		if rem < 0:
			x, rem = x + 1, rem + 2
		digits = str(rem) + digits
print digits


