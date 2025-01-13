all: report

report: report.o functions.o
	gcc -o report report.o functions.o

report.o: report.c
	gcc -c -o report.o report.c

functions.o: functions.c
	gcc -c -o functions.o functions.c

clean:
	del *.o
	del report.exe
	