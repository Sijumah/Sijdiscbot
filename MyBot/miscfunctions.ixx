module;


#include <vector>


export module miscfunctions;

void funcname(auto param){};

template <class T>
void delete_and_swap_from_vectors(std::vector<T*>& deleter, std::vector<T*>& reciever){
    reciever.insert(deleter.begin(),deleter.end());
    //delete from old one; this function seems redundant... will investigate
};
