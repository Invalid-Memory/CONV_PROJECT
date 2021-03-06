/*--------------------------------------------------------------------------\
|   vector_def.hpp of ConvNeurNet Project---------Student Work              |
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
#ifndef   CONV_PROJECT_VECTOR_DEFINITION
# define  CONV_PROJECT_VECTOR_DEFINITION
# include "vector_dec.h"
 namespace conv{
     template <typename type>
     inline vector<type>::vector(void):vsize(0),last_index(0){
         head=new lelem;
         tail=head;
         head->next=tail;
         tail->next=head;
         head->up=tail;
         tail->up=head;
         head->it=nullptr;
         last_aim=head->next;
     }
     template <typename type>
     inline vector<type>::vector(vector&& mv){
         move(mv);
     }
     template <typename type>
     inline vector<type>::~vector(void){
         clear();
         delete head;
     }
     template <typename type>
     inline void vector<type>::swap(int& a,int& b){
         int mid=a;
         a=b;
         b=mid;
     }
     template <typename type>
     inline void vector<type>::swap(fplelem a,fplelem b){
         typedef unsigned long long int ull;
         ull mid;
         mid=reinterpret_cast<ull>(a);
         a=b;
         b=reinterpret_cast<lelem*>(mid);
     }
     template <typename type>
     void vector<type>::copy(const vector& cp){
         this->clear();
         for(int i=0;i<cp.size();i++) {
             this->push_back(cp[i]);
         }
     }
     template <typename type>
     void vector<type>::copy(type* cp,int s){
         this->clear();
         for(int i=0;i<s;i++){
            this->push_back(cp[i]);
         }
     }
     template <typename type>
     void vector<type>::move(vector&& mv){
         swap(mv.head,this->head);
         swap(mv.tail,this->tail);
         swap(mv.vsize,this->vsize);
         swap(mv.last_index,this->last_index);
         swap(mv.last_aim,this->last_aim);
     }
     template <typename type>
     template <typename...argpack>
     void vector<type>::push_back(argpack...pack){
         static_assert(requires{new type{pack...};},"Initializer list invalid.");
         tail->next=new lelem;
         tail->next->up=tail;
         tail=tail->next;
         tail->next=head;
         tail->it=new type{pack...};
         vsize++;
         if(last_aim==head){
             last_aim=head->next;
         }
     }
     template <typename type>
     template <typename...argpack>
     void vector<type>::push_front(argpack...pack){
         static_assert(requires{new type{pack...};},"Initializer list invalid.");
         head->up=new lelem;
         head->up->next=head;
         head=head->up;
         head->up=tail;
         tail->next=head;
         head->next->it=new type{pack...};
         vsize++;
         last_index++;
         if(last_aim==head){
             last_aim=head->next;
         }
     }
     template <typename type>
     inline int vector<type>::size(void)const{
         return vsize;
     }
     template <typename type>
     void vector<type>::clear(void){
         while(head!=tail){
             if(tail->it!=nullptr){
                 delete tail->it;
             }
             tail=tail->up;
             delete tail->next;
         }
         /*if(head->it!=nullptr){
             delete head->it;
         }*/
//         delete head;
//         head=new lelem;
//         tail=head;
         head->next=tail;
         tail->next=head;
         head->up=tail;
         tail->up=head;
         vsize=0;
         last_aim=head->next;
         last_index=0;
     }
     template <typename type>
     type& vector<type>::operator[](int index)const{
//       std::cout<<"operator[](): "<<index<<std::endl;
         if(index>=vsize){
             throw -1;
         }
         lelem* aim=last_aim;
         if(index==last_index){
             return (*last_aim->it);
         }
         else if(index>last_index){
             for(int i=last_index;i<index;i++){
                 aim=aim->next;
                 if(aim==head){
                     throw -1;
                 }
             }
         }
         else{
             for(int i=last_index;i>index;i--){
                 aim=aim->up;
                 if(aim==head){
                     throw -1;
                 }
             }
         }
         if(aim->it==nullptr){
             throw -1;
         }
         last_aim=aim;
         last_index=index;
         return *(aim->it);
     }
 }
#endif
