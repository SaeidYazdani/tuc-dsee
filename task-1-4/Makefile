APP=bitcount
GCC-ARM=arm-linux-gnueabihf-gcc-4.8.3

bitcount: main.c
	@gcc -o $(APP) main.c -DEXECUTABLE_NAME='"$(APP)"'
	@echo "Jobs done! ouput = $(APP)"

.PHONY: clean 
clean:
	@echo "Cleaning..."
	@rm -rf *.o *~ $(APP)
	@echo "done!"
