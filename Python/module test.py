import os
path = "C:/"
dirfiles = os.listdir(path)

dir_names = []
file_names = []

for each in dirfiles :
    fullpath = path + each
    if os.path.isdir(fullpath):
        dir_names.append(fullpath+'C:/')
    else:
        file_names.append(fullpath)

print('dir_names : ', dir_names)
print('file_names : ', file_names)
