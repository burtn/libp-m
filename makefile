test-headings:
	gcc headings.c tests_headingsc.c
	mv a.out test-headings
test-imagegen:
	gcc image.c headings.c colour.c tests_imagec.c
	mv a.out test-imagegen
	./test-imagegen
	pnmtopng image_test_PBM.pbm > image_test_PBM.png
	pnmtopng image_test_PGM.pgm > image_test_PGM.png
	# open *.png
clean:
	rm -f test-headings
	rm -f test-pbm
	rm -f *.png
	rm -f *.pbm
	rm -f *.pgm
	rm -f *.ppm
	rm -f *.pnm
