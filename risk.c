#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int attack(int defenders){

	//needed attackers
	int needed=0;

	while(defenders>0){
		//generate attacker rolls
		int a1=rand()%6+ 1;
		int a2=rand()%6+ 1;
		int a3=rand()%6+ 1;

		//generate defender rolls
		int d1=rand()%6+ 1;
		int d2=rand()%6+ 1;

		//storage for sorting rolls
		int temp=0;

		//sort dice rolls
		if(a3>a2){
                	temp=a2;
                	a2=a3;
                	a3=temp;
        	}
		if(a2>a1){
			temp=a1;
			a1=a2;
			a2=temp;
		}

		//calculate losses if there are more then two defenders
		if(defenders>=2){
			if(d2>d1){
                		temp=d2;
                		d1=d2;
                		d2=temp;
			}
			//if attacker roll is higher kill a defender
			if(a1>d1){
			defenders--;
			}
			//otherwise add to attackers needed
			else{
				needed++;
			}

			if(a2>d2){
                        	defenders--;
                	}
                	else{
                        	needed++;
                	}
		}

		//calculate losses if there is only one defender
		else{
			 if(a1>d1){
                        	defenders--;
                	}
                	else{
                        	needed++;
                	}
		}
	}
	return needed;
}

void print(int total){

	 cout<<"Total attackers needed: ";

        if(total<3){
                cout<<"3"<<endl;
        }
        else{
                cout<<total+3<<endl;
        }


}

int main(){
	int defenders=0;

	int total=0;

	int runs=100000;

	cout<<"Enter the number of defenders: "<<endl;
        cin>>defenders;

	srand(time(0));

	for(int i=0;i<runs;i++){
		total+=attack(defenders);
	}

	total=total/runs;

	print(total);

	return 0;
}
