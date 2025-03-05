
#define INF 1e+9 //����������
#define MAX_V 100000 //���_���̍ő�l

struct edge {
	int to;
	int cost;
	//edge e ={to, cost}
};

// <�ŒZ����, ���_�̔ԍ�>
using P = pair<int, int>;

int V;// ���_�̐�
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
	//s����i�ւ̍ŒZ������d[i]�ɕۑ� i=v_i
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
	fill(d, d + V, INF);
	d[s] = 0;//�����ʒu�ւ̃R�X�g��0

	que.push(pair<int,int>(0, s));
	//que��make_pair(cost,to)?

	while (!que.empty()) {
		pair<int,int> p = que.top();
		que.pop();
		int v = p.second;//v=p.second from s to v
		//���̌�₪�ǉ�����Ă���C����܂łɁCs����p.second�ւ̂�肢���o�H���������Ă���Ȃ疳��
		if (d[v] < p.first) continue;
		//v=p.second 
		for (int i = 0; i < (int)G[v].size(); ++i) {
			edge e = G[v][i];
			//e : i�Ԗڂ� v �� v_i �����ԕӁ@
			// G[v][i]=(v_i, v_to_vi_cost)
			// e.to=v_i
			int v_i=e.to;
			int v_to_vi_cost=e.cost;
	        	// v_to_vi_cost means v to v_i costs v_to_vi_cost
			if (d[v_i] > d[v] + v_to_vi_cost) {
				d[v_i] = d[v] + v_to_vi_cost;
				//from s to v_i > from s to v + from v to v_i
				//v���o�R�����ق����R�X�g���Ⴂ�Ȃ�o�R����
				que.push(pair<int,int>(d[v_i], v_i));
				// d[v_i]���X�V���ꂽ�Ȃ�΁C
				// v_i �ƂȂ����Ă���Ƃ��������
			}
		}
	}
}

int main() {
	cin >> V;
	int E;//�ӂ̐�
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b>>c ;
		a--; b--;
		//the route a to b costs c
		edge e = { b, c };
		// push_back(e{b,c})�ł�����
		G[a].push_back(e);
		//�L���O���t�̏ꍇ�ł���A�����O���t�Ȃ� e{a,c}���K�v
	}
	dijkstra(0);
	//dijkstra(int s); n����̍ŒZ�������v�Z
	//d[i]��s����i�܂ł̍ŒZ�������ۑ������ the path from s to i costs d[i]
}
