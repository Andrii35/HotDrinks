#include "drinks.h"

Drink::Drink():wotter(100), kaffe(100), tee(100), shoogar(100), milk(100), money(0)
{
}

Drink::Drink(int w, int k, int t, int s, int m):wotter(w),kaffe(k),tee(t),shoogar(s),milk(m), money(0)
{

}



Drink::~Drink()
{
}

int Drink::getWotter() const
{
	return wotter;
}

int Drink::getKaffe() const
{
	return kaffe;
}

int Drink::getTee() const
{
	return tee;
}

int Drink::getShoogar() const
{
	return shoogar;
}

int Drink::getMilk() const
{
	return milk;
}

int Drink::getMoney() const
{
	return money;
}

void Drink::setWotter(int obj)
{
	wotter = obj;
}

void Drink::setKaffe(int obj)
{
	kaffe = obj;
}

void Drink::setTee(int obj)
{
	tee = obj;
}

void Drink::setShoogar(int obj)
{
	shoogar = obj;
}

void Drink::setMilk(int obj)
{
	milk = obj;
}

void Drink::setMoney(int pr)
{
	money += pr;
}

void Drink::setTakeMoney(int mon)
{
	money = mon;
}

void Drink::clearMoney()
{
	money = 0;
}

Kaffe::Kaffe( int w, int k, int s, int m, int pr): cafepr(pr),Drink(w,k,0,s,m)
{
}

Kaffe::Kaffe():Drink()
{
}

Kaffe::~Kaffe()
{
}

int Kaffe::getCafepr() const
{
	return cafepr;
}

void Kaffe::setCafepr(int pr)
{
	cafepr = pr;
}

void Kaffe::Espresso()
{
	setWotter(getWotter() - 20);
	setKaffe(getKaffe() - 20);

}

void Kaffe::AmericanoWithMilk()
{
	setWotter(getWotter() - 40);
	setKaffe(getKaffe() - 20);
	setMilk(getMilk() - 10);
}

void Kaffe::AmericanoWithoutMilk()
{
	setWotter(getWotter() - 40);
	setKaffe(getKaffe() - 20);
}


Tee::Tee(int w, int t, int s,int pr):teepr(pr), Drink(w,0,t,s,0)
{
}

Tee::Tee():Drink()
{
}

Tee::~Tee()
{
}

int Tee::getTeepr() const
{
	return teepr;
}

void Tee::setTeepr(int pr)
{
	teepr = pr;
}

void Tee::HotTee()
{
	setWotter(getWotter() - 200);
	setTee(getTee() - 20);
}



Capuchino::Capuchino(int w, int k, int s, int m,int pr):cappr(pr),Drink(w,k,0,s,m)
{
}

Capuchino::Capuchino():Drink()
{
}

Capuchino::~Capuchino()
{
}

int Capuchino::getCappr() const
{
	return cappr;
}

void Capuchino::setCappr(int pr)
{
	cappr = pr;
}

void Capuchino::Capuch()
{
	setWotter(getWotter() - 100);
	setKaffe(getKaffe() - 30);
	setMilk(getMilk() - 50);
}

Mashine::Mashine(int w, int k, int t, int s, int m):Capuchino::Drink(w,k,t,s,m),Tee(w, t, s), Kaffe(w, k,  s, m),Capuchino(w, k, s, m),Shoogar(s)
{
}

Mashine::Mashine():Capuchino::Drink()
{
}

Mashine::~Mashine()
{
	
}



void Mashine::AddIngridients()
{
	int volume;
	if (getKaffe() < 100) {
		cout << "Kaffee is fast out, fill kaffee: \n";
		cin >> volume;
		setKaffe(getKaffe() + volume);
	}
	if (getWotter() < 100) {
		cout << "Wotter is fast out, fill wotter: \n";
		cin >> volume;
		setWotter(getWotter() + volume);
	}
	if (getTee() < 100) {
		cout << "Tee is fast out, fill tee: \n";
		cin >> volume;
		setTee(getTee() + volume);
	}
	if (getShoogar() < 100) {
		cout << "Shoogar is fast out, fill shoogar: \n";
		cin >> volume;
		setShoogar(getShoogar() + volume);
	}
	if (getMilk() < 100) {
		cout << "Milk is fast out, fill milk: \n";
		cin >> volume;
		setMilk(getMilk() + volume);
	}

}

void Mashine::ShowIngridients()
{
	cout << "Mashine have ingridients for drinks:\n";
	cout << "Watter: " << getWotter() << endl;
	cout << "Kaffe: " << getKaffe()<<endl;
	cout << "Tee: " << getTee() << endl;
	cout << "Shoogar: " << getShoogar() << endl;
	cout << "Milk: " << getMilk() << endl;

}

