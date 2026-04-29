// Room: kang1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "康府大门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大威猛的石狮子镇住了
大门两侧。门外有带刀侍卫把守，戒备森严。门边挂着两个灯笼，大门正面
高高挂着一个大匾(bian)。
LONG
	);

	set("exits", ([
		"west" : __DIR__"changjie4",
		"north" : __DIR__"kang2",
	]));
        set("item_desc",([
           "bian":BRED HIC"\n"
		  "*********************\n"
                  "*                   *\n"
                  "*    "+HIW"康亲王府"+HIC"       *\n"
                  "*	            *\n"
                  "*********************\n"NOR,
                ]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
 
    if(dir == "north" && objectp(present("guan bing", environment(me))))
            return notify_fail("官兵拦住你骂道：“你以为你是谁啊？一个寻常百姓，难道还想进府见康大人？！\n你这" + RANK_D->query_rude(me) +"快给我滚远点儿，不然别怪我不客气！”\n");
    
  return ::valid_leave(me, dir);
}
