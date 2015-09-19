#include <bits/stdc++.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

// 50%
void func1()
{
	for(;;)
	{
		for(int i=0; i<96000000; i++);
		Sleep(10);
	}
}

// 50%
void func2()
{
	const DWORD busyTime = 10;	// 10ms
	const DWORD idleTime = busyTime;
	int startTime = 0;
	while(true)
	{
		DWORD startTime = GetTickCount();
		while(GetTickCount() - startTime <= busyTime);
		Sleep(idleTime);
	}
}

// sin
void func3()
{
	const int SAMPLINT_COUNT = 200;
	const double PI = acos(-1);
	const int TOTAL_AMPLITUDE = 300;	// 每个抽样点对应的时间片 
	
	DWORD busySpan[SAMPLINT_COUNT];
	int amplitude = TOTAL_AMPLITUDE / 2;
	double radian = 0.0;
	double radianIncrement = 2.0 / (double)SAMPLINT_COUNT;
	for(int i=0; i<SAMPLINT_COUNT; i++)
	{
		busySpan[i] = (DWORD)(amplitude + (sin(PI * radian) * amplitude));
		radian += radianIncrement;
	}
	DWORD startTime = 0;
	for(int j=0; ;j = (j + 1) % SAMPLINT_COUNT)
	{
		startTime = GetTickCount();
		while(GetTickCount() - startTime <= busySpan[j]);
		Sleep(TOTAL_AMPLITUDE - busySpan[j]);
	}
}

int main()
{
	func3();
	return 0;
}
