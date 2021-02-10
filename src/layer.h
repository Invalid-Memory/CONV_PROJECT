/*--------------------------------------------------------------------------\
|   layer.h of ConvNeurNet Project---------Student Work                     |
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
#ifndef   CONV_PROJECT_LAYER
# define  CONV_PROJECT_LAYER
# include "neural_node.h"
# define convp(lay)  dynamic_cast<conv::convlayer*>(lay)
# define poolp(lay)  dynamic_cast<conv::poolayer*>(lay)
# define depthp(lay) dynamic_cast<conv::depthlayer*>(lay)
 namespace conv{
     typedef enum layer_type{
         conv   ,
         pooling,
         depth  ,
     }   lyt    ;
     typedef enum depnode_type{
         dsoftmax ,
         dsigmoid ,
         drelu    ,
         dsoftplus,
         dnone    ,
     }   dpnt     ;
     class layer{
     protected:
         typedef                  node               *pnode                  ;
         vector<pnode>            lay                                        ;
         int                      length                                     ;
//       using                    sthr                           =std::thread;
//       bool                     isbehaving                                 ;
//       bool                     isexisting                                 ;
//       sthr*                    beh                                        ;
//       void                     base_initialize    (int,lyt)               ;
     public:
         inline         explicit  layer              (int,lyt)               ;
         virtual                 ~layer              (void)                  ;
         virtual        void      process            (ldvector&)         pure;
//       inline         void      set_relative_layer (layer*)                ;
//       inline         bool&     behaving           (void)                  ;
//       inline         bool&     existing           (void)                  ;
//       inline         void      wait               (void)                  ;
     }                                                                       ;
     class convlayer:public layer{
     protected:
         ldvector            weight                                                   ;
         ldvector            object                                                   ;
         ldvector            buffer                                                   ;
         int                 objlength                                                ;
         void                calc              (void)                                 ;
     public:
         explicit            convlayer         (ldvector&)                            ;
         inline    virtual  ~convlayer         (void)                override =default;
         virtual   void      process           (ldvector&)           override         ;
//       inline    void      set_object_length (long int)                             ;
//       inline    ldouble*  get_object        (void)                                 ;
//       inline    long int  get_length        (void)                                 ;
//       friend    void      push              (convlayer&,ldouble*)                  ;
//       void                initialize        (int)                                  ;
     }                                                                                ;
     class poolayer:public layer{
     public:
         inline   explicit   poolayer   (int)                        ;
         inline   virtual   ~poolayer   (void)      override =default;
         virtual  void       process    (ldvector&)                  ;
//       void                initialize (int)                        ;
     }                                                               ;
     class depthlayer:public layer{
     protected:
         vector<ldvector>  softmaxwei                                  ;
         bool              ifsoftmax                                   ;
     public:
         explicit          depthlayer (dpnt,vector<ldvector>&)         ;
         virtual          ~depthlayer (void)                   =default;
         virtual void      process    (ldvector&)                      ;
//       void              initialize (int,int,dpnt)                   ;
     }                                                                 ;
     inline conv::layer::layer(int n,lyt ly):length(n){
     }
     inline conv::poolayer::poolayer(int n1):layer(n1,pooling){
     }
     //rubbish bin---------------------------------------
     /*inline void layer::set_relative_layer(layer* rel){
         relative=rel;
     }*/
     /*inline void convlayer::set_object_length(long int l){
         length=l;
     }
     void push(convlayer&,ldouble*);
     void push(depthlayer&);
     void conv_behavior(convlayer*);
     void depth_behavior(depthlayer&);
     inline bool& layer::behaving(void){
         return isbehaving;
     }
     inline bool& layer::existing(void){
         return isexisting;
     }*/
     /*inline void layer::wait(void){
         while(isbehaving==true){
             std::this_thread::yield();
         }
     }*/
     /*inline ldouble* convlayer::get_object(void){
         return object;
     }
     inline long int convlayer::get_length(void){
         return length;
     }*/
     //--------------------------------------------------
 }
#endif
