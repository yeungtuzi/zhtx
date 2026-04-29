// Room: /d/suzhou/xx2.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit ROOM;  

void create()
{
	set("short", RED"小巷子"NOR);
	set("long", @LONG
这是一条昏暗的小巷子，里面充满了不祥的气息。听说有个蒙面人在这里出没，
见人就杀，好吓人喔。你还是别呆在这儿好。这儿几乎一个人影也没有。东边
不远处就是北大街了。
LONG
	);

	set("exits", ([
		"east" : __DIR__"nroad3",
	       	"west" : __DIR__"xx",
	]));      

	setup();
}

int valid_leave(object ob,string dir)
{
	 if( userp(ob) && random(2))
        {
                return notify_fail("你往前走着，两边的景色没有明显的变化。\n");
        }
        return 1;
}


