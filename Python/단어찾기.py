f = open('vocabulary2.txt','r')
lines = f.readlines()

dic = {}

for line in lines :
    words = line.split('\t')
    dic[words[1]] = words[3]
    dic[words[6]]=words[8]

print(dic)

word=input('word : ')
print(dic[word])

