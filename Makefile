CC=g++
CFLAG=-I. -std=c++11 
OBJ = factoryAbstractTest.o factoryAbstract.o 
OBJ2 = factoryAbstractMultiThreadTest.o factoryAbstract.o 
OBJ1 = ObjectPoolTest.o factoryAbstract.o ObjectPool.o
DEP = factoryAbstract.h ObjectPool.h


%.o : %.cpp $(DEP)
	$(CC) -c $(CFLAG) $< 

factory : $(OBJ)
	$(CC) -o $(FLAG) $@ $^ 

factmt : $(OBJ2)
	$(CC) -o $(FLAG) $@ $^ -lpthread 

op:$(OBJ1)
	$(CC) -o $(FLAG) $@ $^

clean:
	rm *.o factory op factmt
