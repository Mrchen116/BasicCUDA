#include<pybind11/pybind11.h>
#include <pybind11/stl.h>  // 用于自动处理 STL 容器的包含文件
#include<vector>

template<typename T> 
std::vector<T> add(std::vector<T> &a) {
    for(T &i : a) {
        i += 1;
    }
    return a;
}

PYBIND11_MODULE(myexample, m) {
    m.doc() = "pybind11 example plugin";
    // 为 int 和 double 类型的 vector 实例化模板函数
    m.def("add_int", &add<int>, "A function which adds one to each element of an int list");
    m.def("add_double", &add<double>, "A function which adds one to each element of a double list");
}
// c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example.cpp -o myexample`python3-config --extension-suffix`
// 编译，注意PYBIND11_MODULE里写的名字要和编译中的输出名字保持一致。