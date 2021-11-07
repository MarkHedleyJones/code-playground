
all: \
	test \
	spinLockSleep \
	mutex \
	conditionVariable \
	atomicCondition \
	producerConsumer \
	spinlockAcquireRelease \
	transitivity \
	acquireReleaseWithWaiting \
	acquireReleaseWithoutWaiting \
	relaxed

test: test.cpp
	g++ -pthread -o test test.cpp

spinLockSleep: spinLockSleep.cpp
	g++ -pthread -o spinLockSleep  spinLockSleep.cpp

mutex: mutex.cpp
	g++ -pthread -o mutex mutex.cpp

conditionVariable: conditionVariable.cpp
	g++ -pthread -o conditionVariable conditionVariable.cpp

atomicCondition: atomicCondition.cpp
	g++ -pthread -o atomicCondition atomicCondition.cpp


producerConsumer: producerConsumer.cpp
	g++ -pthread -o producerConsumer producerConsumer.cpp

spinlockAcquireRelease: spinlockAcquireRelease.cpp
	g++ -pthread -o spinlockAcquireRelease  spinlockAcquireRelease.cpp

transitivity: transitivity.cpp
	g++ -pthread -o transitivity  transitivity.cpp

acquireReleaseWithWaiting: acquireReleaseWithWaiting.cpp
	g++ -pthread -o acquireReleaseWithWaiting  acquireReleaseWithWaiting.cpp

acquireReleaseWithoutWaiting: acquireReleaseWithoutWaiting.cpp
	g++ -pthread -o acquireReleaseWithoutWaiting  acquireReleaseWithoutWaiting.cpp

relaxed: relaxed.cpp
	g++ -pthread -o relaxed  relaxed.cpp
