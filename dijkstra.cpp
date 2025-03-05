
#define INF 1e+9 //初期化注意
#define MAX_V 100000 //頂点数の最大値

struct edge {
	int to;
	int cost;
	//edge e ={to, cost}
};

// <最短距離, 頂点の番号>
using P = pair<int, int>;

int V;// 頂点の数
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
	//sからiへの最短距離をd[i]に保存 d[i] means the path from s to i costs d[i]
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
	fill(d, d + V, INF);
	d[s] = 0;//初期位置へのコストは0

	que.push(pair<int,int>(0, s));
	//queはmake_pair(cost,destination)

	while (!que.empty()) {
		auto [cost_v,v] = que.top();
		que.pop();
		//from s to v costs cost_v
		//この候補が追加されてから，見るまでに，sからvへのよりいい経路が見つかっているなら無視
		if (d[v] < cost_v) continue;

		for (int i = 0; i < (int)G[v].size(); ++i) {
			edge e = G[v][i];
			//e : v と w を結ぶ辺　
			// G[v][i]=(w, v_to_w_cost)
			// e.to=w
			int w=e.to;
			int v2w_cost=e.cost;
	        	// v2w_cost means v to w costs v2w_cost
			if (d[w] > d[v] + v2w_cost) {
				d[w] = d[v] + v2w_cost;
				//from s to w > from s to v + from v to w
				//vを経由したほうがコストが低いなら経由する
				que.push({d[w], w});
				// d[w]が更新されたならば，
				// w とつながっているところも見る
			}
		}
	}
}

int main() {
	cin >> V;
	int E;//辺の数
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b>>c ;
		a--; b--;
		//the route a to b costs c
		edge e = { b, c };
		// push_back(e{b,c})でも動く
		G[a].push_back(e);
		//有向グラフの場合であり、無向グラフなら e{a,c}も必要
	}
	dijkstra(0);
	//dijkstra(int s); nからの最短距離を計算
	//d[i]はsからiまでの最短距離が保存される the path from s to i costs d[i]
}
