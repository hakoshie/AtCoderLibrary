typedef pair<int, int> P;

bool ps1(const P &forall_a_in_P, const P &forall_b_in_P)
{ //first����
	return forall_a_in_P.first < forall_b_in_P.first;
}
bool ps2(const P &forall_a_in_P, const P &forall_b_in_P)
{ //first�~��
	return forall_a_in_P.first > forall_b_in_P.first;
}
bool ps3(const P &forall_a_in_P, const P &forall_b_in_P)
{ //second����
	return forall_a_in_P.second < forall_b_in_P.second;
}
bool ps4(const P &forall_a_in_P, const P &forall_b_in_P)
{ //second�~��
	return forall_a_in_P.second > forall_b_in_P.second;
}