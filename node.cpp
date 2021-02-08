/*--------------------------------------------------------------------------\
|   node.cpp of ConvNeurNet Project---------Student Work                    |
|   Copyleft (C) 2021  丁嘉一                                                |
+                                                                           +
|   This program is free software: you can redistribute it and/or modify    |
|   it under the terms of the GNU General Public License as published by    |
|   the Free Software Foundation, either version 3 of the License, or       |
|   (at your option) any later version.                                     |
+                                                                           +
|   This program is distributed in the hope that it will be useful,         |
|   but WITHOUT ANY WARRANTY; without even the implied warranty of          |
|   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           |
|   GNU General Public License for more details.                            |
+                                                                           +
|   You should have received a copy of the GNU General Public License       |
|   along with this program.  If not, see <https://www.gnu.org/licenses/>.  |
\--------------------------------------------------------------------------*/
#include "neural_node.h"
#include <iostream>
using std::endl;
using conv::ldouble;
conv::node::node(ldvector& wei):data(0),weilen(wei.size()){
    if(wei.size()==0){
        inweight=nullptr;
    }
    else{
        inweight=new ldouble[wei.size()];
        for(int i=0;i<wei.size();i++){
            inweight[i]=wei[i];
        }
    }
}
conv::node::~node(void){
    if(inweight!=nullptr){
        delete[] inweight;
    }
}
ldouble conv::sigmoidnode::activate(ldvector& input){
    if(input.size()!=weilen){
        throw -1;
    }
    ldouble res=0;
    for(int i=0;i<weilen;i++){
        res+=input[i]*inweight[i];
    }
    return sigmoid(res);
}
ldouble conv::relunode::activate(ldvector& input){
    if(input.size()!=weilen){
        std::cout<<input.size()<<"!="<<weilen<<endl;
        throw -1;
    }
    ldouble res=0;
    for(int i=0;i<weilen;i++){
        res+=input[i]*inweight[i];
    }
    return relu(res);
}
ldouble conv::softplusnode::activate(ldvector& input){
    if(input.size()!=weilen){
        std::cout<<"Length Not Equal"<<endl;
        throw -1;
    }
    ldouble res=0;
    for(int i=0;i<weilen;i++){
        res+=input[i]*inweight[i];
    }
    return softplus(res);
}
/*conv::convnode::convnode(void):node(0){
    initweight(data);
    std::cout<<data<<endl;
}
ldouble conv::convnode::activate(obj& input){
    if(input.data.size()!=1){
        throw -1;
    }
    return input.data[0]*data;
}*/
