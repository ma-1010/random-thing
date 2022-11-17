#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;
const int title_row = 33;
const int title_col = 40;
const int options_row = 4;
const int options_col = 16;

class BattleShip {
private:

	char player_attack_radar[11][13] =
	{
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	};

	char player_board[11][13] =
	{
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	};

	char computer_board[11][13] =
	{
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	  {'#','-','-','-','-','-','-','-','-','-','-','#'},
	};


	char game_title[title_row][title_col] =
	{
	  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	};

	char options[options_row][options_col] =
	{
	  {' ',' ',' ',' ','N','e','w',' ','G','a','m','e',' ',' ',' ',' '},
	  {' ',' ','I','n','s','t','r','u','c','t','i','o','n','s',' ',' '},
	  {' ',' ',' ',' ','C','r','e','d','i','t','s',' ',' ',' ',' ',' '},
	  {' ',' ',' ',' ',' ',' ','E','x','i','t',' ',' ',' ',' ',' ',' '},
	};

	char hv[10];
	char player_ship_coordinates[10];
	char player_attack_coordinates[10];
	int a = 65, b = 65;
	int computer_ship_space_on_board = 14;
	int player_ship_space_on_board = 14;
	int arrow_row = 0, arrow_col = 0;
	int patrol_boat_size = 2, player_patrol_boat_size = 2;
	int submarine_size = 3, player_submarine_size = 3;
	int destroyer_size = 4, player_destroyer_size = 4;
	int helicarrier_size = 5, player_helicarrier_size = 5;
	int row, col;
	int attack_row, attack_col;
	int computer_row, computer_col;
	int computer_attack_row, computer_attack_col;
	int computer_hv;
	char options_move;
	char upordown;
	char first_computer_coordinate;
	int ship_number = 0;
	int computer_ship = 0;
	bool valid_ship_position;
	bool valid_computer_ship_position;
	bool valid_attack_coordinates;
	bool valid_computer_attack_coordinates;
	bool hit = false;
	bool patrol_boat_hit = false;
	bool submarine_hit = false;
	bool destroyer_hit = false;
	bool helicarrier_hit = false;
	string name;


public:
	void print_game_title() {
		system("Color 8F");
		for (int i = 0; i < title_row; i++) {
			cout << setw(44);
			for (int j = 0; j < title_col; j++) {
				if (game_title[i][j] == '#') {
					cout << (char)219;
				}
				else if (game_title[i][j] == '!') {
					cout << (char)178;
				}
				else if (game_title[i][j] == '+') {
					cout << (char)43;
				}
				else if (game_title[i][j] == '@') {
					cout << (char)233;
				}
				else if (game_title[i][j] == '$') {
					cout << (char)173;
				}
				else {
					cout << (char)32;
				}
			}cout << endl;
		}
	}

	void print_options() {
		for (int i = 0; i < options_row; i++) {
			cout << setw(56);
			for (int j = 0; j < options_col; j++) {
				if (i == arrow_row && j == arrow_col) {
					cout << (char)175;
				}
				cout << options[i][j];
			}cout << endl;
		}
	}

	void player_chooses_options() {
		while (1) {
			if (kbhit()) {
				options_move = getch();
				if (arrow_row == 0 && arrow_col == 0 && options_move == 13) {
					system("CLS");
					enter_player_name();
					take_computer_input();
					print_player_board_and_attack_radar();
					take_player_input();
					tell_player_shits_about_to_get_real();
					player_sets_attack();
				}
				else if (arrow_row == 1 && arrow_col == 0 && options_move == 13) {
					system("CLS");
					instructions();
					if (options_move == -32) {
						system("CLS");
						instructions();
					}
				}
				else if (arrow_row == 2 && arrow_col == 0 && options_move == 13) {
					system("CLS");
					credits();
				}
				else if (arrow_row == 3 && arrow_col == 0 && options_move == 13) {
					system("CLS");
					system("Color 80");
					for (int i = 0; i < 18; i++) {
						cout << endl;
					}cout << setw(58);
					for (int i = 1; i <= 6; i++) {
						cout << (char)i << " ";
					}
					for (int i = 0; i < 18; i++) {
						cout << endl;
					}
					Sleep(5000);
					exit(0);
				}
				else if (options_move == 27) {
					system("CLS");
					print_game_title();
					print_options();
				}
				else if (options_move == -32) {
					upordown = getch();
					switch (upordown) {
					case 72:
						if (arrow_row > 0) {
							arrow_row--;
						}
						break;
					case 80:
						if (arrow_row < options_row - 1) {
							arrow_row++;
						}
						break;
					}
					system("CLS");
					print_game_title();
					print_options();
				}
			}
		}
	}

