runClient:
	g++ -Wall -Wextra -Werror -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics -c main_client.cpp -o main_client.o
	g++ -Wall -Wextra -Werror -o main_client_test main_client.o client.cpp message.cpp -L../ -lftpp -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics
	./main_client_test
runServer:
	g++ -Wall -Wextra -Werror -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics -c my_main_server.cpp -o main_server.o
	g++ -Wall -Wextra -Werror -o main_server_test main_server.o server.cpp message.cpp -L../ -lftpp -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics
	./main_server_test

all:
	# Compile the message test
	g++ -Wall -Wextra -Werror -I../includes -o test_message main_message.cpp

	g++ -Wall -Wextra -Werror -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics -c main_client.cpp -o main_client.o
	g++ -Wall -Wextra -Werror -o main_client_test main_client.o client.cpp message.cpp -L../ -lftpp -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics

	g++ -Wall -Wextra -Werror -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics -c my_main_server.cpp -o main_server.o
	g++ -Wall -Wextra -Werror -o main_server_test main_server.o server.cpp message.cpp -L../ -lftpp -I../includes -I../DataStructures -I../DesignPatterns -I../IOStream -I../Thread -I../Network -I../Mathematics

	./test_message
	./main_client_test
	./main_server_test
clean:
	rm -f main_client_test main_client.o main_server_test main_server.o test_message