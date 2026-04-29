// Room: /d/xingxiu/xxh4.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这里已经是星宿海的深处了,又潮湿又阴冷，唯有这条小路才显示此处有人居住。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xxh5",
  "southwest" : __DIR__"xxh3",
]));
	set("objects", ([
		__DIR__"npc/tianlang" : 1,
		__DIR__"npc/haoshou" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiu");

	setup();
	replace_program(ROOM);
}
