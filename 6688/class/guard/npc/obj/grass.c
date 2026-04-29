//grass.c
//by tlang
#include <ansi.h>
inherit ITEM;
int decayed;

void create()
{
	set_name(HIW"绛珠仙草"NOR, ({ "fairy grass","grass" }) );
	set("long", "一棵鲜艳欲滴的仙草。\n");
	set("unit", "株" );
	set("no_get",1);
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
			tell_room(env,YEL"这草仿佛动了一下。\n"NOR);
			switch(random(3)) {
				case 0:
				set_name(RED"绛珠仙草"NOR, ({ "fairy grass", "grass" }) );
					break;
				case 1:
				set_name(BLU"绛珠仙草"NOR, ({"fairy grass", "grass" }) );
					break;
				default:
				set_name(YEL"绛珠仙草"NOR, ({ "fairy grass", "grass" }) );
					break;
				}				
			set("long","一棵非常美丽的仙草。\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			tell_room(env,RED"这草需要浇水了。\n"NOR);
			set_name(YEL"绛珠仙草"NOR, ({ "dry grass", "grass" }) );
			set("long", "一棵急需要水的草。\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			tell_room(env,BLK"一棵将死的草。\n"NOR);
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

void init()
{
	add_action("do_water","water");
}
//this is for player to water grass and call out lin daiyu.
int do_water(string arg)
{
	object me,ob,obj,env;
	me=this_player();
	ob=this_object();
	env=environment(me);

	if(!arg || arg!="fairy grass")
		return notify_fail("泥想给什么东西浇水？\n");
	else {
	if(!present("cold snow",me))
		return notify_fail("你浇完后，什么也没有发生。\n");
	me->set("helper",1);
	obj=new("/class/guard/npc/lindy");
	obj->move(env);
	tell_room(env,"当"+RANK_D->query_respect(me)+"给草浇水后，草不见了，\n"
	"一位貌若天仙的女子出现了。\n");
	destruct(ob);
		return 1;
	}
	return 1;
}

