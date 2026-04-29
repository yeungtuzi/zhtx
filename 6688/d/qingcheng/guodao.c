// Room: /open/hihi/keep2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"过道"NOR);
	set("long", @LONG
这是连接镖局大厅和林家后院的一条通道，过道不大，而且过道边上又摆
放着一些旧木材，使不大的通道显得更小了，仅能允许两个人肩并肩的通过。
再往西就可以到后院了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "east" : __DIR__"houting1",
	  "west" : __DIR__"houyuan",
	]));
	set("no_clean_up", 0);
	setup();
	
}

void reset()
{
        object ob;
	
        ::reset();
        set("exits/west", __DIR__"houyuan" );
        if( ob = find_object(__DIR__"houyuan") )
                ob->set("exits/east", __DIR__"guodao");
        
}

