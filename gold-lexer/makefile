
gold: main.o gold.o
	    g++ -o $@ $^

%.o: %.cpp
	    g++ -o $@ -c $<

%.cpp: %.l
	    flex -o $@ $<