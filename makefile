test-headings:
	gcc headings.c tests_headingsc.c
	mv a.out testheadings
clean:
	rm testheadings
