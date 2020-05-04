#include "stos.h"

Stos::Stos(const Stos& rhs): 
_size(rhs._size)
{
    _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane,0);

    Ogniwo* main_stack = _pSzczyt;
    Ogniwo* temp = rhs._pSzczyt;
    while((temp->_p_nastepny) != nullptr)
    {
        temp = temp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(temp->_dane,_pSzczyt->_p_nastepny);
        _pSzczyt = _pSzczyt->_p_nastepny;

    }
    _pSzczyt->_p_nastepny = nullptr;
    _pSzczyt = main_stack;
}

Stos& Stos::operator=(Stos const& rhs)
{
    if(this == &rhs)
        return *this;

    delete [] this->_pSzczyt;
    
    _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane,0);

    Ogniwo* main_stack = _pSzczyt;
    Ogniwo* temp = rhs._pSzczyt;
    
    while(temp->_p_nastepny != nullptr)
    {
        temp = temp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(temp->_dane,_pSzczyt->_p_nastepny);
        _pSzczyt = _pSzczyt->_p_nastepny;
    }
    _pSzczyt->_p_nastepny = nullptr;
    _pSzczyt = main_stack;
    return *this;
}

std::ostream& operator <<(std::ostream & os, const Stos& rhs)
{
    Ogniwo* temp = rhs._pSzczyt;
    while(temp != nullptr)
    {
        os << temp->_dane<<", ";
        temp = temp->_p_nastepny;
    }
    return os;
}
//                                  ---ZADANIE---
void Stos::reverse()
{
    Ogniwo* current = this->_pSzczyt;
    Ogniwo* prev = nullptr;
    Ogniwo* next = nullptr;
    while(current != nullptr)
    {
        next = current->_p_nastepny;
        current->_p_nastepny = prev;
        prev = current;
        current = next;
    }
    this->_pSzczyt = prev;
    return;
}
//                                  ---ZADANIE---
