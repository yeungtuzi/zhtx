// Room: /d/quanzhen/shijie2.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
你走在一条又窄又陡的石阶上,一边是悬崖，一边是峭壁，你不禁有些害怕，
上面就是重阳宫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shijie1.c",
  "southup" : __DIR__"shijie3.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yueru.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
