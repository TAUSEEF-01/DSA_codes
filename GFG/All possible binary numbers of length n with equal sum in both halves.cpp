// C++ program to generate all binary strings with
// equal sums in left and right halves.
#include <bits/stdc++.h>
using namespace std;

/* Default values are used only in initial call.
n is number of bits remaining to be filled
di is current difference between sums of
	left and right halves.
left and right are current half substrings. */
void equal(int n, string left="", string right="",
										int di=0)
{
	// TWO BASE CASES
	// If there are no more characters to add (n is 0)
	if (n == 0)
	{
		// If difference between counts of 1s and
		// 0s is 0 (di is 0)
		if (di == 0)
			cout << left + right << " ";
		return;
	}

	/* If 1 remains than string length was odd */
	if (n == 1)
	{
		// If difference is 0, we can put remaining
		// bit in middle.
		if (di == 0)
		{
			cout << left + "0" + right << " ";
			cout << left + "1" + right << " ";
		}
		return;
	}

	/* If difference is more than what can be
	be covered with remaining n digits
	(Note that lengths of left and right
		must be same) */
	if ((2 * abs(di) <= n))
	{ 
		
		/* add 0 to end in both left and right
		half. Sum in both half will not
			change*/
		equal(n-2, left+"0", right+"0", di);

		/* add 0 to end in both left and right
		half* subtract 1 from di as right
		sum is increased by 1*/
		equal(n-2, left+"0", right+"1", di-1);

		/* add 1 in end in left half and 0 to the
		right half. Add 1 to di as left sum is
		increased by 1*/
		equal(n-2, left+"1", right+"0", di+1);

		/* add 1 in end to both left and right
		half the sum will not change*/
		equal(n-2, left+"1", right+"1", di);
	}
}

/* driver function */
int main()
{
	int n = 5; // n-bits
	equal(n);
	return 0;
}
