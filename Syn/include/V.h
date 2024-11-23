
#ifndef UNTITLED1_V_H
#define UNTITLED1_V_H

#include <iostream>
#include <functional>

class V {
    private:
        std::string lexeme;
    public:
        V() = default;
        V(std::string lexeme);
        std::string getLexeme() const;      

        bool operator==(const V& other) const;
};

namespace std {
template <> struct hash<V> {
  size_t operator()(const V &v) const {
    return std::hash<std::string>()(v.getLexeme());
  }
};
} // namespace std

#endif //UNTITLED1_V_H