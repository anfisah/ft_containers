#include "../Containers/Map.hpp"
#include <string>
#include <iostream>
#include <map>

#define PURPLE "\e[36m"
#define GREEN "\e[34m"
#define REDD "\e[32;1m"
#define RESET "\e[0m"

void map_constructors()
{
	std::cout << REDD << "DEFAULT CONSTRUCTOR" << std::endl;
	ft::map<char, int> m1;
	std::map<char, int> m2;
	std::cout << RESET << "constructed" << std::endl;

	std::cout << REDD << "COPY CONSTRUCTOR" << std::endl;

	ft::map<char, int> mit;
	mit.insert(ft::make_pair('a', 1));
	mit.insert(ft::make_pair('c', 13));
	mit.insert(ft::make_pair('j', 3));

	ft::map<char, int> new_mit(mit);
	std::cout << PURPLE << new_mit['a'] << ' ' << new_mit['c'] << ' ' << new_mit['j'] << "  - ft" << std::endl;

	std::map<char, int> mit2;
	mit2.insert(std::make_pair('a', 1));
	mit2.insert(std::make_pair('c', 13));
	mit2.insert(std::make_pair('j', 3));

	std::map<char, int> new_mit2(mit2);
	std::cout << GREEN << new_mit2['a'] << ' ' << new_mit2['c'] << ' ' << new_mit2['j'] << "  - std" << std::endl;

	std::cout << REDD << "FILL CONSTRUCTOR" << std::endl;

	ft::map<char, int> f1(mit.begin(), mit.end());
	std::map<char, int> f2(mit2.begin(), mit2.end());
	std::cout << PURPLE << f1['a'] << ' ' << f1['c'] << ' ' << f1['j'] << "  - ft" << std::endl;
	std::cout << GREEN << f2['a'] << ' ' << f2['c'] << ' ' << f2['j'] << "  - std" << std::endl;

	std::cout << REDD << "OPERATOR =" << std::endl;

	ft::map<char, int> o1 = f1;
	std::map<char, int> o2 = f2;
	std::cout << PURPLE << o1['a'] << ' ' << o1['c'] << ' ' << o1['j'] << "  - ft" << std::endl;
	std::cout << GREEN << o2['a'] << ' ' << o2['c'] << ' ' << o2['j'] << "  - std" << std::endl;
	std:: cout << std::endl;
}

void map_iterator()
{
	ft::map<char, int> m1;
	std::map<char, int> m2;

	for (int i = 65; i < 85; i++)
		m1.insert(ft::make_pair(i, 1));

	for (int i = 65; i < 85; i++)
		m2.insert(std::make_pair(i, 1));

	ft::map<char, int>::iterator it = m1.begin();
	ft::map<char, int>::const_iterator cit = ++m1.begin();
	ft::map<char, int>::reverse_iterator rit = m1.rbegin();
	ft::map<char, int>::const_reverse_iterator crit = ++m1.rbegin();

	std::map<char, int>::iterator it2 = m2.begin();
	std::map<char, int>::const_iterator cit2 = ++m2.begin();
	std::map<char, int>::reverse_iterator rit2 = m2.rbegin();
	std::map<char, int>::const_reverse_iterator crit2 = ++m2.rbegin();

	std::cout << REDD << "ITERATORS" << std::endl;
	while (it != m1.end())
		std::cout << PURPLE << it++->first << ' ';
	std::cout << " - ft" << std::endl;

	while (it2 != m2.end())
		std::cout << GREEN << it2++->first << ' ';
	std::cout << " - std" << std::endl;

	std::cout << REDD << "CONST ITERATORS" << std::endl;
	std::cout << PURPLE << "const it : " << cit->first << "  - ft" << std::endl;
	std::cout << GREEN << "const it : " << cit2->first << "  - std" << std::endl;

	std::cout << REDD << "REVERSE ITERATORS" << std::endl;
	while (rit != m1.rend())
		std::cout << PURPLE << rit++->first << ' ';
	std::cout << " - ft" << std::endl;

	while (rit2 != m2.rend())
		std::cout << GREEN << rit2++->first << ' ';
	std::cout << " - std" << std::endl;

	std::cout << REDD << "CONST REVERSE ITERATORS" << std::endl;
	std::cout << PURPLE << "const rev it : " << crit->first << "  - ft" << std::endl;
	std::cout << GREEN << "const rev it : " << crit2->first << "  - std" << std::endl;
	
	std::cout << std::endl;
}

