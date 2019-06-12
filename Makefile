EXEC:=main.out
OBJS:=fakemn
LIBS:=fake-mininet/lib
CXXFLAGS:= -std=c++11

all: $(EXEC)

# executable (using static library)
# need libfakemn.a (compile from the Makefile of project root)
$(EXEC): %.out: %.cc
	g++ -o $@ $< -I$(LIBS) -g3 -L. -l$(OBJS) $(CXXFLAGS)

# reset & clean
clean: 
	rm -rf $(EXEC)
	rm -rf outfile.txt