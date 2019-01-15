#include <stdio.h>
#include <allegro5/allegro.h> 
#include <allegro5/allegro_native_dialog.h> 
#include <allegro5/allegro_ttf.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_native_dialog.h> 
#include <allegro5/allegro_acodec.h>
#include<math.h>
#include <conio.h>
struct mohre
{
	int x = 0 ;
	int y =  0 ;
	int color =  0 ;
	bool condition = false;
	int shomarande = 0;
	int reshte = 0;
};
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
void table(mohre marble[20][20],const int LinesNum, int x, int y) {
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
void mouseCourser(float &x, float &y) {
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
			x = ev.mouse.x;
			y = ev.mouse.y;
		}
	}
}
int taghatoeYaab(mohre marble[20][20],float a, float b, const int LinesNum) {
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
void reshte(mohre marble[20][20], int i,int j, int color, const int LinesNum,int shomarande) {
	for (int h = -1; h < 2; h++)
	{
		for (int v = -1; v < 2; v++)
		{
			if (h*v!=0) continue;
			if (!h && !v) continue;
			if (i + h<0 || j + v<0 || i + h >= LinesNum || j + v >= LinesNum)continue;
			if (marble[i + h][j + v].condition && marble[i + h][j + v].color == color && marble[i + h][j + v].reshte != shomarande) {
				marble[i + h][j + v].reshte = shomarande;
				reshte(marble, i+h,j+v, color, LinesNum,shomarande);
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
					if (!marble[i+h][j+v].condition) sw = 1;
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
			printf("%d ", marble[j][i].condition);
		}
		printf("\n");
	}
}
void drawmohre(mohre marble[20][20],int tgt, int y, int LinesNum, int shomarande) {
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
	reshte(marble, i, j, marble[i][j].color, LinesNum,shomarande);
}
int Suicide(mohre marble[20][20], int LinesNum, int tgt,int &shomarande) {
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
	if (!marble[i][j].condition && (marble[i][j].reshte*(sw-1) ==0)){
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
void RefreshScreen(mohre marble[20][20],const int LinesNum,int x,int y) {
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
void BoolEye(bool eye[20][20], mohre marble[20][20], const int LinesNum) {
	int sw ;

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
					eye[i][j] = true;
					//printf("%d %d\n", i, j);
				}
			}
		}
	}
}
int BestMove(mohre marble[20][20], const int LinesNum, int shomarande,int sw1) {// age suicide inja nayad oon akhara ke fght ye ja mitoone bezare hamash hamoon ja mizare va oonjam az qza suicide hast 
	int tgt = 0;
	int max = 0;
	int color = (shomarande+1) % 2 + 1;
	int rate[20][20] = { 0 };
	bool eye[20][20] = { false };
	if (sw1==1) {
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
			if (i == 0 || i == LinesNum-1) rate[i][j]++;
			if (j == 0 || j == LinesNum-1) rate[i][j]++;
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
int nobatdehi(mohre marble[20][20], int MultiPlayer, const int LinesNum,int &shomarande,float &a,float &b,int sw1) {
	int tgt = -1;
	if (MultiPlayer) {
		while (tgt == -1) {

			mouseCourser(a, b);
			tgt = taghatoeYaab(marble, a, b, LinesNum);
		}
	}
	else if (shomarande % 2) {
		while (tgt == -1) {

			mouseCourser(a, b);
			tgt = taghatoeYaab(marble, a, b, LinesNum);
		}

	}
	else tgt = BestMove(marble, LinesNum, shomarande,sw1);
	shomarande++;
	return tgt;
}
int HalgheRefrence(mohre marble[20][20], int LinesNum, int primei, int primej, int A[20][20], int &sw, int i, int j,int loop[20][20]) {
	int divar = 0;
	if ((sw - A[i][j])> 2 && qhadr(primei - i) == 1 && qhadr(primej - j) == 1)
	{
		loop[primei][primej] = (100 * i + j);
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
				if (HalgheRefrence(marble, LinesNum, primei + h, primej + v, A, sw, i, j, loop) == 2) {
					loop[primei][primej] = (100 * i + j);
					return 2;
				}
			}
		}
	}
	return 0;
}
int HalgheRefrence1(mohre marble[20][20], int LinesNum,int primei,int primej,int i,int j,int loop[20][20],int A[20][20],int &sw) {
	for (int h = -1; h < 2; h++)
	{
		for (int v = -1; v < 2; v++)
		{
			if (primei + h < 0 || primej + v < 0 || primei + h >= LinesNum || primej + v >= LinesNum) {
				if (primei + h != i && primej + v != j && marble[i + h][j + v].condition && marble[i + h][j + v].color == marble[i][j].color) {
					loop[primei + h][primej + v] = 100 * i + j;
					return 1;
				}
				else return 0;
			}
			if (A[primei + h][primej + v]) continue;
			if (HalgheRefrence1(marble, LinesNum, primei + h, primej + v, i, j, loop, A, sw)) {
				loop[primei + h][primej + v ] = 100 * i + j;
				A[primei + h][primej + v] += 3;
				return 1;
			}


		}
	}
	return 0;
}
void halghe(mohre marble[20][20], int LinesNum) {
	int primei = 0;
	int primej = 0;
	int loop[20][20] = { 0 };
	//system("CLS");
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (!marble[i][j].condition || loop[i][j]) continue;
				primei = i;
				primej = j;
				int A[20][20] = { 0 };
				int sw = 1;
				int sw1 = 0;
				A[i][j] = sw;
				if (HalgheRefrence(marble, LinesNum, primei, primej, A, sw, i, j, loop) == 2) {

				}
				else if (i == 0 || i == LinesNum || j == 0 || j == LinesNum) {
					A[20][20] = { 0 };
					HalgheRefrence1(marble, LinesNum, primei, primej, i, j, loop, A, sw);
				}
		}
	}
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{

			printf("%d   ", loop[j][i]);

		}
		printf("\n");

	}
}
/*void EmtiazDehi(mohre marble[20][20],const int LinesNum,int y,int &shomarande) {
	int sefidpoint = 0;
	int siahpoint = 0;
	bool eye[20][20] = { false };
	BoolEye(eye, marble, LinesNum);
	for (int i = 0; i < LinesNum; i++)
	{
		for (int j = 0; j < LinesNum; j++)
		{
			if (!eye[i][j]) continue;
			int rang1 = 0;
			int rang2 = 0;
			for (int h = -1; h < 2; h++)
			{
				for (int v = -1; v < 2; v++)
				{
					if (v*h != 0) continue;
					if (v == 0 && h == 0) continue;
					if (i + h < 0 || j + v < 0 || i + h > LinesNum || j + v > LinesNum) {
						rang1++;
						rang2++;
						continue;
					}
					if (marble[i][j].color == 1) rang1++;
					else rang2++;
				}
			}
			if (rang1 == 4) drawmohre(marble, i * 100 + j, y, LinesNum, 2 * shomarande);
			if (rang2 == 4) drawmohre(marble, i * 100 + j, y, LinesNum, 2 * shomarande + 1);
			shomarande += 3;
		}
	}
}*/
int main() {
	mohre marble[20][20];
	int MultiPlayer = 1;
	float a, b;
	int tgt;
	int sw1 = 0;
	int shomarande = 1;
	int LinesNum = 9;
	int  x, y;
	int i, j;
	int reshte;
	GetDisplayResolution(x, y);
	start(x, y);
	table(marble,LinesNum, x, y);
	al_flip_display();
	while (true) {
		tgt = nobatdehi(marble, MultiPlayer, LinesNum, shomarande, a, b, sw1);
		j = tgt % 100;
		i = (tgt - j) / 100;
		sw1 = 0;
		drawmohre(marble, tgt, y, LinesNum, shomarande);
		reshte = marble[i][j].reshte;
		if (Capturing(marble, LinesNum)) {
			if (!reshte) Suicide(marble, LinesNum, tgt, shomarande);
			RefreshScreen(marble, LinesNum, x, y);
		}
		//halghe(marble, LinesNum);
		//printmarble(marble, LinesNum);
		//printf("%d\n", shomarande);
	}
}