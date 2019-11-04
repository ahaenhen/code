#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
const int M = 15;
struct Point {
	int val, no;
};
Point point[M];
int edge[M][M];
void print(int t, int n) {
	int i;
	for(i=t; i<n; ++i) printf("%d\t", point[i].val);
	printf("\n");
}
bool cmp(Point pa, Point pb) {
	return pa.val > pb.val;
}
bool havelHakimi(int n) {
	bool flag = true;
	sort(point, point+n, cmp);
	//print(0, n);
	int i, j;
	for(i=0; i<n; ++i) {
		int t = point[i].val;
		for(j=i+1; j<=i+t; ++j) {
			point[j].val--;
			if(point[j].val < 0) {flag = false; break;}
			edge[point[i].no][point[j].no] =  edge[point[j].no][point[i].no] = 1;
		}
		sort(point+i+1, point+n, cmp);
		//print(i+1, n);
		if(false == flag) break;
	}	
	return flag;
}
int main() {
	int t, n;
	int i, j;
	//freopen("/home/lsy/Desktop/2.txt", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<n; ++i) {
			scanf("%d", &point[i].val);
			point[i].no = i;
		}
		memset(edge, 0, sizeof(edge));
		if(false == havelHakimi(n)) printf("NO\n");
		else {
			printf("YES\n");
			for(i=0; i<n; ++i) {
				for(j=0; j<n; ++j) {
					if(0 != j) printf(" ");
					printf("%d", edge[i][j]);
				}
				printf("\n");
			}
		}
		if(t) printf("\n");
	}
	return 0;
}
