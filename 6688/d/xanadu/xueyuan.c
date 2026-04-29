// 幽明山庄
// by yeung. All rights reserved.

#include <combat.h>
#include <ansi.h>

inherit "/std/room/doom.c";

string *all_dirs = ({"north","south","east","west","southwest","northeast","southeast","northwest"});

void create()
{
	set("short", "雪原");
	set("long", @LONG
	这里是一片无垠的雪地，天地之间一片苍茫，两行足迹远远地
延伸出去，似乎永无尽头。此时狂风大作，风中隐隐传来厉啸和“咯咯”
的笑声。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	  "north" : __FILE__,
	  "south" : __FILE__,
	  "east" : __FILE__,
	  "west" : __FILE__,
	  "southeast" : __FILE__,
	  "southwest" : __FILE__,
	  "northeast" : __FILE__,
	  "northwest" : __FILE__,		
	]));

	set("objects", ([
			__DIR__"npc/roc" : 1,
		])
	);
	setup();
}
                                    
int valid_leave(object ob,string dir)
{
	object roc;

	switch(random(15))
	{
	 	case 1:
	 	case 2:		
		case 3:
			write(RED"\n狂风飞雪之中，似乎有什么东西自你上空一掠而过！"NOR);
			if( objectp(roc = find_living("death roc")) )
			{
//				write("幽冥大鹏突然从低垂的云层中破空飞至。\n");
				COMBAT_D->do_attack(roc,ob,roc->query_temp("weapon"),TYPE_QUICK);
				write(YEL"幽冥大鹏振羽长啸，身形转眼消失在云层中。\n\n"NOR);
			}
			return 1;
		default:
			if( dir == all_dirs[random(4)] ) 
				ob->add_temp("doom_trigger",1);
			if( dir == all_dirs[4+random(4)] ) 
				ob->add_temp("doom_trigger",-1); 

			if( ob->query_temp("doom_trigger") == 10)
			{
				write("你终于找到了出口，来到了幽明山庄的正门。\n");
				ob->move(__DIR__"gate");
				ob->delete_temp("doom_trigger");
                                return notify_fail("");
			}                                                           

			if( ob->query_temp("doom_trigger") == -10)
			{
				write("你终于找到了来时的路，渡过了小河，循原路返回。\n");
				ob->move(__DIR__"dukou");        
				ob->delete_temp("doom_trigger");
				return notify_fail("");
			}                                                           
			return 1;
	}

}