	void enter_player_name() {
		system("CLS");
		system("Color 02");
		for (int i = 0; i < 19; i++) {
			cout << endl;
		}
		cout << setw(72) << "Hay nhap tên ban ";
		getline(cin, name);
	}

	void display_ship_statuses() {
		system("CLS");
		cout << setw(63) << "Tinh trang tau dich " << (char)179 << " " << name << "'s Tinh trang tau" << endl;
		cout << setw(43) << (char)201;
		for (int i = 0; i < 40; i++) {
			cout << (char)205;
		}cout << (char)187 << endl;
		cout << setw(43) << (char)186 << "Tau tuan tra: " << patrol_boat_size << setw(7) << (char)179 << setw(18) << "Tau tuan tra: " << player_patrol_boat_size << (char)186 << endl;
		cout << setw(43) << (char)186 << "Tau ngam: " << submarine_size << setw(9) << (char)179 << setw(18) << "Tau ngam: " << player_submarine_size << (char)186 << endl;
		cout << setw(43) << (char)186 << "Tau khu truc: " << destroyer_size << setw(9) << (char)179 << setw(18) << "Tau khu truc: " << player_destroyer_size << (char)186 << endl;
		cout << setw(43) << (char)186 << "Tau san bay: " << helicarrier_size << setw(7) << (char)179 << setw(18) << "Tau san bay: " << player_helicarrier_size << (char)186 << endl;
		cout << setw(43) << (char)200;
		for (int i = 0; i < 40; i++) {
			cout << (char)205;
		}cout << (char)188 << endl;

	}

	void print_player_board_and_attack_radar() {
		display_ship_statuses();
		system("Color F1");
		for (int i = 0; i < 5; i++) {
			cout << endl;
		}
		cout << setw(52) << "0 1 2 3 4 5 6 7 8 9" << setw(41) << "0 1 2 3 4 5 6 7 8 9" << endl;
		cout << setw(32) << (char)218;
		for (int j = 0; j < 21; j++) {
			cout << (char)196;
		}cout << (char)191 << setw(19) << (char)218;
		for (int n = 0; n < 21; n++) {
			cout << (char)196;
		}cout << (char)191 << endl;
		for (int k = 0; k < 10; k++) {
			cout << setw(30) << (char)a++ << " ";
			for (int l = 0; l < 12; l++) {
				if (player_board[k][l] == '-') {
					cout << (char)248 << " ";
				}
				else if (player_board[k][l] == '#') {
					cout << (char)179 << " ";
				}
				else if (player_board[k][l] == 'P') {
					cout << (char)80 << " ";
				}
				else if (player_board[k][l] == 'S') {
					cout << (char)83 << " ";
				}
				else if (player_board[k][l] == 'D') {
					cout << (char)68 << " ";
				}
				else if (player_board[k][l] == 'H') {
					cout << (char)72 << " ";
				}
				else if (player_board[k][l] == '!') {
					cout << (char)33 << " ";
				}
				else if (player_board[k][l] == '$') {
					cout << (char)237 << " ";
				}
			}
			cout << setw(17) << (char)b++;
			for (int m = 0; m < 12; m++) {
				if (player_attack_radar[k][m] == '-') {
					cout << (char)248 << " ";
				}
				else if (player_attack_radar[k][m] == '#') {
					cout << (char)179 << " ";
				}
				else if (player_attack_radar[k][m] == '!') {
					cout << (char)33 << " ";
				}
				else if (player_attack_radar[k][m] == '$') {
					cout << (char)237 << " ";
				}
			}cout << endl;
		}a = 65;
		b = 65;
		cout << setw(32) << (char)192;
		for (int o = 0; o < 21; o++) {
			cout << (char)196;
		}cout << (char)217 << setw(19) << (char)192;
		for (int p = 0; p < 21; p++) {
			cout << (char)196;
		}cout << (char)217 << endl << endl;
	}

	void take_player_input() {
		do {
			valid_ship_position = true;
			if (ship_number == 0) {
				cout << setw(90) << "Hay nhap toa do cua tau tuan tra(2 o): ";
			}
			else if (ship_number == 1) {
				cout << setw(89) << "Hay nhap toa do cua tau ngam(3 o): ";
			}
			else if (ship_number == 2) {
				cout << setw(88) << "Hay nhap toa do cua tau khu truc(4 o): ";
			}
			else if (ship_number == 3) {
				cout << setw(91) << "Hay nhap toa do cua tau sau bay (5 o): ";
			}
			cin.getline(player_ship_coordinates, 11, '\n');
			cout << endl << endl;
			check_for_correct_coordinates();
			print_player_board_and_attack_radar();
			if (valid_ship_position == true) {
				ship_number++;
			}
		} while (!valid_ship_position || ship_number < 4);
	}

