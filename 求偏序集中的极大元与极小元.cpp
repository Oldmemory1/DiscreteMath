#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
using namespace std;
class Link{
	private:
	char ConnectedData;
	public:
	Link* NextLink;
	public:
	char GetConnectedData(){
		return this->ConnectedData;
	}
	void SetConnectedData(char c){
		this->ConnectedData=c;
		this->NextLink=NULL;
	}
};
class Element{
	private:
	int SerialNumber;
	char Data;
	bool HaveBeenAnEnd;
	bool HaveBeenASource;
	public:
	Link* ThisIsSource;
	Link* ThisIsEnd;
	Element* NextElement;
	public:
	void Create(int number,char data){
		this->SerialNumber=number;
		this->Data=data;
		this->HaveBeenAnEnd=false;
		this->HaveBeenASource=false;
		this->ThisIsSource=NULL;
		this->ThisIsEnd=NULL;
	}
	bool GetWhetherItIsAnEnd(){
		return this->HaveBeenAnEnd;
	}
	bool GetWhetherItIsASource(){
		return this->HaveBeenASource;
	}
	int GetSerialNumber(){
		return this->SerialNumber;
	}
	char GetData(){
		return this->Data;
	}
	void SetItIsASource(){
		this->HaveBeenASource=true;
	}
	void SetItIsAEnd(){
		this->HaveBeenAnEnd=true;
	}
    void OutPutInformation(){
    	Link* ATempLink=new Link;
    	Link* BTempLink=new Link;
    	ATempLink=this->ThisIsSource;
    	BTempLink=this->ThisIsEnd;
    	printf("里面的字符数据：%c\n",this->GetData());
	    printf("以此点为起点的数据：\n");
		while(ATempLink!=NULL){
	    	printf("%c",ATempLink->GetConnectedData());
	    	ATempLink=ATempLink->NextLink;
		}
		printf("\n");
		printf("以此点为终点的数据：\n");
		while(BTempLink!=NULL){
			printf("%c",BTempLink->GetConnectedData());
			BTempLink=BTempLink->NextLink;
		}
		printf("\n");
	} 
};
int main(){
	char TempData;
	int DataNumber=0;
	Element* Start=new Element;
	Element* temp=new Element;
	while(true){
		scanf("%c",&TempData);
		if(TempData==','){
			continue;
		}else if(TempData=='\n'){
			break;
		}else{
			if(DataNumber==0){
				Element* NewElement=new Element;
				NewElement->Create(DataNumber,TempData);
				NewElement->NextElement=NULL;
				Start=NewElement;
				temp=NewElement;
				DataNumber++;
			}else if(DataNumber>0){
				Element* NewElement=new Element;
				NewElement->Create(DataNumber,TempData);
				NewElement->NextElement=NULL;
				temp->NextElement=NewElement;
				temp=temp->NextElement;
				DataNumber++;
			} 
		}
	}
	/*while(Start!=NULL){
		printf("%c\n",Start->GetData());
		Start=Start->NextElement;
	}*/
	char TempData1,TempData2;
	char judge;
	Element* CheckStart=new Element;
	Element* CheckEnd=new Element;
	Link* TempLink1=new Link;
	Link* TempLink2=new Link;
	
	while(true){
		scanf("<%c,%c>",&TempData1,&TempData2);
		judge=getchar();
		
		for(CheckStart=Start;CheckStart!=NULL;CheckStart=CheckStart->NextElement){
			if(CheckStart->GetData()==TempData1){
				if(CheckStart->ThisIsSource==NULL){
					Link* NewLink=new Link;
					NewLink->SetConnectedData(TempData2);
					CheckStart->ThisIsSource=NewLink;
					CheckStart->SetItIsASource(); 
				}else if(CheckStart->ThisIsSource!=NULL){
					for(TempLink1=CheckStart->ThisIsSource;TempLink1->NextLink!=NULL;TempLink1=TempLink1->NextLink){
						//结束之后,TempLink1一定在CheckStart的ThisisSource的最后一项 
					}
					Link* NewLink=new Link;
					NewLink->SetConnectedData(TempData2);
					TempLink1->NextLink=NewLink;
				}
			}
		}
		for(CheckEnd=Start;CheckEnd!=NULL;CheckEnd=CheckEnd->NextElement){
			if(CheckEnd->GetData()==TempData2){
				if(CheckEnd->ThisIsEnd==NULL){
					Link* NewLink=new Link;
					NewLink->SetConnectedData(TempData1);
					CheckEnd->ThisIsEnd=NewLink;
					CheckEnd->SetItIsAEnd();
				}else if(CheckEnd->ThisIsEnd!=NULL){
					for(TempLink2=CheckEnd->ThisIsEnd;TempLink2->NextLink!=NULL;TempLink2=TempLink2->NextLink){
						//
					}
					Link* NewLink=new Link;
					NewLink->SetConnectedData(TempData1);
					TempLink2->NextLink=NewLink;
				}
			}
		}
		if(judge==','){
			continue;
		}else if(judge=='\n'){
			break;
		}
	}
	queue<char>MaxiniumElements;
	queue<char>MinimalElements;
	char Storage;
	while(Start!=NULL){
		if(Start->GetWhetherItIsAnEnd()==false){
			MinimalElements.push(Start->GetData());
		}
		if(Start->GetWhetherItIsASource()==false){
			MaxiniumElements.push(Start->GetData());
		}
		//Start->OutPutInformation();
		Start=Start->NextElement;
	}
	while(MinimalElements.empty()==false){
		Storage=MinimalElements.front();
		MinimalElements.pop(); 
		if(MinimalElements.empty()==true){
			printf("%c\n",Storage);
		}else if(MinimalElements.empty()==false){
			printf("%c,",Storage); 
		}

	} 
	while(MaxiniumElements.empty()==false){
		Storage=MaxiniumElements.front();
		MaxiniumElements.pop();
		if(MaxiniumElements.empty()==true){
			printf("%c\n",Storage);
		}else if(MaxiniumElements.empty()==false){
			printf("%c,",Storage); 
		}
 
	}
}
