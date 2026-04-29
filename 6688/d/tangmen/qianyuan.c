// Room: /d/tangmen/qianyuan.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "前院");
        	set("long", @LONG
这是前院，院里栽了几棵大槐树，还有一口水井，几个唐门六代弟子正在打水，
东西两侧是给客人居住的厢房，门紧闭着。
LONG
        		);
        	set("exits", ([ /* sizeof() == 2 */
  		"north"  : __DIR__"guodao",
  		"south"  : __DIR__"gate",
		]));
        	set("outdoors", "tangmen");

               set("objects",([
                     __DIR__"npc/npc_meng" : 1,
                   ]));
        	setup();
        	replace_program(ROOM);
}

