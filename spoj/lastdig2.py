def mod_exp(base, pwr, mod):
	x = 1
	while pwr > 0:
		if pwr % 2 == 1:
			x = (x * base) % mod
		pwr = pwr >> 1
		base = (base * base) % mod
	return x

t = int(raw_input())
while t:
	t -= 1
	x = raw_input().split(' ')
	a, b = str(x[0]), long(x[1]);
	a = int(a[-1])
	if a == 0 and b == 0:
		print '0'
	elif a != 0 and b == 0:
		print '1'
	else:
		b = b % 4
		if b == 0:
			b = 4
		print mod_exp(a, b, 10)
	


