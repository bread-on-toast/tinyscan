tinyscan:	main.cpp scan.cpp
	g++ main.cpp scan.cpp -lX11 -lpthread -lcv -lhighgui -o tinyscan -lcurses
