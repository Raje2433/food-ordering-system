#include<iostream>
#include<fstream>
using namespace std;
class customer{
protected:
string name,email,username,username1,p,p1;
double mobileno;
int choice,cr,cr1;
char address[50];
public:
int getdata();
int login();
int getchoice();
virtual int getdish(){
return 0;
}
};
class nonveg:public customer{
protected:
int choice1,n1,c1[10],q1[10],total,p1[9]={150,114,185,185,170,150,13,40,50},p2[7]={105,186,160,160,146,130,66};
int p3[9]={120,160,180,150,16,50,13,40,60};
public:
nonveg();
void gethotel();
int getdish();
~nonveg(){}
};
class veg:public customer{
protected:
int choice2,n2,c2[10],q2[10],total2,pr1[7]={150,100,200,75,190,100,160},pr2[9]={99,170,150,70,80,60,80,40,150},pr3[9]={150,114,185,185,170,150,13,40,50};
public:
veg();
void gethotel1();
int getdish();
~veg(){}
};
class dessert:public customer{
protected:
int choice3,n3,c3[10],q3[10],total3,pi1[9]={1560,1560,940,940,940,113,113,113,113},pi2[7]={60,70,80,65,50,30,30};
public:
dessert();
void gethotel2();
int getdish();
~dessert(){}
};
class Bill:public customer{
private:
int m,pay,p2,up;
public:
void display(int p);
void mode();
void disp(){
cout<<"\n\n"<<name<<",you will receive your order soon at "<<address<<" and for further details about delivery,";
cout<<"we will contact you on "<<mobileno<<".";
cout<<"\n\n\n\t\t\tThankyou for your ordering with us!!!\n\n";
}
};
int main(){
customer *c1;
veg v1;
nonveg n1;
dessert d1;
Bill b1;
int ch1;
ofstream f1;
f1.open("sidenilo.txt",ios::out|ios::app);
ch1=b1.getdata();
int nv,v,d;
switch(ch1){
case 1:
c1=&n1;
n1.gethotel();
nv=c1->getdish();
b1.display(nv);
f1<<"Bill :"<<nv<<"\n";
f1.write((char*)&b1,sizeof(b1));
break;
case 2:
c1=&v1;
v1.gethotel1();
v=c1->getdish();
b1.display(v);
f1<<"Bill :"<<v<<"\n";
f1.write((char*)&b1,sizeof(b1));
break;
case 3:
c1=&d1;
d1.gethotel2();
d=c1->getdish();
b1.display(d);
f1<<"Bill :"<<d<<"\n";
f1.write((char*)&b1,sizeof(b1));
break;
}
b1.mode();
b1.disp();
f1<<"************************************************************************\n\n";
f1.close();
return 0;
}
int customer::login(){
cout<<"\nEnter the username :";
cin>>username1;
cout<<"\nEnter the password :";
cin>>p1;
cr=getchoice();
return cr;
}
int customer::getchoice(){
if(p1==p&&username1==username){
cout<<"\n\nEnter Your Choice :\n\t1.Non-Veg\n\t2.Veg\n\t3.Dessert\n";
cin>>choice;
return choice;
}
else{
if(username1!=username)
cout<<"\n\tYour username is incorrect,Please enter the correct username\n";
else if(p1!=p)
cout<<"\n\tYour Password is incorrect,Please enter the correct password\n";
else
cout<<"\n\tYour Username and Password is incorrect,Please enter the correct Username and Password\n";
login();
}
}
nonveg::nonveg(){
total=0;
}
void nonveg::gethotel(){
cout<<"\nWelcome to the non-veg restaurants\n";
cout<<"\n\n\t\t1.Mug and Beans\n\t\t2.Blind Chemistry\n\t\t3.Chopstix\n";
cout<<"\n\nPlease choose the hotel..........";
cin>>choice1;
}
int nonveg::getdish(){
if(choice1==1){
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.Giant meals - Rs.150\n";
cout<<"2.Veg sweet corn soup - Rs.114\n";
cout<<"3.Veg schezwan fried rice - Rs.185\n";
cout<<"4.Fried momos veg - Rs.185\n";
cout<<"5.Fried veg burger - Rs.170\n";
cout<<"6.Butter paneer - Rs.150\n";
cout<<"7.Idli - Rs.13\n";
cout<<"8.Dosa - Rs.40\n";
cout<<"9.Naan - Rs.50\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n1;
for(int i=0;i<n1;i++){
cout<<"Enter the food menu number :";
cin>>c1[i];
cout<<"Enter the quantity of the food :";
cin>>q1[i];
}
for(int i=0;i<n1;i++){
for(int j=1;j<=9;j++){
if(j==c1[i])
total=total+(q1[i]*p1[j-1]);
}
}
return total;
}
else if(choice1==2){
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.Paneer 65 - Rs.105\n";
cout<<"2.chicken Seekh Kebab - Rs.186\n";
cout<<"3.chicken Kebab - Rs.160\n";
cout<<"4.Chicken Schezwan Fried rice - Rs.160\n";
cout<<"5.Chicken Sandwich - Rs.146\n";
cout<<"6.Butterscotch shake - Rs.130\n";
cout<<"7.Sweet and salted lassi - Rs.66\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n1;
for(int i=0;i<n1;i++){
cout<<"Enter the food menu number :";
cin>>c1[i];
cout<<"Enter the quantity of the food :";
cin>>q1[i];
}
for(int i=0;i<n1;i++){
for(int j=1;j<=7;j++){
if(j==c1[i])
total=total+(q1[i]*p2[j-1]);
}
}
return total;
}
else{
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.Gobi 65 - Rs.120\n";
cout<<"2.Boneless chicken - Rs.160\n";
cout<<"3.Butter chicken - Rs.180\n";
cout<<"4.Butter Paneer - Rs.150\n";
cout<<"5.Parotta - Rs.16\n";
cout<<"6.Naan - Rs.50\n";
cout<<"7.Idli - Rs.13\n";
cout<<"8.Dosa - Rs.40\n";
cout<<"9.Grilled chicken(quarter) - Rs.60\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n1;
for(int i=0;i<n1;i++){
cout<<"Enter the food menu number :";
cin>>c1[i];
cout<<"Enter the quantity of the food :";
cin>>q1[i];
}
for(int i=0;i<n1;i++){
for(int j=1;j<=7;j++){
if(j==c1[i])
total=total+(q1[i]*p3[j-1]);
}
}
return total;
}
}
int customer::getdata(){
ofstream f1;
f1.open("sidenilo.txt",ios::out|ios::app);
cout<<"\n\t\t\t===========================================================\n";
cout<<"\n\t\t\t SIDENILO ORDERING SYSTEM \n";
cout<<"\n\t\t\t===========================================================\n";
cout<<endl<<endl;
cout<<"\t\t\t'Food is the symbolic of love when words are inadequate'\n\n";
cout<<"\t\t\t\t\tSignup and Login\n";
cout<<"\nEnter Name :";
cin>>name;
f1<<"Name :"<<name<<"\n";
cout<<"\nEnter username :";
cin>>username;
f1<<"Username :"<<username<<"\n";
cout<<"\nEnter email :";
cin>>email;
f1<<"Email :"<<email<<"\n";
cout<<"\nEnter password :";
cin>>p;
f1<<"password :"<<p<<"\n";
cout<<"\nEnter Mobile Number :";
cin>>mobileno;
f1<<"Mobilenumber :"<<mobileno<<"\n";
cout<<"\nEnter address :";
cin>>address;
f1<<"Address :"<<address<<"\n";
cout<<"\n\nThankyou for signing up.........";
cr1=login();
return cr1;
f1.close();
}
veg::veg(){
total2=0;
}
void veg::gethotel1(){
cout<<"\nWelcome to the veg restaurants\n";
cout<<"\n\n\t\t1)Sangeethas\n\t\t2)Anandha Bhavan\n\t\t3)Veg Paradise\n";
cout<<"\n\nPlease choose the hotel..........";
cin>>choice2;
}
int veg::getdish(){
if(choice2==1){
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.meals - Rs.150\n";
cout<<"2.variety rice - Rs.100\n";
cout<<"3.fried rice - Rs.200\n";
cout<<"4.Butter naan - Rs.75\n";
cout<<"5.Panneer butter masala - Rs.190\n";
cout<<"6.Gobi 65 - Rs.100\n";
cout<<"7.Gobi manjurian - Rs.160\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n2;
for(int i=0;i<n2;i++){
cout<<"Enter the food menu number :";
cin>>c2[i];
cout<<"Enter the quantity of the food :";
cin>>q2[i];
}
for(int i=0;i<n2;i++){
for(int j=1;j<=7;j++){
if(j==c2[i])
total2=total2+(q2[i]*pr1[j-1]);
}
}
return total2;
}
else if(choice2==2){
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.Paneer Shawarma - Rs.99\n";
cout<<"2.Paneer Shawarma pizza - Rs.170\n";
cout<<"3.Corn Shawarma pizza - Rs.150\n";
cout<<"4.Lemon and mint mojito - Rs.70\n";
cout<<"5.Blue curaco mojito - Rs.80\n";
cout<<"6.Fruit salad with icecream - Rs.60\n";
cout<<"7.Brownie with ice cream - Rs.80\n";
cout<<"8.Lime juice - Rs.40\n";
cout<<"9.Kitkat milkshake - Rs.150\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n2;
for(int i=0;i<n2;i++){
cout<<"Enter the food menu number :";
cin>>c2[i];
cout<<"Enter the quantity of the food :";
cin>>q2[i];
}
for(int i=0;i<n2;i++){
for(int j=1;j<=9;j++){
if(j==c2[i])
total2=total2+(q2[i]*pr2[j-1]);
}
}
return total2;
}
else{
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.Giant meals - Rs.150\n";
cout<<"2.Veg sweet corn soup - Rs.114\n";
cout<<"3.Veg schezwan fried rice - Rs.185\n";
cout<<"4.Fried momos veg - Rs.185\n";
cout<<"5.Fried veg burger - Rs.170\n";
cout<<"6.Butter paneer - Rs.150\n";
cout<<"7.Idli - Rs.13\n";
cout<<"8.Dosa - Rs.40\n";
cout<<"9.Naan - Rs.50\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n2;
for(int i=0;i<n2;i++){
cout<<"Enter the food menu number :";
cin>>c2[i];
cout<<"Enter the quantity of the food :";
cin>>q2[i];
}
for(int i=0;i<n2;i++){
for(int j=1;j<=9;j++){
if(j==c2[i])
total2=total2+(q2[i]*pr3[j-1]);
}
}
return total2;
}
}
dessert::dessert(){
total3=0;
}
void dessert::gethotel2(){
cout<<"\nWelcome to the non-veg restaurants\n";
cout<<"\n\n\t\t1)Ibaco\n\t\t2)Famous Jigarthanda\n\t\t3)Hott Spott\n";
cout<<"\n\nPlease choose the hotel..........";
cin>>choice3;
}
int dessert::getdish(){
if(choice3==1){
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.Black forest icecream cake - Rs.1560\n";
cout<<"2.Blackcurrent Rich Cream Icecream Cake - Rs.1560\n";
cout<<"3.Chocolate Overload icecream cake - Rs.940\n";
cout<<"4.Swiss choco Symphony icecream cake - Rs.940\n";
cout<<"5.Caramel walnut icecream cake - Rs.940\n";
cout<<"6.Bean vanilla icecream - Rs.113\n";
cout<<"7.Belgian Chocoholic icecream - Rs.113\n";
cout<<"8.Butterscotch Bliss icecream - Rs.113\n";
cout<<"9.Cotton candy icecream - Rs.113\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n3;
for(int i=0;i<n3;i++){
cout<<"Enter the food menu number :";
cin>>c3[i];
cout<<"Enter the quantity of the food :";
cin>>q3[i];
}
for(int i=0;i<n3;i++){
for(int j=1;j<=9;j++){
if(j==c3[i])
total3=total3+(q3[i]*pi1[j-1]);
}
}
return total3;
}
else if(choice3==2){
cout<<"\t\t================================\n";
cout<<"\t MENU\n";
cout<<"\t\t================================\n";
cout<<"1.Mini Jigarthanda - Rs.60\n";
cout<<"2.Jumbo Jigarthanda - Rs.70\n";
cout<<"3.Special Jigarthanda - Rs.80\n";
cout<<"4.Jigarthanda with nuts - Rs.65\n";
cout<<"5.Basanthi - Rs.50\n";
cout<<"6.Rasamlai(2 pcs) - Rs.30\n";
cout<<"7.Rosemilk - Rs.30\n";
cout<<"\n\nEnter the number of foods you are going to order :";
cin>>n3;
for(int i=0;i<n3;i++){
cout<<"Enter the food menu number :";
cin>>c3[i];
cout<<"Enter the quantity of the food :";
cin>>q3[i];
}
for(int i=0;i<n3;i++){
for(int j=1;j<=9;j++){
if(j==c3[i])
total3=total3+(q3[i]*pi2[j-1]);
}
}
return total3;
}
else
cout<<"Service to this hotel is currently unavailable....\n";
}
void Bill::display(int p){
cout << "\n\t\t ================================================"<<endl;
cout << "\t\t| Food Ordering System |"<<endl;
cout << "\t\t ================================================"<<endl;
cout << endl;
cout << endl;
cout << "\t\t\t Bill No : CP51 Order : NB1353"<<endl;
cout << endl;
cout << endl;
cout << "\t\t\t Cashier : Harry"<<endl;
cout << endl;
cout<<"\t\t\t\t YOUR TOTAL BILL IS Rs."<<p<<endl;
cout<<"\t\t\t\t\t";
cout << "\n\t\t ================================================"<<endl;
}
void Bill::mode(){
cout<<"\n\n\t\tEnter the choice you are going to pay the payment \n";
cout<<"\n\n\t\t1.Cash on delivery\n\n\t\t2.UPI\n\n";
cin>>m;
if(m==1)
cout<<"\n\tThankyou for choosing cash on delivery you will receive your bill and order soon\n\n";
else{
cout<<"Enter UPI ID :";
cin>>up;
cout<<"Enter password :";
cin>>p2;
cout<<"Enter the payment :";
cin>>pay;
cout<<"Payment paid successfully\n\n";
}
}
