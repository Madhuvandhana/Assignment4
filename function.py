import os
def two():
	#performs upgrade from one to two
	fd_r=open('file.txt','r').readlines()
	fd_w=open('file.txt','w')
	for line in fd_r:
    		line=line.strip()+","+"null"
        	fd_w.write(line+"\n")
	fd_w.close()  

	
