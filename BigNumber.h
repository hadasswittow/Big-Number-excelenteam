//
// Created by hadasswittow on 11/27/19.
//

#ifndef BIGNUMBERREPRESENTATION_BIGNUMBER_H
#define BIGNUMBERREPRESENTATION_BIGNUMBER_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <bitset>

typedef std::vector<unsigned char> bitvector;

class BigNumber {
public:
    BigNumber(long long num);
    BigNumber(const bitvector& bv):m_number_vec(bv){};
    bitvector get_number_vec() const;

    friend std::ostream &operator<<(std::ostream &os, const BigNumber &bn);

private:
    bitvector m_number_vec;
};

inline BigNumber::BigNumber(long long num) {
    for (; num > 0; num /= 256) {
        m_number_vec.push_back(num % 256);
    }
}

inline bitvector BigNumber::get_number_vec() const {
    return m_number_vec;
}

// ------------------------ operators ----------------------------------
inline std::ostream &operator<<(std::ostream &os, const BigNumber &bn) {
    bitvector temp = bn.get_number_vec();
    for (bitvector::const_reverse_iterator it = temp.rbegin(); it != temp.rend(); ++it) {
        os << std::bitset<8>(+*it);
    }
    os << '\n';
    return os;
}

inline BigNumber operator+(const BigNumber &bn1, const BigNumber &bn2) {
    bitvector ans;
    short temp;
    bool flag = false;
    bitvector vec_num1 = bn1.get_number_vec();
    bitvector vec_num2 = bn2.get_number_vec();
    size_t size = std::min(vec_num1.size(), vec_num2.size());
    for (size_t i = 0; i < size; ++i) {
        temp = vec_num1.at(i) + vec_num2.at(i);
        ans.push_back((temp+flag) % 256);
        flag=temp>255;
    }
    if (vec_num1.size() > vec_num2.size()) {
        for (size_t i = size; i < vec_num1.size(); ++i) {
            ans.push_back((vec_num1.at(i)+flag) % 256);
            flag=vec_num1.at(i)>255;
        }
    }
    else{
        for (size_t i = size; i < vec_num2.size(); ++i) {
            ans.push_back((vec_num2.at(i)+flag) % 256);
            flag= vec_num2.at(i)>255;
        }
    }
    return BigNumber(ans);
}



#endif //BIGNUMBERREPRESENTATION_BIGNUMBER_H
