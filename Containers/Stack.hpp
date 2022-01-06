#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft {

	template <class T, class Container = vector<T> >
	class stack
	{
		public:
		    typedef T			value_type;
		    typedef Container	container_type;
		    typedef size_t		size_type;

		protected:
		    container_type c;

		public:
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}
			~stack() {}
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push (const value_type& val) { c.push_back(val); }
			void pop() { c.pop_back(); }

		/* Let the operator functions acceed to the c protected attribute.
		It is needed to avoid the use non public member classes.
		To let all the overloaded operators work well.
		-> c is the sub jacent container */
		template <class A, class B>
		friend bool operator==(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool operator!=(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool operator<(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool operator<=(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool operator>(const stack<A,B> &lhs, const stack<A,B> &rhs);
		template <class A, class B>
		friend bool operator>=(const stack<A,B> &lhs, const stack<A,B> &rhs);

	};

	template <class T, class Container>
	  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	  {
		  return lhs.c == rhs.c;
	  }

	template <class T, class Container>
	  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	  {
		   return lhs.c != rhs.c;
	  }

	template <class T, class Container>
	  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	  {
		  return lhs.c < rhs.c;
	  }

	template <class T, class Container>
	  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	  {
		  return lhs.c <= rhs.c;
	  }

	template <class T, class Container>
	  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	  {
		  return lhs.c > rhs.c;
	  }

	template <class T, class Container>
	  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	  {
		  return lhs.c >= rhs.c; 
	  }
	
}

#endif