#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

//Автомат гарячих напоїв.
//Створити ієрархію класів для подання гарячих напоїв Автомату(кава, чай, капучіно та ін.)
//Створити програму для роботи Автомату у  режимах адмін та користувач
//У режимі адміна передбачити
//Завантаження автомату водою, кава, чай, цукор(адмін)
//Вивід статистики наявності складових для приготування напоїв(адмін)
//Зміна цін на напої(адмін)
//Вилучення кешу
//У режимі користувача передбачити
//Замовлення напою(+оплата)
class Drink {
	int wotter;
	int kaffe;
	int tee;
	int shoogar;
	int milk;
	int money;
public:
	Drink();
	Drink(int w, int k, int t, int s, int m);
	
	~Drink();
	int getWotter()const;
	int getKaffe()const;
	int getTee()const;
	int getShoogar()const;
	int getMilk()const;
	int getMoney()const;
	void setWotter(int obj);
	void setKaffe(int obj);
	void setTee(int obj);
	void setShoogar(int obj);
	void setMilk(int obj);
	void setMoney(int mon);
	void setTakeMoney(int mon);
	void clearMoney();

		
};
class Shoogar :virtual public Drink {
	
public:
	Shoogar(int s);
	Shoogar();
	~Shoogar();
	void AddShoogar();
	
};
class Kaffe : virtual public Drink {
	int cafepr;
public:
	Kaffe(int w, int k, int s, int m, int pr=25);
	Kaffe();
	~Kaffe();
	int getCafepr()const;
	void setCafepr(int pr);
	void Espresso();
	void AmericanoWithMilk();
	void AmericanoWithoutMilk();
			
};

class Tee: virtual public Drink {
	int teepr;
public:
	Tee(int w, int t, int s, int pr=15);
	Tee();
	~Tee();
	int getTeepr()const;
	void setTeepr(int pr);
	void HotTee();
	
};
class Capuchino : virtual public Drink {
	int cappr;
public:
	Capuchino(int w, int k, int s, int m, int pr=30);
	Capuchino();
	~Capuchino();
	int getCappr()const;
	void setCappr(int pr);
	void Capuch();

};

class Mashine :public Kaffe, public Tee, public Capuchino, public Shoogar {
	
	public:
		Mashine(int w, int k, int t, int s, int m);
		Mashine();
		~Mashine();
		
		void AddIngridients();
		void ShowIngridients();
		void HotDrinksMashine();
		void TakeCash();
		void ChaingePrice();
			   
};

void Menu(Mashine &drinks, map<string, int>admin);