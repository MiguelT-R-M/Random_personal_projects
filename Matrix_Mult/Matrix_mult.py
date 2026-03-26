
MA = int(input("Informe a quantidade de linhas da Mat A ")) 
NA = int(input("Informe a Colunas de linhas da Mat A "))
print("")
MB = int(input("Informe a quantidade de linhas da Mat B "))
NB = int(input("Informe a Colunas de linhas da Mat B "))

Mat_A = []
Mat_B = []
Mat_mult = []

print("")
for x in range(0, MA):
    Mat_A.append([])
    for y in range(0, NA):
        Mat_A[x].append(int(input(f"Informe a posição ({x+1},{y+1}) da matriz A: ")))
print("")

for x in range(0, MB):
    Mat_B.append([])
    for y in range(0, NB):
        Mat_B[x].append(int(input(f"Informe a posição ({x+1},{y+1}) da matriz B: ")))

for x in range(0, MA):
    Mat_mult.append([])
    for y in range(0, NB):
        Mat_mult[x].append(0)


if(len(Mat_A[0])==len(Mat_B)):

    for x in range(0,len(Mat_A)):

        for y in range(0, len(Mat_B[0])):

            for z in range(0, len(Mat_B)):
                
                Mat_mult[x][y] += Mat_A[x][z]*Mat_B[z][y]

for x in Mat_mult:
    print(x)