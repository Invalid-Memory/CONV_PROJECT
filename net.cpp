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
using std::endl;
using std::fstream;
using std::ios;
using std::hex;
using std::dec;
using std::uppercase;
using std::nouppercase;
using conv::ldouble;
using conv::ldvector;
conv::net::net(string nncfile){  //nnc=nueral network configure
    fstream nncreader,inreader;
    nncreader.open(static_cast<char*>(nncfile),ios::in);
    if(nncreader.is_open()==false){
        std::cout<<"failed to open "<<nncfile<<endl;
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
                n=m;
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
                nncreader>>m;
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
                n=m;
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
ldvector* conv::net::exec(string inputfile){
    fstream inreader;
    inreader.open(static_cast<const char*>(inputfile),ios::in|ios::binary);
    if(inreader.is_open()==false){
        throw -1;
    }
    inreader.seekg(0,ios::end);
    objectlength=inreader.tellg();
    byte* mid=new byte[objectlength]{0};
    inreader.seekg(0,ios::beg);
    inreader.read(mid,objectlength);
    object.clear();
    for(int i=0;i<objectlength;i++){
        object.push_back(static_cast<ldouble>(static_cast<unsigned char>(mid[i])));
        //if(i<objectlength){
        //    std::cout<<static_cast<int>(static_cast<unsigned char>(mid[i]))<<' ';
        //}
    }
    delete[] mid;
    //std::cout<<endl<<'\n';
    inreader.close();
    //std::cout<<endl;
    for(int i=0;i<ly.size();i++){
        ly[i]->process(object);
        std::cout<<1+i<<" process"<<endl;
        //mid1->move(right_ref(*mid2));
       // for(int i=0;i<(mid1->size());i++){
        //   std::cout<</*i<<':'<<*/(*mid1)[i]<<' ';
       // }
       // std::cout<<endl;
        // mid2;
    }
    return &object;
}
