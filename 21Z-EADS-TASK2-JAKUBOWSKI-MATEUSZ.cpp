#include "21Z-EADS-TASK2-JAKUBOWSKI-MATEUSZ.h"
#include <iostream>

using namespace std;

int main(){

    bi_ring<int, int> seqA;
    bi_ring<int, int> seqB;
    bi_ring<int, int> seqC;
    bi_ring<int, int> seqD;
    cout<<"\n----------------------------------PUSHING ONE ELEMENT----------------------------------\n";
    seqA.push(1,1);
    seqA.print();
    cout<<"Is the list empty: "<<seqA.isEmpty();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n-----------------------------------------CLEAR-----------------------------------------\n";
    seqA.clearAll();
    cout<<"Is the list empty: "<<seqA.isEmpty();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n--------------------------------PUSHING THREE ELEMENTS---------------------------------\n";
    seqA.push(1,1);
    seqA.push(2,2);
    seqA.push(3,3);
    seqA.print();
    cout<<"Is the list empty: "<<seqA.isEmpty();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n------------------------------INSERT AFTER FIRST ELEMENT-------------------------------\n";
    seqA.insertAfter(11, 11, seqA.begin());
    seqA.print();
    cout<<"Is the list empty: "<<seqA.isEmpty();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n------------------------------INSERT AFTER LAST ELEMENT--------------------------------\n";
    seqA.insertAfter(33, 33, seqA.end());
    seqA.print();
    cout<<"Is the list empty: "<<seqA.isEmpty();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n-------------------------INSERT AFTER SPECIFIED ELEMENT(2,2)---------------------------\n";
    bi_ring<int, int>::const_iterator iterA = seqA.cbegin();
    (iterA++)++;
    seqA.insertAfter(22, 22, iterA);
    seqA.print();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n-----------------------------------------CLEAR-----------------------------------------\n";
    seqA.clearAll();
    cout<<"\n---------------------------INSERT AFTER WHEN LIST IS EMPTY-----------------------------\n";
    seqA.insertAfter(22, 22, seqA.begin());
    seqA.print();
    cout<<"\n--------------------------------PUSHING THREE ELEMENTS---------------------------------\n";
    seqA.push(1,1);
    seqA.push(2,2);
    seqA.push(3,3);
    seqA.print();
    cout<<"\n------------------------------INSERT BEFORE FIRST ELEMENT------------------------------\n";
    seqA.insertBefore(00, 00, seqA.begin());
    seqA.print();
    cout<<"Is the list empty: "<<seqA.isEmpty();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n------------------------------INSERT BEFORE LAST ELEMENT-------------------------------\n";
    seqA.insertBefore(33, 33, seqA.end());
    seqA.print();
    cout<<"Is the list empty: "<<seqA.isEmpty();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n------------------------INSERT BEFORE SPECIFIED ELEMENT(33,33)-------------------------\n";
    seqA.insertBefore(222, 222, iterA);
    seqA.print();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n-----------------------------------------CLEAR-----------------------------------------\n";
    seqA.clearAll();
    cout<<"\n--------------------------INSERT BEFORE WHEN LIST IS EMPTY-----------------------------\n";
    seqA.insertBefore(22, 22, seqA.begin());
    seqA.print();
    cout<<"\n--------------------------------PUSHING FIVE ELEMENTS----------------------------------\n";
    seqA.push(1,1);
    seqA.push(2,2);
    seqA.push(3,3);
    seqA.push(4,4);
    seqA.push(5,5);
    seqA.print();
    cout<<"\n---------------------------------ERASE FIRST ELEMENT-----------------------------------\n";
    seqA.erase(seqA.begin());
    seqA.print();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n----------------------------------ERASE LAST ELEMENT-----------------------------------\n";
    seqA.erase(seqA.end());
    seqA.print();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n--------------------ERASE ITERATOR SPECIFIED ELEMENT(SECOND ONE)-----------------------\n";
    bi_ring<int, int>::const_iterator iterB = seqA.cbegin();
    (iterB++);
    seqA.erase(iterB);
    seqA.print();
    cout<<"\nThe number of elements in the list: "<<seqA.size()<<"\n";
    cout<<"\n--------------------------------ERASE FROM EMPTY LIST----------------------------------\n";
    seqB.erase(iterB);
    seqB.print();
    cout<<"\nThe number of elements in the list: "<<seqB.size()<<"\n";


    //Part 2
    cout<<"\n---------------------------------CREATING TWO LISTS------------------------------------\n";
    seqC.push(1,1);
    seqC.push(1,1);
    seqC.push(1,1);
    seqC.push(1,1);
    seqC.push(1,1);
    seqC.push(1,1);
    seqC.print();
    seqD.push(2,2);
    seqD.push(2,2);
    seqD.push(2,2);
    seqD.push(2,2);
    seqD.push(2,2);
    seqD.push(2,2);
    seqD.print();
    cout<<"\n------------------------------------SHUFFLE EX.1---------------------------------------\n";
    
    bi_ring<int,int> outcome;
    outcome = shuffle(seqC,1,seqD, 2, 2);
    outcome.print();
    cout<<"\n------------------------------------SHUFFLE EX.2---------------------------------------\n";
    outcome = shuffle(seqC,3,seqD, 2, 2);
    outcome.print();
    cout<<"\n------------------------------------SHUFFLE EX.3---------------------------------------\n";
    outcome = shuffle(seqC,1,seqD, 1, 4);
    outcome.print();
    return 0;

}
