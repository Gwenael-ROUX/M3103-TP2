#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

template <typename T>
CNode<T>* CList<T>::Begin () const
{
    return m_Head /*-> GetNextNode ()*/;
}

template <typename T>
void CList<T>::AddAfter (CNode<T>* ptr, const T & val)
{
    ptr -> SetNextNode (new CNode<T> (val, ptr-> GetNextNode()));
}
/*Ptr_t AjoutApres (Ptr_t Tete, int NewVal, Ptr_t PtrElem)
{
    if (! PtrElem) PtrElem = Tete;

    PtrElem->SetSuivant
           (new C1Link (NewVal, PtrElem->GetSuivant()));

    return PtrElem->GetSuivant();

} // AjoutApres()
*/

template <typename T>
CList<T>::CList () : m_Head (new CNode<T> ()), m_Queue (m_Head) {};

template <typename T>
CList<T>::~CList () {
    delete m_Head;
}

template <typename T>
CNode<T>* CList<T>::Find (const T & val) const
{
    CNode<T>* Ptr (m_Head);
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());

    return Ptr;
}

template <typename T>
void CList<T>::Add (const T & val, CNode<T>* ptr)
{
    if (ptr != nullptr)
    {
        CNode<T>* ptrTmp = new CNode<T> (val, ptr -> GetNextNode ());
        ptr -> SetNextNode (ptrTmp);
    }
    else
        m_Head = new CNode<T> (val, m_Head);
}

template <typename T>
void CList<T>::push_front (const T & val)
{
    m_Head = new CNode<T> (val, m_Head);
    if (m_Queue == nullptr) m_Queue = m_Head;
}

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (CNode<T>* Ptr (m_Head -> GetNextNode()); Ptr; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (CNode<T>* pDelete)
{
    CNode<T>* pFind (m_Head);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());

    pFind -> SetNextNode (pDelete -> GetNextNode ());
    pDelete -> SetNextNode (nullptr);

    delete pDelete;
}

template <typename T>
void CList<T>::push_back (const T & val)
{
    CNode<T>* pTmp = new CNode<T> (val, NULL);
    m_Queue -> SetNextNode (pTmp);
    m_Queue = pTmp;
}
#endif // LIST_HPP
