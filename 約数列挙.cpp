set<int> divisor(int n)
{
	set<int> value;
	for( int ite=1; (ll)ite*ite<=n;ite++)
	{
		
			if (n % ite == 0)
			{
				value.insert(ite);
				value.insert(n / ite);
				
			}
		
	}
	return value;
}
/*

set<ll> divisor(ll n)
{
	set<ll> value;
	for( ll i=1; i*i<=n;i++)
	{
		
			if (n % i == 0)
			{
				value.insert(i);
				value.insert(n / i);
			}
		
	}
	return value;
}
*/