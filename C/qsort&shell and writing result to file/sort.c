//
// Created by Oleh on 26.03.2017.
//
#include "sort.h"
#include <stdio.h>

//declaration function
void swap(int *theInt1, int *theInt2);
int partitionIt(int *anArray, int aLeftIndex, int aRightIndex, int aPivot);
int mediana(int *anArray, int aLeftIndex, int aRightIndex);
void m_manualSort(int *anArray, int aLeftIndex, int aRightIndex);

//shell sort
void shellSort(int *anArray, int aSize)
{
    int theInner = 0;
    int theOuter = 0;
    int theH = 1; // start h = 1

    //1. Calculate start value of h
    while (theH <= aSize/3)
    {
        theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
    }

    //2. Sequental decrease h to 1
    while (theH > 0)
    {
        for (theOuter = theH; theOuter < aSize; theOuter ++)
        {
            int theTmp = *(anArray+theOuter);
            theInner = theOuter;

            // the first sub-array {0, 4, 8}
            while (theInner > theH-1 && *(anArray+theInner - theH) >= theTmp)
            {
                *(anArray+theInner) = *(anArray+theInner-theH);
                theInner -= theH;
            }

            *(anArray+theInner) = theTmp;
        }

        theH = (theH - 1) / 3; //decrease h
    }
}

//quick sort
void quickSort(int *anArray, int aLeftIndex, int aRightIndex)
{

    int theSize = aRightIndex - aLeftIndex + 1;

    if (theSize <= 3)
    {
        m_manualSort(anArray, aLeftIndex, aRightIndex);
    }
    else
    {
        int thePivot = mediana(anArray, aLeftIndex, aRightIndex);
        int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
        //left part sorting
        quickSort(anArray, aLeftIndex, thePartitionIndex-1);
        //right part sorting
        quickSort(anArray, thePartitionIndex, aRightIndex);
    }

}

//help function for quicksort
int partitionIt(int *anArray, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex;
    int theRight = aRightIndex ;
    while (1)
    {
        // search the bigest element

        while (*(anArray+theLeft) > aPivot)
        {
            theLeft++;
        }

        // search the lowest element
        while (*(anArray+theRight) < aPivot)
        {
            theRight--;
        }

        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            swap((anArray+theLeft), (anArray+theRight));
            theLeft++;
            theRight--;
        }
    }

    return theLeft; // return break position
}

int mediana(int *anArray, int aLeftIndex, int aRightIndex)
{
    int theCenter = (aLeftIndex + aRightIndex) / 2;

    if (*(anArray+aLeftIndex) < *(anArray+theCenter))
    {
        swap((anArray+aLeftIndex), (anArray+theCenter));
    }

    if (*(anArray+aLeftIndex) < *(anArray+aRightIndex))
    {
        swap((anArray+aLeftIndex), (anArray+aRightIndex));
    }

    if (*(anArray+theCenter) < *(anArray+aRightIndex))
    {
        swap((anArray+theCenter), (anArray+aRightIndex));
    }

    swap((anArray+theCenter), (anArray+aRightIndex - 1));

    return *(anArray+aRightIndex - 1);
}

void m_manualSort(int *anArray, int aLeftIndex, int aRightIndex)
{
    int theSize = aRightIndex - aLeftIndex + 1;

    if (theSize <= 1)
    {
        return;
    }

    if (2 == theSize)
    {
        if (*(anArray+aLeftIndex) < *(anArray+aRightIndex))
        {
            swap((anArray+aLeftIndex), (anArray+aRightIndex));
        }
        return ;
    }
    else
    {
        // 3 elementes
        if (*(anArray+aLeftIndex) < *(anArray+aRightIndex - 1))
        {
            swap(anArray+aLeftIndex, anArray+aRightIndex - 1);
        }

        if (*(anArray+aLeftIndex) < *(anArray+aRightIndex))
        {
            swap(anArray+aLeftIndex, anArray+aRightIndex);
        }

        if (*(anArray+aRightIndex - 1) < *(anArray+aRightIndex))
        {
            swap(anArray+aRightIndex - 1, anArray+aRightIndex);
        }
    }
}

//swap function
void swap(int *theInt1, int *theInt2)
{
    int temp=*theInt1;
    *theInt1=*theInt2;
    *theInt2=temp;
}


