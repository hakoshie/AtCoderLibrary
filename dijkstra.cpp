
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
	//sからiへの最短距離をd[i]に保存 i=v_i
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
	fill(d, d + V, INF);
	d[s] = 0;//初期位置へのコストは0

	que.push(pair<int,int>(0, s));
	//queはmake_pair(cost,to)?

	while (!que.empty()) {
		pair<int,int> p = que.top();
		que.pop();
		int v = p.second;//v=p.second from s to v
		//この候補が追加されてから，見るまでに，sからp.secondへのよりいい経路が見つかっているなら無視
		if (d[v] < p.first) continue;
		//v=p.second 
		for (int i = 0; i < (int)G[v].size(); ++i) {
			edge e = G[v][i];
			//e : i番目の v と v_i を結ぶ辺　
			// G[v][i]=(v_i, v_to_vi_cost)
			// e.to=v_i
			int v_i=e.to;
			int v_to_vi_cost=e.cost;
	        	// v_to_vi_cost means v to v_i costs v_to_vi_cost
			if (d[v_i] > d[v] + v_to_vi_cost) {
				d[v_i] = d[v] + v_to_vi_cost;
				//from s to v_i > from s to v + from v to v_i
				//vを経由したほうがコストが低いなら経由する
				que.push(pair<int,int>(d[v_i], v_i));
				// d[v_i]が更新されたならば，
				// v_i とつながっているところも見る
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