	void check_for_correct_coordinates() {

		if (player_ship_coordinates[0] < 'a' || player_ship_coordinates[0] > 'j' ||
			player_ship_coordinates[1] < '0' || player_ship_coordinates[1] > '9')
		{
			valid_ship_position = false;
			print_player_board_and_attack_radar();
			cout << setw(91) << "Toa do nhap ko hop le " << endl;
			cout << setw(98) << "Xin chac rang ban nhap toa do la 1 chu cai + 1 so  vd nhu: a3" << endl;
			Sleep(5000);
		}
		else {
			assign_values_of_row_column();
			check_for_valid_cell();
		}
	}

	void check_for_valid_cell() {
		if (player_board[row][col] == '-') {
			if (ship_number == 0) {
				player_board[row][col] = 'P';
			}
			else if (ship_number == 1) {
				player_board[row][col] = 'S';
			}
			else if (ship_number == 2) {
				player_board[row][col] = 'D';
			}
			else if (ship_number == 3) {
				player_board[row][col] = 'H';
			}
			ask_player_for_horizontal_or_vertical();
		}
		else {
			print_player_board_and_attack_radar();
			cout << setw(92) << "Toa do nay da co tau duoc dat" << endl << endl;
			Sleep(3000);
			valid_ship_position = false;
		}
	}

	void ask_player_for_horizontal_or_vertical() {

		print_player_board_and_attack_radar();
		cout << setw(28) << player_ship_coordinates[0] << player_ship_coordinates[1] << " Hay nhan (h) de dat tau nam nganh hoac (v) de dat tau nam doc: ";
		cin.getline(hv, 10, '\n');
		if (hv[0] == 'h') {
			if (ship_number == 0 && player_board[row][col + 1] == '-') {
				player_board[row][col + 1] = 'P';
			}
			else if (ship_number == 1 && player_board[row][col + 1] == '-' && player_board[row][col + 2] == '-') {
				player_board[row][col + 1] = 'S';
				player_board[row][col + 2] = 'S';
			}
			else if (ship_number == 2 && player_board[row][col + 1] == '-' && player_board[row][col + 2] == '-' &&  player_board[row][col + 3] == '-') {
				player_board[row][col + 1] = 'D';
				player_board[row][col + 2] = 'D';
				player_board[row][col + 3] = 'D';
			}
			else if (ship_number == 3 && player_board[row][col + 1] == '-' && player_board[row][col + 2] == '-' &&  player_board[row][col + 3] == '-' && player_board[row][col + 4] == '-') {
				player_board[row][col + 1] = 'H';
				player_board[row][col + 2] = 'H';
				player_board[row][col + 3] = 'H';
				player_board[row][col + 4] = 'H';
			}
			else {
				print_player_board_and_attack_radar();
				cout << setw(85) << "Loi. Ko du cho de dat nam ngang" << endl << endl;
				Sleep(3000);
				player_board[row][col] = '-';
				valid_ship_position = false;
			}
		}
		else if (hv[0] == 'v') {
			if (ship_number == 0 && player_board[row + 1][col] == '-') {
				player_board[row + 1][col] = 'P';
			}
			else if (ship_number == 1 && player_board[row + 1][col] == '-' && player_board[row + 2][col] == '-') {
				player_board[row + 1][col] = 'S';
				player_board[row + 2][col] = 'S';
			}
			else if (ship_number == 2 && player_board[row + 1][col] == '-' && player_board[row + 2][col] == '-' &&  player_board[row + 3][col] == '-') {
				player_board[row + 1][col] = 'D';
				player_board[row + 2][col] = 'D';
				player_board[row + 3][col] = 'D';
			}
			else if (ship_number == 3 && player_board[row + 1][col] == '-' && player_board[row + 2][col] == '-' &&  player_board[row + 3][col] == '-' && player_board[row + 4][col] == '-') {
				player_board[row + 1][col] = 'H';
				player_board[row + 2][col] = 'H';
				player_board[row + 3][col] = 'H';
				player_board[row + 4][col] = 'H';
			}
			else {
				print_player_board_and_attack_radar();
				cout << setw(85) << "Loi. Ko du cho de dat nam doc." << endl << endl;
				Sleep(3000);
				player_board[row][col] = '-';
				valid_ship_position = false;
			}
		}
		else {
			print_player_board_and_attack_radar();
			cout << setw(105) << "Hay nhan (h) de dat tau nam nganh hoac (v) de dat tau nam doc." << endl << endl;
			player_board[row][col] = '-';
			Sleep(5000);
			valid_ship_position = false;
		}
	}

	void tell_player_shits_about_to_get_real() {
		for (int i = 0; i < 4; i++) {
			system("CLS");
			system("Color 0C");
			for (int i = 0; i < 18; i++) {
				cout << endl;
			}   Sleep(500);
			cout << setw(74) << "Chuan bi....";
			Sleep(500);
		}
	}

