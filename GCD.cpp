int GCD(int x, int y) {
	return x ? GCD(y % x, x) : y;
}