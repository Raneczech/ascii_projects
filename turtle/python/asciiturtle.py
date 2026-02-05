#by Raneczech

VELIKOST = 20

povrch = [[0 for _ in range(VELIKOST)] for _ in range(VELIKOST)]

class turtle:
	def __init__(self, id=0):
		self.id = id
		self.pen = False
		self.hdg = 0
		self.plocha = [[0 for _ in range(VELIKOST)] for _ in range(VELIKOST)]
		self.plocha[3][2] = 1
		self.lx = 2
		self.ly = 3
		self.x = 2
		self.y = 3
	def goTo(self,x,y):
		self.x = x
		self.y = y
		self.plocha[self.y][self.x] = 1
		if self.pen: self.plocha[self.ly][self.lx] = 2
		else: self.plocha[self.ly][self.lx] = 0
		self.lx = x
		self.ly = y
	def left(self,angle):
		self.hdg = (self.hdg - angle) % 4
	def right(self,angle):
		self.hdg = (self.hdg + angle) % 4
	def forward(self,dist):
		if self.hdg == 0:
			for _ in range(dist): self.goTo(self.x,self.y-1)
		if self.hdg == 1:
			for _ in range(dist): self.goTo(self.x+1,self.y)
		if self.hdg == 2:
			for _ in range(dist): self.goTo(self.x,self.y+1)
		if self.hdg == 3:
			for _ in range(dist): self.goTo(self.x-1,self.y)
	def backward(self,dist):
		if self.hdg == 0:
			for _ in range(dist): self.goTo(self.x,self.y+1)
		if self.hdg == 1:
			for _ in range(dist): self.goTo(self.x-1,self.y)
		if self.hdg == 2:
			for _ in range(dist): self.goTo(self.x,self.y-1)
		if self.hdg == 3:
			for _ in range(dist): self.goTo(self.x+1,self.y)
	def penup(self):
		self.pen = False
	def pendown(self):
		self.pen = True

def gfx(plocha):
	print("\033[20A",end='')
	for i in plocha:
		for j in i:
			if j == 0: print('   ',end='')
			elif j == 1: print(' @ ',end='')
			else: print('###',end='')
		print('',end='\n')