	void take_computer_input() {

		do {
			system("CLS");
			system("Color 3A");
			for (int i = 0; i < 19; i++) {
				cout << endl;
			}
			cout << setw(90) << "Doi cho may sap xep tau vao vi tri ......";
			valid_computer_ship_position = true;
			srand(time(0));
			computer_row = rand() % 11;
			computer_col = rand() % 11;
			check_if_computer_move_is_valid();
			if (valid_computer_ship_position == true) {
				computer_ship++;
			}
		} while (computer_ship < 4 || !valid_computer_ship_position);

		system("CLS");
		for (int i = 0; i < 19; i++) {
			cout << endl;
		}
		cout << setw(90) << "Tau cua may da xep xong. Gio den luot ban xep tau";
		Sleep(3000);
		system("CLS");
	}

	void check_if_computer_move_is_valid() {
		if (computer_board[computer_row][computer_col] == '-') {
			if (computer_ship == 0) {
				computer_board[computer_row][computer_col] = 'P';
			}
			else if (computer_ship == 1) {
				computer_board[computer_row][computer_col] = 'S';
			}
			else if (computer_ship == 2) {
				computer_board[computer_row][computer_col] = 'D';
			}
			else if (computer_ship == 3) {
				computer_board[computer_row][computer_col] = 'H';
			}
			computer_chooses_horizontal_or_vertical();
		}
		else {
			valid_computer_ship_position = false;
		}
	}


	void computer_chooses_horizontal_or_vertical() {
		computer_hv = 1 + rand() % 2;
		if (computer_hv == 1) {
			if (computer_ship == 0 && computer_board[computer_row][computer_col + 1] == '-') {
				computer_board[computer_row][computer_col + 1] = 'P';
			}
			else if (computer_ship == 1 && computer_board[computer_row][computer_col + 1] == '-' && computer_board[computer_row][computer_col + 2] == '-') {
				computer_board[computer_row][computer_col + 1] = 'S';
				computer_board[computer_row][computer_col + 2] = 'S';
			}
			else if (computer_ship == 2 && computer_board[computer_row][computer_col + 1] == '-' && computer_board[computer_row][computer_col + 2] == '-' && computer_board[computer_row][computer_col + 3] == '-') {
				computer_board[computer_row][computer_col + 1] = 'D';
				computer_board[computer_row][computer_col + 2] = 'D';
				computer_board[computer_row][computer_col + 3] = 'D';
			}
			else if (computer_ship == 3 && computer_board[computer_row][computer_col + 1] == '-' && computer_board[computer_row][computer_col + 2] == '-' && computer_board[computer_row][computer_col + 3] == '-' && computer_board[computer_row][computer_col + 4] == '-') {
				computer_board[computer_row][computer_col + 1] = 'H';
				computer_board[computer_row][computer_col + 2] = 'H';
				computer_board[computer_row][computer_col + 3] = 'H';
				computer_board[computer_row][computer_col + 4] = 'H';
			}
			else {
				computer_board[computer_row][computer_col] = '-';
				valid_computer_ship_position = false;
			}
		}
		else if (computer_hv == 2) {
			if (computer_ship == 0 && computer_board[computer_row + 1][computer_col] == '-') {
				computer_board[computer_row + 1][computer_col] = 'P';
			}
			else if (computer_ship == 1 && computer_board[computer_row + 1][computer_col] == '-' && computer_board[computer_row + 2][computer_col] == '-') {
				computer_board[computer_row + 1][computer_col] = 'S';
				computer_board[computer_row + 2][computer_col] = 'S';
			}
			else if (computer_ship == 2 && computer_board[computer_row + 1][computer_col] == '-' && computer_board[computer_row + 2][computer_col] == '-' && computer_board[computer_row + 3][computer_col] == '-') {
				computer_board[computer_row + 1][computer_col] = 'D';
				computer_board[computer_row + 2][computer_col] = 'D';
				computer_board[computer_row + 3][computer_col] = 'D';
			}
			else if (computer_ship == 3 && computer_board[computer_row + 1][computer_col] == '-' && computer_board[computer_row + 2][computer_col] == '-' && computer_board[computer_row + 3][computer_col] == '-' && computer_board[computer_row + 4][computer_col] == '-') {
				computer_board[computer_row + 1][computer_col] = 'H';
				computer_board[computer_row + 2][computer_col] = 'H';
				computer_board[computer_row + 3][computer_col] = 'H';
				computer_board[computer_row + 4][computer_col] = 'H';
			}
			else {
				computer_board[computer_row][computer_col] = '-';
				valid_computer_ship_position = false;
			}
		}
		system("CLS");
	}

