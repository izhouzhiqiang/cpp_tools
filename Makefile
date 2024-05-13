all :
	rm -rf build/
	mkdir -p build
	cd build && cmake ../ && make

clean :
	rm -rf build

test :
	cd test && make
