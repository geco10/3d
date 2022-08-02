#include<cstdio>
enum class Dimention{
  Z,
  Y,
  X
};
void clean_line() {
	char c;
	do {
	    c = getchar();
	} while (c!='\n');
}
void print(int n, int m, int h, int a[10][10][10], Dimention d) {
	if (d == Dimention::Z) {
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				printf("%i ",a[0][i][j]);
			}
			puts("");
		}
	}
	else if (d == Dimention::X) {
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < h; k++) {
				printf("%i ", a[k][i][0]);
			}
			puts("");
		}
	}
	else if (d == Dimention::Y) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				printf("%i ", a[k][0][j]);
			}
			puts("");
		}
	}
}
void fil(int n,int m,int h,int a[10][10][10],Dimention d) {
	if(d==Dimention::Z){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				a[0][i][j]=1;
			}
		}
		for (int i = 0; i < n; i++){
			a[0][i][0] = 1;
		}
	}
	else if (d == Dimention::X) {
		for (int k = 0; k < h; k++) {
			for (int i = 0; i < n; i++) {
				a[k][i][0] = 1;
			}
		}
		for (int k = 0; k < h; k++) {
			a[k][0][0] = 1;
		}
	}
	else if (d == Dimention::Y) {
		for (int k = 0; k < h; k++) {
			for (int j = 0; j < m; j++) {
				a[k][0][j] = 1;
			}
		}
		for (int j = 0; j < m; j++) {
			a[0][n-1][j] = 1;
		}
	}
}
char getschar() {
	clean_line();
	return getchar();
}
int main() {
	int n, m, h;
	Dimention d= Dimention::Z;
	printf("Enter size:");
	scanf_s("%i %i %i",&h,&n,&m);
	int a[10][10][10];
	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; j++) {
				a[k][i][j] = 0;
			}
		}
	}
	int g = 1;
	while (g != 0){
		print(n, m, h, a, d);
		printf("Enter command 1,2:");
		scanf_s("%i",&g);
		if (g == 1) {
			fil(n, m, h, a, d);
		}
		else if (g == 2) {
			char r;
			printf("Enter dimention:");
			r = getschar();
			if (r == 'X')d = Dimention::X;
			else if (r == 'Y')d = Dimention::Y;
			else if (r == 'Z')d = Dimention::Z;

		}
	}
}