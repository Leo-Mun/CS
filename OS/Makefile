all:
	@make clean
	@make build
	@make run

build:
	@echo "Building..."
	@make Phil_A
	@make Phil_B
	@make Phil_C

Phil_A:
	@gcc -o A avoid_A.c

Phil_B:
	@gcc -o B avoid_B.c

Phil_C:
	@gcc -o C avoid_C.c

run:
	@echo "Running..."
	./A & ./B & ./C

clean:
	@rm R1 R2 R3 C1 C2 C3 ACount BCount CCount
	@ipcrm -a
