//jianjun.c
//by emote
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","将军石");
	set("long",
@LONG
这里就是将军石了，从这里极目远眺，向东望去，便可清晰的观赏到朝阳
峰危崖上五指分明，宛如一只巨人左手掌迹。此崖曰：“仙掌崖”，此掌乃是
关中八景之首“华岳仙掌”。传说是巨灵神开山分黄河所留下的掌印。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"down": __DIR__"beike",
		]));
	set("outdoors","huashan"); 
	setup();
	
}

int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="down")
	{
	     tell_object(me,HIC"你恋恋不舍的走下了将军石。\n"NOR);
	 }
	 return 1;
}
