#ifndef AV_H
#define AV_H

#include <vector>
#include <algorithm>

template <typename T, typename Y>
class AV {

public:

	using key_type = T;
	using mapped_type = Y;
	using value_type = std::pair<T, Y>;
	using iterator = typename std::vector<value_type>::iterator;

	iterator begin() {return v.begin(); }
	iterator end() {return v.end(); }

	// Constructor
	AV(){}
	
	// Deconstructor
	~AV(){}
	
	void insert(const value_type& val);
	iterator find(const key_type& K);

private:
	std::vector<value_type> v;
};

template<typename T, typename Y>
void AV<T,Y>::insert(const value_type& val) {
	v.push_back(val);
}

template<typename T, typename Y>
typename AV<T,Y>::iterator AV<T,Y>::find(const key_type& K) {
	for (auto it = v.begin(); it != v.end(); it++) {
		if (it->first == K) {
			return it;
		}
	} return v.end();
}

#endif
