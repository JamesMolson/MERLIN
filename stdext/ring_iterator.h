//## begin module%3AC8795900D2.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\stdext\ring_iterator.h
 * last modified 31/07/01 13:09:44
 */

/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 *
 * Copyright (c) 2000 by The Merlin Collaboration.  
 * ALL RIGHTS RESERVED. 
 *
 * Permission to use, copy, modify, distribute and sell this
 * software and its documentation for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * No representations about the suitability of this software for
 * any purpose is made. It is provided "as is" without express
 * or implied warranty.
 */

#ifndef ring_iterator_h
#define ring_iterator_h 1

#include <iterator>

// template class ring_iterator
// An iterator which cyclicly iterates through a sequence (container).

template<class C, class I>
class ring_iterator {
	private:

		I curr;   // current iterator position 
		C* cont;  // pointer to container

	public:

		typedef typename C::value_type& reference_type;
		typedef typename C::value_type* pointer_type;

		ring_iterator(C& c, I itor)
			: curr(itor),cont(&c) {}
		ring_iterator() {}

		ring_iterator& operator++() {
			if((++curr)==cont->end())
				curr=cont->begin();
			return *this;
		};

		ring_iterator operator++(int) {
			ring_iterator tmp(*this);
			if((++curr)==cont->end())
				curr = cont->begin();
			return tmp;
		};

		ring_iterator& operator--() {
			if(curr==cont->begin())
				curr=cont->end();
			--curr;
			return *this;
		};

		ring_iterator operator--(int) {
			ring_iterator tmp(*this);
			if(curr==cont->begin())
				curr=cont->end();
			--curr;
			return tmp;
		};

		bool operator==(const ring_iterator<C,I>& rhs) const {
			return curr == rhs.curr;
		}

		bool operator!=(const ring_iterator<C,I>& rhs) const {
			return curr != rhs.curr;
		}

		bool operator==(const I& rhs) const {
			return curr == rhs;
		}

		bool operator!=(const I& rhs) const {
			return curr != rhs;
		}

		reference_type operator*() {
			return *curr;
		}

		pointer_type operator->() {
			return &*curr;
		}
};

template <class C, class I>
inline ring_iterator<C,I> make_ring_iterator(C& cont, I& iter)
{
  return ring_iterator<C,I>(cont,iter);
}

template <class C>
inline ring_iterator<C,typename C::iterator> make_ring_iterator(C& cont)
{
  return ring_iterator<C,typename C::iterator>(cont,cont.begin());
}

#endif

