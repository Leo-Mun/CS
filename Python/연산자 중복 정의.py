class Matrix:
    def __init__(self, row, col, data):
        self.row=row
        self.col=col
        self.data=data

    def __add__(self, other):
        res = Matrix(2,2,[[0,0],[0,0]])
        for r in range(self.row):
            for c in range(self.col):
                res.data[r][c] = self.data[r][c] + other.data[r][c]
        return res
    
    def __str__(self):
        return str(self.data)
    
data = [[1,2],[3,4]]
mat1=Matrix(2,2,data)
data = [[2,4],[6,8]]
mat2=Matrix(2,2,data)

mat3 = mat1 + mat2
print(mat3)
