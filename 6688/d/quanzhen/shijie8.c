// Room: /d/quanzhen/shijie8.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
你走在一条又窄又陡的石阶上,一边是悬崖，一边是峭壁，你不禁有些害怕，
前面好象有一个很大的宫殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"gongmen.c",
		"southdown" : __DIR__"shijie7.c",
]));
      set("objects",([
     __DIR__"npc/qzdizi.c" : 2 ,
    ]));

	setup();
	replace_program(ROOM);
}
