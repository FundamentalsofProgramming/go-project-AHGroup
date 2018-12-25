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
void start(int x, int y) {
	init_display(x, y);
	al_rest(2);
	int j = 0;
	for (int i = 0; i <125; i++)
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
	for (int i = x / 7; i < x - y / 5; i ++)
	{
	al_draw_line(x / 7, y - y / 13, i, y - y / 13, al_map_rgb(255, 255, 255), 25);
	al_flip_display();
	}
	
	al_rest(3);
	al_clear_to_color(al_map_rgb(125, 61, 0));
	al_flip_display();
	al_rest(1);
	*/
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
	al_flip_display();
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
			if (i + h<0 || j + v<0 || i + h >= LinesNum || j + v >= LinesNum)continue;
			if (marble[i + h][j + v].color == color && marble[i + h][j + v].reshte != shomarande) {
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
int suicide(mohre marble[20][20], int LinesNum, int tgt,int &shomarande) {
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
	if (marble[i][j].condition==false && (marble[i][j].reshte * (sw-1) )==0) {
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
int main() {
	mohre marble[20][20];
	float a, b;
	int tgt;
	int shomarande = 0;
	int LinesNum = 9;
	int  x, y;
	GetDisplayResolution(x, y);
	start(x, y);
	table(marble,LinesNum, x, y);
	while (true) {
		mouseCourser(a, b);
		tgt = taghatoeYaab(marble, a, b, LinesNum);
		if (tgt + 1) {
			shomarande++;
			drawmohre(marble,tgt, y, LinesNum, shomarande);
			int sw1 = Capturing(marble, LinesNum);
			printmarble(marble, LinesNum);
			if (sw1) {
				suicide(marble, LinesNum, tgt, shomarande);
				RefreshScreen(marble, LinesNum, x, y);

			}











		}
	}
}