//OBJ:/d/xueshan/npc/obj/hsword2.c
//by tlang for 混世神剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
int dest();

void create()
{
	set_name("混世神剑", ({ "sword" }) );
	set_weight(800);
//        set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",  "千古神器，得之不易。\n");
		set("value", 999);
		set("material", "crimson gold");
        }
        init_sword(50);
	setup();
}

//this is for the sword to disappear.
void init()
{
	remove_call_out("greeting");
	call_out("greeting",1);
}

void greeting()
{
	if(!environment() || environment(this_player())!=environment() )
		return;
	tell_object(this_player(),"the sword goto the dragon.");
	this_player()->start_busy(10);
//	call_out("dest",1);
}

int dest()
{
//	message_vision("the sword goto the dragon.\n");
	destruct(this_object());
}



