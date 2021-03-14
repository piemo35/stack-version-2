#include <iostream> 
#define MAX 5
using namespace std; 
  
class Stack
{
	public: 
		int st[MAX+1];
		int val;
		void set(int st[]);
		void stampa(int st[]);
		void push(int st[], int val);
		int vuoto(int st[]);
		int pieno(int st[]);
		void pop(int st[]);
};
  
int main() 
{
	int scelta;
	Stack myStack;
	myStack.set(myStack.st);
	
	cout << "Situazione coda: " << endl;

	if(myStack.vuoto(myStack.st)) cout << "\nCoda vuota" <<endl;
	else myStack.stampa(myStack.st);
	
	do{
		cout << "\nMENU\n1-PUSH \n2-POP \n0-Esci\n" << endl;
		cin >> scelta;

		switch(scelta){

			case 1:
			    if(myStack.pieno(myStack.st))
			    {
				    cout << "! ! ! ! ! ! ! CODA PIENA ! ! ! ! ! ! ! " << endl;
			    }else{
			        cout << "Scrivi il valore da inserire" <<endl;
			        cin >> myStack.val;
			        myStack.push(myStack.st,myStack.val);
			        myStack.stampa(myStack.st);
			    }
			    break;
			
			case 2:
			    if(myStack.vuoto(myStack.st))
			    {
				    cout << "! ! ! ! ! ! ! CODA VUOTA ! ! ! ! ! ! ! " << endl;
			    }else{
			        myStack.pop(myStack.st);
			        myStack.stampa(myStack.st);
			    }
			    break;

			default:
				break;
		}
	}while(scelta != 0);
	
	return 0;
	
}

void Stack::pop(int st[])
{
	st[st[0]] = 0;
	st[0] = st[0]-1;
}

void Stack::push(int st[], int val)
{
	st[0] = st[0]+1;
	st[st[0]] = val;
}

void Stack::stampa(int st[])
{
	cout << "\nStack:\n" <<endl;
	for(int i=MAX; i>0; i--) cout << st[i] << endl;
}

int Stack::vuoto(int st[])
{
	return st[0]==0 ? 0 : 1;
}

int Stack::pieno(int st[])
{
	return st[0]==MAX ? 0 : 1;
}

void Stack::set(int st[])
{
	for(int i=0; i<MAX+1; i++) st[i] = 0;
}
