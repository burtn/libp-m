test-headings:
	gcc headings.c tests_headingsc.c
	mv a.out test-headings
test-pbm:
	gcc image.c headings.c tests_imagec.c
	mv a.out test-pbm
	./test-pbm
	pnmtopng image_test_PBM.pbm > image_test_PBM.png
	open image_test_PBM.png 
clean:
	rm -f test-headings
	rm -f test-pbm
	rm -f *.png
	rm -f *.pbm
	rm -f *.pgm
	rm -f *.ppm
	rm -f *.pnm
