//## begin module%371396580064.cm preserve=no
//## end module%371396580064.cm

//## begin module%371396580064.cp preserve=no
//## end module%371396580064.cp

//## Module: deleters%371396580064; Package specification
//## Subsystem: stdext%371396420276
//## Source file: D:\Dev\Merlin\stdext\deleters.h

#ifndef deleters_h
#define deleters_h 1

//## begin module%371396580064.additionalIncludes preserve=no
//## end module%371396580064.additionalIncludes

//## begin module%371396580064.includes preserve=yes
#include <utility>
//## end module%371396580064.includes

//## begin module%371396580064.declarations preserve=no
//## end module%371396580064.declarations

//## begin module%371396580064.additionalDeclarations preserve=yes
//## end module%371396580064.additionalDeclarations


//## Class: deleter%37137A4903DE; Parameterized Class
//	Function object for deleting containers of pointers.
//## Category: stdext%37137ACC02C6; Global
//## Subsystem: stdext%371396420276
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class T>
class deleter 
{
  public:

    //## Other Operations (specified)
      //## Operation: operator()%924021901
      //	Deletes the pointer p.
      void operator () (T* p);

  protected:
  private:
  private:  //## implementation
};

//## Class: map_deleter%37137B5F0028; Parameterized Class
//	Function object for deleting associative containers
//	whose value types are pointers.
//## Category: stdext%37137ACC02C6; Global
//## Subsystem: stdext%371396420276
//## Persistence: Transient
//## Cardinality/Multiplicity: n

template <class key, class val>
class map_deleter 
{
  public:

    //## Other Operations (specified)
      //## Operation: operator()%924021900
      void operator () (std::pair<key,val*>& arg);

  protected:
  private:
  private:  //## implementation
};

// Parameterized Class deleter 


//## Other Operations (inline)
//## Operation: operator()%924021901
template <class T>
inline void deleter<T>::operator () (T* p)
{
  //## begin deleter::operator()%924021901.body preserve=yes
	if(p) delete p;
  //## end deleter::operator()%924021901.body
}

// Parameterized Class map_deleter 


//## Other Operations (inline)
//## Operation: operator()%924021900
template <class key, class val>
inline void map_deleter<key,val>::operator () (std::pair<key,val*>& arg)
{
  //## begin map_deleter::operator()%924021900.body preserve=yes
	if(arg.second) delete arg.second;
  //## end map_deleter::operator()%924021900.body
}

// Parameterized Class deleter 

// Parameterized Class map_deleter 

//## begin module%371396580064.epilog preserve=yes
//## end module%371396580064.epilog


#endif
