import os,pygame
pygame.init()
os.chdir("D:\TankIO\image")
image=pygame.image.load("font.bmp")
w=image.get_width()
h=image.get_height()
image=pygame.transform.scale(image,(w*2,h*2))
pygame.image.save(image,'output.bmp')