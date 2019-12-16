#include <vector>
#include <iostream> 
using namespace std; 
struct edge{	
	int to, 
	cost;}; 
const int MAX = 10001;
const int INF = 0x3f3f3f3f; // ���������޷�����Ļ��ľ��� 

vector<edge> G[MAX]; // ͼ
int d[MAX];
int used[MAX];
int V; // ������
int E; // ����
int s; // �����ĵ� 
void creat(){	
		// ��Ϊֻ��֧�ֶ��� 0 ~ n�� ��������� 1 ~ n, ���и��� ֻҪ�Ѷ����ֵ�� 1 ������	
		// ��������� 0 ~ n	
		cin >> V >> E >> s;	
		for(int i = 0; i < E; ++i){	    
			int from, to, cost;	    
			cin >> from >> to >> cost;	    
			edge e;	    
			e.to = to;	    
			e.cost = cost;	    
			G[from].push_back(e);	
			}
		} 
void Dijkstra(int s){	
		fill(d, d + V, INF);	
		fill(used, used + V, false);	
		d[s] = 0;	
		while(true){	    
			int v = -1;	    
		for(int i = 0; i < V; ++i){		
			if(!used[i] && (v == -1 || d[v] > d[i])){ // Ѱ�ҵ���ĳһ�����̾���			
				v = i;		
				}	    
			}	    
		if(v == -1) break;	    
		used[v] = true;	    
		for(int i = 0; i < (int)G[v].size(); ++i){	        
			edge e = G[v][i];		
			if(d[v] != INF) // ������ڲ��ܵ���ĵ�Ļ������迼��                
			d[e.to] = min(d[e.to], d[v] + e.cost); // v -> i ��v�� e.to����ľ���	    
			}	
		}
	} 
void solve(){	
		creat();	
		Dijkstra(s);	
		for(int i = 0; i < V; ++i) 
		cout << d[i] << ' '; // �����������������̾��룬 ����޷�������Ϊ INF
	}
int main(){	
	solve();	
	return 0;
}


