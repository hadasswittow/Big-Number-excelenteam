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
    BigNumber(const BigNumber& other):m_number_vec(other.get_number_vec()),m_sign(other.m_sign){}
    BigNumber(long long num, bool sign=false);
    BigNumber(const bitvector& bv, bool sign=false):m_number_vec(bv),m_sign(sign){};
    bitvector get_number_vec() const;
    bool get_sign_bit()const{return m_sign;}
    bitvector& get_num_by_ref();
    void set_sign_bit(bool sign){m_sign=sign;}
    void twos_complement();
    friend std::ostream &operator<<(std::ostream &os, const BigNumber &bn);

private:
    bitvector m_number_vec;
    bool m_sign;
};
inline void one_complement(bitvector& vec){
    for(size_t i=0;i<vec.size();++i){
        vec.at(i)=255 -vec.at(i);
    }
}
inline bitvector& BigNumber::get_num_by_ref(){
    return m_number_vec;
}
inline void add_one(bitvector& vec){
    bool flag = true;
    unsigned char temp;
    for(int i=0;i<vec.size();++i){
        if(flag){
            temp=vec.at(i);
            vec.at(i)=((temp+flag) % 256);
            flag=temp>255;
        }
        else
            break;
    }
}
inline void BigNumber::twos_complement(){
    one_complement(m_number_vec);
    add_one(m_number_vec);
}
inline BigNumber::BigNumber(long long num, bool sign) {
    for (; num > 0; num /= 256) {
        m_number_vec.push_back(num % 256);
    }
    m_sign = sign;
    if(!m_sign)
        twos_complement();
}

inline bitvector BigNumber::get_number_vec() const {
    return m_number_vec;
}

// ------------------------ operators ----------------------------------
inline std::ostream &operator<<(std::ostream &os, const BigNumber &bn) {
    bitvector temp = bn.get_number_vec();
    os<< bn.m_sign<<" ";
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
    if(flag)
        ans.push_back(1);

    return BigNumber(ans,false);
}
BigNumber operator-(const BigNumber& num){
    BigNumber ans(num);
    ans.twos_complement();
    ans.set_sign_bit(!ans.get_sign_bit());
    return ans;
}


#endif //BIGNUMBERREPRESENTATION_BIGNUMBER_H
