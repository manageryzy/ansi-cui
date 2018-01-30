all:
	mkdir -p build
	cd build&&cmake ..&&make -j4
	@echo "\033[0;32m" run main in build directory "\033[0m"
clean:
	rm -rf build
	rm -rf CMakeFiles
	rm -rf CMakeCache.txt
