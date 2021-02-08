/*--------------------------------------------------------------------------\
|   neural_node.h of ConvNeurNet Project---------Student Work               |
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
#ifndef   CONV_PROJECT_NODE
# define  CONV_PROJECT_NODE
# include "vector.h"
# include "string.h"
 namespace conv{
     typedef vector<ldouble> ldvector;
     class node{
     protected:
         typedef           node      *pnode     ;
         ldouble           data                 ;
         ldouble*          inweight             ;
         int               weilen               ;
//       pnode*            link                 ;
//       int               link_num             ;
     public:
         explicit          node      (int)      ;
         virtual          ~node      (void)     ;
         virtual  ldouble  activate  (ldvector&) pure;
     };
     class sigmoidnode:public node{
     public:
         inline sigmoidnode(int);
         ldouble activate(ldvector&)override;
     };
     class relunode:public node{
     public:
         inline           relunode (int)                        ;
         virtual  inline ~relunode (void)      override =default;
         ldouble          activate (ldvector&) override         ;
     }                                                          ;
     class softplusnode:public node{
     public:
         explicit inline  softplusnode (int)                        ;
         virtual  inline ~softplusnode (void)      override =default;
         ldouble          activate     (ldvector&) override         ;
     }                                                              ;

     inline conv::sigmoidnode::sigmoidnode(int n):node(n){
     }
     inline conv::relunode::relunode(int n):node(n){
     }
     inline conv::softplusnode::softplusnode(int n):node(n){
     }
//rubbish bin----------------------------------------------
     /*class convnode:public node{
     public:
         explicit           convnode (void)             ;
         virtual  inline   ~convnode (void)     =default;
         ldouble            activate (obj&)    override;
//       inline   ldouble&  getw     (void)             ;
     };*/
     /*inline ldouble& conv::convnode::getw(void){
         return data;
     }*/
//---------------------------------------------------------
 }
#endif
