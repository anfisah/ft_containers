#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../Iterators/iterator.hpp"
#include "../Iterators/random_access_iterator.hpp"
#include "../Iterators/reverse_iterator.hpp"
#include "../Iterators/Others.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T 												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference 				reference;
			typedef typename allocator_type::const_reference 		const_reference;
			typedef typename allocator_type::pointer 				pointer;
			typedef typename allocator_type::const_pointer 			const_pointer;
			typedef typename ft::random_access_iterator<T>			iterator;
			typedef typename ft::random_access_iterator<const T> 	const_iterator;
			typedef typename ft::reverse_iterator<iterator> 		reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> 	const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t					 						size_type;

		private:
			pointer 		_array;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()) 
			: _array(nullptr), _alloc(alloc), _size(0), _capacity(0) {}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0)
			{
				_array = _alloc.allocate(0);
				this->assign(first, last);
			}

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n)
			{
				_array = _alloc.allocate(n);
				for(size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], val);
			}
			vector(const vector& x)
			{
				_size = x._size;
    			_capacity = x._capacity;
				_alloc = x._alloc;
   				_array = _alloc.allocate(_size, &x._array);
    			for (size_type i = 0; i < _size; i++)
    	    		_alloc.construct(&_array[i], x._array[i]);
			}
			~vector(void)
			{
				_alloc.deallocate(_array, _size);
			}
			vector &operator=(const vector& x)
			{
				if (this == &x)
					return (*this);
				if (_array != nullptr)
					_alloc.deallocate(_array, _size);
				_size = x._size;
    			_capacity = x._capacity;
				_alloc = x._alloc;
   				_array = _alloc.allocate(_size, &x._array);
    			for (size_type i = 0; i < _size; i++)
    	    		_alloc.construct(&_array[i], x._array[i]);
				return *this;
			}

			iterator begin() { return iterator(&_array[0]); }
			const_iterator begin() const { return const_iterator(&_array[0]); }
			iterator end() { return iterator(&_array[_size]); }
			const_iterator end() const {return const_iterator(&_array[_size]);}
			
			reverse_iterator rbegin() { return reverse_iterator(this->end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
			reverse_iterator rend() { return reverse_iterator(this->begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

			size_type size() const { return _size;}
			size_type max_size() const { return _alloc.max_size(); }
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type i = n; i < _size; i++)
					{
						_alloc.destroy(&_array[i]);
					}
				} else if (n > _size && n > _capacity)
				{
					value_type *new_array = _alloc.allocate(n, &_array);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&new_array[i], _array[i]);
					_alloc.deallocate(_array, _size);
					_array = new_array;
					_capacity = n;
					for (size_type y = _size; y < n; y++) {
						_alloc.construct(&_array[y], val);
						_size++;
					}
				}
				_size = n;
			}

			size_type capacity() const { return _capacity; }
			bool empty() const 
			{
				if (_size == 0)
					return true;
				else
					return false;
			}
			void reserve(size_type n)
			{
   				if (n > _capacity)
   				{
					 T *new_array = _alloc.allocate(n, &_array);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&new_array[i], _array[i]);
					_alloc.deallocate(_array, _size);
					_array = new_array;
					_capacity = n;
				}
			}
			reference operator[](size_type n)
			{
				reference elem_ref = *(_array + n);
				return elem_ref;
			}
			const_reference operator[](size_type n) const
			{
				const_reference elem_ref = *(_array + n);
				return elem_ref;
			}
			reference at(size_type n) 
			{ 
				if (n >= _size) 
					throw std::out_of_range("Out of range");
				reference elem_ref = *(_array + n);
				return elem_ref;
			}
			const_reference at(size_type n) const
			{ 
				if (n >= this->size()) 
					throw std::out_of_range ("Out of range");
				const_reference elem_ref = *(_array + n);
				return elem_ref;
			}
			reference front() {return reference(_array[0]);}
			const_reference front() const {return const_reference(_array[0]);}
			reference back() { return reference(_array[_size - 1]); }
			const_reference back() const { return const_reference(_array[_size - 1]); }

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				this->clear();
				this->insert(this->begin(), first, last);
			}
			void assign(size_type n, const value_type& val)
			{
				this->clear();
				this->insert(this->begin(), n, val);
			}

			void push_back(const value_type& val)
			{
				if (_size + 1 > _capacity)
				{
					T *new_array = _alloc.allocate(_size + 1, &_array);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&new_array[i], _array[i]);
					_alloc.deallocate(_array, _size);
					_array = new_array;
					_capacity = _size + 1;
				}
				_alloc.construct(&_array[_size], val);
				_size += 1;
			}
			void pop_back() 
			{ 
				_alloc.destroy(&_array[_size - 1]);
				_size--;
			}
			iterator insert (iterator position, const value_type& val) 
			{
				difference_type idx = position - this->begin();

				this->insert(position, 1, val);
				return (iterator(this->begin() + idx));
			}
			void insert (iterator position, size_type n, const value_type& val)
			{

				difference_type const	idx = position - this->begin();
				difference_type const	old_end_idx = this->end() - this->begin();
				iterator				old_end, end;

				this->resize(this->_size + n);

				end = this->end();
				position = this->begin() + idx;
				old_end = this->begin() + old_end_idx;
				while (old_end != position)
					*--end = *--old_end;
				while (n-- > 0)
					*position++ = val;
			}
			template <class InputIterator>
			size_t	itlen(InputIterator first, InputIterator last) {
			size_t	i = 0;

			while (first != last)
			{
				++first;
				++i;
			}
			return (i);
			}
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = NULL)
			{
				difference_type const	idx = position - this->begin();
				difference_type const	old_end_idx = this->end() - this->begin();
				iterator				old_end, end;
				this->resize(this->_size + (itlen(first, last)));
				end = this->end();
				position = this->begin() + idx;
				old_end = this->begin() + old_end_idx;
				while (old_end != position)
					*--end = *--old_end;
				while (first != last)
					*position++ = *first++;
			}

			iterator erase (iterator position) {
				size_type pos = position - this->begin();
				_alloc.destroy(&_array[pos]);
				for (size_type i = pos; i < _size; i++)
				{
					_alloc.construct(&_array[i], _array[i + 1]);
					_alloc.destroy(&_array[i + 1]);
				}
				_size--;
				return this->begin() + pos;
			}

			iterator erase (iterator first, iterator last)
			{
				size_type pos = first - this->begin();
				size_type n = last - first;
				for (size_type i = 0; i < n; i++)
					_alloc.destroy(&_array[pos + i]);
				for (size_type i = pos; i < _size; i++)
				{
					_alloc.construct(&_array[i], _array[i + n]);
					_alloc.destroy(&_array[i + n]);
				}
				_size -= n;
				return begin() + pos;
			}
			void swap (vector& x)
			{
				size_type		sizeTemp = x._size;
				size_type		capTemp = x._capacity;
				allocator_type	allocTemp = x._alloc;
				pointer			arrayTemp = x._array;

				x._size = _size;
				x._capacity = _capacity;
				x._alloc = _alloc;
				x._array = _array;
				
				_size = sizeTemp;
				_capacity = capTemp;
				_alloc = allocTemp;
				_array = arrayTemp;
			}
			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				_size = 0;
			}

			allocator_type get_allocator() const
			{
				return this->_alloc;
			}
		};

		template <class T, class Alloc>
			bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				if (lhs.size() == rhs.size())
					return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
				return false;
			}

		template <class T, class Alloc>
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
			   return !(lhs == rhs);
			}
		template <class T, class Alloc>
			bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
		template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
			  return !(rhs < lhs);
			}
		template <class T, class Alloc>
		 	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		 	{
				return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
		 	}
		template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
			  return !(lhs < rhs);
			}
		template <class T, class Alloc>
  			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
			{
				x.swap(y);
			}
		
}

#endif