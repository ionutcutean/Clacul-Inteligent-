 #include <iostream>
 #include <cmath>
 using namespace std;
 
 
 
 void codificare(float x, float a,float b, int lg, int *gene) 
 {
 
 	float x1=(x-a)/(b-a);
 	cout<<"transformata x1 este "<<x1;
 	for(int i=0;i<lg;i++)
 		{
 			x1=(x1*2);
			 gene[i]=(int)(x1);
 		//	cout<<gene[i]; 
			x1=x1-gene[i] ;
			
		 }
 	
 }
 
 void decodificare(float *x, float a,float b, int lg, int *gene) 
 {
 	//alocare??
 	
 	float x1=0;
 	for(int i=0;i<lg;i++)
 		{
 			x1=x1+gene[i]*1/pow(2,i+1);
			
		 }
		cout<<"\n transformatul x1 "<<x1;
	*x= a+x1*(b-a);
	cout<<"\n\n originalul decodificat este "<<*x;	
 }
 
 int main()
 {

float x,a,b,x1;
int lg=50;
int gene[lg];
 	
cout<<"dati capetele intervalului.... \n";
cout<<"a="; cin>>a;
cout<<"b="; cin>>b;
cout<<"dati valoare lui x din intervalul specificat \n";
cin>>x;

codificare(x,a,b,lg,gene);
cout<<"reprezentarea in binar este: ";
for(int i=0;i<lg;i++) 	
	cout<<gene[i];
 decodificare(&x,a,b,lg,gene);	
 }
