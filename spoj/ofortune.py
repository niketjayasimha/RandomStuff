import math

def ci(p, r, t, a):
	amt, intrst = 0, 0
	i = 0
	while i < t:
		i += 1
		intrst = math.floor(p * r)
		amt = p + intrst - a
		p = amt
	return amt

def si(p, r, t, a):
	intrst, ti = 0, 0
	i = 0
	while i < t:
		i += 1
		intrst = math.floor(p * r)
		ti += intrst
		p -= a
	return p + ti

datasets = int(raw_input())
i = 0
while i < datasets:
	i += 1
	p = int(raw_input())
	t = int(raw_input())
	option = int(raw_input())
	maximum = 0.0
	j = 0
	while j < option:
		j += 1
		s = raw_input()
		b = s.split(' ')
		choice = int(b[0])
		r = float(b[1])
		a = int(b[2])
		if choice == 0:
			amount = si(p, r, t, a)
		else:
			amount = ci(p, r, t, a)
		if amount > maximum:
			maximum = amount
	print maximum
