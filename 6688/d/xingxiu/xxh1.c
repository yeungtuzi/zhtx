// Room: /d/xingxiu/xxh1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里就是星宿海。说是海，其实是一片湖泊和沼泽。一条小路通向星宿海的深处。
说是路，不过是走的人多了便成了路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	 "north" : __DIR__"xxh2",
	 "eastdown" : "/d/road/xingsuhai",	 
]));
	set("objects", ([
		__DIR__"npc/azi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiu");

	setup();
}

int valid_leave(object me, string dir)
{
	object *obs;
	int i;

	if( (dir == "north") && (me->query("mark/ding_chushi") > 4)  )
		return notify_fail("这个地方你还敢进去，小心丁老怪废了你的武功！\n");
	
	obs = all_inventory(me);
	for(i=0; i<sizeof(obs); i++)
		if( obs[i]->is_character() )
			return notify_fail("背着"+obs[i]->name()+"不嫌累吗？\n");

	return ::valid_leave(me, dir);
}

