COMPILE  = g++
OPTION   = -std=c++2a -fPIC
REMOVE   = rm -f
OBJFILE  = main.o net.o node.o layer.o def.o str.o
OUTFILE  = exec
total: $(OUTFILE) clear

$(OUTFILE): $(OBJFILE)
	$(COMPILE) -o exec $(OBJFILE) $(OPTION)

def.o: definition.cpp declaration.h
	$(COMPILE) -c -o def.o definition.cpp $(OPTION)

str.o: conv_string.cpp string.h vector.h
	$(COMPILE) -c -o str.o conv_string.cpp $(OPTION)

node.o: node.cpp neural_node.h
	$(COMPILE) -c -o node.o node.cpp $(OPTION)

layer.o: layer.cpp layer.h
	$(COMPILE) -c -o layer.o layer.cpp $(OPTION)

net.o: net.cpp net.h
	$(COMPILE) -c -o net.o net.cpp $(OPTION)

main.o: main.cpp project.h
	$(COMPILE) -c -o main.o main.cpp $(OPTION)

clear: $(OBJFILE)
	$(REMOVE) $(OBJFILE)