void Mashine::HotDrinksMashine()
{
	
	int numb = 100;
	while (numb != 0) {
		cout << "Choise a drink: \n";
		cout << "1. Espresso - " << getCafepr() << " ua" << endl;
		cout << "2. Americano with milk - " << getCafepr() + 5 << " ua" << endl;
		cout << "3. Americano without milk - " << getCafepr() - 5 << " ua" << endl;
		cout << "4. Tee - " << getTeepr() << " ua" << endl;
		cout << "5. Capuchino - " << getCappr() << " ua" << endl;
		cout << "0. Exit\n";
		cin >> numb;
		switch (numb) {
		case 1: {

			if (getKaffe() < 20 || getWotter() < 20) {
				cout << "Not ingridiens, ask an administrator\n";
				return;
			}
			else {
				int yourmoney;
				cout << "Please, pay:";
				cin >> yourmoney;
				if (getCafepr() == yourmoney) {
					setMoney(getCafepr());
					Espresso();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
				}
				else if (getCafepr() < yourmoney) {
					setMoney(getCafepr());
					Espresso();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
					cout << "Your rest are " << yourmoney - getCafepr()<<" ua "<<endl;
				}
				else if (getCafepr() > yourmoney) {
					int m;
					m = getCafepr() - yourmoney;
					cout << "Your money is not enuff, give now " <<  m<< " ua " << endl;
					cin >> yourmoney;
					if (getCafepr() ==m+yourmoney) {
						setMoney(getCafepr());
						Espresso();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
					}
					else if (getCafepr() <m+yourmoney) {
						setMoney(getCafepr());
						Espresso();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
						cout << "Your rest are " << (m+yourmoney) - getCafepr() << " ua " << endl;
					}
					
				}
			}
			break;
		}
		case 2: {
			if (getKaffe() < 20 || getWotter() < 40 || getMilk() < 10) {
				cout << "Not ingridiens, ask an administrator\n";
				return;
			}
			else {
				int yourmoney;
				cout << "Please, pay:";
				cin >> yourmoney;
				if (getCafepr()+5 == yourmoney) {
					setMoney(getCafepr() + 5);
					AmericanoWithMilk();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
				}
				else if (getCafepr() + 5 < yourmoney) {
					setMoney(getCafepr() + 5);
					AmericanoWithMilk();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
					cout << "Your rest are " << yourmoney - (getCafepr() + 5) << " ua " << endl;
				}
				else if (getCafepr() + 5 > yourmoney) {
					int m;
					m = getCafepr()+5 - yourmoney;
					cout << "Your money is not enuff, give now " << m << " ua " << endl;
					cin >> yourmoney;
					if (getCafepr()+5 == m + yourmoney) {
						setMoney(getCafepr());
						AmericanoWithMilk();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
					}
					else if (getCafepr()+5 < m + yourmoney) {
						setMoney(getCafepr()+5);
						AmericanoWithMilk();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
						cout << "Your rest are " << (m + yourmoney) - (getCafepr()+5) << " ua " << endl;
					}

				}
			}
			break;
		}
		case 3: {
			if (getKaffe() < 20 || getWotter() < 40) {
				cout << "Not ingridiens, ask an administrator\n";
				return;
			}
			else {
				int yourmoney;
				cout << "Please, pay:";
				cin >> yourmoney;
				if (getCafepr() - 5 == yourmoney) {
					setMoney(getCafepr() - 5);
					AmericanoWithoutMilk();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
				}
				else if (getCafepr() - 5 < yourmoney) {
					setMoney(getCafepr() - 5);
					AmericanoWithoutMilk();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
					cout << "Your rest are " << yourmoney - (getCafepr() - 5) << " ua " << endl;
				}
				else if (getCafepr() - 5 > yourmoney) {
					int m;
					m = (getCafepr() - 5) - yourmoney;
					cout << "Your money is not enuff, give now " << m << " ua " << endl;
					cin >> yourmoney;
					if (getCafepr() - 5 == m + yourmoney) {
						setMoney(getCafepr());
						AmericanoWithoutMilk();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
					}
					else if (getCafepr() - 5 < m + yourmoney) {
						setMoney(getCafepr() - 5);
						AmericanoWithoutMilk();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
						cout << "Your rest are " << (m + yourmoney) - (getCafepr() - 5) << " ua " << endl;
					}

				}
			}
			break;
		}
		case 4: {
			if (getTee() < 20 || getWotter() < 200) {
				cout << "Not ingridiens, ask an administrator\n";
				return;
			}
			else {
				int yourmoney;
				cout << "Please, pay:";
				cin >> yourmoney;
				if (getTeepr() == yourmoney) {
					setMoney(getTeepr());
					HotTee();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
				}
				else if (getTeepr() < yourmoney) {
					setMoney(getTeepr());
					HotTee();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
					cout << "Your rest are " << yourmoney - getTeepr() << " ua " << endl;
				}
				else if (getTeepr() > yourmoney) {
					int m;
					m = getTeepr() - yourmoney;
					cout << "Your money is not enuff, give now " << m << " ua " << endl;
					cin >> yourmoney;
					if (getTeepr() == m + yourmoney) {
						setMoney(getTeepr());
						HotTee();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
					}
					else if (getTeepr() < m + yourmoney) {
						setMoney(getTeepr());
						HotTee();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
						cout << "Your rest are " << (m + yourmoney) - getTeepr() << " ua " << endl;
					}

				}
			}
			break;
		}
		case 5: {
			if (getKaffe() < 30 || getWotter() < 100 || getMilk() < 50) {
				cout << "Not ingridiens, ask an administrator\n";
				return;
			}
			else {
				int yourmoney;
				cout << "Please, pay:";
				cin >> yourmoney;
				if (getCappr() == yourmoney) {
					setMoney(getCappr());
					Capuch();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
				}
				else if (getCappr() < yourmoney) {
					setMoney(getCappr());
					Capuch();
					int shoogar=0;
					while (shoogar != 2) {
						cout << "1. Shoogar\n";
						cout << "2. No shoogar\n";
						cin >> shoogar;
						switch (shoogar) {
						case 1: {
							if (getShoogar() < 20) {
								cout << "Not ingridiens, ask an administrator\n";
								return;
							}
							else {
								AddShoogar();
							}
							break;
						}
						}
					}
					cout << "Your rest are " << yourmoney - getCappr() << " ua " << endl;
				}
				else if (getCappr() > yourmoney) {
					int m;
					m = getCappr() - yourmoney;
					cout << "Your money is not enuff, give now " << m << " ua " << endl;
					cin >> yourmoney;
					if (getCappr() == m + yourmoney) {
						setMoney(getCappr());
						Capuch();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
					}
					else if (getCappr() < m + yourmoney) {
						setMoney(getCappr());
						Capuch();
						int shoogar=0;
						while (shoogar != 2) {
							cout << "1. Shoogar\n";
							cout << "2. No shoogar\n";
							cin >> shoogar;
							switch (shoogar) {
							case 1: {
								if (getShoogar() < 20) {
									cout << "Not ingridiens, ask an administrator\n";
									return;
								}
								else {
									AddShoogar();
								}
								break;
							}
							}
						}
						cout << "Your rest are " << (m + yourmoney) - getCappr() << " ua " << endl;
					}

				}
			}
			break;
		}
		}
		system("cls");
	}
	}