void map_capacity()
{
	std::cout << REDD << "CAPACITY" << std::endl;

	ft::map<std::string, char> tab;
	
	tab.insert(ft::make_pair("hey", 'A'));
	tab.insert(ft::make_pair("kk", 'D'));
	tab.insert(ft::make_pair("lol", 'K'));

	std::map<std::string, char> tab2;
	
	tab2.insert(std::make_pair("hey", 'A'));
	tab2.insert(std::make_pair("kk", 'D'));
	tab2.insert(std::make_pair("lol", 'K'));

	std::cout << PURPLE << "size : " << tab.size() << "  - ft" << std::endl;
	std::cout << GREEN << "size : " << tab2.size() << "  - std" << std::endl;

	std::cout << PURPLE << "empty : " << tab.empty() << "  - ft" << std::endl;
	std::cout << GREEN << "empty : " << tab2.empty() << "  - std" << std::endl;

	std::cout << std::endl;
}

void map_access()
{
	std::cout << REDD << "ELEMENT ACCESS" << std::endl;
	
	ft::map<std::string, char> tab;
	
	tab.insert(ft::make_pair("hey", 'A'));
	tab.insert(ft::make_pair("kk", 'D'));
	tab.insert(ft::make_pair("lol", 'K'));
	
	std::map<std::string, char> tab2;
	
	tab2.insert(std::make_pair("hey", 'A'));
	tab2.insert(std::make_pair("kk", 'D'));
	tab2.insert(std::make_pair("lol", 'K'));

	std::cout << PURPLE << "tab[\"lol\"] : " << tab["lol"] << "  - ft" << std::endl;
	std::cout << GREEN << "tab[\"lol\"] : " << tab2["lol"] << "  - std" << std::endl;

	std::cout << std::endl;
}

void map_modifiers(int i)
{
	
	if (i == 0)
	{
		std::cout << REDD << "INSERT" << std::endl;
		std::cout << PURPLE;
		std::cout << "ft -" << std::endl;
		ft::map<char,int> mymap;

		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));
		mymap.insert (it, ft::pair<char,int>('c',400));


		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c')); //find operation used

		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}
	else if (i == 1)
	{

		std::cout << GREEN;
		std::cout << "std -" << std::endl;
		std::map<char,int> mymap;

		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));
		mymap.insert (it, std::pair<char,int>('c',400));


		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}
	
}

