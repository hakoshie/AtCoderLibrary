int GCD(int x, int y) {
	return x ? GCD(y % x, x) : y;
}

int LCM(int m, int n)
{
	if ((0 == m) || (0 == n))
		return 0;

	return ((m / GCD(m, n)) * n); // lcm = m * n / GCD(m,n)
}