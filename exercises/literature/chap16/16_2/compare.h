#ifndef COMPARE_H
#define COMPARE_H

template <typename T1, typename T2>
class compare{
	public:
		compare()=default;
		bool cmpr(const T1 &a,const T2 &b){
			return a > b;
		}
};

#endif
