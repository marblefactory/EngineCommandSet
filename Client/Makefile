CFLAGS = -std=c++11 -w
LINKER = -lboost_system -lpthread

bser:
	g++ $(CFLAGS) test_server.cpp -o test_server.out $(LINKER)
bcli:
	g++ $(CFLAGS) client.cpp logger.cpp -o client.out $(LINKER) 
rser:
	./test_server.out 
rcli:
	./client.out $(HOST) $(SERVICE)
	#Usage: make rcli HOST="localhost" SERVICE="1024"
clean:
	rm *.out
