import os
import random
import numpy as np

def StrassenMult(A,B,n):#Strassen compute
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
        S1=B12-B22
        S2=A11+A12
        S3=A21+A22
        S4=B21-B11
        S5=A11+A22
        S6=B11+B22
        S7=A12-A22
        S8=B21+B22
        S9=A11-A21
        S10=B11+B12
        P1=StrassenMult(A11,S1,n/2)
        P2=StrassenMult(S2,B22,n/2)
        P3=StrassenMult(S3,B11,n/2)
        P4=StrassenMult(A22,S4,n/2)
        P5=StrassenMult(S5,S6,n/2)
        P6=StrassenMult(S7,S8,n/2)
        P7=StrassenMult(S9,S10,n/2)
        C11=P5+P4-P2+P6
        C12=P1+P2
        C21=P3+P4
        C22=P5+P1-P3-P7
        C1=np.hstack((C11,C12))
        C2=np.hstack((C21,C22))
        C=np.vstack((C1,C2))
     #   print S1
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
    C=StrassenMult(A,B,8)
    print C

main()
