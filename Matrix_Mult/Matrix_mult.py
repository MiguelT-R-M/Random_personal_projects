
## MA = int(input("Informe a quantidade de linhas da Mat A ")) 
## NA = int(input("Informe a Colunas de linhas da Mat A "))

## MB = int(input("Informe a quantidade de linhas da Mat B "))
## NB = int(input("Informe a Colunas de linhas da Mat B "))

Mat_A =    [[10, 58, 74],[89, 11, 11],[58, 74, 96]]
Mat_B =    [[22, 41, 13],[29, 10, 9],[7, 1, 2]]
Mat_mult = [[0, 0 ,0],[0, 0, 0],[0, 0, 0]]

if(len(Mat_A[0])==len(Mat_B)):

    for x in range(0,len(Mat_A)):

        for y in range(0, len(Mat_B[0])):

            for z in range(0, len(Mat_B[0])):
                Mat_mult[x][y] += Mat_A[x][z]*Mat_B[z][y]

for x in Mat_mult:
    print(x)