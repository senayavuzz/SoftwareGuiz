//Cevap Anahtarý : B  C  C  D  D  D  C  B  C  C
//SENANUR YAVUZ  
//EDANUR BULUZ  
#include <iostream> 
#include <windows.h> 
#include <locale.h> 
#include <time.h>   
 
using namespace std;

class program
{
public:
	void temizle(){   // temizleme fonksiyonu
		system("CLS");
	}
	
	void gotoxy(short x, short y) // düzlemde x ve y koordinatlarýný kullanarak nerede konumlanacaðýný belirtir.
	{ 
		HANDLE hConsoleOutput; 
		COORD Cursor_Pos={x-1,y-1}; 
		hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleCursorPosition(hConsoleOutput,Cursor_Pos); 
	} 

	void baslangic() //oyuna geçmeden önce yapýlan tanýtým.
	{ 
		int i,j; 
		
		gotoxy(45,20); cout<<"MÝLYONER YARIÞMASINA HOÞGELDÝNÝZ "; 
		gotoxy(50,14); cout<<" OYUN YÜKLENÝYOR"; 
		
		for(j=40;j<=80;j++) 
		{ 
			gotoxy(j,16);cout<<"-"; 
			gotoxy(j,18);cout<<"-";
		} 
		for(i=40;i<=80;i++) 
		{  
			gotoxy(i,17);cout<<"#";
		    Sleep(50); 
		} 
	} 
	void giris()
	{	
		gotoxy(10,8);	cout <<"\t\t\t\t****YARIÞMA KURALLARI****"<<endl;
		gotoxy(10,10);	cout <<"Oyun içerisinde toplam 10 adet soru bulunmaktadýr."<<endl;
		gotoxy(10,12);	cout<<"Tüm sorularýn doðru cevaplanmasý durumunda oyuncu 1 milyon kazanacaktýr.\n"<<endl;
		gotoxy(10,14);	cout<<"1-Verilen süre bittikten sonra cevabýnýzý girmelisiniz.\n"<<endl;
		gotoxy(10,16);  cout<<"2-1.(birinci) sorudan 5.(beþinci) soruya kadar her soru için 1 dakikanýz bulunmaktadýr.\n"<<endl;
	    gotoxy(10,18);	cout<<"3-6.(altýncý) soru ve sonraki sorularda zaman kýsýtlamasý bulunmamaktadýr.\n "<<endl;
		gotoxy(10,20);  cout<<"4-Oyun içerisinde 3 adet joker hakkýnýz bulunmaktadýr."<<endl;
		gotoxy(10,22);  cout<<"Bu jokerler seyirci jokeri(S/s) ,yarý yarýya cevap jokeri(Y/y) ve telefon jokeri(T/t).\n"<<endl;
		gotoxy(10,24);  cout<<"5-Soruyu cevaplamak istemezseniz çekilme hakkýnýzý (P/p) kullanabilirsiniz.\n"<<endl;
	  
		Sleep(7000); 
	}
};

class jus {          //programýn sürdürülebilir olmasý geliþtirme sürecinde ek joker hakký tanýmlamalarý gibi iþlemlerin rahat olabilmesi için açtýk.
	private:
		int s_jokersayisi=1,t_jokersayisi=1,y_jokersayisi=1;  //joker sayýlarýný dýþarýdan eriþime kapatmak için private kullandýk.
	public:
	    int toplam=1000;
	    
	    void paraIslem()	{    //para ödülünü fonksiyonla çaðýrmýþ oluruz.
		toplam=toplam*2;
		cout<<" toplam para ödülü:"<<toplam<<endl;
		}
	
