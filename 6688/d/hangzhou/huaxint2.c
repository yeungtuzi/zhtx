//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short", HIM"空中楼阁"NOR);
	set("long", @LONG
	  这儿是大仙小霖和他的夫人住的地方，现在只有他的未婚妻
雪儿，还有一个小姑娘在，小姑娘看上去呆呆的，好象很伤心，又好象
傻傻的样子。
LONG
	);    
	set("exits", ([
		"down" : __DIR__"huaxint",
	]));

 	set("objects",([
	__DIR__"npc/lucy" : 1,
	__DIR__"npc/snower" : 1,
	]));

	set("no_fight", 1);
	
	setup();
}

