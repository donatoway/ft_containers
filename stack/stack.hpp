#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <fstream>
#include <list>
#include <stack>

#include "../vector/vector.hpp"
#include "../map/map.hpp"

namespace ft
{
	template <typename T, typename container=ft::vector<T> >
	class stack 
	{
		public:	
			typedef T			value_type;
			typedef container	container_type;
			typedef size_t		size_type;
		
		protected:
			container _stack;

		public:
			explicit stack (const container_type& ctnr = container_type())
			:	_stack(ctnr) {}
			
			stack(stack const &src)
			{
				_stack = src._stack;		
			}	

			stack &operator=(stack const &src)
			{
				_stack = src._stack;
				return *this;
			}

			~stack() {}

			bool empty() const
			{
				return _stack.empty();
			}

			size_type size() const
			{
				return _stack.size();
			}

			value_type &top()
			{
				return _stack.back();
			}

			const value_type &top() const
			{
				return _stack.back();
			}

			void push (const value_type& val)
			{
				_stack.push_back(val);
			}
			
			void pop()
			{
				_stack.pop_back();				
			}
 			
			friend bool operator==( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._stack == rhs._stack);}
			friend bool operator!=( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._stack != rhs._stack);}
			friend bool operator>=( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._stack >= rhs._stack);}
			friend bool operator>( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._stack > rhs._stack);}
			friend bool operator<=( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._stack <= rhs._stack);}
			friend bool operator<( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._stack < rhs._stack);}												
	};
} 


#endif