	void player_sets_attack() {
		do {
			valid_attack_coordinates = true;
			print_player_board_and_attack_radar();
			cout << setw(76) << "Hay nhap toa do tan cong : ";
			cin.getline(player_attack_coordinates, 10, '\n');

			check_for_correct_attack_coordinates();
			if (computer_ship_space_on_board == 0) {
				for (int i = 0; i < 6; i++) {
					system("CLS");
					system("Color 4E");
					for (int i = 0; i < 19; i++) {
						cout << endl;
					}
					Sleep(500);
					cout << setw(60) << name << " WINNN!!!" << endl;
					Sleep(500);
				}
				credits();
			}
			else if (valid_attack_coordinates == true) {
				Sleep(3000);
				print_player_board_and_attack_radar();
				computer_sets_attack();
			}
		} while (!valid_attack_coordinates || computer_ship_space_on_board > 0);
	}

	void check_for_correct_attack_coordinates() {
		if (player_attack_coordinates[0] < 'a' || player_attack_coordinates[0] > 'j' ||
			player_attack_coordinates[1] < '0' || player_attack_coordinates[1] > '9') {
			valid_attack_coordinates = false;
			system("CLS");
			print_player_board_and_attack_radar();
			cout << setw(91) << "Loi .Toa do nhap ko hop le." << endl;
			cout << setw(98) << "Xin chac rang ban nhap toa do la 1 chu cai + 1 so  vd nhu: a3" << endl;
			Sleep(3000);
		}
		else {
			assign_values_of_attack_row_column();
			player_sets_attack_on_board();
		}
	}

	void assign_values_of_row_column() {

		if (player_ship_coordinates[0] == 'a') {
			row = 0;
		}
		else if (player_ship_coordinates[0] == 'b') {
			row = 1;
		}
		else if (player_ship_coordinates[0] == 'c') {
			row = 2;
		}
		else if (player_ship_coordinates[0] == 'd') {
			row = 3;
		}
		else if (player_ship_coordinates[0] == 'e') {
			row = 4;
		}
		else if (player_ship_coordinates[0] == 'f') {
			row = 5;
		}
		else if (player_ship_coordinates[0] == 'g') {
			row = 6;
		}
		else if (player_ship_coordinates[0] == 'h') {
			row = 7;
		}
		else if (player_ship_coordinates[0] == 'i') {
			row = 8;
		}
		else if (player_ship_coordinates[0] == 'j') {
			row = 9;
		}

		if (player_ship_coordinates[1] == '0') {
			col = 1;
		}
		else if (player_ship_coordinates[1] == '1') {
			col = 2;
		}
		else if (player_ship_coordinates[1] == '2') {
			col = 3;
		}
		else if (player_ship_coordinates[1] == '3') {
			col = 4;
		}
		else if (player_ship_coordinates[1] == '4') {
			col = 5;
		}
		else if (player_ship_coordinates[1] == '5') {
			col = 6;
		}
		else if (player_ship_coordinates[1] == '6') {
			col = 7;
		}
		else if (player_ship_coordinates[1] == '7') {
			col = 8;
		}
		else if (player_ship_coordinates[1] == '8') {
			col = 9;
		}
		else if (player_ship_coordinates[1] == '9') {
			col = 10;
		}
	}


	void assign_values_of_attack_row_column() {

		if (player_attack_coordinates[0] == 'a') {
			attack_row = 0;
		}
		else if (player_attack_coordinates[0] == 'b') {
			attack_row = 1;
		}
		else if (player_attack_coordinates[0] == 'c') {
			attack_row = 2;
		}
		else if (player_attack_coordinates[0] == 'd') {
			attack_row = 3;
		}
		else if (player_attack_coordinates[0] == 'e') {
			attack_row = 4;
		}
		else if (player_attack_coordinates[0] == 'f') {
			attack_row = 5;
		}
		else if (player_attack_coordinates[0] == 'g') {
			attack_row = 6;
		}
		else if (player_attack_coordinates[0] == 'h') {
			attack_row = 7;
		}
		else if (player_attack_coordinates[0] == 'i') {
			attack_row = 8;
		}
		else if (player_attack_coordinates[0] == 'j') {
			attack_row = 9;
		}

		if (player_attack_coordinates[1] == '0') {
			attack_col = 1;
		}
		else if (player_attack_coordinates[1] == '1') {
			attack_col = 2;
		}
		else if (player_attack_coordinates[1] == '2') {
			attack_col = 3;
		}
		else if (player_attack_coordinates[1] == '3') {
			attack_col = 4;
		}
		else if (player_attack_coordinates[1] == '4') {
			attack_col = 5;
		}
		else if (player_attack_coordinates[1] == '5') {
			attack_col = 6;
		}
		else if (player_attack_coordinates[1] == '6') {
			attack_col = 7;
		}
		else if (player_attack_coordinates[1] == '7') {
			attack_col = 8;
		}
		else if (player_attack_coordinates[1] == '8') {
			attack_col = 9;
		}
		else if (player_attack_coordinates[1] == '9') {
			attack_col = 10;
		}
	}

