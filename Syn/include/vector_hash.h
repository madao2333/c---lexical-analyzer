// vector_hash.h
#ifndef VECTOR_HASH_H
#define VECTOR_HASH_H

#include "V.h"
#include <vector>
#include <functional>

// 自定义哈希函数
struct VectorHash {
    size_t operator()(const std::vector<V>& vVec) const {
        std::hash<V> hasher;
        size_t seed = 0;
        for (auto& v : vVec) {
            seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

#endif // VECTOR_HASH_H