	    void set_s_joker(int s)	{   //deðiþkenler private olduðundan get ve set fonksiyonlarý ile belirtildi.
	    	s_jokersayisi=s;
		}
		int get_s_joker(){
			return s_jokersayisi;
		}
		void set_t_joker(int t)	{
	    	t_jokersayisi=t;
		}
		int get_t_joker(){
			return t_jokersayisi;
		}
		 void set_y_joker(int y)	{
	    	y_jokersayisi=y;
		}
		int get_y_joker(){
			return y_jokersayisi;
		}
		void s_joker(int);   
		void t_joker(int);
		void y_joker(int);
		void cekilme();		
};
void jus::s_joker(int x) //seyirci jokeri fonksiyonu
{    
    if(s_jokersayisi==0)         //joker sayýsý kontrol
	{
		cout<<"seyirci joker hakkýnýzý kullandýnýz"<<endl;
	}
    else 
	{
		if(x==1){
			cout<<"%7 A\n%50 B\n%13 C\n%30 D\n";
			s_jokersayisi--;
		}
		else if(x==2){
			cout<<"%7 A\n%10 B\n%63 C\n%20 D\n";
			s_jokersayisi--;
	   	}
	   	else if(x==3){
	   		cout<<"%15 A\n%30 B\n%50 C\n%5 D\n";
			s_jokersayisi--;
		}
	    else if(x==4){
	    	cout<<"%10 A\n%30 B\n%5 C\n%55 D\n";
			s_jokersayisi--;
		}
		else if(x==5){
			cout<<"%15 A\n%15 B\n%11 C\n%59 D\n";
			s_jokersayisi--;	
		}
		else if(x==6){
			cout<<"%15 A\n%15 B\n%11 C\n%59 D\n";
			s_jokersayisi--;
		}
		else if(x==7){
			cout<<"%15 A\n%15 B\n%59 C\n%11 D\n";
			s_jokersayisi--;
		}
		else if(x==8){
			cout<<"%5 A\n%75 B\n%9 C\n%11 D\n";
			s_jokersayisi--;	
		}
		else if(x==9){
			cout<<"%5 A\n%9 B\n%75 C\n%11 D\n";
			s_jokersayisi--; 
		}
		else if(x==10){
		    cout<<"%5 A\n%9 B\n%75 C\n%11 D\n";
			s_jokersayisi--;	
		}
    }			
}
void jus::t_joker(int y) // telefon jokeri fonksiyonu
{  
	if(t_jokersayisi==0)
	{
		cout<<"telefon joker hakkýnýzý kullandýnýz"<<endl;
	}
	else
	{
		if(y==1){	
		    cout<<"\nCevabýn B olabileceðini düþünüyorum .\n";
			t_jokersayisi--;
		}
		else if(y==2){
		    cout<<"\n cevap C olabilir.\n";
			t_jokersayisi--; 	
		}
		else if(y==3){
		    cout<<"\nCevabýn C olabileceðini düþünüyorum.\n";
			t_jokersayisi--;
		}
		else if(y==4){
			cout<<"\nCevabýn D olduðundan eminim .\n";
			t_jokersayisi--;
		}
		else if(y==5){
			cout<<"\nCevabýn D olduðundan eminim.\n";
			t_jokersayisi--;
		}
		else if(y==6){
			cout<<"\nCevabýn D olduðundan eminim.\n";
			t_jokersayisi--;
		}
		else if(y==7){
			cout<<"\nCevabýn C olabileceðini düþünüyorum.\n";
			t_jokersayisi--;
		}
		else if(y==8){
			cout<<"\ncevap B olabilir.\n";
			t_jokersayisi--;
		}
		else if(y==9){
			cout<<"\ncevap C olabilir.\n";
			t_jokersayisi--;
		}
		else if(y==10){
			cout<<"\nCevabýn C olabileceðini düþünüyorum.\n";
			t_jokersayisi--;
		}
	}	
}
void jus::y_joker(int z) //%50 joker fonksiyonu
{   
	if(y_jokersayisi==0)
	{
		cout<<"%50 joker hakkýnýzý kullandýnýz."<<endl;
	}
	else
	{
		if(z==1){
			cout<<"Cevap B veya D";
			y_jokersayisi--;
		}
		else if(z==2){
		    cout<<"Cevap C veya D";
			y_jokersayisi--;
		}
		else if(z==3){
			cout<<"Cevap C veya D";
			y_jokersayisi--;
		}
		else if(z==4){
			cout<<"Cevap C veya D";
			y_jokersayisi--;
		}
		else if(z==5){
			cout<<"Cevap C veya D";
			y_jokersayisi--;
		}
		else if(z==6){
		    cout<<"Cevap C veya D";
			y_jokersayisi--;	
		}
		else if(z==7){
			cout<<"Cevap C veya D";
			y_jokersayisi--;
		}
		else if(z==8){
			cout<<"Cevap A veya B";
			y_jokersayisi--;
		}
		else if(z==9){
			cout<<"Cevap A veya C";
			y_jokersayisi--;
		}
		else if(z==10){
			cout<<"Cevap A veya C";
			y_jokersayisi--;	
		}
	}	
}
void jus::cekilme()
{
	cout <<"çekilme hakkýnýzý kullandýnýz ."<<endl;
	cout<<"toplam para ödülünüz : "<<toplam;
	exit(0);			
}
class question : public program,jus // program ve jus classlarýnda olan fonksiyonlar ve deðiþkenler extend ediliyor.
{	
	public:
		int i; // for döngülerinin içinde kullandýðýmýz i deðiþkeni
	void soru1()
	{
		char cvp1;
		
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t    1)c++ programlama dilinde aþaðýdakilerden hangisi doðru bir isimlendirme deðildir? \n\n"<<endl;
		cout<<"       \t\t      a) int _sayi     b)int .deger      c) float ortalama_sonuc     d) string dogumGunu\n\n"<<endl;
		
