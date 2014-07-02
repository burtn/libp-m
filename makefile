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
test-readimage:
	make test-imagegen
	gcc -Wno-pointer-sign -Wno-incompatible-pointer-types-discards-qualifiers reader.c tests_readerc.c image.c colour.c headings.c	
	mv a.out test-readimage
	./test-readimage
	pnmtopng reader_test_out.pbm > reader_test_PBM.png
clean:
	rm -f test-headings
	rm -f test-imagegen
	rm -f test-readimage
	rm -f *.png
	rm -f *.pbm
	rm -f *.pgm
	rm -f *.ppm
	rm -f *.pnm
