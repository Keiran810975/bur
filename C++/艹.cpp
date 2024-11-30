#include <iostream>
#include <cstring>
using namespace std;

int global_total_elements; // headquarter的总生命元
int lion_decrease; // lion走一步降低的忠诚度
int city_num; // 中间的城市总数量
int time_limit; // 时间限制
int health_value_of_warrior[5] = {}; // 武士初始生命值
int attack_force_of_warrior[5] = {}; // 武士攻击力
int sequence_of_warrior[2][5] = { {2, 3, 4, 1, 0}, {3, 0, 1, 2, 4} }; // red与blue制造武士的顺序
char warrior_names_list[5][20] = {"dragon", "ninja", "iceman", "lion", "wolf"}; // 武士名,按照输入的顺序来

string weapon_name(int i) {
    if (i == 0) return "sword";
    if (i == 1) return "bomb";
    return "arrow";
} // 输出编号对应的武器名字

void timer(int n) {
    printf("%03d:%02d ", n / 60, n % 60);
} // 输出时间格式

class warrior {
public:
    int health_value;
    int attack_force;
    int id;
    int weapon[4] = {}; // 0 sword 1 bomb 2 new arrow 3 used arrow;
    int loyalty = 0; // 没有使用auto,仅适用于lion但是必须在基类声明
    string side_name; // red or blue 
    int side_id = 0; // 0 or 1
    string warrior_name;
    int times_of_choose_weapon = 1; // 在每个城市的战斗前选武器选了多少次
    int total_weapon = 0; // 武器总数量
    bool has_fight = false; // 仅用于dragon判断是否yell

    warrior(int i, string s) : id(i), side_name(s) {
        memset(weapon, 0, sizeof(weapon));
        if (side_name == "blue") side_id = 1;
    }

    virtual ~warrior() {} // 基类定义虚析构

    virtual void yell(int city) {}
    // 仅用于dragon,基类随便写，由dragon类覆盖

    virtual void take_enemy_weapon(warrior* p, int city) {}
    // 仅用于wolf,同理

    int count_weapon() {
        int res = 0;
        for (int i = 0; i < 4; i++) {
            res += weapon[i];
        }
        return res;
    } // 实时计数武器数量,与total_weapon重复因为用于不同需求,避免对total_weapon的更新出错

    void get_loser_weapon(warrior* p) {
        if (total_weapon >= 10) return;
        for (int i = 0; i < 4; i++) {
            if (total_weapon + p->weapon[i] > 10) {
                weapon[i] += 10 - total_weapon;
                total_weapon = 10;
                break;
            } else {
                total_weapon += p->weapon[i];
                weapon[i] += p->weapon[i];
            }
        }
    }

    void warrior_report(int current_time) {
        timer(current_time);
        cout << side_name << " " << warrior_name << " " << id << " has " 
             << weapon[0] << " sword " << weapon[1] << " bomb " 
             << weapon[2] + weapon[3] << " arrow and " << health_value 
             << " elements" << endl;
    }

    int decide_weapon() {
        int decision = 114514;
        bool next_round = false;

        if (count_weapon() <= times_of_choose_weapon) {
            next_round = true;
        }

        if (times_of_choose_weapon <= weapon[0]) {
            times_of_choose_weapon++;
            decision = 0;
        } else if (times_of_choose_weapon <= weapon[0] + weapon[1]) {
            weapon[1]--;
            total_weapon--;
            decision = 1;
        } else if (times_of_choose_weapon <= weapon[0] + weapon[1] + weapon[3]) {
            weapon[3]--;
            total_weapon--;
            decision = 3;
        } else if (times_of_choose_weapon <= count_weapon()) {
            weapon[2]--;
            weapon[3]++;
            decision = 2;
            times_of_choose_weapon++;
        }

        if (next_round) times_of_choose_weapon = 1;

        return decision;
    }
};

class dragon : public warrior {
public:
    dragon(int& total, int i, string s) : warrior(i, s) {
        warrior_name = "dragon";
        weapon[id % 3]++;
        total_weapon++;
        health_value = health_value_of_warrior[0];
        attack_force = attack_force_of_warrior[0];
        total -= health_value;
    }

    void yell(int city) override {
        timer(hour);
        cout << ":40 " << side_name << " " << warrior_name << " " << id 
             << " yelled in city " << city << endl;
    }
};

class ninja : public warrior {
public:
    ninja(int& total, int i, string s) : warrior(i, s) {
        warrior_name = "ninja";
        weapon[id % 3]++;
        weapon[(id + 1) % 3]++;
        total_weapon += 2;
        health_value = health_value_of_warrior[1];
        attack_force = attack_force_of_warrior[1];
        total -= health_value;
    }
};

class iceman : public warrior {
public:
    iceman(int& total, int i, string s) : warrior(i, s) {
        warrior_name = "iceman";
        weapon[id % 3]++;
        total_weapon++;
        health_value = health_value_of_warrior[2];
        attack_force = attack_force_of_warrior[2];
        total -= health_value;
    }
};

class lion : public warrior {
public:
    lion(int& total, int i, string s) : warrior(i, s) {
        warrior_name = "lion";
        weapon[id % 3]++;
        total_weapon++;
        health_value = health_value_of_warrior[3];
        attack_force = attack_force_of_warrior[3];
        total -= health_value;
        loyalty = total;
        loyal_report();
    }

    void loyal_report() {
        cout << "Its loyalty is " << loyalty << endl;
    }

    void lion_ranaway(int current_time) {
        if (loyalty <= 0) {
            timer(current_time);
            cout << side_name << " lion " << id << " ran away" << endl;
        }
    }
};

