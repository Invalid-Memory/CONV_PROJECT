EXEC     = sh
COMPILE  = g++
MAKEPATH = mkdir
OPTION   = -std=c++2a -fPIC
SRCPATH  = $(PWD)/src
MKSCPT   = $(PWD)/make
include ./make/objval.mk

total: startup project

startup:
	$(EXEC) $(MKSCPT)/script/mkobj.sh

project: $(OBJFILE)
	$(EXEC) $(MKSCPT)/script/rmout.sh

$(OBJPATH)/def.o: $(SRCPATH)/definition.cpp $(SRCPATH)/declaration.h
	$(COMPILE) -c -o $(OBJPATH)/def.o $(SRCPATH)/definition.cpp $(OPTION)

$(OBJPATH)/str.o: $(SRCPATH)/conv_string.cpp $(SRCPATH)/string.h $(SRCPATH)/vector.h
	$(COMPILE) -c -o $(OBJPATH)/str.o $(SRCPATH)/conv_string.cpp $(OPTION)

$(OBJPATH)/node.o: $(SRCPATH)/node.cpp $(SRCPATH)/neural_node.h
	$(COMPILE) -c -o $(OBJPATH)/node.o $(SRCPATH)/node.cpp $(OPTION)

$(OBJPATH)/layer.o: $(SRCPATH)/layer.cpp $(SRCPATH)/layer.h
	$(COMPILE) -c -o $(OBJPATH)/layer.o $(SRCPATH)/layer.cpp $(OPTION)

$(OBJPATH)/net.o: $(SRCPATH)/net.cpp $(SRCPATH)/net.h
	$(COMPILE) -c -o $(OBJPATH)/net.o $(SRCPATH)/net.cpp $(OPTION)

$(OBJPATH)/read.o: $(SRCPATH)/file_reader.cpp $(SRCPATH)/file_reader.h
	$(COMPILE) -c -o $(OBJPATH)/read.o $(SRCPATH)/file_reader.cpp $(OPTION)

$(OBJPATH)/main.o: $(SRCPATH)/main.cpp $(SRCPATH)/project.h
	$(COMPILE) -c -o $(OBJPATH)/main.o $(SRCPATH)/main.cpp $(OPTION)
