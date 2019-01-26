#include"includess.h"
struct mohre
{
	int x = 0;
	int y = 0;
	int color = 0;
	bool condition = false;
	int shomarande = 0;
	int reshte = 0;
	int halghe = 0;
};
int timee;
int LinesNum = 9;
int shomarande = 0, ww = 0, yy = 0, tt = 0, jj = 0, ii = 0, qq = 0;
bool nn[100] = { false };
bool hb1 = true, hb2 = true, hb3 = true, hw1 = true, hw2 = true, hw3 = true;
enum lolo
{
	mainmenup, singleplayerp, twoplayerp, gamep, aboutusp, savep, loadp, gameoverp
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
void updatedokme(char image_name[], char image_namme[], float a, float b, float x, float y, int width, int height, int i, int &c) {
	if (a > x   && a<x + width  && b>y  && b < y + height && c % 2 == 1) {
		nn[i] = true;
		create_bitmap(image_namme, x, y, width, height), c++;
	}
	else if (c % 2 == 0 && (a < x || a>x + width || b<y || b > y + height))nn[i] = false, create_bitmap(image_name, x, y, width, height), c++;
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
int qhadr(int i) {
	if (i > 0)return i;
	else return (-i);
}
void start(int x, int y) {
	init_display(x, y);
	al_rest(2);
	int j = 0;
	for (int i = 0; i <125; i++)
	{
		if (i < 61)j = i;
		al_clear_to_color(al_map_rgb(i, j, 0));
		al_flip_display();
		//al_rest(0.04);
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
	for (int i = x / 7; i < x - y / 5; i ++)
	{
	al_draw_line(x / 7, y - y / 13, i, y - y / 13, al_map_rgb(255, 255, 255), 25);
	al_flip_display();
	}

	al_rest(3);*/
	al_clear_to_color(al_map_rgb(125, 61, 0));
	al_flip_display();
	al_rest(1);

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
}
void mouseCourser(float &a, float &b,float x,float y) {
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	int q = 1, Q = 1, w = 1, r = 1, A = 0, B = 0, C = 0, D = 0;
	if (!hb1)B = -30, A = -30;
	if (!hb2)B = -60;
	if (!hw1)B = -30, A = -30;
	if (!hw2)B = -60;
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;
		//	if (!hb3 || !hw3) {
			//	part = gameoverp;
			//	break;
			//}
			updatedokme("5.png", "5.1.png", a, b, y / 7, 3 * y / 4, y / 4, y / 10, 8, q);
			updatedokme("20.1.png", "20.png", a, b, y / 7, 3 * y / 20, y / 4, y / 10, 11, Q);
			updatedokme("save.png", "save.1.png", a, b, y / 7, 9 * y / 20, y / 4, y / 10, 12, r);
			if (timee + 30 <= time(NULL)) {

				if (timee + 120 + A + B <= time(NULL) && hb3 && !hb2&&shomarande % 2 == 1)hb3 = false, create_bitmap("sabz.png", x - y / 10, y / 5, y / 15, y / 15);
				if (timee + 120 + A + B <= time(NULL) && hw3 && !hw2&&shomarande % 2 == 0)hw3 = false, create_bitmap("sabz.png", x - y / 10, y / 15, y / 15, y / 15);


				if (timee + 90 + A + B <= time(NULL) && hb2 && !hb1&&shomarande % 2 == 1)hb2 = false, create_bitmap("sabz.png", x - y / 5, y / 5, y / 15, y / 15);
				if (timee + 90 + A + B <= time(NULL) && hw2 && !hw1&&shomarande % 2 == 0)hw2 = false, create_bitmap("sabz.png", x - y / 5, y / 15, y / 15, y / 15);

				if (timee + 60 <= time(NULL) && hb1&&shomarande % 2 == 1)hb1 = false, create_bitmap("sabz.png", x - y / 5 - y / 10, y / 5, y / 15, y / 15);
				if (timee + 60 <= time(NULL) && hw1&&shomarande % 2 == 0)hw1 = false, create_bitmap("sabz.png", x - y / 5 - y / 10, y / 15, y / 15, y / 15);


			}
		}
	}

	if (nn[8])part = mainmenup;
	if (nn[11])shomarande++;
	if (nn[12])part = savep;
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
			if (!h && !v) continue;
			if (i + h<0 || j + v<0 || i + h >= LinesNum || j + v >= LinesNum)continue;
			if (marble[i + h][j + v].condition && marble[i + h][j + v].color == color && marble[i + h][j + v].reshte != shomarande) {
				marble[i + h][j + v].reshte = shomarande;
				reshte(marble, i + h, j + v, color, LinesNum, shomarande);
			}
		}
	}
}
void reshte2(mohre marble[20][20], int i, int j, int color, const int LinesNum, int shomarande) {
	for (int h = -1; h < 2; h++)
	{
		for (int v = -1; v < 2; v++)
		{
			//if (h*v != 0) continue;
			if (!h && !v) continue;
			if (i + h < 0 || j + v < 0 || i + h >= LinesNum || j + v >= LinesNum)continue;
			if (marble[i + h][j + v].condition && marble[i + h][j + v].color == color && marble[i + h][j + v].halghe != shomarande) {
				marble[i + h][j + v].halghe = shomarande;
				reshte2(marble, i + h, j + v, color, LinesNum, shomarande);
			}
		}
	}
}
int Capturing(mohre marble[20][20], int LinesNum, int &sefid, int &siaah) {
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
			int reshte = marble[i][j].reshte;
			if (A[i][j]) {
				if (!marble[i][j].reshte) {
					if (marble[i][j].color == 2) siaah++;
					else sefid++;
					marble[i][j].condition = false;
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
								if (reshte == marble[f][l].reshte) {
									if (marble[i][j].color == 2) siaah++;
									else sefid++;
									marble[f][l].condition = false;
									printf("\n %d %d \n", f, l);
									//marble[f][l].color = 0;
									marble[f][l].reshte = 0;
									sw1++;

								}
							}
						}
					}
				}
			}
		}
	}
	return sw1;
}
void printmarble(mohre marble[20][20], int LinesNum) {
	//system("CLS");
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			printf("%d ", marble[j][i].halghe);
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
int Suicide(mohre marble[20][20], int LinesNum, int tgt, int &shomarande, int &sefid, int &siaah) {
	int j = tgt % 100;
	int i = (tgt - j) / 100;
	int sw = 0;
	for (int v = -1; v < 2; v++)
	{
		for (int h = -1; h < 2; h++)
		{
			if (i*h != 0) continue;
			if (i + h<0 || j + v<0 || i + h > LinesNum || j + v > LinesNum)continue;
			if (marble[i + h][j + v].color == marble[i][j].color) sw++;
		}
	}
	if (!marble[i][j].condition && (marble[i][j].reshte*(sw - 1) == 0)) {
		marble[i][j].condition = true;
		marble[i][j].color = shomarande % 2 + 1;
		Capturing(marble, LinesNum, sefid, siaah);
		if (marble[i][j].condition) {
			if (marble[i][j].color == 2) siaah--;
			else sefid--;
			return 2;
		}
		else {
			if (marble[i][j].color == 2) siaah -= 2;
			else sefid -= 2;

			shomarande--;
			return 1;
		}
	}
	return 0;
}
void RefreshScreen(mohre marble[20][20], const int LinesNum, int x, int y) {
	int pp;
	al_clear_to_color(al_map_rgb(100, 115, 15));
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
	create_bitmap("5.png", y / 7, 3 * y / 4, y / 4, y / 10);//dokme
	create_bitmap("20.1.png", y / 7, 3 * y / 20, y / 4, y / 10);//dokme
	create_bitmap("save.png", y / 7, 9 * y / 20, y / 4, y / 10);//dokme
	if (hw2)	create_bitmap("l.png", x - y / 5, y / 15, y / 15, y / 15);
	if (hw1)create_bitmap("l.png", x - y / 5 - y / 10, y / 15, y / 15, y / 15);
	if (hw3)	create_bitmap("l.png", x - y / 10, y / 15, y / 15, y / 15);
	al_draw_filled_circle(x - 2 * y / 5, y / 10, 50, al_map_rgb(255, 255, 255));
	if (hb2)create_bitmap("l.png", x - y / 5, y / 5, y / 15, y / 15);
	if (hb1)create_bitmap("l.png", x - y / 5 - y / 10, y / 5, y / 15, y / 15);
	if (hb3)	create_bitmap("l.png", x - y / 10, y / 5, y / 15, y / 15);
	al_draw_filled_circle(x - 2 * y / 5, y / 4, 50, al_map_rgb(0, 0, 0));
	if (shomarande == 0)pp = 1;
	else pp = 0;
	al_draw_filled_circle(3 * y / 2, y / 2, 50, al_map_rgb(255 * pp, 255 * pp, 255 * pp));
	al_flip_display();
	al_flip_display;
}
void BoolEye(bool eye[20][20], mohre marble[20][20], const int LinesNum) {
	int sw;

	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			sw = 0;
			if (marble[i][j].condition) {
				continue;
			}
			for (int h = -1; h < 2; h++)
			{
				for (int v = -1; v < 2; v++)
				{
					if (v*h != 0) continue;
					if (v == 0 && h == 0) continue;
					if (i + h < 0 || j + v < 0 || i + h > LinesNum || j + v > LinesNum) {
						sw++;
						continue;
					}
					if (marble[i + h][j + v].condition) {
						sw++;
					}
				}
				if (sw == 4) {
					/*for (int s = -1; s < 2; s++)
					{
					for (int e = -1; e < 2; e++)
					{
					if (i + s < 0 || j + e < 0 || i + s >= LinesNum || j + e >= LinesNum)continue;
					if (!marble[i + s][j + e].condition) continue;
					for (int ii = 0; ii < LinesNum; ii++)
					{
					for (int jj = 0; jj < LinesNum; jj++)
					{
					if (marble[ii][jj].reshte == marble[i + s][j + e].reshte) marble[ii][jj].reshte = 0;
					}
					}
					}
					}*/
					eye[i][j] = true;
					//printf("%d %d\n", i, j);
				}
			}
		}
	}
}
int SearchAzTah(int A[20], int B[20], int C[20], int D[20]) {
	for (int i = 0; i < 20; i++)
	{
		if (!A[i]) continue;
		for (int j = 0; j < 20; j++)
		{
			if (B[j] != A[i]) continue;
			for (int h = 0; h < 20; h++)
			{
				if (C[h] != A[i]) continue;
				for (int k = 0; k < 20; k++)
				{
					if (D[k] != A[i]) continue;
					printf("\ndddddddd\n");
					return A[i];
				}
			}
		}
	}


	return 0;
}
int BestMove(mohre marble[20][20], const int LinesNum, int shomarande, int sw1) {// age suicide inja nayad oon akhara ke fght ye ja mitoone bezare hamash hamoon ja mizare va oonjam az qza suicide hast 
	int tgt = 0;
	int max = 0;
	int color = (shomarande + 1) % 2 + 1;
	int rate[20][20] = { 0 };
	bool eye[20][20] = { false };
	if (sw1 == 1) {
		int i, j;
		while (true) {
			i = rand();
			j = rand();
			//printf("%d %d", i, j);
			if (!marble[i][j].condition) return i * 100 + j;
		}
	}
	BoolEye(eye, marble, LinesNum);
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (marble[i][j].condition) continue;
			if (eye[i][j]) continue;  //   attention::::::this is temp.
			if (i == 0 || i == LinesNum - 1) rate[i][j]++;
			if (j == 0 || j == LinesNum - 1) rate[i][j]++;
			for (int h = -1; h < 2; h++)
			{
				for (int v = -1; v < 2; v++)
				{
					if (i + h < 0 || j + v < 0 || i + h > LinesNum || j + v > LinesNum) continue;
					if (marble[i + h][j + v].condition && marble[i + h][j + v].color != color) rate[i][j] += 3;
					if (marble[i + h][j + v].condition && marble[i + h][j + v].color == color) rate[i][j] += 2;
				}
			}



			if (rate[i][j] > max) {
				max = rate[i][j];
				tgt = i * 100 + j;
			}
		}
	}
	return tgt;
}
int nobatdehi(mohre marble[20][20], int MultiPlayer, const int LinesNum, int &shomarande, float &a, float &b, int sw1,float x, float y) {
	int tgt = -1;
	bool s=true;
	int pp;
	if (MultiPlayer) {
		while (tgt == -1) {

			mouseCourser(a, b,x,y);
			
			tgt = taghatoeYaab(marble, a, b, LinesNum);
			if (nn[8] || nn[11] || nn[12]) {
				s = false;
				break;
			}
		}
	}
	else if (shomarande % 2) {
		while (tgt == -1) {

			mouseCourser(a, b, x, y);
			tgt = taghatoeYaab(marble, a, b, LinesNum);
			if (nn[8] || nn[11] || nn[12]) {
				s = false;
				break;
			}
		}

	}
	else tgt = BestMove(marble, LinesNum, shomarande, sw1);
	shomarande++;
	if (!s) {
		if (shomarande % 2 == 0)pp = 1;
		else pp = 0; 
		al_draw_filled_circle(3 * y / 2, y / 2, 50, al_map_rgb(255 * pp, 255 * pp, 255 * pp));
		al_flip_display();
		shomarande++;
	}
	timee = time(NULL);
	nn[11] = false;
	return tgt;
}
/*int HalgheRefrence(mohre marble[20][20], int LinesNum, int primei, int primej, int A[20][20], int &sw, int i, int j) {
int divar = 0;
if ((sw - A[i][j])> 2 && qhadr(primei - i) == 1 && qhadr(primej - j) == 1)
{
marble[primei][primej].halghe = (100 * i + j);
return 2;
}
for (int h = -1; h < 2; h++)
{
for (int v = -1; v < 2; v++)
{
if (!v && !h) continue;
if (primei + h < 0 || primej + v < 0 || primei + h > LinesNum || primej + v > LinesNum) {
divar++;
if (divar > 2) return 1;
continue;
}
if (!marble[primei + h][primej + v].condition) continue;
if (marble[primei + h][primej + v].color == marble[i][j].color && !A[primei + h][primej + v]) {
sw++;
A[primei + h][primej + v] = sw;
if (HalgheRefrence(marble, LinesNum, primei + h, primej + v, A, sw, i, j) == 2) {
marble[primei][primej].halghe = (100 * i + j);
return 2;
}
}
}
}
return 0;
}
int HalgheRefrence1(mohre marble[20][20], int LinesNum,int primei,int primej,int i,int j,int A[20][20],int &sw) {
for (int h = -1; h < 2; h++)
{
for (int v = -1; v < 2; v++)
{
A[primei][primej] += 3;
if (marble[primei + h][primej + v].color != marble[i][j].color) continue;
if (!marble[primei + h][primej + v].condition) continue;
if (v == 0 && h == 0) continue;
if (A[primei + h][primej + v]>3) continue;

if (primei + h == 0 || primej + v == 0 || primei + h == LinesNum-1 || primej + v == LinesNum-1) {
if (primei + h == i && primej + v == j) continue;
marble[primei + h][primej + v].halghe = -(100*i+j);
A[primei + h][primej + v] += 3;
return 1;
//else return 0;
}
if (HalgheRefrence1(marble, LinesNum, primei + h, primej + v, i, j,  A, sw)) {
marble[primei + h][primej + v ].halghe = -(100 * i + j);
return 1;
}


}
}
return 0;
}
void halghe(mohre marble[20][20], int LinesNum) {
int primei = 0;
int primej = 0;
for (int i = 0; i < LinesNum; i++)
{
for (int j = 0; j < LinesNum; j++)
{
if (!marble[i][j].condition || marble[i][j].halghe) continue;
primei = i;
primej = j;
int A[20][20] = { 0 };
int sw = 1;
int sw1 = 0;
A[i][j] = sw;
if (HalgheRefrence(marble, LinesNum, primei, primej, A, sw, i, j) == 2) {

}
else if (i == 0 || i == LinesNum-1 || j == 0 || j == LinesNum-1) {
A[20][20] = { 0 };

if (HalgheRefrence1(marble, LinesNum, primei, primej, i, j, A, sw)) {
marble[i][j].halghe = -(100 * i + j);
}
}
}
}
}*/
void halghe1(mohre marble[20][20], int LinesNum, int shomarande) {
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (!marble[i][j].condition) continue;
			if (marble[i][j].halghe) continue;
			reshte2(marble, i, j, marble[i][j].color, LinesNum, shomarande);
		}
	}
}
int InsideOut(mohre marble[20][20], const int LinesNum, int i, int j) {
	int sw1 = 0;
	int swich = 0;
	int tgt = 0;
	int A[20] = { 0 };
	int B[20] = { 0 };
	int C[20] = { 0 };
	int D[20] = { 0 };
	for (int k = 1; LinesNum - k >= i; k++)
	{
		if (marble[LinesNum - k][j].halghe) {
			A[k] = marble[LinesNum - k][j].halghe;
		}
	}
	for (int k = 0; k <= i; k++)
	{
		if (marble[k][j].halghe) {
			B[k] = marble[k][j].halghe;
		}
	}
	for (int k = 1; LinesNum - k >= j; k++)
	{
		if (marble[i][LinesNum - k].halghe) {
			C[k] = marble[i][LinesNum - k].halghe;
		}
	}
	for (int k = 0; k <= j; k++)
	{
		if (marble[i][k].halghe) {
			D[k] = marble[i][k].halghe;
		}
	}
	int search = SearchAzTah(A, B, C, D);
	if (search) {
		for (int i = 0; i < LinesNum; i++)
		{
			for (int j = 0; j < LinesNum; j++)
			{
				if (marble[i][j].halghe == search) {
					return i * 100 + j;
				}
			}
		}
	}
	for (int o = 1; o <= LinesNum / 2; o++)
	{
		if (i >= LinesNum / 2) {
			if (marble[i - o][j].halghe) sw1 = marble[i - o][j].halghe;
		}
		else if (marble[i + o][j].halghe) {
			sw1 = marble[i + o][j].halghe;
		}

	}
	for (int o = 1; o <= LinesNum / 2; o++)
	{
		if (j >= LinesNum / 2) {
			if (sw1 && marble[i][j - o].halghe == sw1) {
				return i * 100 + (j - o);
			}
		}
		else if (sw1 && marble[i][j + o].halghe == sw1) {
			return i * 100 + (j + o);
		}
	}
	return 0;
}
void EmtiazDehi(mohre marble[20][20], int LinesNum, int &shomarande, int &sefid, int &siaah) {
	sefid = siaah = 0;
	int a, b;
	mohre marble2[20][20];
	int tgt, ii, jj;
	halghe1(marble, LinesNum, shomarande);
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			marble2[i][j].color = marble[i][j].color;
			marble2[i][j].condition = marble[i][j].condition;
			marble2[i][j].halghe = marble[i][j].halghe;
			marble2[i][j].reshte = marble[i][j].reshte;
			marble2[i][j].shomarande = marble[i][j].shomarande;
			marble2[i][j].x = marble[i][j].x;
			marble2[i][j].y = marble[i][j].y;
		}
	}
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (marble2[i][j].condition) continue;
			tgt = InsideOut(marble, LinesNum, i, j);
			if (!tgt) continue;
			jj = tgt % 100;
			ii = (tgt - j) / 100;
			marble2[i][j].condition = true;
			marble2[i][j].color = marble2[ii][jj].color;
		}
	}
	if (Capturing(marble2, LinesNum, a, b)) {

		/*for (int i = 0; i < LinesNum; i++)
		{
		for (int j = 0; j < LinesNum; j++)
		{
		if (!reshte) Suicide(marble2, LinesNum, tgt, shomarande, sefid, siaah);
		}
		}*/
	}

	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (marble2[i][j].condition) continue;
			tgt = InsideOut(marble, LinesNum, i, j);
			if (!tgt) continue;
			jj = tgt % 100;
			ii = (tgt - j) / 100;
			marble2[i][j].condition = true;
			marble2[i][j].color = marble2[ii][jj].color;
		}
	}

	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			printf("%d=%d ", marble2[j][i].color, marble2[j][i].condition);
			//if (!marble2[i][j].condition) continue;
			if (marble2[i][j].color == 2) sefid++;
			else if (marble2[i][j].color == 1) siaah++;
			else if (marble[i][j].condition) {
				if (marble[i][j].color == 1) sefid++;
				if (marble[i][j].color == 2) siaah++;
			}
		}
		printf("\n\n");
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
			updatedokme("about.png", "about1.png", a, b, 3 * x / 8, 17 * y / 24, x / 4, y / 8, 2, w);
		}
	}
	if (nn[0])part = singleplayerp, nn[0] = nn[8] = false;
	if (nn[1])part = twoplayerp, nn[1] = nn[8] = false;
	if (nn[2])part = aboutusp, nn[2] = nn[8] = false;
}
void aboutus(float x, float y) {
	float a, b;
	int i = 1;
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
			updatedokme("5.png", "5.1.png", a, b, x / 2 + y / 4, 3 * y / 4, y / 4, y / 10, 9, i);
		}
	}
	if (nn[9])part = mainmenup, nn[9] = false, nn[8] = false;

}
void save(float x, float y) {
	float a, b;
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	int q = 1, Q = 1, w = 1, W = 1, A = 1, E = 1;
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;
			updatedokme("s1.png", "s1.1.png", a, b, x / 2 - y / 8, y / 20, y / 4, y / 10, 12, q);
			updatedokme("s2.png", "s2.1.png", a, b, x / 2 - y / 8, y / 20 + y / 5, y / 4, y / 10, 12, Q);
			updatedokme("s3.png", "s3.1.png", a, b, x / 2 - y / 8, y / 20 + 2 * y / 5, y / 4, y / 10, 12, w);
			updatedokme("s4.png", "s4.1.png", a, b, x / 2 - y / 8, y / 20 + 3 * y / 5, y / 4, y / 10, 12, W);
			updatedokme("s5.png", "s5.1.png", a, b, x / 2 - y / 8, y / 20 + 4 * y / 5, y / 4, y / 10, 12, A);
			updatedokme("5.png", "5.1.png", a, b, x / 2 - 3 * y / 4, 3 * y / 4, y / 4, y / 10, 8, E);
		}
	}
	if (nn[8])part = gamep;
}
void load(float x, float y) {
	float a, b;
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	int q = 1, Q = 1, w = 1, W = 1, A = 1, E = 1;
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;
			updatedokme("s1.png", "s1.1.png", a, b, x / 2 - y / 8, y / 20, y / 4, y / 10, 12, q);
			updatedokme("s2.png", "s2.1.png", a, b, x / 2 - y / 8, y / 20 + y / 5, y / 4, y / 10, 13, Q);
			updatedokme("s3.png", "s3.1.png", a, b, x / 2 - y / 8, y / 20 + 2 * y / 5, y / 4, y / 10, 14, w);
			updatedokme("s4.png", "s4.1.png", a, b, x / 2 - y / 8, y / 20 + 3 * y / 5, y / 4, y / 10, 15, W);
			updatedokme("s5.png", "s5.1.png", a, b, x / 2 - y / 8, y / 20 + 4 * y / 5, y / 4, y / 10, 16, A);
			updatedokme("5.png", "5.1.png", a, b, x / 2 - 3 * y / 4, 3 * y / 4, y / 4, y / 10, 8, E);
		}
	}
	if (nn[8])part = twoplayerp;
}
void twoplayer(float x, float y) {
	float a, b;
	init_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	int q = 1, Q = 1, w = 1, W = 1, e = 1, E = 1, r = 1, f = 1;
	while (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			a = ev.mouse.x;
			b = ev.mouse.y;
			if (tt == 0)updatedokme("14.png", "14.1.png", a, b, x / 2 - y / 4, y / 4, y / 8, y / 8, 3, q);
			if (ww == 0)updatedokme("13.png", "13.1.png", a, b, x / 2 - y / 16, y / 4, y / 8, y / 8, 4, Q);
			if (yy == 0)updatedokme("15.png", "15.1.png", a, b, x / 2 + y / 8, y / 4, y / 8, y / 8, 5, w);
			if (qq == 0)updatedokme("4.png", "4.1.png", a, b, x / 2 - y / 4, y / 2, y / 4, y / 10, 6, W);
			if (ii == 0)updatedokme("6.png", "6.1.png", a, b, x / 2 + y / 16, y / 2, y / 4, y / 10, 7, e);
			updatedokme("5.png", "5.1.png", a, b, x / 2 - y / 2, 3 * y / 4, y / 4, y / 10, 8, E);
			updatedokme("7.png", "7.1.png", a, b, x / 2 + y / 4, 3 * y / 4, y / 4, y / 10, 9, r);
			updatedokme("load.png", "load.1.png", a, b, x / 2 - y / 8, 3 * y / 4, y / 4, y / 10, 10, f);
		}
	}
	if (nn[3])nn[3] = false, LinesNum = 9, tt = 1, ww = 0, yy = 0, create_bitmap("13.png", x / 2 - y / 16, y / 4, y / 8, y / 8), create_bitmap("15.png", x / 2 + y / 8, y / 4, y / 8, y / 8);
	if (nn[4])nn[4] = false, LinesNum = 13, ww = 1, tt = 0, yy = 0, create_bitmap("15.png", x / 2 + y / 8, y / 4, y / 8, y / 8), create_bitmap("14.png", x / 2 - y / 4, y / 4, y / 8, y / 8);
	if (nn[5])nn[5] = false, LinesNum = 19, yy = 1, tt = 0, ww = 0, create_bitmap("13.png", x / 2 - y / 16, y / 4, y / 8, y / 8), create_bitmap("14.png", x / 2 - y / 4, y / 4, y / 8, y / 8);
	if (nn[6])nn[6] = false, shomarande = 1, qq = 1, ii = 0, create_bitmap("6.png", x / 2 + y / 16, y / 2, y / 4, y / 10);//dokme
	if (nn[7])nn[7] = false, shomarande = 0, qq = 0, ii = 1, create_bitmap("4.png", x / 2 - y / 4, y / 2, y / 4, y / 10);//dokme
	if (nn[8] || nn[9] || nn[10]) {
		tt = ww = yy = qq = ii = 0;
		if (nn[8])part = mainmenup;
		if (nn[9]) part = gamep;
		if (nn[10])part = loadp;
	}
	else twoplayer(x, y);

}
void playsong() {
	ALLEGRO_SAMPLE *shot = NULL;
	ALLEGRO_SAMPLE_INSTANCE *songinstance = NULL;
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(10);
	shot = al_load_sample("aaa.ogg");
	al_play_sample(shot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
int main() {
	mohre marble[20][20];
	playsong();
	int MultiPlayer = 1;
	float a, b;
	int tgt;
	int sw1 = 0;
	int  x, y;
	int i, j;
	int reshte;
	int sefid = 0;
	int siaah = 0;
	int primesefid = 0;
	int primesiaah = 0;
	int pp = 0;
	ALLEGRO_FONT *fona;
	GetDisplayResolution(x, y);
	start(x, y);
	//table(marble, LinesNum, x, y);
	al_flip_display();
	part = mainmenup;
	while (1)
	{
		switch (part)
		{
		case mainmenup:
			al_clear_to_color(al_map_rgb(124, 60, 0));
			create_bitmap("10.png", 3 * x / 8, y / 8, x / 4, y / 8);//dokme
			create_bitmap("8.png", 3 * x / 8, 5 * y / 12, x / 4, y / 8);//dokme
			create_bitmap("about.png", 3 * x / 8, 17 * y / 24, x / 4, y / 8);//dokme
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
			create_bitmap("5.png", x / 2 - y / 2, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("7.png", x / 2 + y / 4, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("load.png", x / 2 - y / 8, 3 * y / 4, y / 4, y / 10);//dokme
			al_flip_display();
			twoplayer(x, y);
			if (nn[10]) {
				nn[10] = false;
				break;
			}
			break;
		case singleplayerp:
			init_text();
			al_clear_to_color(al_map_rgb(100, 100, 0));
			print_text(fona, "Board Size:", 180, x / 4, y / 4, 255, 185, 255, "BuxtonSketch.ttf");
			print_text(fona, "Play as:", 180, x / 4, y / 2, 255, 185, 255, "BuxtonSketch.ttf");
			create_bitmap("14.png", x / 2 - y / 4, y / 4, y / 8, y / 8);//dokme
			create_bitmap("13.png", x / 2 - y / 16, y / 4, y / 8, y / 8);//dokme
			create_bitmap("15.png", x / 2 + y / 8, y / 4, y / 8, y / 8);//dokme
			create_bitmap("4.png", x / 2 - y / 4, y / 2, y / 4, y / 10);//dokme
			create_bitmap("6.png", x / 2 + y / 16, y / 2, y / 4, y / 10);//dokme
			create_bitmap("5.png", x / 2 - y / 2, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("7.png", x / 2 + y / 4, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("load.png", x / 2 - y / 8, 3 * y / 4, y / 4, y / 10);//dokme
			al_flip_display();
			twoplayer(x, y);
			if (nn[10]) {
				nn[10] = false;
				break;
			}
		case gamep:

			al_clear_to_color(al_map_rgb(100, 115, 15));
			/*create_bitmap("l.png", x - y / 5, y / 15, y / 15, y / 15);
			create_bitmap("l.png", x - y / 5 - y / 10, y / 15, y / 15, y / 15);
			create_bitmap("l.png", x - y / 10, y / 15, y / 15, y / 15);
			al_draw_filled_circle(x - 2 * y / 5, y / 10, 50, al_map_rgb(255, 255, 255));
			create_bitmap("l.png", x - y / 5, y / 5, y / 15, y / 15);
			create_bitmap("l.png", x - y / 5 - y / 10, y / 5, y / 15, y / 15);
			create_bitmap("l.png", x - y / 10, y / 5, y / 15, y / 15);
			al_draw_filled_circle(x - 2 * y / 5, y / 4, 50, al_map_rgb(0, 0, 0));
			create_bitmap("5.png", y / 7, 3 * y / 4, y / 4, y / 10);//dokme
			create_bitmap("20.1.png", y / 7, 3 * y / 20, y / 4, y / 10);//dokme
			create_bitmap("save.png", y / 7, 9 * y / 20, y / 4, y / 10);//dokme
			al_flip_display();*/
			table(marble, LinesNum, x, y);
			RefreshScreen(marble, LinesNum, x, y);
			if (shomarande == 0)pp = 1;
			else pp = 0;
			al_draw_filled_circle(3 * y / 2, y / 2, 50, al_map_rgb(255 * pp, 255 * pp, 255 * pp));
			al_flip_display();
			timee = time(NULL);
			while (shomarande < 100) {
				if (shomarande % 2 == 0)pp = 1;
				else pp = 0;
				al_draw_filled_circle(3 * y / 2, y / 2, 50, al_map_rgb(255 * pp, 255 * pp, 255 * pp));
				al_flip_display();
				tgt = nobatdehi(marble, MultiPlayer, LinesNum, shomarande, a, b, sw1, x, y);
				if (!hb3 || !hw3)break;
				j = tgt % 100;
				i = (tgt - j) / 100;
				sw1 = 0;
				drawmohre(marble, tgt, y, LinesNum, shomarande);
				reshte = marble[i][j].reshte;
				if (Capturing(marble, LinesNum, sefid, siaah)) {
					if (!reshte) Suicide(marble, LinesNum, tgt, shomarande, sefid, siaah);
					RefreshScreen(marble, LinesNum, x, y);
				}
				//halghe(marble, LinesNum);
				EmtiazDehi(marble, LinesNum, shomarande, primesefid, primesiaah);
				//tempr(marble, LinesNum);
				printf("\nsefid: %d+%d  ;siaah:%d+%d\n", primesefid, sefid, primesiaah, siaah);
				printmarble(marble, LinesNum);
				if (nn[8] || nn[12])
					if (nn[8]) {
						for (int i = 0; i < 20; i++)
						{
							for (int j = 0; j < 20; j++)
							{
								marble[i][j].condition = false;
							}
						}
						nn[8] = nn[9] = false;
						break;
					}
					else {
						nn[12] = false;
						break;
					}
			}
			break;
		case aboutusp:
			init_text();
			al_clear_to_color(al_map_rgb(90, 100, 20));
			create_bitmap("5.png", x / 2 + y / 4, 3 * y / 4, y / 4, y / 10);
			print_text(fona, "This game has been created by AH Group ", 50, x / 2, 5 * y / 12, 255, 255, 255, "cambriai.ttf");
			print_text(fona, "Amirhossein Torkanloo,Hossein Farahmand ", 50, x / 2, 5 * y / 12 + 100, 255, 255, 255, "cambriai.ttf");
			print_text(fona, "Thanks to Saeid Abrishami ,Hosein Mohebbi ,Muhammad Daaraa and .::MAZ::.", 50, x / 2, 5 * y / 12 + 200, 255, 255, 255, "cambriai.ttf");
			print_text(fona, "Ferdowsi University Of Mashhad", 50, x / 2, 5 * y / 12 + 400, 200, 255, 255, "cambriai.ttf");
			print_text(fona, "2018-2019", 50, x / 2, 5 * y / 12 + 500, 200, 255, 255, "cambriai.ttf");
			create_bitmap("f1.png", 3 * y / 2, y / 7, y / 4, y / 4);//ferdowsi picture
			create_bitmap("asd.png", y / 7, 3 * y / 5, y / 2, y / 4);//our picture
			create_bitmap("ah.png", y / 7, y / 7, y / 3, y / 3);//ah groupe picture
			al_flip_display();
			aboutus(x, y);
			break;
		case savep:
			al_clear_to_color(al_map_rgb(90, 100, 20));
			create_bitmap("s1.png", x / 2 - y / 8, y / 20, y / 4, y / 10);//dokme
			create_bitmap("s2.png", x / 2 - y / 8, y / 20 + y / 5, y / 4, y / 10);//dokme
			create_bitmap("s3.png", x / 2 - y / 8, 2 * y / 5 + y / 20, y / 4, y / 10);//dokme
			create_bitmap("s4.png", x / 2 - y / 8, 3 * y / 5 + y / 20, y / 4, y / 10);//dokme
			create_bitmap("s5.png", x / 2 - y / 8, 4 * y / 5 + y / 20, y / 4, y / 10);//dokme
			create_bitmap("5.png", x / 2 - 3 * y / 4, 3 * y / 4, y / 4, y / 10);//dokme
			save(x, y);
			if (nn[8]) {
				nn[8] = false;
				break;
			}
			break;
		case loadp:
			al_clear_to_color(al_map_rgb(90, 100, 20));
			create_bitmap("s1.png", x / 2 - y / 8, y / 20, y / 4, y / 10);//dokme
			create_bitmap("s2.png", x / 2 - y / 8, y / 20 + y / 5, y / 4, y / 10);//dokme
			create_bitmap("s3.png", x / 2 - y / 8, 2 * y / 5 + y / 20, y / 4, y / 10);//dokme
			create_bitmap("s4.png", x / 2 - y / 8, 3 * y / 5 + y / 20, y / 4, y / 10);//dokme
			create_bitmap("s5.png", x / 2 - y / 8, 4 * y / 5 + y / 20, y / 4, y / 10);//dokme
			create_bitmap("5.png", x / 2 - 3 * y / 4, 3 * y / 4, y / 4, y / 10);//dokme
			load(x, y);
			if (nn[8]) {
				nn[8] = false;
				break;
			}
			break;
		case gameoverp:
			init_text();
			al_clear_to_color(al_map_rgb(100, 115, 15));
			create_bitmap("5.png", x / 2 + y / 4, 3 * y / 4, y / 4, y / 10);
			print_text(fona, "Player Wins ", 50, x / 2, 5 * y / 12, 255, 255, 255, "cambriai.ttf");
			al_flip_display();
			aboutus(x, y);
			if (nn[8]) {
				nn[8] = false;
				break;
			}
			break;
		default:
			break;
		}
	}
}/*
 while (shomarande<100) {
 if (shomarande % 2 == 0)pp = 1;
 else pp = 0;
 al_draw_filled_circle(3 * y / 2, y / 2, 50, al_map_rgb(255 * pp, 255 * pp, 255 * pp));
 al_flip_display();
 tgt = nobatdehi(marble, MultiPlayer, LinesNum, shomarande, a, b, sw1);
 if (!hb3 || !hw3)break;
 j = tgt % 100;
 i = (tgt - j) / 100;
 sw1 = 0;
 drawmohre(marble, tgt, y, LinesNum, shomarande);
 reshte = marble[i][j].reshte;
 if (Capturing(marble, LinesNum, sefid, siaah)) {
 if (!reshte) Suicide(marble, LinesNum, tgt, shomarande, sefid, siaah);
 RefreshScreen(marble, LinesNum, x, y);
 create_bitmap("5.png", y / 7, 3 * y / 4, y / 4, y / 10);//dokme
 create_bitmap("20.1.png", y / 7, 3 * y / 20, y / 4, y / 10);//dokme
 create_bitmap("save.png", y / 7, 9 * y / 20, y / 4, y / 10);//dokme
 if (hw2)	create_bitmap("l.png", x - y / 5, y / 15, y / 15, y / 15);
 if (hw1)create_bitmap("l.png", x - y / 5 - y / 10, y / 15, y / 15, y / 15);
 if (hw3)	create_bitmap("l.png", x - y / 10, y / 15, y / 15, y / 15);
 al_draw_filled_circle(x - 2 * y / 5, y / 10, 50, al_map_rgb(255, 255, 255));
 if (hb2)create_bitmap("l.png", x - y / 5, y / 5, y / 15, y / 15);
 if (hb1)create_bitmap("l.png", x - y / 5 - y / 10, y / 5, y / 15, y / 15);
 if (hb3)	create_bitmap("l.png", x - y / 10, y / 5, y / 15, y / 15);
 al_draw_filled_circle(x - 2 * y / 5, y / 4, 50, al_map_rgb(0, 0, 0));
 if (shomarande == 0)pp = 1;
 else pp = 0;
 al_draw_filled_circle(3 * y / 2, y / 2, 50, al_map_rgb(255 * pp, 255 * pp, 255 * pp));
 al_flip_display();
 }
 //halghe(marble, LinesNum);
 EmtiazDehi(marble, LinesNum, shomarande, primesefid, primesiaah);
 //tempr(marble, LinesNum);
 printf("\nsefid: %d+%d  ;siaah:%d+%d\n", primesefid, sefid, primesiaah, siaah);
 printmarble(marble, LinesNum);
 if (nn[8] || nn[12]) {
 nn[8] = nn[9] = nn[12] = false;
 break;
 }
 }
 scanf_s("%d", &a);
 }*/