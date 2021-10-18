
all: spinLockSleep mutex conditionVariable atomicCondition test

spinLockSleep: spinLockSleep.cpp
	g++ -pthread -o spinLockSleep  spinLockSleep.cpp

mutex: mutex.cpp
	g++ -pthread -o mutex mutex.cpp

conditionVariable: conditionVariable.cpp
	g++ -pthread -o conditionVariable conditionVariable.cpp

atomicCondition: atomicCondition.cpp
	g++ -pthread -o atomicCondition atomicCondition.cpp

test: test.cpp
	g++ -pthread -o test test.cpp
