

all:	string_gen vuln_program

string_gen:	string_gen.cc
	g++ string_gen.cc -o attack-string

vuln_program:	vuln_program.c
	gcc -m32 ./vuln_program.c -fno-stack-protector -z execstack -static -o vuln_program

clean:	
	rm -f sg attack-string vuln_program *.txt
