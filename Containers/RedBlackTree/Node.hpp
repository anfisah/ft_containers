#ifndef UTILS_HPP
#define UTILS_HPP

#include "../../Iterators/iterator.hpp"
#include "../../Iterators/iterator_traits.hpp"
#include "../../Iterators/random_access_iterator.hpp"
#include <iostream>
#include <iterator>

namespace ft
{
	template <class Arg1, class Arg2, class Result>
		struct binary_function {
			typedef	Arg1	first_argument_type;
			typedef	Arg2	second_argument_type;
			typedef	Result	result_type;
		};

	template <class T>
		struct less : public binary_function <T, T, bool>
		{
			bool operator() (const T& x, const T& y) const { return (x < y);}
		};

	enum Color { RED, BLACK, DBLACK };

	template<typename T>
	struct Node
	{
	public:
		typedef T		value_type;
		typedef Color	color_type;

		value_type	value;
		Node*	parent;
		Node*	left;
		Node*	right;
		color_type	color;

		Node() : value(), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}

		Node(const value_type& val, Node* parent = nullptr,
				Node* left = nullptr, Node* right = nullptr, color_type color = RED)
		: value(val), parent(parent), left(left), right(right), color(color) {}

		Node(const Node& other) : value(other.value), parent(other.parent), left(other.left),
			right(other.right), color(other.color) {}

		virtual ~Node() {}

		Node& operator=(const Node& other)
		{
			if (this == &other)
				return (*this);
			this->value = other.value;
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
			this->color = other.color;
			return (*this);
		}

		bool operator==(const Node& other)
		{
			if (this->value == other.value)
				return (true);
			return (false);
		}
		bool operator!=(const Node& other)
		{
			if (this->value != other.value)
				return (true);
			return (false);
		}

	};

	template <class T1, class T2>
		bool operator== (const Node<T1>& lhs, const Node<T2>& rhs)
		{ return lhs == rhs; }

	template <class T1, class T2>
		bool operator!= (const Node<T1>& lhs, const Node<T2>& rhs)
		{ return (lhs != rhs); }

}

#endif