target:
	gcc -o cal cal.c 

run: target
	./cal

clean:
	rm cal