   		for(i=40;i<=80;i++)    // süre için gereken döngü.
		{ 
			gotoxy(i,20);
			cout<<"#";
			Sleep(100); 
		}
		cevap1:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp1;
	  	switch(cvp1)
		{
			case 'B' :   // doðru cevap verildiðinde çalýþacak olan kod parçasý.
			case 'b':  
				temizle();         
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
				paraIslem();			
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :    // seyirci jokeri çaðýrýldýðýnda çalýþacak olan kod parçasý.
			case 's':
			    s_joker(1);     // seyirci jokeri çaðýrýldýðýnda jus classýndan çaðýrýlacak olan fonksiyon.
			    goto cevap1; break;

			case 'T' :   // telefon jokeri çaðýrýldýðýnda çalýþacak olan kod parçasý.
			case 't':
		        t_joker(1);     // telefon jokeri çaðýrýldýðýnda jus classýndan çaðýrýlacak olan fonksiyon.
				goto cevap1; break;
				
			case 'Y' :  // %50 jokeri çaðýrýldýðýnda çalýþacak olan kod parçasý.
			case 'y':
			    y_joker(1);     // %50 jokeri çaðýrýldýðýnda jus classýndan çaðýrýlacak olan fonksiyon.
			    goto cevap1; break;
			    
			case 'P':    //çekilme hakký çaðýrýldýðýnda çalýþacak olan kod parçasý.
			case 'p':
		       cekilme();      //çekilme hakký çaðýrýldýðýnda jus classýndan çaðýrýlacak olan fonksiyon.
		       
			default:    // istenilen cevap verilmediðinde çalýþacak olan kod parçasý.
				temizle();
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);	
		}		
	}
	
	void soru2()
	{
		char cvp2;
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t    2-dünyadaki ilk yazýlýmcý kimdir? \n\n"<<endl;
		cout<<"       \t\t     a) Charles babbage     b) John Backus    c) Ada augusta lovelace    d) Guido Van Rossum\n\n"<<endl;
		
   		for(i=40;i<=80;i++) 
		{ 
			gotoxy(i,20);
			cout<<"#";
			Sleep(100); 
		}
		cevap2:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp2;
	  	switch(cvp2)
		{
			case 'C' : 
			case 'c' :  
			    temizle();        
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
		  		paraIslem();
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(2);
			    goto cevap2; break;
			
			case 'T' :
			case 't' :
			    t_joker(2);
			    goto cevap2; break;
			case 'Y' :
			case 'y' :
			    y_joker(2);		
				goto cevap2; break;
			case 'P':
			case 'p':
		        cekilme();		
			default:
				temizle();
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
	void soru3()
	{
		char cvp3;
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t    3-Aþaðýdakilerden hangisi nesne yönelimli bir programlama dili deðildir? \n\n"<<endl;
		cout<<"      \t\t\t       a) C#     b) PHP     c) C      d) Dart\n\n"<<endl;
		
   		for(i=40;i<=80;i++) 
		{ 
			gotoxy(i,20);
			cout<<"#";
			Sleep(100); 
		}
		cevap3:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp3;
	  	switch(cvp3)
		{
			case 'C' : 
			case 'c' :  
			    temizle();          
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
		  		paraIslem();
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(3);
			    goto cevap3; break;
			case 'T' :
			case 't' :
			    t_joker(3);
			    goto cevap3; break;
			case 'Y' :
			case 'y' :
		        y_joker(3);
		        goto cevap3; break;
		    case 'P':
			case 'p':
		        cekilme();			
			default:
				temizle(); 
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
	void soru4()
	{
		char cvp4;
		cout<<" \n\n  \n\n\n\t\t    4-“___________tanýmlý bir sýnýfa farklý sýnýflardan eriþilirken _________ tanýmlý bir sýnýfa farklý sýnýflardan eriþilemez.”"<<endl;
		cout<<     "\n\t\t Cümlesinde verilen boþluklara sýrasýyla hangileri getirilmelidir? \n\n"<<endl;
		cout<<"          a) Default-protected    b) Protected-private    c) Private-public    d) Public-private \n\n"<<endl;
		
		for(i=40;i<=80;i++) 
		{ 
			gotoxy(i,20);
			cout<<"#";
			Sleep(100); 
		}
		cevap4:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp4;
	  	switch(cvp4)
		{
			case 'D' : 
			case 'd' : 
			    temizle();           
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
				paraIslem();
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(4);
			    goto cevap4; break;
			case 'T' :
			case 't' :
			    t_joker(4);
			    goto cevap4; break;
			case 'Y' :
			case 'y' :
			    y_joker(4);
			    goto cevap4; break;
		    case 'P':
			case 'p':
		        cekilme();			
			default:
				temizle();
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}
	}
			
	void soru5()
	{
		char cvp5;
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t    5-Nesnelerin ayný olaya farklý tepkiler verebilme yeteneðine ne ad verilir? \n\n"<<endl;
		cout<<"   \t\t        a) Encapsulation     b) Ýnterface     c) Ýnheritance     d) Polymorphism\n\n"<<endl;
		
   		for(i=40;i<=80;i++) 
		{ 
			gotoxy(i,20);
			cout<<"#";
			Sleep(100); 
		}
		cevap5:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp5;
	  	switch(cvp5)
		{
			case 'D' : 
			case 'd' : 
			    temizle();          
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
		  		paraIslem();
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(5);
			    goto cevap5; break;
			case 'T' :
			case 't' :
			    t_joker(5);
			    goto cevap5; break;
			case 'Y' :
			case 'y' :
			    y_joker(5);
			    goto cevap5; break;
		    case 'P':
			case 'p':
		        cekilme();			
			default:
				temizle();  
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
	void soru6()
	{
		char cvp6;
		cout<<"       \n\n\t\t\t\n\n\t\t\n\n\n\t\t   6-artýrma-azaltma operatörlerinin kullaným yerine göre aþaðýdakilerden hangisi yanlýþtýr? \n"<<endl;
		cout<<"\t\t a) x=10 ve y=x++; ise y=10 ve x=11 olur."<<endl;
		cout<<"\t\t b) x=10 ve y=++x; ise y=11 ve x=11 olur."<<endl;
		cout<<"\t\t c) x=10 ve y=x--; ise y=10 ve x=9 olur."<<endl;
		cout<<"\t\t d) x=10 ve y=--x; ise y=9 ve x=10 olur. \n\n"<<endl;
		
		cevap6:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp6;
	  	switch(cvp6)
		{
			case 'D' : 
			case 'd' :
				temizle();              
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
		  		paraIslem();
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(6);
				goto cevap6; break;
			case 'T' :
			case 't' :
			    t_joker(6);
			    goto cevap6; break;
			case 'Y' :
			case 'y' :
			    y_joker(6);
			    goto cevap6; break;
		    case 'P':
			case 'p':
			    cekilme();			
			default:
				temizle();  
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
	void soru7()
	{
		char cvp7;
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t  7-Aþaðýdaki gibi tanýmlanan “Random.dat” dosyasý hangi amaçla açýlmýþ olabilir?\n"<<endl;
		cout<<"     \t\t File *rDosya = fopen(“Random.dat”,”ab+”);\n"<<endl;
		cout<<" 			a) Yalnýz okuma amaçlý."<<endl;
		cout<<" 			b)  Yalnýz yazma amaçlý."<<endl;
		cout<<"			c) Hem okuma hem yazma amaçlý."<<endl;
		cout<<"			d) Arama amaçlý \n\n"<<endl;
		
		cevap7:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp7;
	  	switch(cvp7)
		{
			case 'C' : 
			case 'c' :  
				temizle();           
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
		  		paraIslem();
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(7);
			    goto cevap7; break;
			case 'T' :
			case 't' :
			    t_joker(7);
			    goto cevap7; break;
			case 'Y' :
			case 'y' :
			    y_joker(7);
			    goto cevap7; break;
		    case 'P':
			case 'p':
		        cekilme();			
			default:
				temizle(); 
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
	void soru8()
	{
		char cvp8;
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t  8-Aþaðýdaki program parçasýnýn ekran çýktýsý ne olur?\n"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"     \t\t  int s=1; \n While(s<4){\n s++;\n if(s==3)\n continue; \n cout<<s<<endl; }\n"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<" \t\t\t  	a) 1 2 "<<endl;
		cout<<" \t\t\t	b) 2 4 "<<endl;
		cout<<" \t\t\t	c) 3   "<<endl;
		cout<<" \t\t\t	d) 2   "<<endl;
		
		cevap8:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp8;
	  	switch(cvp8)
		{
			case 'B' : 
			case 'b' :
				temizle();   
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
				paraIslem();		    	
				cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					cout<<"#";
					gotoxy(i,20);
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(8);
			    goto cevap8; break;
			case 'T' :
			case 't' :
			    t_joker(8);
			    goto cevap8; break;
			case 'Y' :
			case 'y' :
		        y_joker(8);
		        goto cevap8; break;
		    case 'P':
			case 'p':
		       cekilme();			
			default:
				temizle();  
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
	void soru9()
	{
		char cvp9;
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t 9-aþaðýdaki program parçasýnýn çalýþtýrýlmasýndan sonra a dizisinin yeni eleman deðerleri ne olur?\n"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"  \t\t int A[ ] = {8,1,9,3,5}; \n\t\t A[0] += A[1]; \n\t\t A[1] -= A[3]; \n\n"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t a) 1,-2,9,3,5"<<endl;
		cout<<"\t\t\t b) 5,3,2,9,1"<<endl;
		cout<<"\t\t\t c) 9,-2,9,3,5"<<endl;
		cout<<"\t\t\t d) 9,0,9,3,5"<<endl;
		
		cevap9:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp9;
	  	switch(cvp9)
		{
			case 'C' : 
			case 'c' : 
				temizle();             
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
		  		paraIslem();
		    	cout<<"\n\n                 Sonraki sorunuz hazirlaniyor"<<endl; 
				for(i=40;i<=80;i++) 
				{ 
					gotoxy(i,20);
					cout<<"#";
					Sleep(20); 
				} 	
				break;
			
			case 'S' :
			case 's' :
			    s_joker(9);
			    goto cevap9; break;
			case 'T' :
			case 't' :
			    t_joker(9);
			    goto cevap9; break;
			case 'Y' :
			case 'y' :
			    y_joker(9);
			    goto cevap9; break;
		    case 'P':
			case 'p':
		        cekilme();			
			default:
				temizle();
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz :( \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
	void soru10()
	{
		char cvp10;
		cout<<"       \n\n\t\t\t  \n\n\t\t  \n\n\n\t\t 10-aþaðýdaki program parçasýnýn çýktýsý nedir ?\n"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"         class Dikdortgen{ \n int en,boy;\n public:\n Dikdortgen(int e,int b){ en = e; boy = b; } \n int alan(){ \n return en*boy; \n} \n}; \n ";
		cout<<"int main()\n{ Dikdortgen x(5,10);\n cout << x.alan()<<endl;\n return 0;\n } "<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"a) 60"<<endl;
		cout<<"b) 15"<<endl;
		cout<<"c) 50"<<endl;
		cout<<"d) 5"<<endl;
		
		cevap10:
		cout<<"\nYanýtýnýz: "; 
		cin>>cvp10;
	  	switch(cvp10)
		{
			case 'C' : 
			case 'c' : 
				temizle();           
				cout<<"\n\n                TEBRIKLER DOGRU YANITI VERDINIZ \n"<<endl; 
		  		paraIslem();
		    	cout<<"\n\n                 TEBRÝKLER TÜM SORULARI DOÐRU CEVAPLADINIZ. ARTIK BÝR MÝLYONERSÝNÝZ!!!"<<endl; 
				for(i=40;i<=80;i++){
					gotoxy(i,20);
					cout<<"#";
					Sleep(100);
				}
				break;
			case 'S' :
			case 's' :
			    s_joker(10);
			    goto cevap10; break;
			case 'T' :
			case 't' :
			    t_joker(10);
			    goto cevap10; break;
			case 'Y' :
			case 'y' :
			    y_joker(10);
			    goto cevap10; break;
		    case 'P':
			case 'p':
		        cekilme();			
			default:
				temizle();
				gotoxy(10,17);cout<<"malesef oyunu kaybettiniz. \n"; 
				gotoxy(10,20);cout<<"toplam para ödülünüz: "<<toplam<<endl; 
				Sleep(2000); 
				exit(0);
		}		
	}
};
int main()
{
	setlocale(LC_ALL, "Turkish");
	SetConsoleTitle("Kim Milyoner Olmak Ister");
 	system("color B4");                            
	program a;
	question q;	
    a.baslangic();	
	system("CLS");
    a.giris();
    system("CLS");
	q.soru1();
    system("CLS");
    q.soru2();
    system("CLS");
    q.soru3();
    system("CLS");
    q.soru4();
    system("CLS");
    q.soru5();
    system("CLS");
    q.soru6();
    system("CLS");
    q.soru7();
    system("CLS");
    q.soru8();
    system("CLS");
    q.soru9();
    system("CLS");    
    q.soru10();
    system("CLS");
	
	return 0;
}
