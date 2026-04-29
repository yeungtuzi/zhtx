// Room: /u/hacky/quanzhen/shijie1.c
// Made by: hacky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
你走在一条又窄又陡的石阶上,一边是悬崖，一边是峭壁，你不禁有些害怕，
前面好象有一个很大的宫殿。路旁边一条小道通向山后。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shijie2.c",
  "northdown" : __DIR__"road3.c",
  "west" : "/d/gumu/shandao5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
