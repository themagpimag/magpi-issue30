# W. H. Bell
# A Makefile to build Bags.exe

CC=g++
TARGET=Bags
OBJECTS=main.o Bag.o ColouredBag.o BeanBag.o
INCFLAGS=

$(TARGET).exe: $(OBJECTS)
	@echo "**"
	@echo "** Linking Executable"
	@echo "**"
	$(CC) $(OBJECTS) -o $(TARGET).exe

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET).exe

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 
