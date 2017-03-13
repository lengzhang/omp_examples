compile_code = gcc -o run_example -fopenmp

list :
	echo hi
	
parallel :
	$(compile_code) parallel_example.c
	
.PHONY : run
run    :
		./run_example

.PHONY : clean
clean  :
		-rm run_example *.o


