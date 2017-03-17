compile_code = gcc -o run_example -fopenmp

list :
	echo "OpenMP Examples"
	
barrier :
	$(compile_code) barrier.c
	
for :
	$(compile_code) for.c

master :
	$(compile_code) master.c
	
parallel :
	$(compile_code) parallel.c

private :
	$(compile_code) private.c
	
firstprivate :
	$(compile_code) firstprivate.c
	
lastprivate :
	$(compile_code) lastprivate.c
	
.PHONY : run
run    :
		./run_example

.PHONY : clean
clean  :
		-rm run_example *.o


