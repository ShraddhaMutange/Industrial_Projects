///////////////////////////////////////////////////////////////////////////////////////////
// 
//      Generalised Data structure Library
// 
///////////////////////////////////////////////////////////////////////////////////////////

/*
--------------------------------------------------------------------------------
Type                Name of class for node      Name of class for functionality
--------------------------------------------------------------------------------
Singly Linear       SinglyLLLnode               SinglyLLL
Singly Circular     SinglyCLLnode               SinglyCLL
Doubly Linear       DoublyLLLnode               DoublyLLL
Doubly Circular     DoublyCLLnode               DoublyCLL
--------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Singly Linear LL using Generic approach
// 
///////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:      
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);  
        void DeleteAtPos(int pos);
};

template <class T>
SinglyLLL<T> :: SinglyLLL()  // Default constructor
{
    cout << "Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertFirst 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;         // IMP
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display values of linked list
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    int iCnt = 0;

    SinglyLLLnode<T> * temp = NULL;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Int
//  Description :       Used to return number of values in linked list
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position of node
//  Output :            Nothing
//  Description :       Used to insert node at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;

    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node present at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;

    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    if((pos < 1) || (pos > this->iCount))
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;

        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Doubly Linear LL using Generic approach
// 
///////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public: 
        T data;
        DoublyLLLnode<T> *next;
        DoublyLLLnode<T> *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout << "Linked list gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertFirst 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn; 
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }    

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn; 
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }    

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position of node
//  Output :            Nothing
//  Description :       Used to insert node at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;

    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;    // temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL) // if(iCount == 0)  // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)          // LL contains one node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        // LL contains more than one node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL) // if(iCount == 0)  // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)          // LL contains one node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        // LL contains more than one node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node present at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;

    DoublyLLLnode<T> * temp = NULL;

    if((pos < 1) || (pos > this->iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        delete temp->next->prev;

        temp->next->prev = temp;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display values of linked list
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;

    temp = first;

    cout << "NULL <=> ";

    while(temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Int
//  Description :       Used to return number of values in linked list
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Singly Circular LL using Generic approach
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertFirst 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T> :: Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last->next);
    
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Int
//  Description :       Used to return number of values in linked list
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node present at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position of node
//  Output :            Nothing
//  Description :       Used to insert node at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>(no);

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Doubly Circular LL using Generic approach
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
    T data;
    DoublyCLLnode<T> *next;
    DoublyCLLnode<T> *prev;

    DoublyCLLnode(int no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);

};

template <class T>
DoublyCLL<T> :: DoublyCLL()  // Default constructor
{
    cout << "Object of DoublyCL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertFirst 
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at first position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;

        this->iCount--;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->last->next = this->first;
        this->first->prev = this->last;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node present at last position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;

        this->iCount--;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display values of linked list
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: Display()
{
    int iCnt = 0;

    DoublyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    temp = this->first;

    printf(" <=> ");

    do
    {
        printf("| %d | <=> ", temp->data);
        temp = temp->next;

    }while(temp != this->last->next);

    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Int
//  Description :       Used to return number of values in linked list
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position of node
//  Output :            Nothing
//  Description :       Used to insert node at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;

    DoublyCLLnode<T> * newn = NULL;
    DoublyCLLnode<T> * temp = NULL;

    if((pos < 1) || (pos > this->iCount+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     DeleteAtPos
//  Input :             Position of node
//  Output :            Nothing
//  Description :       Used to delete node present at a specific position
//  Author :            Shraddha Dhananjay Mutange
//  Date :              06/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;

    DoublyCLLnode<T> * temp = NULL;

    if((pos < 1) || (pos > this->iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;

        temp->next->prev = temp;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////
// 
//  Final code of Stack using Generic approach
// 
///////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

    Stacknode(T no)
    {
        this->data = no;
        this->next= NULL;
    }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();
        void Push(T);
        T Pop();
        T Peep();
        void Display();
        int Count();
};

template <class T>
Stack<T> :: Stack()
{
    cout << "Stack is created succesfully\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Push
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to element at top of stack
//  Author :            Shraddha Dhananjay Mutange
//  Date :              08/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: Push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Pop
//  Input :             Nothing
//  Output :            Data which is removed
//  Description :       Used to remove an element from the top
//  Author :            Shraddha Dhananjay Mutange
//  Date :              08/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: Pop()
{
    T Value = 0;

    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    
    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Peep
//  Input :             Nothing
//  Output :            Data which is removed
//  Description :       Used to display an element present the top without removing it
//  Author :            Shraddha Dhananjay Mutange
//  Date :              08/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: Peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    
    Value = this->first->data;

    return Value;
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display elements in the stack
//  Author :            Shraddha Dhananjay Mutange
//  Date :              08/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }
    
    while(temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Int
//  Description :       Used to return number of elements present in the stack
//  Author :            Shraddha Dhananjay Mutange
//  Date :              08/01/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////
// 
//  Queue using Generic approach
// 
///////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

    Queuenode(T no)
    {
        this->data = no;
        this->next= NULL;
    }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();
        void Enqueue(T);      // InsertLast
        T Dequeue();          // DeleteFirst
        void Display();
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout << "Queue is created succesfully\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void Queue<T> :: Enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;      // this->last = newn;
    }

    this->iCount++;
}

template <class T>
T Queue<T> :: Dequeue()
{
    T Value = 0;

    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    
    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }
    
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | - ";
        temp = temp->next;
    }

    cout << "\n";
}

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////// End of Library ////////////////////////////////////////////

int main()
{
    return 0;
}