	void assigning_computer_coordinates_to_alphabets() {
		if (computer_attack_row == 0) {
			first_computer_coordinate = 'a';
		}
		else if (computer_attack_row == 1) {
			first_computer_coordinate = 'b';
		}
		else if (computer_attack_row == 2) {
			first_computer_coordinate = 'c';
		}
		else if (computer_attack_row == 3) {
			first_computer_coordinate = 'd';
		}
		else if (computer_attack_row == 4) {
			first_computer_coordinate = 'e';
		}
		else if (computer_attack_row == 5) {
			first_computer_coordinate = 'f';
		}
		else if (computer_attack_row == 6) {
			first_computer_coordinate = 'g';
		}
		else if (computer_attack_row == 7) {
			first_computer_coordinate = 'h';
		}
		else if (computer_attack_row == 8) {
			first_computer_coordinate = 'i';
		}
		else if (computer_attack_row == 9) {
			first_computer_coordinate = 'j';
		}
	}



	void player_sets_attack_on_board() {
		if (player_attack_radar[attack_row][attack_col] == '!' || player_attack_radar[attack_row][attack_col] == '$') {
			print_player_board_and_attack_radar();
			cout << setw(82) << "Ban da tan cong vao toa do nay.";
			Sleep(3000);
			valid_attack_coordinates = false;
		}
		else if (computer_board[attack_row][attack_col] == 'P') {
			print_player_board_and_attack_radar();
			cout << setw(84) << "Ban da ban trung tau tuan tra cua dich.";
			player_attack_radar[attack_row][attack_col] = '!';
			patrol_boat_size--;
			computer_ship_space_on_board--;
		}
		else if (computer_board[attack_row][attack_col] == 'S') {
			print_player_board_and_attack_radar();
			cout << setw(84) << "Ban da ban trung tau ngam cua dich.";
			player_attack_radar[attack_row][attack_col] = '!';
			submarine_size--;
			computer_ship_space_on_board--;
		}
		else if (computer_board[attack_row][attack_col] == 'D') {
			print_player_board_and_attack_radar();
			cout << setw(84) << "Ban da ban trung tau khu truc cua dich.";
			player_attack_radar[attack_row][attack_col] = '!';
			destroyer_size--;
			computer_ship_space_on_board--;
		}
		else if (computer_board[attack_row][attack_col] == 'H') {
			print_player_board_and_attack_radar();
			cout << setw(84) << "Ban da ban trung san bay cua dich.";
			player_attack_radar[attack_row][attack_col] = '!';
			helicarrier_size--;
			computer_ship_space_on_board--;
		}
		else {
			print_player_board_and_attack_radar();
			cout << setw(71) << "Ban da ban truot" << endl << endl;
			player_attack_radar[attack_row][attack_col] = '$';
		}

	}

	void print_computer_board() {
		system("CLS");
		system("Color F1");
		cout << endl << endl << endl << endl;
		cout << setw(75) << "You Missed By That Much" << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(73) << "0 1 2 3 4 5 6 7 8 9" << endl;
		cout << setw(52) << " " << (char)218;
		for (int i = 0; i < 21; i++) {
			cout << (char)196;
		}cout << (char)191 << endl;
		for (int i = 0; i < 10; i++) {
			cout << setw(52) << (char)a++;
			for (int j = 0; j < 12; j++) {
				if (computer_board[i][j] == '#') {
					cout << (char)179 << " ";
				}
				else if (computer_board[i][j] == '-') {
					cout << (char)248 << " ";
				}
				else if (computer_board[i][j] == 'P') {
					cout << (char)80 << " ";
				}
				else if (computer_board[i][j] == 'S') {
					cout << (char)83 << " ";
				}
				else if (computer_board[i][j] == 'D') {
					cout << (char)68 << " ";
				}
				else if (computer_board[i][j] == 'H') {
					cout << (char)72 << " ";
				}
			}cout << endl;
		}a = 65;
		cout << setw(52) << " " << (char)192;
		for (int i = 0; i < 21; i++) {
			cout << (char)196;
		}cout << (char)217 << endl << endl;
		Sleep(6000);
	}


