// Room: /class/qingcheng/inn3f.c

inherit ROOM;

void create()
{
	set("short", "[1;35m卧室[2;37;0m");
	set("long", @LONG
		你来到了酒店的三层，这里是老板和老板娘的卧室，屋子北端摆着一张
大床，上面盖着粉红色的床垫，与那白色的蚊帐，金色的流苏恰好相配。西边
的书架上，书摆得整整齐齐的。南边的窗户(window)吹来习习凉风，你不禁有
点陶醉了。
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
		"shielf" : "这个书架上放满了书，以致你分不出哪一本是有用的,该拿(take)哪一本书(book)呢？
",
		"window" : "你透过窗户，看到了整个镖局的情况，特别是镖局后院。正在这时，镖局后院
传来了一阵轻微的响声，你想再听时，却又什么也没有听到。
",
]));
	set("exits", ([ /* sizeof() == 2 */
		"down" : __DIR__"innup",
		"westdown" : __DIR__"midao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
