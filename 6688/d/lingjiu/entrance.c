// Room: /d/lingjiu/entrance.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一条平整的青石大道，路面皆是用长约七尺，宽约三尺的青
石铺成，实难以想象如此高峰之上海洋如此浩大的工程！路两旁
是茫茫松海。往北透过雾气你隐约看到了一座城堡的样子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gate",
  "southdown" : __DIR__"qingshilu",
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
