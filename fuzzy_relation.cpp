//Author: Peng-Yu chen 
//Date: Unknown

#include<iostream>
#include<iomanip>
#define n 7

using namespace std;


void closure(double des[][n],double a[][n],double b[][n]){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			des[i][j] = 0;
			for(int k=0;k<n;k++){
				double tmp = min(a[i][k],b[k][j]);
				if(tmp > des[i][j]){
					des[i][j] = tmp;
				}
			}		
		}
	}
}

int main(){
	int ch_pt = 1;
	double b[n][n] = {0};
	double a[n][n] = {{1.0,0.0,0.8,0.0,0.6,0.8,0.0},
			{0.0,1.0,0.0,0.6,0.0,0.5,0.0},
			{0.8,0.0,1.0,0.8,0.0,0.0,0.0},
			{0.0,0.6,0.8,1.0,0.0,0.0,0.8},
			{0.6,0.0,0.0,0.0,1.0,0.6,0.0},
			{0.8,0.5,0.0,0.0,0.6,1.0,0.0},
			{0.0,0.0,0.0,0.8,0.0,0.0,1.0}};

	while(ch_pt > 0){
		ch_pt = 0;
		closure(&b[0],&a[0],&a[0]);
	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<fixed<<setprecision(1)<<b[i][j]<<" ";
				if(a[i][j] != b[i][j]){
					b[i][j] = max(a[i][j],b[i][j]);
					ch_pt++;
				}
				a[i][j] = b[i][j];
			}
				cout<<endl;
		}
		cout<<"# of change points: "<<ch_pt<<endl;
		cout<<"----------------------"<<endl;
	}

	return 0;
}
/***/
