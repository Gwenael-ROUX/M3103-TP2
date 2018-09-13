#ifndef LISTE_HPP
#define LISTE_HPP

#include <iomanip>

using namespace std;

template <typename T>
class CList
{
private:
    CNode<T>* m_Head;
    CNode<T>* m_tail;
public:
    CList (CNode<T>* Head = nullptr): m_Head(Head){}

    ~CList (){}

   //ajout en tête de liste
    void push_front (const T & val){ m_Head = new CNode<T> (val, m_Head);}

   //affichage
    void Show () const{
        for (CNode<T>* ptr (m_Head); ptr != nullptr; ptr = ptr->GetNextNode ())
                cout << ptr->GetData () << "; ";
    }

    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const{
        CNode<T>* ptr (m_Head);
            for ( ; ptr != nullptr && ptr->GetData () != val; ptr = ptr->GetNextNode ());
            return ptr;
    }

    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>* ptr){
        if (nullptr == ptr) return;
        CNode<T>* ptrTmp = new CNode<T> (val, ptr->GetNextNode ());
        ptr->SetNextNode (ptrTmp);
    }

    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>* pDelete){
        if (!pDelete)return;
        CNode<T>* prec = m_Head;
        if (pDelete == m_Head){
            m_Head = m_Head -> GetNextNode;
            prec -> SetNextNode (nullptr);
            delete prec;
            return;
        }
        CNode<T>* pFind (m_Head);
        for ( ; pFind->GetNextNode () != pDelete; pFind = pFind->GetNextNode ())
        if (pFind->GetNextNode () == nullptr) return;
        pFind->SetNextNode (pDelete->GetNextNode ());
        pDelete->SetNextNode (nullptr);
        delete pDelete;
    }
};

#endif // LISTE_HPP
