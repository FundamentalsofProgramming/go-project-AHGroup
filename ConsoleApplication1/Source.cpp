#include"includess.h"
struct mohre
{
	int x = 0;
	int y = 0;
	int color = 0;
	bool condition = false;
	int shomarande = 0;
	int reshte = 0;
};
int LinesNum = 9;
int shomarande = 0;
int ww = 0;
int yy = 0,tt =0, jj =0, ii = 0;
int qq = 0;
enum lolo
{
	mainmenup, singleplayerp, twoplayerp, gamep, optionp
}part;
void init_display(int x, int y) {
	ALLEGRO_DISPLAY *display = al_create_display(x, y);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
}
void init_text() {
	al_init_font_addon();
	al_init_ttf_addon();
}
void init_bitmap() {
	al_init_image_addon();
}
void create_bitmap(char image_name[], float x, float y, int width, int height)
{
	ALLEGRO_BITMAP  *image = NULL;
	image = al_load_bitmap(image_name);
	al_draw_scaled_bitmap(image, 0, 0,                           // source origin 
		al_get_bitmap_width(image),     // source width 
		al_get_bitmap_height(image),    // source height
		x, y,                           // target origin 
		width, height,                  // target dimensions  
		0                               // flags 
	);
	al_flip_display();
}
bool nn[100] = { false };
void updatedokme(char image_name[], char image_namme[], float a, float b, float x, float y, int width, int height, int i, int &c) {
	if (a > x   && a<x + width  && b>y  && b < y + height && c % 2 == 1) {
		nn[i] = true;
		create_bitmap(image_namme, x, y, width, height), c++;
	}
	else if (c % 2 == 0 && (a < x || a>x + width || b<y || b > y + height))nn[i] = false, create_bitmap(image_name, x, y, width, height), c++;
}
void updatedokmee(char image_name[], char image_namme[], float a, float b, float x, float y, int width, int height, int i, int &c) {
	if (a > x   && a<x + width  && b>y  && b < y + height && c % 2 == 1) {
		nn[i] = true, c++;
		create_bitmap(image_namme, x, y, width, height);
	}
	else if (c % 2 == 0 && (a < x || a>x + width || b<y || b > y + height))nn[i] = false, create_bitmap(image_name, x, y, width, height), c++;
}
void init_primitive() {
	al_init_primitives_addon();
}
int init_mouse() {
	if (!al_install_mouse())
		return -1;
	return 0;
}
void print_text(ALLEGRO_FONT *&font, char text[], int s, int x, int y, int R = 255, int G = 255, int B = 255, char font_name[] = "cambriai.ttf")
{
	font = al_load_ttf_font(font_name, s, 0);
	al_draw_text(font, al_map_rgb(R, G, B), x, y, ALLEGRO_ALIGN_CENTER, text);
	al_flip_display();
}
void GetDisplayResolution(int &x, int &y) {
	ALLEGRO_DISPLAY_MODE   disp_data;
	al_init(); // I'm not checking the return value for simplicity.
	al_init_image_addon();
	al_init_primitives_addon();
	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
	x = disp_data.width;
	y = disp_data.height * 9.37 / 10;
}
void start(int x, int y) {
	init_display(x, y);
	al_rest(2);
	int j = 0;
	for (int i = 0; i < 125; i++)
	{
		if (i < 61)j = i;
		al_clear_to_color(al_map_rgb(i, j, 0));
		al_flip_display();
		al_rest(0.04);
	}
	/*
	init_text();
	ALLEGRO_FONT *font;
	print_text(font, "Go Game", y / 9, x / 2, 5 * y / 12, 255, 255, 255, "cambriai.ttf");
	al_rest(1.5);
	al_flip_display();
	print_text(font, "producted by AH group", y / 45, 13 * x / 20, 12 * y / 23, 255, 255, 255, "cambriai.ttf");
	al_rest(2);
	init_primitive();
	al_draw_rectangle(x / 7-10, 9 * y / 10, x - y / 5 +10, 18 * y / 19, al_map_rgb(255, 255, 255), y / 200);
	print_text(font, "Loading", y / 25, x / 12, y - y / 10, 255, 255, 255, "cambriai.ttf");
	al_flip_display();
	al_rest(1);
	for (int i = x / 7; i < x - y / 5; i+=10)
	{
	al_draw_line(x / 7, y - y / 13, i, y - y / 13, al_map_rgb(255, 255, 255), 25);
	al_flip_display();
	}
	al_rest(1);
	al_clear_to_color(al_map_rgb(125, 61, 0));
	al_flip_display();

*/
}
void table(mohre marble[20][20], const int LinesNum, int x, int y) {
	int k = -(9 * y / 11) / (LinesNum - 1);
	int d = -k;
	for (int i = 0; i < LinesNum; i++)
	{
		k += d;
		for (int j = 0; j < LinesNum; j++)
		{
			al_draw_filled_circle((x - (LinesNum - 1)*d) / 2 + (i*(d)), (y - (LinesNum - 1)*d) / 2 + (j*(d)), y / 200, al_map_rgb(0, 0, 0)); //drawing tiny circles where tow lines cross each other.
			marble[i][j].x = (x - (LinesNum - 1)*d) / 2 + (i*(d));
			marble[i][j].y = (y - (LinesNum - 1)*d) / 2 + (j*(d));
		}
		al_draw_line((x - (LinesNum - 1)*d) / 2 + k, (y - (LinesNum - 1)*d) / 2, (x - (LinesNum - 1)*d) / 2 + k, (y - (LinesNum - 1)*d) / 2 + (LinesNum - 1)*d, al_map_rgb(0, 0, 0), y / 200);
		al_draw_line((x - (LinesNum - 1)*d) / 2, (y - (LinesNum - 1)*d) / 2 + k, (x - (LinesNum - 1)*d) / 2 + (LinesNum - 1)*d, (y - (LinesNum - 1)*d) / 2 + k, al_map_rgb(0, 0, 0), y / 200);
	}
	al_flip_display();
}
void mouseCourser(float &a, float &b) {
	int q = 1;
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;

		}
	}
}
void mainmenu(float x, float y) {
	float a, b;
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	int q = 1, Q = 1, w = 1;
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;
			updatedokme("10.png", "10.1.png", a, b, 3 * x / 8, y / 8, x / 4, y / 8, 0, q);
			updatedokme("8.png", "8.1.png", a, b, 3 * x / 8, 5 * y / 12, x / 4, y / 8, 1, Q);
			updatedokme("9.png", "9.1.png", a, b, 3 * x / 8, 17 * y / 24, x / 4, y / 8, 2, w);
		}
	}
	if (nn[0])part = singleplayerp, nn[8] = false;
	if (nn[1])part = twoplayerp, nn[8] = false;
	if (nn[2])part = optionp;
}
void game(float &a, float &b, float x, float y) {
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	int q = 1, Q = 1, w = 1;
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;
			updatedokme("5.png", "5.1.png", a, b, y / 5, y / 5, y / 4, y / 10, 8, q);
			updatedokme("20.1.png", "20.png", a, b, y / 5, y / 5 + y / 5, y / 4, y / 10, 11, Q);
		}
	}
	if (nn[8])part = mainmenup;
}
void twoplayer(float x, float y) {
	float a, b;
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	int q = 1, Q = 1, w = 1, W = 1, e = 1, E = 1, r = 1;
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;
			if (tt == 0)updatedokme("14.png", "14.1.png", a, b, x / 2 - y / 4, y / 4, y / 8, y / 8, 3, q);
			if (ww == 0)updatedokme("13.png", "13.1.png", a, b, x / 2 - y / 16, y / 4, y / 8, y / 8, 4, Q);
			if (yy == 0)updatedokme("15.png", "15.1.png", a, b, x / 2 + y / 8, y / 4, y / 8, y / 8, 5, w);
			if (qq==0)updatedokme("4.png", "4.1.png", a, b, x / 2 - y / 4, y / 2, y / 4, y / 10, 6, W);
			if (ii == 0)updatedokme("6.png", "6.1.png", a, b, x / 2 + y / 16, y / 2, y / 4, y / 10, 7, e);
			updatedokme("5.png", "5.1.png", a, b, x / 2 + y / 16, 3 * y / 4, y / 4, y / 10, 8, E);
			updatedokme("7.png", "7.1.png", a, b, x / 2 - 5 * y / 16, 3 * y / 4, y / 4, y / 10, 9, r);
		}
	}
	if (nn[3])nn[3]=false,LinesNum = 9,tt=1,ww=0,yy=0, create_bitmap("13.png", x / 2 - y / 16, y / 4, y / 8, y / 8), create_bitmap("15.png", x / 2 + y / 8, y / 4, y / 8, y / 8);
	if (nn[4])nn[4] = false, LinesNum = 13, ww = 1, tt = 0, yy = 0, create_bitmap("15.png", x / 2 + y / 8, y / 4, y / 8, y / 8), create_bitmap("14.png", x / 2 - y / 4, y / 4, y / 8, y / 8);
	if (nn[5])nn[5] = false,LinesNum = 19,yy=1,tt=0,ww=0, create_bitmap("13.png", x / 2 - y / 16, y / 4, y / 8, y / 8), create_bitmap("14.png", x / 2 - y / 4, y / 4, y / 8, y / 8);
	if (nn[6])nn[6] = false,shomarande = 1,qq=1,ii=0, create_bitmap("6.png", x / 2 + y / 16, y / 2, y / 4, y / 10);//dokme
	if (nn[7] )nn[7] = false,shomarande = 0,qq=0,ii=1, create_bitmap("4.png", x / 2 - y / 4, y / 2, y / 4, y / 10);//dokme
	if (nn[8] || nn[9]) {
		if (nn[8])part = mainmenup;
		if (nn[9]) part = gamep;
	}
	else twoplayer(x, y);

}
int taghatoeYaab(mohre marble[20][20], float a, float b, const int LinesNum) {
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if ((pow((a - (marble[i][j].x)), 2) + pow(b - (marble[i][j].y), 2) < 400) && (marble[i][j].condition == false)) {
				return i * 100 + j;
			}
		}
	}
	return -1;
}
void reshte(mohre marble[20][20], int i, int j, int color, const int LinesNum, int shomarande) {
	for (int h = -1; h < 2; h++)
	{
		for (int v = -1; v < 2; v++)
		{
			if (h*v != 0) continue;
			if (i + h<0 || j + v<0 || i + h >= LinesNum || h + v >= LinesNum)continue;
			if (marble[i + h][j + v].color == color && marble[i + h][j + v].reshte != shomarande) {
				marble[i + h][j + v].reshte = shomarande;
				reshte(marble, i + h, j + v, color, LinesNum, shomarande);
			}
		}
	}
}
int Capturing(mohre marble[20][20], int LinesNum) {
	int sw;
	int sw1 = 0;
	bool A[20][20] = { false };
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (!marble[i][j].condition) continue;
			sw = 0;
			for (int h = -1; h < 2; h++)
			{
				for (int v = -1; v < 2; v++)
				{
					if (h*v) continue;
					if (i + h<0 || j + v<0 || i + h >= LinesNum || j + v >= LinesNum)continue;
					if (!marble[i + h][j + v].condition) sw = 1;
					if (sw == 1) break;
				}
				if (sw == 1) break;
			}
			if (sw == 0) {
				A[i][j] = true;
			}
		}
	}
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (A[i][j]) {
				if (!marble[i][j].reshte) {
					marble[i][j].reshte = 0;
					marble[i][j].condition = false;
					//marble[i][j].color = 0;
					sw1++;
				}
				else {
					sw = 0;
					for (int f = 0; f < LinesNum; f++)
					{
						for (int l = 0; l < LinesNum; l++)
						{
							if (marble[i][j].reshte == marble[f][l].reshte && A[f][l] == false) {
								sw++;
								break;
							}
						}
						if (sw) break;

					}
					if (!sw) {
						for (int f = 0; f < LinesNum; f++)
						{
							for (int l = 0; l < LinesNum; l++)
							{
								if (marble[i][j].reshte == marble[f][l].reshte) {
									marble[f][l].condition = false;
									//marble[f][l].color = 0;
									//marble[f][l].reshte = 0;
									sw1++;
									/*









									INJA BAYAD marble[f][l] AZ SAFHE HAZF SHE VA EMTIAZESH BE RANG DIGE BERE :|










									*/
								}
							}
						}
					}
				}
			}
		}
	}
	return sw1;
	return 0;
}
void printmarble(mohre marble[20][20], int LinesNum) {
	system("CLS");
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			printf("%d ", marble[j][i].color);
		}
		printf("\n");
	}
}
void drawmohre(mohre marble[20][20], int tgt, int y, int LinesNum, int shomarande) {
	int c = shomarande % 2;
	int k;
	if (LinesNum == 19)k = y / 60;
	if (LinesNum == 13)k = y / 38;
	if (LinesNum == 9)k = y / 25;
	int j = tgt % 100;
	int i = (tgt - j) / 100;
	al_draw_filled_circle(marble[i][j].x, marble[i][j].y, k, al_map_rgb(255 * c, 255 * c, 255 * c));
	al_flip_display();
	marble[i][j].color = c + 1;
	marble[i][j].condition = true;
	marble[i][j].shomarande = shomarande;
	reshte(marble, i, j, marble[i][j].color, LinesNum, shomarande);
}
int suicide(mohre marble[20][20], int LinesNum, int tgt, int &shomarande) {
	int j = tgt % 100;
	int i = (tgt - j) / 100;
	if (marble[i][j].condition == false && !marble[i][j].reshte) {
		marble[i][j].condition = true;
		marble[i][j].color = shomarande % 2 + 1;
		Capturing(marble, LinesNum);
		if (marble[i][j].condition) return 2;
		else {
			shomarande--;
			return 1;
		}
	}
	return 0;
}
void RefreshScreen(mohre marble[20][20], const int LinesNum, int x, int y) {
	al_clear_to_color(al_map_rgb(125, 61, 0));
	table(marble, LinesNum, x, y);
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (marble[i][j].condition) {
				int tgt = i * 100 + j;
				drawmohre(marble, tgt, y, LinesNum, marble[i][j].shomarande);
			}
		}
	}
	al_flip_display;
}
int main() {
	mohre marble[20][20];
	float a, b;
	int  x, y, tgt;
	GetDisplayResolution(x, y);
	start(x, y);
	part = mainmenup;
	while (1)
	{
		ALLEGRO_FONT *fona;
		switch (part)
		{
		case mainmenup:
			al_clear_to_color(al_map_rgb(124, 60, 0));
			create_bitmap("10.png", 3 * x / 8, y / 8, x / 4, y / 8);//dokme
			create_bitmap("8.png", 3 * x / 8, 5 * y / 12, x / 4, y / 8);//dokme
			create_bitmap("9.png", 3 * x / 8, 17 * y / 24, x / 4, y / 8);//dokme
			al_flip_display();
			mainmenu(x, y);
			break;
		case twoplayerp:
			init_text();
			al_clear_to_color(al_map_rgb(100, 100, 0));
			print_text(fona, "Board Size:", 180, x / 4, y / 4, 255, 185, 255, "BuxtonSketch.ttf");
			print_text(fona, "Play as:", 180, x / 4, y / 2, 255, 185, 255, "BuxtonSketch.ttf");
			create_bitmap("14.png", x / 2 - y / 4, y / 4, y / 8, y / 8);//dokme
			create_bitmap("13.png", x / 2 - y / 16, y / 4, y / 8, y / 8);//dokme
			create_bitmap("15.png", x / 2 + y / 8, y / 4, y / 8, y / 8);//dokme
			create_bitmap("4.png", x / 2 - y / 4, y / 2, y / 4, y / 10);//dokme
			create_bitmap("6.png", x / 2 + y / 16, y / 2, y / 4, y / 10);//dokme
			create_bitmap("5.png", x / 2 + y / 16, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("7.png", x / 2 - 5 * y / 16, 3 * y / 4, y / 4, y / 10);//dokme
			al_flip_display();
			twoplayer(x, y);
			break;
		case singleplayerp:
			al_clear_to_color(al_map_rgb(100, 100, 0));
			init_text();
			al_clear_to_color(al_map_rgb(100, 100, 0));
			print_text(fona, "Board Size:", 180, x / 4, y / 4, 255, 185, 255, "BuxtonSketch.ttf");
			print_text(fona, "Play as:", 180, x / 4, y / 2, 255, 185, 255, "BuxtonSketch.ttf");
			create_bitmap("14.png", x / 2 - y / 4, y / 4, y / 8, y / 8);//dokme
			create_bitmap("13.png", x / 2 - y / 16, y / 4, y / 8, y / 8);//dokme
			create_bitmap("15.png", x / 2 + y / 8, y / 4, y / 8, y / 8);//dokme
			create_bitmap("5.png", x / 2 + y / 16, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("7.png", x / 2 - 5 * y / 16, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("4.png", x / 2 - y / 4, y / 2, y / 4, y / 10);//dokme
			create_bitmap("6.png", x / 2 + y / 16, y / 2, y / 4, y / 10);//dokme
			al_flip_display();
			twoplayer(x, y);
			break;
		case gamep:
			al_clear_to_color(al_map_rgb(124, 60, 0));
			create_bitmap("5.png", y / 5, y / 5, y / 4, y / 10);//dokme
			create_bitmap("20.1.png", y / 5, y / 5 + y / 5, y / 4, y / 10);//dokme
			al_flip_display();
			table(marble, LinesNum, x, y);
			while (true) {
				game(a, b, x, y);
				tgt = taghatoeYaab(marble, a, b, LinesNum);
				if (tgt + 1) {
					shomarande++;
					drawmohre(marble, tgt, y, LinesNum, shomarande);
					int sw1 = Capturing(marble, LinesNum);
					printmarble(marble, LinesNum);
					if (sw1) {
						suicide(marble, LinesNum, tgt, shomarande);
						RefreshScreen(marble, LinesNum, x, y);
						create_bitmap("5.png", y / 5, y / 5, y / 4, y / 10);//dokme
						create_bitmap("20.1.png", y / 5, y / 5 + y / 5, y / 4, y / 10);//dokme
					}
				}
				if (nn[8]) {
					nn[8] = false, nn[9] = false;
					break;
				}
				if (nn[11])shomarande++;
			}
			break;
		case optionp:
			break;
		default:
			break;
		}
	}
}