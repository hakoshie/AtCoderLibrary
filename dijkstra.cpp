
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
	//s����i�ւ̍ŒZ������d[i]�ɕۑ� d[i] means the path from s to i costs d[i]
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
	fill(d, d + V, INF);
	d[s] = 0;//�����ʒu�ւ̃R�X�g��0

	que.push(pair<int,int>(0, s));
	//que��make_pair(cost,destination)

	while (!que.empty()) {
		auto [cost_v,v] = que.top();
		que.pop();
		//from s to v costs cost_v
		//���̌�₪�ǉ�����Ă���C����܂łɁCs����v�ւ̂�肢���o�H���������Ă���Ȃ疳��
		if (d[v] < cost_v) continue;

		for (int i = 0; i < (int)G[v].size(); ++i) {
			edge e = G[v][i];
			//e : v �� w �����ԕӁ@
			// G[v][i]=(w, v_to_w_cost)
			// e.to=w
			int w=e.to;
			int v2w_cost=e.cost;
	        	// v2w_cost means v to w costs v2w_cost
			if (d[w] > d[v] + v2w_cost) {
				d[w] = d[v] + v2w_cost;
				//from s to w > from s to v + from v to w
				//v���o�R�����ق����R�X�g���Ⴂ�Ȃ�o�R����
				que.push({d[w], w});
				// d[w]���X�V���ꂽ�Ȃ�΁C
				// w �ƂȂ����Ă���Ƃ��������
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