class wolf : public warrior {
public:
    wolf(int& total, int i, string s) : warrior(i, s) {
        warrior_name = "wolf";
        health_value = health_value_of_warrior[4];
        attack_force = attack_force_of_warrior[4];
        total -= health_value;
    }

    void take_enemy_weapon(warrior* p, int city) override {
        int delta;
        string s;
        int i;

        if (p->warrior_name == "wolf") return;

        for (i = 0; i < 4; i++) {
            if (p->weapon[i] > 0) {
                if (total_weapon == 10) break;
                else if (total_weapon < 10 && total_weapon + p->weapon[i] > 10) {
                    delta = 10 - total_weapon;
                    weapon[i] += 10 - total_weapon;
                    p->weapon[i] -= 10 - total_weapon;
                    p->total_weapon -= 10 - total_weapon;
                    s = weapon_name(i);
                    total_weapon = 10;
                    break;
                } else if (total_weapon < 10 && total_weapon + p->weapon[i] <= 10) {
                    delta = p->weapon[i];
                    p->total_weapon -= p->weapon[i];
                    weapon[i] += p->weapon[i];
                    p->weapon[i] = 0;
                    total_weapon += p->weapon[i];
                    s = weapon_name(i);
                    break;
                }
            }
        }

        if (i == 2 && total_weapon < 10 && p->weapon[3] > 0) {
            while (total_weapon < 10 && p->weapon[3] > 0) {
                total_weapon++;
                p->weapon[3]--;
                weapon[3]++;
                delta++;
                p->total_weapon--;
            }
        }

        if (!s.empty()) {
            timer(hour);
            cout << ":35 " << side_name << " wolf " << id << " took " << delta << " " 
                 << s << " from " << p->side_name << ' ' << p->warrior_name << ' ' 
                 << p->id << " in city " << city << endl;
        }
    }
};

class city {
public:
    int city_id;
    warrior* red_ptr = nullptr;
    warrior* blue_ptr = nullptr;
    int elements = 0;
    int flag_color = -1; // 无旗 0 red 1 blue
    int continue_victory = 0; // 当前旗帜胜利次数
    int just_fight = 0; // 0 no 1 red 2 blue 3 all die

    city(int id) : city_id(id) {}

    void add_elements() {
        elements += 10;
    }

    void produce_elements(warrior* p) {
        timer(hour);
        cout << ":30 " << p->side_name << " " << p->warrior_name << " " << p->id 
             << " earned " << elements << " elements for his headquarter" << endl;
        p->health_value += elements;
        elements = 0;
    }

    void march_to_next_city(warrior* p, string direction) {
        string position;
        if (city_id == 0) position = "red headquarter";
        else if (city_id == city_num + 1) position = "blue headquarter";
        else position = "city " + to_string(city_id);

        timer(hour);
        cout << ":10 " << p->side_name << " " << p->warrior_name << " " << p->id 
             << " marched to " << position << " with " << p->health_value 
             << " elements and force " << p->attack_force << endl;
    }

    void print_attack_info(int attack_mode, warrior* p, warrior* q) {
        string s;
        if (attack_mode == 1) s = "shot";
        if (attack_mode == 0) s = "fought";
        if (attack_mode == -1) s = "bombed";
        timer(hour);
        cout << ":40 " << p->side_name << " " << p->warrior_name << " " << p->id 
             << " " << s << " " << q->side_name << " " << q->warrior_name << " " 
             << q->id << " in city " << city_id << endl;
    }

    void print_killed_info(warrior* p) {
        timer(hour);
        cout << ":40 " << p->side_name << " " << p->warrior_name << " " << p->id 
             << " was killed in city " << city_id << endl;
    }
};

class headquarter {
public:
    string side_name;
    int total;
    int warrior_id = 1;
    warrior* warrior_list[1000] = {}; // 武士数组
    int warrior_count[5] = {}; // 每个武士类型的数量
    int side_id = 0; // 0 red 1 blue
    int sequence[5] = {};

    headquarter(string s) : side_name(s) {
        if (side_name == "blue") side_id = 1;
        memcpy(sequence, sequence_of_warrior[side_id], sizeof(sequence));
    }

    void create_warrior() {
        if (total < health_value_of_warrior[sequence[(warrior_id - 1) % 5]]) return;

        warrior* new_warrior = nullptr;
        int warrior_type = sequence[(warrior_id - 1) % 5];

        switch (warrior_type) {
        case 0:
            new_warrior = new dragon(total, warrior_id, side_name);
            break;
        case 1:
            new_warrior = new ninja(total, warrior_id, side_name);
            break;
        case 2:
            new_warrior = new iceman(total, warrior_id, side_name);
            break;
        case 3:
            new_warrior = new lion(total, warrior_id, side_name);
            break;
        case 4:
            new_warrior = new wolf(total, warrior_id, side_name);
            break;
        }

        warrior_list[warrior_id] = new_warrior;
        warrior_count[warrior_type]++;
        timer(hour);
        cout << ":00 " << side_name << " " << warrior_names_list[warrior_type] 
             << " " << warrior_id << " born" << endl;
        warrior_id++;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ":" << endl;
        cin >> global_total_elements >> city_num >> lion_decrease >> time_limit;
        for (int j = 0; j < 5; j++) {
            cin >> health_value_of_warrior[j];
        }
        for (int j = 0; j < 5; j++) {
            cin >> attack_force_of_warrior[j];
        }

        headquarter red("red"), blue("blue");
        red.total = blue.total = global_total_elements;
        city* cities[city_num + 2];

        for (int j = 0; j <= city_num + 1; j++) {
            cities[j] = new city(j);
        }

        int current_time = 0;
        while (current_time <= time_limit) {
            red.create_warrior();
            blue.create_warrior();
            // 假设每次循环是1小时
            current_time += 60;
        }
    }
    return 0;
}
