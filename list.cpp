#include "list.h"
#include "my_data.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------

    first(L) = NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------

    P = new elmlist;

    info(P).ID = x.ID;
    info(P).Name = x.Name;
    info(P).Rank = x.Rank;
    info(P).score = x.score;
    next(P) = NULL;

    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------

    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------

    if (first(L) != NULL)
    {
        cout << "test1";
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        cout << "test2";
        first(L) = P;
    }

    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------

    if (first(L) != NULL)
    {
        address Q = first(L);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
    else
    {
        insertFirst(L,P);
    }

    //----------------------------------------
}

address findElm(List L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */

    address P;
    //-------------your code here-------------

    P = first(L);
    while (next(P) != NULL && info(P).ID != x.ID)
    {
        P = next(P);
    }

    if (info(P).ID != x.ID)
    {
        return NULL;
    }

    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------

    P = first(L);
    first(L) = next(P);
    next(P) = NULL;

    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    address Q = first(L);
    while (next(next(Q)) != NULL)
    {
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = NULL;

    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------

    address P = first(L);

    if (first(L) != NULL)
    {
        cout<<"== DATA =="<<endl;
        while (P != NULL)
        {
            cout<<info(P).ID<<"  "<<info(P).Name<<"  ";
            cout<<info(P).Rank<<"  "<<info(P).score<<endl;
            P = next(P);
        }
    }
    else
    {
        cout<<"[empty]"<<endl;
    }

    //----------------------------------------
}


void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------

    if (next(Prec) != NULL)
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
    else
    {
        insertLast(L,P);
    }

    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
    if (next(Prec) != NULL)
    {
        P = next(Prec);
        if (next(P) != NULL)
        {
            next(Prec) = next(P);
            next(P) = NULL;
        }
        else
        {
            next(Prec) = NULL;
        }
    }

    //----------------------------------------
}

