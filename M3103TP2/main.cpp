#include <iostream>

#include "node.hpp"
#include "liste.hpp"

using namespace std;

void ListeSimple (void)
{
    std::cout << "ListeSimple : \n\n";

    CNode<int>* Tete = nullptr;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; ) {
        Tete = new CNode<int> (i++, Tete);
        std::cout << Tete << endl;
    }

    for (CNode<int>* Ptr (Tete); Ptr; Ptr = Ptr->GetNextNode ())
        std::cout << Ptr->GetData() << "; ";

    std::cout << '\n';

    // Dans cette version, le destructeur de C1Link detruit son
    //   suivant donc la destruction de la liste est recursive

    delete Tete;

}// ListeSimple ()



void ListeSimpleV2 ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<int> AList;

    // Le dernier element cree est toujours le premier de la liste

    for (unsigned i (0); i < 5; )
    {
        AList.push_front (i++);
    }

    AList.Show ();

    int i;
    cout << "entrer i" << endl;
    cin >>i;
    CNode<int>* ptr = AList.Find (i);
    AList.Add (3*i, ptr);
    AList.Show ();

    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;

}



int main (){
    ListeSimpleV2();
    return 0;
}