	void computer_sets_attack() {
		do {
			valid_computer_attack_coordinates = true;
			computer_attack_row = rand() % 11;
			computer_attack_col = rand() % 11;

			if (patrol_boat_hit == true) {
				if (player_board[computer_attack_row][computer_attack_col] == 'P') {
					computer_sets_attack_on_board();
				}
				else {
					valid_computer_attack_coordinates = false;
				}
			}
			else if (submarine_hit == true) {
				if (player_board[computer_attack_row][computer_attack_col] == 'S') {
					computer_sets_attack_on_board();
				}
				else {
					valid_computer_attack_coordinates = false;
				}
			}
			else if (destroyer_hit == true) {
				if (player_board[computer_attack_row][computer_attack_col] == 'D') {
					computer_sets_attack_on_board();
				}
				else {
					valid_computer_attack_coordinates = false;
				}
			}
			else if (helicarrier_hit == true) {
				if (player_board[computer_attack_row][computer_attack_col] == 'H') {
					computer_sets_attack_on_board();
				}
				else {
					valid_computer_attack_coordinates = false;
				}
			}
			if (patrol_boat_hit == false && submarine_hit == false
				&& destroyer_hit == false && helicarrier_hit == false) {
				computer_sets_attack_on_board();
			}

		} while (!valid_computer_attack_coordinates || player_ship_space_on_board > 0);
	}


	void computer_sets_attack_on_board() {
		assigning_computer_coordinates_to_alphabets();
		if (player_board[computer_attack_row][computer_attack_col] == 'P') {
			cout << setw(82) << "Dich da ban trung tau tuan tra cua ban: " << first_computer_coordinate << computer_attack_col - 1 << endl << endl;
			patrol_boat_hit = true;
			player_board[computer_attack_row][computer_attack_col] = '!';
			player_ship_space_on_board--;
			player_patrol_boat_size--;
		}
		else if (player_board[computer_attack_row][computer_attack_col] == 'S') {
			cout << setw(81) << "Dich da ban trung tau ngam cua ban: " << first_computer_coordinate << computer_attack_col - 1 << endl << endl;
			submarine_hit = true;
			player_board[computer_attack_row][computer_attack_col] = '!';
			player_ship_space_on_board--;
			player_submarine_size--;
		}
		else if (player_board[computer_attack_row][computer_attack_col] == 'D') {
			cout << setw(81) << "Dich da ban trung tau khu truc cua ban: " << first_computer_coordinate << computer_attack_col - 1 << endl << endl;
			destroyer_hit = true;
			player_board[computer_attack_row][computer_attack_col] = '!';
			player_ship_space_on_board--;
			player_destroyer_size--;
		}
		else if (player_board[computer_attack_row][computer_attack_col] == 'H') {
			cout << setw(81) << "Dich da ban trung tau san bay cua ban: " << first_computer_coordinate << computer_attack_col - 1 << endl << endl;
			helicarrier_hit = true;
			player_board[computer_attack_row][computer_attack_col] = '!';
			player_ship_space_on_board--;
			player_helicarrier_size--;
		}
		else if (player_board[computer_attack_row][computer_attack_col] == '-') {
			cout << setw(73) << "Dich ban truot " << first_computer_coordinate << computer_attack_col - 1 << endl << endl;
			player_board[computer_attack_row][computer_attack_col] = '$';
		}
		else {
			valid_computer_attack_coordinates = false;
		}
		clear_hit();
		if (player_ship_space_on_board == 0) {
			for (int i = 0; i < 6; i++) {
				system("CLS");
				system("Color 2E");
				for (int i = 0; i < 19; i++) {
					cout << endl;
				}
				Sleep(500);
				cout << setw(72) << "May tinh thang!!!" << endl;
				Sleep(500);
			}
			print_computer_board();
			credits();
		}
		else if (valid_computer_attack_coordinates == true) {
			Sleep(3000);
			player_sets_attack();
		}
	}

	void clear_hit() {
		if (player_helicarrier_size == 0) {
			helicarrier_hit = false;
		}if (player_submarine_size == 0) {
			submarine_hit = false;
		}if (player_patrol_boat_size == 0) {
			patrol_boat_hit = false;
		}if (player_destroyer_size == 0) {
			destroyer_hit = false;
		}
	}

