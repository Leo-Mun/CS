import math
def string_xor(data, key) :
    repeat = math.ceil(len(data)/len(key))
    repeatKey=key*repeat
    return "".join(chr(ord(a) ^ ord(b)) for a,b in zip(data, repeatKey))

if __name__=="__main__":
    key = "123"
    data = input("Type the data : ")
    print("Plain Text : "+data)
    
    encryptText = string_xor(data,key)
    print("Encrypt Text : "+ encryptText)
    
    decryptText = string_xor(encryptText, key)
    print("Decrypt Text : "+ decryptText)
