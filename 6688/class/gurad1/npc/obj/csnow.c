//cold snow
//by tlang
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int decayed;

void create()
{
	set_name(WHT"经年寒雪"NOR, ({ "cold snow","snow" }) );
	set("long", "妙玉珍藏多年的寒冰冷雪，非常宝贵.\n");
	set("unit", "钵" );
	set("max_liquid", 15);
        set("liquid", ([
                "type": "water",
                "name": "水",
                "remaining": 15,
                "water_apply": 300,
        ]) );
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
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
			tell_room(env,YEL"The snow is begging to disappear.\n"NOR);
			set("long","The snow begans to disappear.\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			tell_room(env,RED"The snow is disappear more quickly.\n"NOR);
			set("long", "Snow left.\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			tell_room(env,BLK"The snow is all disappeared in the sun.\n"NOR);
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

