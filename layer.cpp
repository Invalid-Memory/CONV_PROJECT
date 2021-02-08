/*--------------------------------------------------------------------------\
|   layer.cpp of ConvNeurNet Project---------Student Work                   |
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
#include <thread>
//#include <mutex>
//#include <condition_variable>
#include <iostream>
#include <cmath>
#include "layer.h"
using    std::endl                        ;
using    conv::convlayer                  ;
using    conv::ldouble                    ;
using    conv::ldvector                        ;
//using  std::thread                      ;
//using  std::mutex                       ;
//using  std::lock_guard                  ;
//using  std::unique_lock                 ;
//using  std::condition_variable          ;
//static mutex                   lock     ;
//static unique_lock<mutex>      ul(lock) ;
//static condition_variable      cvconv   ;
//static condition_variable      cvdepth  ;
conv::layer::~layer(void){
    for(int i=0;i<lay.size();i++){
        delete lay[i];
    }
}
conv::convlayer::convlayer(int n1):layer(n1,conv){
    for(int i=0;i<n1;i++){
        weight.push_back(0);
        initweight(weight[i]);
    }
    std::cout<<"CONV Construction"<<endl;
}
void conv::convlayer::calc(void){
    for(int i=0;i<(length-1)/2;i++){
        object.push_back(static_cast<ldouble>(0));
        object.push_front(static_cast<ldouble>(0));
    }
    std::cout<<endl;
    for(int i=0;i<buffer.size();i++){
        for(int j=0;j<length;j++){
            buffer[i]+=object[i+j]*weight[j];
        }
    }
}
void conv::convlayer::process(ldvector& input){
    object.copy(input);
    buffer.clear();
    objlength=input.size();
    for(int i=0;i<objlength;i++){
        buffer.push_back(0);
    }
    calc();
    input.copy(buffer);
}
void conv::poolayer::process(ldvector& input){
    int len=input.size();
    for(int i=0;i<((len%4==0)?(0):(length-(len%length)));i++){
        input.push_back(0);
    }
    int reslen=input.size()/length;
    ldvector res;
    int pos=0;
    for(int i=0;i<length;i++){
        res.push_back(input[pos]);
        for(int j=1;j<reslen;j++){
            res[i]=max(input[pos+j],res[i]);
        }
        pos+=length;
    }
    input.copy(res);
}
conv::depthlayer::depthlayer(int n,int n1,dpnt t):layer(n1,depth){
    ifsoftmax=false;
    switch(t){
    case dnone:
        throw -1;
        break;
    case dsoftmax:
        ifsoftmax=true;
        for(int i=0;i<n1;i++){
            softmaxwei.push_back();
            for(int j=0;j<n;j++){
                softmaxwei[i].push_back(0);
                initweight(softmaxwei[i][j]);
            }
        }
        std::cout<<softmaxwei.size()<<endl;
        break;
    case dsoftplus:
        for(int i=0;i<n1;i++){
            lay.push_back(new softplusnode(n));
        }
        break;
    case drelu:
        for(int i=0;i<n1;i++){
            lay.push_back(new relunode(n));
        }
        break;
    case dsigmoid:
        for(int i=0;i<n1;i++){
            lay.push_back(new sigmoidnode(n));
        }
        break;
    }
    std::cout<<"DEPTH Construction, node="<<n1<<", pre="<<n<<endl;
}
void conv::depthlayer::process(ldvector& input){
    ldvector res;
    if(ifsoftmax==false){
        for(int i=0;i<lay.size();i++){
            res.push_back(lay[i]->activate(input));
        }
    }
    else{
        ldvector mid;
        ldouble sum=0;
        for(int i=0;i<softmaxwei.size();i++){
            mid.push_back(0);
            for(int j=0;j<softmaxwei[i].size();j++){
                mid[i]+=input[j]*softmaxwei[i][j];
            }
            sum+=exp(mid[i]);
        }
        for(int i=0;i<mid.size();i++){
            res.push_back(exp(mid[i])/sum);
            std::cout<<mid[i]<<"/"<<'('<<sum<<')'<<"=";
            std::cout<<res[i]<<endl;
        }
        sum=0;
        for(int i=0;i<res.size();i++){
            sum+=res[i];
            std::cout<<"("<<res[i]<<")"<<"+";
        }
        std::cout<<"0="<<sum<<endl;
    }
    input.copy(res);
}
//rubbish bin--------------------------------------------
/*void conv::layer::base_initialize(int n,layer_type ly){
}*/
/*conv::convlayer::~convlayer(void){
//    delete[] object;
//    delete[] output;
}*/
/*void conv::convlayer::forward(void){
    if(relative==nullptr){
        return;
    }
    while((relative->behaving())==true){
        cvconv.wait(ul);
    }
   // for(int i=0;i<length;i++){
       // dynamic_cast<convlayer*>(relative)->get_object()[i]=this->object[i];
   // }
    relative->behaving()=true;
    cvconv.notify_all();
}*/
/*void conv::conv_behavior(convlayer* cl){
    while(true){
        if(cl->behaving()==false){
            cvconv.wait(ul);
            continue;
        }
        if(cl->existing()==false){
            break;
        }
        cl->calc();
        cl->forward();
        cvconv.notify_all();
        cl->behaving()=false;
        cvconv.wait(ul);
    }
}*/
/*void conv::push(convlayer& cl,ldouble* obj){
    for(int i=0;i<cl.length;i++){
        cl.object[i]=obj[i];
    }
//    cl.behaving()=true;
//    cvconv.notify_all();
}*/
//--------------------------------------------------
