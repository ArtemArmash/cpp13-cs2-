#include <iostream>
#include<vector>
using namespace std;

class Weapon {
public:
	virtual void Shoot() = 0;
	virtual void drop() = 0;
	virtual void Reload() = 0;
	virtual void PutUp() = 0;

};

class Player {
private:
	vector<Weapon*>weapons;
	const int max_weapon = 3;
public:
	
	void PutUpWeapon(Weapon* newWeapon) {
		if (weapons.size() < max_weapon)
		{
			weapons.push_back(newWeapon);
			cout << "Weapon is put up\n";
		}
		else {
			throw out_of_range("Player cant put up weapon if he has 3 weapons.\n");
		}
	}
	void Drop(int index) {
		if ( index >= 0 && index < weapons.size() )
		{
			weapons[index]->drop();
			delete weapons[index];
			weapons.erase(weapons.begin() + index);
			cout << "Dropped weapons\n";
		}
		else {
			throw out_of_range("Invalid weapon index.");
		}
	}
	void shoot(int index) {
		if (index >= 0 && index < weapons.size()) {
			weapons[index]->Shoot();
		}
		else{ throw out_of_range("Invalid weapon index."); }
	}
};

class AWP : public Weapon {
public:
	void Shoot() override {
		cout << "AWP shooting." << endl;
	}

	void Reload() override {
		cout << "AWP reloading." << endl;
	}

	void drop() override {
		cout << "Dropped a AWP." << endl;
	}

	void PutUp() override {
		cout << "Picked up a AWP." << endl;
	}
};
class AK_47 : public Weapon {
public:
	void Shoot() override {
		cout << "AK-47 shooting." << endl;
	}

	void Reload() override {
		cout << "AK-47 reloading." << endl;
	}

	void drop() override {
		cout << "Dropped a AK-47." << endl;
	}

	void PutUp() override {
		cout << "Picked up a AK-47." << endl;
	}
};
class M4A1 : public Weapon {
public:
	void Shoot() override {
		cout << "M4A1 shooting." << endl;
	}

	void Reload() override {
		cout << "M4A1 reloading." << endl;
	}

	void drop() override {
		cout << "Dropped a M4A1." << endl;
	}

	void PutUp() override {
		cout << "Picked up a M4A1." << endl;
	}
};
class Deagle : public Weapon {
public:
	void Shoot() override {
		cout << "Deagle shooting." << endl;
	}

	void Reload() override {
		cout << "Deagle reloading." << endl;
	}

	void drop() override {
		cout << "Dropped a Deagle." << endl;
	}

	void PutUp() override {
		cout << "Picked up a Deagle." << endl;
	}
};
class Glock : public Weapon {
public:
	void Shoot() override {
		cout << "Glock shooting." << endl;
	}

	void Reload() override {
		cout << "Glock reloading." << endl;
	}

	void drop() override {
		cout << "Dropped a Glock." << endl;
	}

	void PutUp() override {
		cout << "Picked up a Glock." << endl;
	}
};

int main() {

	Player player;
	player.PutUpWeapon(new AWP());
	
	try {
		player.Drop(0);

	}
	catch (out_of_range& e) { cerr << "Error :" << e.what() << endl; }
}