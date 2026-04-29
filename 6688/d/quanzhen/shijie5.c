// Room: /d/quanzhen/shijie5.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
你走在一条又窄又陡的石阶上,一边是悬崖，一边是峭壁，你不禁有些害怕，
上面不远就是就是重阳宫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie4.c",
  "northwest" : __DIR__"shijie6.c",
]));
        set("objects", ([
      __DIR__"npc/mosheng.c" : 1,
     ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
