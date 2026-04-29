// Room: /d/quanzhen/shijie6.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long",
"你走在一条又窄又陡的石阶上,一边是悬崖，一边是峭壁，你不禁有些害怕.\n"
"上面不远就是就是重阳宫。\n"
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"shijie5.c",
  "northup" : __DIR__"shijie7.c",
]));
        set("objects",([
       __DIR__"npc/kid.c" : 2,
       ]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
