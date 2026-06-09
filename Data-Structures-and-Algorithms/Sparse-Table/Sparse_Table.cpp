#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
#include<numeric>

std::vector<size_t> buildLogTable(size_t n){
    std::vector<size_t> log_table(n+1,0);

    for(size_t i = 2; i <= n; ++i){
        log_table[i] = log_table[i/2] + 1;
    }

    return log_table;
}

template<typename T>
std::vector<std::vector<T>> buildSparseTable(const std::vector<T>& arr, const std::function<T(const T&, const T&)>& op){
    size_t len = arr.size();
    if(!len){
        return {};
    }

    size_t max_log = 0;

    while((1 << max_log) <= len){
        max_log++;
    }

    std::vector<std::vector<T>> SparseTable(len, std::vector<T>(max_log));

    for(size_t i = 0; i < len; ++i){
        SparseTable[i][0] = arr[i];
    }

    for(size_t j = 1; j < max_log; ++j){
        for(size_t i = 0; i + (1 << j) < len; ++i){
            SparseTable[i][j] = op(SparseTable[i][j - 1], SparseTable[i + (1 << (j-1) )][j - 1]);
        }
    }

    return SparseTable;
}

template<typename T>
T query(size_t left, size_t right, const std::vector<std::vector<T>>& SparseTable, const std::vector<size_t>& log_table, const std::function<T(const T&, const T&)>& op){
    size_t len = log_table[right - left + 1];

    return op(SparseTable[left][len], SparseTable[right - (1 << len) + 1][len]);
}



int main(){

    std::function<size_t(const size_t&, const size_t&)> max_op = [](size_t x, size_t y)-> size_t{return std::max(x,y);};

    std::vector<size_t> arr {7,2,3,1,8,5,10,3,12,18};
    std::vector<std::vector<size_t>> SparseTable = buildSparseTable<size_t>(arr, max_op);
    std::vector<size_t> log_table = buildLogTable(arr.size());

    std::cout << query(1, 7, SparseTable, log_table, max_op);

    return 0;
}
