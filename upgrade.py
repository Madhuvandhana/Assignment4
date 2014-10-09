from sequence import sequence
def perform_upgrade(present,next):
	for i in range(present,next+1):
		sequence[i]()
		f=open('digest.txt','w')
		f.write(str(i+1))
		f.close()
def main():
	fread=open('digest.txt')
	present_value=int(fread.read())
	latest_upgrade=len(sequence)
	if latest_upgrade>=present_value:
		perform_upgrade(present_value,latest_upgrade)
	else:
		print("Nothing to upgrade")

main()
