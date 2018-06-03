alphabet = ['c','d','a','b','e']
##print(alphabet)
##alphabet.sort()
##print(alphabet)

##friends = ['Alice','Carole', 'Bob']
##friends_copy = friends[:]
##friends_copy.sort()
##print(friends_copy)
##print(friends)

myAlpha = alphabet
print(id(alphabet), id(myAlpha))
alphabet.sort()
print(id(alphabet), id(myAlpha))
