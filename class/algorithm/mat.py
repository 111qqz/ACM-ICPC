import os
import random
import numpy as np

def matrixMultiply(A,B,n):#compute
    C=np.zeros((n,n))
    if n == 1:
        C[0,0]=A[0,0]*B[0,0]
    else:
        A11=A[0:n/2,0:n/2]
        A12=A[0:n/2,n/2:n]
        A21=A[n/2:n,0:n/2]
        A22=A[n/2:n,n/2:n]
        B11=B[0:n/2,0:n/2]
        B12=B[0:n/2,n/2:n]
        B21=B[n/2:n,0:n/2]
        B22=B[n/2:n,n/2:n]
        C11=matrixMultiply(A11,B11,n/2)+matrixMultiply(A12,B21,n/2)
        C12=matrixMultiply(A11,B12,n/2)+matrixMultiply(A12,B22,n/2)
        C21=matrixMultiply(A21,B11,n/2)+matrixMultiply(A22,B21,n/2)
        C22=matrixMultiply(A21,B12,n/2)+matrixMultiply(A22,B22,n/2)
        C1=np.hstack((C11,C12))

        C2=np.hstack((C21,C22))
        C=np.vstack((C1,C2))
    return C

def ramArr(n):#create ramdom arrays of size n
    a=np.zeros((n,n))
    for i in range(n):
        for j in range(n):
            a[i,j]=1
    return a

def main():
    A=ramArr(8)
    B=ramArr(8)
    print "Mat A:" 
    print A
    print "Mat B:"
    print B #print original A&B
    print "Mat C:"
    C=matrixMultiply(A,B,8)
    print C
    

main()
