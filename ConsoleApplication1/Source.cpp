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
int mohre[20][20][4] = { 0 };
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
}
void table(const int n, int x, int y) {
	int k = -(9 * y / 11) / (n - 1);
	int d = -k;
	for (int i = 0; i < n; i++)
	{
		k += d;
		for (int j = 0; j < n; j++)
		{
			al_draw_filled_circle((x - (n - 1)*d) / 2 + (i*(d)), (y - (n - 1)*d) / 2 + (j*(d)), y / 200, al_map_rgb(0, 0, 0)); //drawing tiny circles where tow lines cross each other.
			mohre[i][j][0] = (x - (n - 1)*d) / 2 + (i*(d));
			mohre[i][j][1] = (y - (n - 1)*d) / 2 + (j*(d));
		}
		al_draw_line((x - (n - 1)*d) / 2 + k, (y - (n - 1)*d) / 2, (x - (n - 1)*d) / 2 + k, (y - (n - 1)*d) / 2 + (n - 1)*d, al_map_rgb(0, 0, 0), y / 200);
		al_draw_line((x - (n - 1)*d) / 2, (y - (n - 1)*d) / 2 + k, (x - (n - 1)*d) / 2 + (n - 1)*d, (y - (n - 1)*d) / 2 + k, al_map_rgb(0, 0, 0), y / 200);
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
int taghatoeYaab(float a, float b, const int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((pow((a - (mohre[i][j][0])), 2) + pow(b - (mohre[i][j][1]), 2) < 400) && (mohre[i][j][2] == 0)) {

				return i * 100 + j;
			}
		}
	}
	return -1;
}
void drawmohre(int tgt, int y, int n, int c) {
	int k;
	if (n == 19)k = y / 60;
	else if (n == 13)k = y / 38;
	else if (n == 9)k = y / 25;
	int j = tgt % 100;
	int i = (tgt - j) / 100;
	al_draw_filled_circle(mohre[i][j][0], mohre[i][j][1], k, al_map_rgb(255 * c, 255 * c, 255 * c));
	mohre[i][j][2] = c % 2 + 1;


	al_flip_display();
}
int main() {
	float a, b;
	int  x, y;
	int c = 0;

	int n = 19;
	GetDisplayResolution(x, y);
	start(x, y);
	table(n, x, y);
	while (true) {
		mouseCourser(a, b);
		if (taghatoeYaab(a, b, n) > -1) {
			c++;
			drawmohre(taghatoeYaab(a, b, n), y, n, c % 2);
		}

	}
}