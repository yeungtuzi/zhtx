//cold snow
//by tlang
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int decayed;

void create()
{
	set_name(WHT"经年寒雪"NOR, ({ "cold snow","snow" }) );
	set_weight(700);
	if( clonep(this_object()) ) 
	set_default_object(__FILE__);
	else {
	set("long", "妙玉珍藏多年的寒冰冷雪，非常宝贵.\n");
	set("unit", "钵" );
	set("max_liquid", 15);
	}
       	set("liquid", ([
                "type": "water",
                "name": "水",
                "remaining": 15,
                "water_apply": 300,
        ]) );
	decayed=0;
	call_out("decay", 120, 1);
}

int is_grass() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }
//this is for changing this object during a period.
void decay(int phase)
{
	object env,me;
	me=this_player();
	env=environment(me);

	decayed = phase;
	switch(phase) {
		case 1:
			tell_room(env,YEL"雪开始化了。\n"NOR);
			set("long","开始化的雪。\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			tell_room(env,RED"雪化得更快了。\n"NOR);
			set("long", "残雪。\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			tell_room(env,BLK"雪在阳光下渐渐消失。\n"NOR);
			if( environment() ) {
				object *inv;
				int i;
				
				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) inv[i]->move(environment());
			}
			destruct(this_object());
			break;
		}
}

