// Room: /d/xixia/yipintang.c

inherit ROOM;

void create()
{
	set("short", "一品堂");
	set("long", @LONG
这里是一品堂的总部，当年西夏为了对付中原武林，设重金招揽天下
英雄好汉，至今已是人才济济，成为武林中一支不可忽视的力量。其统领
赫连铁树更兼征东大将军，地位显赫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yipintang2",
  "east" : __DIR__"eroad1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shiwei5" : 4,
  __DIR__"npc/heliantieshu" : 1,
]));

	setup();
}

int valid_leave(object who, string dir)
{
	who->delete_temp("hitdownypf");
	who->delete_temp("yptest");
	
	return ::valid_leave(who, dir);
}
