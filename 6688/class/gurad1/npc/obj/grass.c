//grass.c
//by tlang
#include <ansi.h>
inherit ITEM;
int decayed;

void create()
{
	set_name(HIW"绛珠仙草"NOR, ({ "fairy grass","grass" }) );
	set("long", "A fairy grass.\n");
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
			tell_room(env,YEL"A beautiful grass comes out.\n"NOR);
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
			set("long","A beautiful grass.\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			tell_room(env,RED"The grass is needing water.\n"NOR);
			set_name(YEL"绛珠仙草"NOR, ({ "dry grass", "grass" }) );
			set("long", "A grass longing for water.\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			tell_room(env,BLK"The grass is dying.And disappeared when wind comes.\n"NOR);
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
		return notify_fail("What do you want to water?\n");
	else {
	if(!present("cold snow",me))
		return notify_fail("You water it and nothing happened?\n");
	me->set("helper",1);
	obj=new("/class/guard/npc/lindy");
	obj->move(env);
	tell_room(env,"When"+RANK_D->query_respect(me)+"water the blue grass,\n"
	"a beautiful girl appear.\n");
	destruct(ob);
		return 1;
	}
	return 1;
}

