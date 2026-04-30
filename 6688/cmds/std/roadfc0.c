#include <ansi.h>
#include <room.h>

inherit ROOM;


void create()
{
	// 2026-04-30: unused variable commented out
	// object san, sna;
	set("short", "驿道");
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"roadsf1",
  "south"  : __DIR__"roomshg",
]));

	set("outdoors", "road");

	setup();
	
}

void init()
{	
	object ob;
	int water, food, bellicosity;
	// 2026-04-30: unused variable commented out
	// string outexit;
	if( interactive( ob = this_player()))
	{
	water = ob->query("water");
	food = ob->query("food");
	bellicosity = ob->query("bellicosity");
	water -= (random(4)+ 1) * water / 10;
	food -= (random(2)+ 1) * water / 10;
	bellicosity += random(10);
	ob->set("water", water);
	ob->set("food", food);
	ob->set("bellicosity", bellicosity);	
       }
	ob->start_busy(5);

        if( ob->query_skill("move") >= 99)
        {
		ob->receive_damage("gin", 5);
                ob->receive_damage("kee", 10);
                ob->receive_damage("sen", 5);
		message_vision(HIG"$N施展轻功，脚步如飞...! \n"NOR, ob);
        }
	else if ( ob->query_skill("move") >= 89 && ob->query_skill("move") < 99)
	{
		ob->receive_damage("gin", 10);
                ob->receive_damage("kee", 15);
                ob->receive_damage("sen", 10);
		message_vision(HIG"$N施展轻功，快步向前...! \n"NOR, ob);
	}
        else if ( ob->query_skill("move") >= 79 && ob->query_skill("move") < 89)	{
		ob->receive_damage("gin", 15);
                ob->receive_damage("kee", 15);
                ob->receive_damage("sen", 15);
		message_vision(HIG"$N施展轻功，大步向前...! \n"NOR, ob);	
	}
	else if ( ob->query_skill("move") >= 69 && ob->query_skill("move") < 79)	{
		ob->receive_damage("gin", 15);
                ob->receive_damage("kee", 15);
                ob->receive_damage("sen", 15);
		message_vision(HIG"$N施展轻功，身体轻多了...! \n"NOR, ob);
	}
	else if ( ob->query_skill("move") >= 59 && ob->query_skill("move") < 69)
	{
		ob->receive_damage("gin", 15);
                ob->receive_damage("kee", 20);
                ob->receive_damage("sen", 15);
		message_vision(HIG"$N施展轻功，走的快多了...! \n"NOR, ob);
	}
	else if ( ob->query_skill("move") >= 49 && ob->query_skill("move") < 59)
	{
		ob->receive_damage("gin", 15);
                ob->receive_damage("kee", 20);
                ob->receive_damage("sen", 15);
		message_vision(HIG"$N已可以施展轻功了...! \n"NOR, ob);
	}
	else if ( ob->query_skill("move") >= 39 && ob->query_skill("move") < 49)
	{
		ob->receive_damage("gin", 20);
                ob->receive_damage("kee", 20);
                ob->receive_damage("sen", 20);
		message_vision(HIR"$N轻功好多了，施展起来还不熟练...! \n"NOR, ob);
	}
	else if ( ob->query_skill("move") >= 29 && ob->query_skill("move") < 39)
	{
		ob->receive_damage("gin", 20);
                ob->receive_damage("kee", 20);
                ob->receive_damage("sen", 20);
		message_vision(HIR"$N轻功好多了，还不太会用...! \n"NOR, ob);
	}
	else if ( ob->query_skill("move") >= 19 && ob->query_skill("move") < 29)
	{
		ob->receive_damage("gin", 20);
                ob->receive_damage("kee", 20);
                ob->receive_damage("sen", 20);
		message_vision(HIR"$N轻功较好...! \n"NOR, ob);
	}
	else if ( ob->query_skill("move") >= 9 && ob->query_skill("move") < 19)
	{
		ob->receive_damage("gin", 20);
                ob->receive_damage("kee", 30);
                ob->receive_damage("sen", 20);
		message_vision(HIR"$N轻功较差...! \n"NOR, ob);
	}
	else
	{
		ob->receive_damage("gin", 20);
		ob->receive_damage("kee", 30);
		ob->receive_damage("sen", 20);
                message_vision(HIR"$N轻功太差了，走起来很费劲...！\n"NOR, ob);
	}
       return;
}