	void instructions() {
		system("Color F0");
		cout << endl << endl << endl;

		cout << setw (85) << "Xin chao! Cam on ban da choi Battleship." << endl << endl;
		cout << setw (100) << "Day là mot tro choi thu vi và don gian và ban duoc dam bao se co mot khoang thoi gian vui ve." << endl << endl;
		cout << setw (118) << "Cac quy tac kha don gian, dau tien, may tinh se thiet lap cac tau cua no tren bang và sau do ban se lam yuong tu" << endl << endl;
		cout << setw (120) << "Ban can nhap toa do de dat va tan cong tau. VD: - a3, j9, b1, c5 v.v ... Hay chac chan khi nhap" << endl << endl;
		cout << setw (104) << "toa do, bat ky bang chu cai nao tu a-j, theo sau la mot so tu 0-9 duoc nhap vao." << endl << endl;
		cout << setw (100) << "Ca ban va may tinh se duoc dua ra 4 chiec thuyen de dat tren ban co." << endl << endl;
		cout << setw (115) << "Mot Thuyen Tuan tra duoc bieu thi bang chu 'P', mot Tau ngam 'S', mot Tau khu truc 'D', và tat nhiên," << endl << endl;
		cout << setw (116) << " mot Tau san bay duoc bieu thi bang chu 'H'. Tat ca cac tau nay can duoc dat " << endl << endl;
		cout << setw (80) << "ngang hay doc." << endl << endl;
		cout << setw (91) << "Khi ban da hoan thanh, da den luc cho cuoc chien bat dau !!!" << endl << endl;
		cout << setw (102) << "Ca ban va may tinh se thay phien nhau và co gang danh chim tau cua nhau." << endl << endl;
		cout << setw (79) << "Nguoi dau tien danh chìm ca 4 tau se chien thang !!!" << endl << endl;
		cout << setw (30) << "Bieu tuong (" << (char) 237 << ") hien thi cho viec ban tan cong truot" << endl << endl;
		cout << setw (87) << "do dó, lo?i bo kha nang tan cong vao vi tri do." << endl << endl;
		cout << setw (31) << "Mat khac (" << (char) 33 << ") hien thi viec ban hoac may tinh da ban trung tau cua doi thu." << endl << endl;
		cout << setw (112) << "Do la luat cua tro choi. Hay an nut 'esc' de thoat ra man hinh chinh de bat dau game moi" << endl << endl;
		cout << setw (95) << "Chuc may man!" << (char) 1 << endl;


	}

	void credits() {
		system("Color 80");
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(84) << "nhóm 12" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(76) << "" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(85) << "" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(68) << "BATTLESHIP" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(69) << "GAME DIRECTOR:" << endl;
		cout << setw(71) << "------------------" << endl;
		cout << setw(69) << "huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(71) << "EXECUTIVE PRODUCERS:" << endl;
		cout << setw(75) << "----------------------------" << endl;
		cout << setw(72) << "loc" << endl;
		cout << setw(67) << "le" << endl << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(71) << "LEAD PROGRAMMER:" << endl;
		cout << setw(76) << "--------------------------" << endl;
		cout << setw(69) << "huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(69) << "ART DIRECTOR:" << endl;
		cout << setw(76) << "----------------------------" << endl;
		cout << setw(69) << "huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(70) << "LEAD DESIGNER:" << endl;
		cout << setw(78) << "------------------------------" << endl;
		cout << setw(69) << "huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(69) << "LEAD EDITOR:" << endl;
		cout << setw(75) << "------------------------" << endl;
		cout << setw(69) << "huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(70) << "UI DEVELOPMENT:" << endl;
		cout << setw(75) << "-------------------------" << endl;
		cout << setw(69) << "huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(70) << "AI DEVELOPMENT:" << endl;
		cout << setw(77) << "-----------------------------" << endl;
		cout << setw(69) << "huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(71) << "SPECIAL THANKS TO:" << endl;
		cout << setw(75) << "--------------------------" << endl;
		cout << setw(67) << "Huy" << endl;
		cout << setw(72) << "Le" << endl;
		cout << setw(72) << "Huy" << endl;
		Sleep(4000);
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(87) << "All rights reserved battleship-game (TM) 2015 (C)" << endl;
		Sleep(4000);
		system("CLS");
		board_clearer();
		print_game_title();
		print_options();
		player_chooses_options();
	}

	void board_clearer() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (player_board[i][j] == 'P' || computer_board[i][j] == 'P' ||
					player_board[i][j] == 'S' || computer_board[i][j] == 'S' ||
					player_board[i][j] == 'D' || computer_board[i][j] == 'D' ||
					player_board[i][j] == 'H' || computer_board[i][j] == 'H' ||
					player_board[i][j] == '!' || player_attack_radar[i][j] == '!' ||
					player_board[i][j] == '$' || player_attack_radar[i][j] == '$') {
					player_board[i][j] = '-';
					computer_board[i][j] = '-';
					player_attack_radar[i][j] = '-';
				}
			}
		}
		computer_ship = 0;
		ship_number = 0;
		computer_ship_space_on_board = 14;
		player_ship_space_on_board = 14;
		patrol_boat_size = 2;
		player_patrol_boat_size = 2;
		submarine_size = 3;
		player_submarine_size = 3;
		destroyer_size = 4;
		player_destroyer_size = 4;
		helicarrier_size = 5;
		player_helicarrier_size = 5;
	}

};




int main() {
	BattleShip b;
	b.print_game_title();
	b.print_options();
	b.player_chooses_options();
}
