 #include <iostream>
 #include <cmath>
 #include <stdlib.h>

 #include <time.h>
 using namespace std;
 
 //TAD Cromozom
   
 struct TCromozom{
 	float X[100];
 	int gene[3000];
	double fitness;		
 };
 
 int lg; //lungimea de reprezentare
 float a[100]; //limite interval definitie
 float b[100]; //limite interval definitie
 int n;
 TCromozom P[100];
 TCromozom PS[100];
 int dim; //dimensiunea populatiei 
 
 
 double FUNCTIE(TCromozom &c)
 {
 	//FUNCTIA SFERA GENERALIZATA - de minimizat
 	double suma=0;
 	for(int i=0;i<n;i++)
 		suma+=c.X[i]*c.X[i];
 	
 	return 1/(1+suma);
 }
 
 void Evaluare()
 {
 	for(int i=0;i<dim;i++)
 		//evaluez individul P[i]
 		{
 			P[i].fitness =FUNCTIE(P[i]);
		 }
 }
 
 void copy(TCromozom &dest, TCromozom sursa)
 {
 	for(int i=0;i<n;i++)
 		dest.X[i]=sursa.X[i];
	for(int i=0;i<n*lg;i++)
 		dest.gene[i]=sursa.gene[i];
	 dest.fitness =sursa.fitness; 
 }
 
 int selectie_concurs_binar();
 int select_prop();
 
 void SELECTIE()
 {int ind;
 	for(int i=0;i<dim;i++)
 		{ //copiez P[ind] in PS[i]
 		//ind=selectie_concurs_binar();
 		ind=select_prop();
 		//cout<<"!!!!!!!!!!!!!!!!  "<<ind;
		 copy(PS[i],P[ind]);
 			
		 }
 }
 
 
 
 
 
 
 void PRINT_POP(TCromozom *pop, int size)
 {
 	for(int i=0;i<size;i++)
 		{
 			for(int k=0;k<n;k++)
 				cout<<pop[i].X[k]<<" "; 
 			cout<<pop[i].fitness<<endl; 
		 }
 }
 
 
 int selectie_concurs_binar()
 {
 	int ind1,ind2;
 	
 	//generez aleator doua pozitii in populatia P , de la 0 la dim-1
 	
 	ind1 =dim*((double) rand() / (RAND_MAX));
 	ind2=dim*((double) rand() / (RAND_MAX));
 	cout<<ind1<<" "<<ind2;
 	if (P[ind1].fitness >P[ind2].fitness )
 		return ind1;
 	else 
 		return ind2;
 }
 
 void generare(TCromozom &c) //generez aleator sol posibila
 {
 	for(int i=0;i<n;i++)
 	{
 		c.X[i]= a[i]+(b[i]-a[i])*((double) rand() / (RAND_MAX));
	 }
 }
 
 void print(TCromozom c)
 {
 	
cout<<"\n IN REAL";
for(int i=0;i<n;i++) 	
	cout<<c.X[i];
/* 	
cout<<"\n IN BINAR";
for(int i=0;i<n*lg;i++) 	
	cout<<c.gene[i];
 */
cout<<"\t "<< c.fitness;  
 }
 void read(TCromozom &c)
 {
cout<<"dati valoare lui x din intervalul specificat \n";
for(int i=0;i<n;i++)
{

cin>>c.X[i] ;
}
 	
 }
 
 int select_prop()
 {
 	double suma=0;
 	for(int i=0;i<dim;i++)
 		suma=suma+P[i].fitness;
 	suma=suma*((double) rand() / (RAND_MAX));
 	int ind; //pozitia individului selectat
 	ind=0;
 	while(suma>=0)
 	{
 		suma=suma-P[ind].fitness;
		 ind++; 
	 }
	 
	 //ind - output
	 return ind;
 }
 
 
 void codificare(TCromozom &c) 
 {int k;
 for(k=0;k<n;k++) //parcurgem secventa x1,x2,...,xn
 {
 // x[k] - convertit in lg valori binare in gene[]
 	float x1=(c.X[k]-a[k])/(b[k]-a[k]);
 	//cout<<"transformata x1 este "<<x1;
 	for(int i=0;i<lg;i++)
 		{
 			x1=(x1*2);
			 c.gene[i+k*lg]=(int)(x1);
 			cout<<c.gene[i]; 
			x1=x1-c.gene[i+k*lg] ;
			
		 }
}
 }
 
 void decodificare(TCromozom &c) 
 {
 	//alocare??
for (int k=0;k<n;k++)
{
//il facel inapoi pe c.X[k]
//c.X[k]=0;
 	float x1=0;
 	for(int i=0;i<lg;i++)
 		{
 			x1=x1+c.gene[i+k*lg]*1/pow(2,i+1);
			
		 }
		//cout<<"\n transformatul x1 "<<x1;
	c.X[k] = a[k]+x1*(b[k]-a[k]);
	//cout<<"\n\n originalul decodificat este "<<*x;	
 }
}
 int main()
 {
srand(time(0));

float x,x1;
int gene[lg];
int i;
cout<<"\n Cate variabile are functia?"; cin>>n;
cout<<"\n Care este lungimea cromozomului?"; cin>>lg;
cout<<"\n Care este lungimea POPULTIEI?"; cin>>dim;

for( i=0;i<n;i++)
{

cout<<"dati capetele intervalului.... \n";
cout<<"a="; cin>>a[i];
cout<<"b="; cin>>b[i];
}
int j;
//parcurgem populatia
for (j=0;j<dim;j++)
	{
//	read(P[j]);
	generare(P[j]);
	Evaluare();
	codificare(P[j]);
	print(P[j]);
	}
SELECTIE();
PRINT_POP(PS,dim);
}

