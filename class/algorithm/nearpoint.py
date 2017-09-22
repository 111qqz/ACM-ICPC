import os
import random
import numpy as np
import math

def sub_sort(array,low,high):
    key=array[low]
    while low < high:
        while low < high and array[high]>=key:
            high=high-1
        while low < high and array[high]<key:
            array[low]=array[high]
            low=low+1
            array[high]=array[low]
    array[low]=key
    return low

def quick_sort(array,low,high):
    if low<high:
        key_index=sub_sort(array,low,high)
        quick_sort(array,low,key_index)
        quick_sort(array,key_index+1,high)

def basicDis(P):
    if len(P) == 1:
        return P[0]
    elif len(P) == 2:
        x1=P[0][0]
        x2=P[1][0]
        y1=P[0][1]
        y2=P[1][1]
        d=math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
        return d
    else:
        x1=P[0][0]
        x2=P[1][0]
        x3=P[2][0]
        y1=P[0][1]
        y2=P[1][1]
        y3=P[2][1]
        d1=math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
        d2=math.sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))
        d3=math.sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3))
        return min(d1,d2,d3)

def nearestPoint(X,Y,P):
    if len(P) <= 3:
        return basicDis(P)
    else:
        PL=P[0:len(P)/2,:]
        PR=P[len(P)/2:len(P),:]
        XL=XR=np.zeros((0,2))
        YL=YR=np.zeros((0,2))
        countxL=countxR=0
        countyL=countyR=0
        for i in range(len(P)):
            for jl in range(len(PL)):
                if X[i,0] == PL[jl,0]:
                    countxL+=1
                    temp=XL.copy()
                    XL=np.zeros((countxL,2))
                    for k in range(len(temp)):
                        XL[k,0]=temp[k,0]
                    XL[countxL-1,0]=P[i,0]
            for jr in range(len(PR)):
                if X[i,0]==PR[jr,0]:
                    countxR+=1
                    temp=XR.copy()
                    XR=np.zeros((countxR,2))
                    for k in range(len(temp)):
                        XR[k,0]=temp[k,0]
                    XR[countxR-1,0]=P[i,0]
        for i in range(len(P)):
            for jl in range(len(PL)):
                if Y[i,1]==PL[jl,1]:
                    countyL+=1
                    temp=YL.copy()
                    YL=np.zeros((countyL,2))
                    for k in range(len(temp)):
                        YL[k,1]=temp[k,1]
                    YL[countyL-1,1]=P[i,1]
            for jr in range(len(PR)):
                if Y[i,1]==PR[jr,1]:
                    countyR+=1
                    temp=YR.copy()
                    YR=np.zeros((countyR,2))
                    for k in range(len(temp)):
                        YR[k,1]=temp[k,1]
                    YR[countyR-1,1]=P[i,1]
        d1=nearestPoint(XL,YL,PL)
        d2=nearestPoint(XR,YR,PR)
        
print d1
        print d2
        d=min(d1,d2)
        return d
                
def main():
    Q=np.zeros((10,2))
    for i in range(10):
        for j in range(2):
            Q[i,j]=random.randint(1,10)
    print Q
    X=Q.copy()
    Y=Q.copy()#Éî¿œ±Ž ¿ª±ÙÐÂµ¥Ôª
    quick_sort(X[:,0],0,9)
    quick_sort(Y[:,1],0,9)
    d=nearestPoint(X,Y,Q)
    print d
main()

    