void Mashine::TakeCash()
{
	int cash;
	cout << "Money in mashine: " << getMoney()<<" ua"<<endl;
	cout << "Enter, how much money will you take: ";
	cin >> cash;
	setTakeMoney(getMoney() - cash);
}

void Mashine::ChaingePrice()
{
	int numb = 100;
	int price;
	while (numb != 0) {
		cout << "Choise a drink for price chainge:" << endl;
		cout << "1. Kaffee\n";
		cout << "2. Tee\n";
		cout << "3. Capuchino\n";
		cout << "0. Exit\n";
		cin >> numb;
		switch (numb) {
		case 1: {
			cout << "Old price for Kaffee: " << getCafepr() << endl;
			cout << "Enter a new price for kaffee:";
			cin >> price;
			setCafepr(price);
			break;
		}
		case 2: {
			cout << "Old price for Tee: " << getTeepr() << endl;
			cout << "Enter a new price for tee:";
			cin >> price;
			setTeepr(price);
			break;
		}
		case 3: {
			cout << "Old price for Capuchino: " << getCappr() << endl;
			cout << "Enter a new price for capuchino:";
			cin >> price;
			setCappr(price);
			break;
		}
		}
	}
}


Shoogar::Shoogar(int s):Drink(0,0,0,s,0)
{
}

Shoogar::Shoogar():Drink()
{
}

Shoogar::~Shoogar()
{
}

void Shoogar::AddShoogar()
{
	setShoogar(getShoogar() - 20);
}

void Menu(Mashine & drinks, map<string, int>admin)
{
	int n = 100;
	string name;
	int password;

	while (n != 0) {
		cout << "1. User\n";
		cout << "2. Admin\n";
		cout << "0. Exit\n";
		cin >> n;
		switch (n) {
		case 1: {
			drinks.HotDrinksMashine();
			break;
		}
		case 2:
		{
			cout << "Enter Login: ";
			cin >> name;
			cout << "Enter password: ";
			cin >> password;
			for (auto&elem : admin) {
				if (elem.first == name && elem.second == password) {
					int action = 100;
					while (action != 0) {
						cout << "Choise an action:\n";
						cout << "1. Show ingredients in mashine\n";
						cout << "2. Fill mashine with ingredients\n";
						cout << "3. Chainge a price\n";
						cout << "4. Take a cash\n";
						cout << "0. Exit\n";
						cin >> action;
						switch (action) {
						case 1: {
							drinks.ShowIngridients();
							break;
						}
						case 2: {
							drinks.AddIngridients();
							break;
						}
						case 3: {
							drinks.ChaingePrice();
							break;
						}
						case 4: {
							drinks.TakeCash();
							break;
						}
						}
					}
				}
				else {
					cout << "Login or password is false\n";
					break;
				}
			}break;
		}
		}
	}
}
