#Define app name and needed source files
#This throws error if it cant find source files
helloworld: main.c
	#do the compile
	#note that @ will surpress printing the command in terminal
	@gcc -o helloworld main.c
	
	@echo "Jobs done! run the code by calling './helloworld'"

#declaring options using phony
.PHONY: clean 

#clean procedures of generated objects
#or other unnecessary files as well as
#the executable file itself...
clean:
	@echo "Cleaning..."
	@rm -rf *.o *~ helloworld
	@echo "done!"
	 


