#ifndef CNODE_HPP
#define CNODE_HPP

#include <iomanip>

using namespace std;

template <typename T>
class CNode
{
private:
    T m_Data;
    CNode* m_Next;
public:
    CNode(T Data = T(), CNode *Next = nullptr): m_Data(Data), m_Next(Next){}

    ~CNode(){
        delete m_Next;
        cout << m_Data << endl;
    }

    void setData(const T &Data){ m_Data = Data;}

    CNode* GetNextNode() const{return m_Next;}

    void SetNextNode(CNode *Next){m_Next = Next;}

    T GetData() const {return m_Data;}
};

#endif // CNODE_HPP