void map_erase(int i)
{
	if (!i)
	{
		std::cout << REDD << "ERASE" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase(it);

		mymap.erase('c');

		it=mymap.find('e');
		mymap.erase(it, mymap.end() );

		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	else
	{
		std::cout << GREEN << "std -" << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it = mymap.find('b');
		mymap.erase(it);

		mymap.erase('c');

		it = mymap.find('e');
		mymap.erase(it, mymap.end());

		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
}

void map_swap(int i)
{
	if (!i)
	{
		std::cout << REDD << "SWAP" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it = bar.begin(); it !=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	else
	{
		std::cout << GREEN << "std -" << std::endl;
		std::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (std::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (std::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	
}

void map_clear()
{
	std::cout << REDD << "CLEAR" << std::endl;
	ft::map<int, int> tab;

	tab.insert(ft::make_pair(1, 5));
	tab.insert(ft::make_pair(3, 8));
	tab.insert(ft::make_pair(5, 66));
	tab.insert(ft::make_pair(13, 5));

	std::map<int, int> tab2;

	tab2.insert(std::make_pair(1, 5));
	tab2.insert(std::make_pair(3, 8));
	tab2.insert(std::make_pair(5, 66));
	tab2.insert(std::make_pair(13, 5));

	std::cout << PURPLE << tab.size() << "  - ft" << std::endl;
	std::cout << GREEN << tab2.size() << "  - std" << std::endl;
	tab.clear();
	tab2.clear();
	std::cout << PURPLE << "cleared : " << tab.size() << "  - ft" << std::endl;
	std::cout << GREEN << "cleared : " << tab2.size() << "  - std" << std::endl;
}

void map_operations(int i)
{
	if (!i)
	{
		std::cout << REDD << "OPERATIONS" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		//COUNT
		ft::map<char,int> mymap;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
		}
	}
	else
	{
		std::cout << GREEN << "std -" << std::endl;
		//COUNT
		std::map<char,int> mymap;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
		}
	}
}

void map_bound(int i)
{
	//BOUNDS
	if (!i)
	{
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow = mymap.lower_bound('b');
		itup = mymap.upper_bound('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);

		for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	else if (i == 1)
	{
		std::cout << GREEN << "std -" << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow = mymap.lower_bound('b');
		itup = mymap.upper_bound('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);

		for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	else if (i == 2)
	{
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	else if (i == 3)
	{
		std::cout << GREEN << "std -" << std::endl;
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::pair<std::map<char,int>::iterator, std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
}

void map_operators(int i)
{
	if (!i)
	{
		std::cout << REDD << "OPERATIONS" << std::endl;
		std::cout << PURPLE << "ft -" << std::endl;
		ft::map<int, char> alice;
		ft::map<int, char> bob;
		ft::map<int, char> eve;

		alice.insert(ft::make_pair(1, 'a'));
		alice.insert(ft::make_pair(2, 'b'));
		alice.insert(ft::make_pair(3, 'c'));

		bob.insert(ft::make_pair(7, 'Z'));
		bob.insert(ft::make_pair(8, 'Y'));
		bob.insert(ft::make_pair(9, 'X'));
		bob.insert(ft::make_pair(10, 'W'));
 
		eve.insert(ft::make_pair(1, 'a'));
		eve.insert(ft::make_pair(2, 'b'));
		eve.insert(ft::make_pair(3, 'c'));
 
		std::cout << std::boolalpha;
 
		std::cout << "alice == bob returns " << (alice == bob) << '\n';
		std::cout << "alice != bob returns " << (alice != bob) << '\n';
		std::cout << "alice <  bob returns " << (alice < bob) << '\n';
		std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
		std::cout << "alice >  bob returns " << (alice > bob) << '\n';
		std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
		std::cout << '\n';

		std::cout << "alice == eve returns " << (alice == eve) << '\n';
		std::cout << "alice != eve returns " << (alice != eve) << '\n';
		std::cout << "alice <  eve returns " << (alice < eve) << '\n';
		std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
		std::cout << "alice >  eve returns " << (alice > eve) << '\n';
		std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	}
	else
	{
		std::cout << GREEN << "std -" << std::endl;
		std::map<int, char> alice;
		std::map<int, char> bob;
		std::map<int, char> eve;

		alice.insert(std::make_pair(1, 'a'));
		alice.insert(std::make_pair(2, 'b'));
		alice.insert(std::make_pair(3, 'c'));

		bob.insert(std::make_pair(7, 'Z'));
		bob.insert(std::make_pair(8, 'Y'));
		bob.insert(std::make_pair(9, 'X'));
		bob.insert(std::make_pair(10, 'W'));
 
		eve.insert(std::make_pair(1, 'a'));
		eve.insert(std::make_pair(2, 'b'));
		eve.insert(std::make_pair(3, 'c'));
 
		std::cout << std::boolalpha;
 
		std::cout << "alice == bob returns " << (alice == bob) << '\n';
		std::cout << "alice != bob returns " << (alice != bob) << '\n';
		std::cout << "alice <  bob returns " << (alice < bob) << '\n';
		std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
		std::cout << "alice >  bob returns " << (alice > bob) << '\n';
		std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
		std::cout << '\n';

		std::cout << "alice == eve returns " << (alice == eve) << '\n';
		std::cout << "alice != eve returns " << (alice != eve) << '\n';
		std::cout << "alice <  eve returns " << (alice < eve) << '\n';
		std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
		std::cout << "alice >  eve returns " << (alice > eve) << '\n';
		std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	}
}

void map_test()
{
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << RESET << "\nmap TEST" << std::endl << std::endl;
	map_constructors();
	map_iterator();
	map_capacity();
	map_access();
	map_modifiers(0);
	map_modifiers(1);
	map_erase(0);
	map_erase(1);
	map_swap(0);
	map_swap(1);
	map_clear();
	map_operations(0);
	map_operations(1);
	map_bound(0);
	map_bound(1);
	map_bound(2);
	map_bound(3);
	map_operators(0);
	map_operators(1);
	std::cout << "--------------------------------------------------------------------" << std::endl;
}

int main(void)
{
	map_test();
	return 0;
}