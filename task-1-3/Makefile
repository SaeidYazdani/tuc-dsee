APP=bitreverse

bitreverse: main.c
	@gcc -o $(APP) main.c -DEXECUTABLE_NAME='"$(APP)"'
	@echo "Jobs done! ouput = $(APP)"

.PHONY: clean 
clean:
	@echo "Cleaning..."
	@rm -rf *.o *~ $(APP)
	@echo "done!"
