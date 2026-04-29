// Room: /d/quanzhen/shijie4.c

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
  "northup" : __DIR__"shijie5.c",
  "west" : __DIR__"shijie3.c",
]));
       set("objects", ([
       __DIR__"npc/mosheng.c" : 1,
          ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
