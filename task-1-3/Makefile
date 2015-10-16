APP=reversebits

bitreverse: main.c
	@gcc -o $(APP) main.c -DEXECUTABLE_NAME='""'
	@echo "Jobs done! ouput = $(APP)"

.PHONY: clean 
clean:
	@echo "Cleaning..."
	@rm -rf *.o *~ $(APP)
	@echo "done!"
