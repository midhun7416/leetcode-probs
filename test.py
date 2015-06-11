from pymouse import PyMouse
import random
import time

def click():
	m = PyMouse()
	X = [50, 75, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700,750, 800,
		850, 900, 950, 1000, 1050, 1100, 1150,1200]
	Y = [300, 350, 250, 250, 220, 170, 190]

	x=X[random.randint(0, len(X)-1)]
	y=Y[random.randint(0, len(Y)-1)]
	m.position() #gets mouse current position coordinates
	m.move(x,y)
	m.click(x,y,random.randint(1,3)) #the third argument "1" represents the mouse button
	m.press(x,y) #mouse button press
	m.release(x,y) #mouse button release

if __name__ =='__main__':
	curr = time.time()
	end = curr + 60*60*4
	while curr<=end:
		click()
		time.sleep(10)
		curr = time.time()