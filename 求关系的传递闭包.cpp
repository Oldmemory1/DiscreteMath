#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std; 
class Warshall{
	public:
	int Calc[11][11];
	int Result[11][11];
	private:
	int DataNum;
	public:
	void Initialization(){
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++){
				this->Result[i][j]=0;
				this->Calc[i][j]=0;
			}
		}
		this->DataNum=0;
	}
	void GetData(){
		char temp;
		int n;
		for(n=0;n<11;n++){
			scanf("%d",&this->Calc[0][n]);
			temp=getchar();
			if(temp=='\n'){
			   break;				
			}
		}
		this->DataNum=n;
		//cout<<this->DataNum<<endl;
		for(int i=1;i<=this->DataNum;i++){
			for(int j=0;j<=this->DataNum;j++){
				scanf("%d",&this->Calc[i][j]);
				getchar();
			}
		}
	}
    void OutPutCalc(){
    	for(int i=0;i<=this->DataNum;i++){
    		for(int j=0;j<=this->DataNum;j++){
    			if(j!=this->DataNum){
    				printf("%d ",this->Calc[i][j]);
				}else if(j==this->DataNum){
					printf("%d\n",this->Calc[i][j]);
				}
			}
		}
	}
	void OutPutResult(){
		for(int i=0;i<=this->DataNum;i++){
    		for(int j=0;j<=this->DataNum;j++){
    			if(j!=this->DataNum){
    				printf("%d ",this->Result[i][j]);
				}else if(j==this->DataNum){
					printf("%d\n",this->Result[i][j]);
				}
			}
		}
	}
	void GetResult(){
		for(int i=0;i<=this->DataNum;i++){
			for(int j=0;j<=this->DataNum;j++){
				this->Result[i][j]=this->Calc[i][j];
				if(this->Result[i][j]>=1){
					this->Result[i][j]=1;
				}
			}
		} 
	}
	void Cal(){
		for(int b=0;b<=this->DataNum;b++){
			for(int a=0;a<=this->DataNum;a++){
				if(this->Calc[a][b]==1&&a!=b){
					//把第a行加到第b行上即可
					for(int w=0;w<=this->DataNum;w++){
						this->Calc[a][w]=this->Calc[b][w]+this->Calc[a][w];
					} 
				}
			}
		}
	}
}; 
int main(){
	Warshall* Calculation=new Warshall;
	Calculation->Initialization();
	Calculation->GetData();
	//Calculation->OutPutCalc();
	Calculation->Cal();
	Calculation->GetResult();
	Calculation->OutPutResult();
}
