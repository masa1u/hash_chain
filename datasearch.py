list = [i*2 for i in range(10000000)]

def linear(key):
	for i in range(len(list)):
		if key == list[i]:
			return i+1
	else:
		return "keyが存在しません"
	
def binary(key):
	top = len(list)-1
	bottom = 0
	count = 0
	while True:
		count += 1
		target = (bottom+top)//2
		if key == list[target]:
			return count
		elif key < list[target]:
			top = target
		else:
			bottom = target
		if len(list) < 2**count:
			break
	return "keyが存在しません"

for i in range(len(list)):
	searchkey = i
	binary(searchkey)
	if i % 1000000 == 0:
		print(i)
# searchkey = int(input("探索するkey:"))

# print("リニアサーチ: " + str(linear(searchkey)))
# print("バイナリーサーチ: " + str(binary(searchkey)))