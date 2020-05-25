#include "stos.h"

//                                  ---ZADANIE---
Stos::Stos(const Stos& rhs): 
_size(rhs._size)
{
    if(rhs.empty())
    {
        _pSzczyt = nullptr;
        _size = 0;
        return;
    }

    _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane,nullptr);

    Ogniwo* main_stack = _pSzczyt;
    Ogniwo* temp = rhs._pSzczyt;
    while((temp->_p_nastepny) != nullptr)
    {
        temp = temp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(temp->_dane,_pSzczyt->_p_nastepny);
        _pSzczyt = _pSzczyt->_p_nastepny;
    }
    _pSzczyt = main_stack;
}

Stos& Stos::operator=(Stos const& rhs)
{
    if(this == &rhs)
        return *this;

    delete _pSzczyt;
    
    if(rhs.empty())
    {
        _pSzczyt = nullptr;
        _size = 0;
    }
    else
    {
        _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane,nullptr);

        Ogniwo* main_stack = _pSzczyt;
        Ogniwo* temp = rhs._pSzczyt;
    
        while(temp->_p_nastepny != nullptr)
        {
            temp = temp->_p_nastepny;
            _pSzczyt->_p_nastepny = new Ogniwo(temp->_dane,_pSzczyt->_p_nastepny);
            _pSzczyt = _pSzczyt->_p_nastepny;
        }
        _pSzczyt = main_stack;
    }
    return *this;
}

//                                  ---ZADANIE---