// Room: /d/lingjiu/rock.c

inherit ROOM;

void create()
{
	set("short", "失足岩");
	set("long", @LONG
这里就是断魂崖的失足岩了，整个看上去就象是放在崖上的一块巨石，
摇摇欲坠。前面是一个十余丈宽的山涧，左右两边皆是万丈深渊！前面
你看到一根铁索伸向对岸，但若非轻功绝顶之人，又企敢试之？
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"cliff",
  "north" : __DIR__"chain",
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
