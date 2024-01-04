/*
 * Overview
 * The ordered associative container std::map and std::multimap associate key with a value. Both are defined in the
 * header <map>. std::set and std::multiset need the header <set>.
 * All four ordered containers are parametrized by their type, their allocator and their comparison function. The
 * containers have default values for the allocators and the comparison function, depending on the type. The declaration
 * of std::map and std::set shows this very nicely.
 *  template <class key, class val, class Comp=less<key>, class Alloc=allocator<pair<const key, val>>
 *  class map;
 *
 *  template <class T, class Comp=less<T>, class Alloc=allocator<T>>
 *  class set;
 *
 * The declaration of both associative containers shows that std::map has an associated value. The key and the values
 * are used for the default allocator: allocator<pair<const key, val>>. std::map has pairs of the type: const key, val.
 * The associated value val doesn't matter for the sort criteria: less<key>. All observations also hold for
 * std::multiset and std::multimap.
 */