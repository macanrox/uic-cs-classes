all: shell monteCarlo

shell:	simpleShell.c header.h
	gcc -g -o shell simpleShell.c

monteCarlo: monteCarloSimulation.c header.h
	gcc -g -o monteCarlo monteCarloSimulation.c -lm