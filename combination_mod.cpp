const int MOD= 998244353;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll COM(ll n , ll r){
	ll tn=n;
	ll tr=r;
	ll out=1;
	rep(i,r){
		out*=tn%MOD;
		out%=MOD;
		out*=modinv(tr,MOD);
		out%=MOD;
		tn--;
		tr--;
	}
	return out;

}


