from Matrix_mult import matMult


def main():
    MA = [[1, 1],[1, 1]]
    MB = [[2],[2]]
    MF = [[0],[0]]

    MF = matMult(MA, MB, MF)

    for x in MF:
        print(x)

if __name__ == "__main__":
    SystemExit(main())