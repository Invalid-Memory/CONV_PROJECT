/*--------------------------------------------------------------------------\
|   net.cpp of ConvNeurNet Project---------Student Work                     |
|   Copyright (C) 2021  丁嘉一                                               |
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
#include <fstream>
#include <iostream>
#include "net.h"
using std::fstream;
using std::ios;
using std::endl;
using std::hex;
using std::dec;
using std::uppercase;
using std::nouppercase;
using conv::ldouble;
using conv::ldvector;
conv::net::net(string nncfile){  //nnc=nueral network configure
    fstream nncreader;
    nncreader.open(static_cast<char*>(nncfile),ios::in);
    if(nncreader.is_open()==false){
        std::cerr<<"failed to open "<<nncfile<<endl;
        throw -1;
    }
    string id;
    char equ;
    string val;
    nncreader>>id;
    if(id!="lyer"){
        throw -1;
    }
    nncreader>>equ;
    if(equ!='='){
        throw -1;
    }
    nncreader>>layernum;
    int m;
    int n;
    vector<ldvector> wei;
    for(int i=0;i<layernum;i++){
        nncreader>>val;
            if(val=="conv"){
                wei.clear();
                wei.push_back();
                nncreader>>m;
                ldouble midw;
                for(int i=0;i<m;i++){
                    nncreader>>midw;
                    wei[0].push_back(midw);
                }
                ly.push_back(new convlayer(wei[0]));
                n=m;
            }
            else if(val=="pool"){
                nncreader>>m;
                ly.push_back(new poolayer(m));
                //n=m;
            }
            else if(val=="depth"){
                wei.clear();
                dpnt type=dnone;
                m=0;
                nncreader>>id;
                if(id=="softmax"){
                    type=dsoftmax;
                }
                else if(id=="relu"){
                    type=drelu;
                }
                else if(id=="sigmoid"){
                    type=dsigmoid;
                }
                else if(id=="softplus"){
                    type=dsoftplus;
                }
                else{
                    throw -1;
                }
                nncreader>>n>>m;
                std::cout<<m<<endl;
                ldouble midw;
                for(int i=0;i<m;i++){
                    wei.push_back();
                    for(int j=0;j<n;j++){
                        nncreader>>midw;
                        wei[i].push_back(midw);
                    }
                }
                ly.push_back(new depthlayer(type,wei));
               // n=m;
            }
            else{
                throw -1;
            }
        }
    //delete[] nm;
    nncreader.close();
    std::cout<<"Net Construction"<<endl;
}
conv::net::~net(void){
    for(int i=0;i<ly.size();i++){
        delete ly[i];
    }
}
ldvector* conv::net::exec(void){
    for(int i=0;i<ly.size();i++){
        ly[i]->process(object);
    }
    return &object;
}
