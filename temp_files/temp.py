import os,pygame
pygame.init()
os.chdir("D:\TankIO\image")
image=pygame.image.load("font.bmp")
w=image.get_width()
h=image.get_height()
x=0
y=0
while y<h:
    while x<w:
        if (image.get_at((x,y)))==(0,162,232,255):
            image.set_at((x,y),((255,255,255)))
        x+=1
    y+=1

pygame.image.save(image,'output.bmp')