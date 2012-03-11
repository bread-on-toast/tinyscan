tinyscan:	main.cpp scan.cpp
	export LD_PRELOAD=/usr/lib/libv4l/v4l1compat.so
	g++ main.cpp scan.cpp -lX11 -lpthread -lcv -lhighgui -o tinyscan -lcurses
