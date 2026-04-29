// Room: /u/p/pock/bj/qihedian.c

inherit ROOM;

void create()
{
	set("short", "[1;35m太和殿[2;37;0m");
	set("long", @LONG
这里是太和殿。大殿的正面有一个大匾，上边用汉文和满文写着太和殿 
三个大字。西边是一条长长的走廊，曲曲折折的通往后院。太和殿是皇帝朝 
见文武百官的地方，一般的凡夫俗子是不可能到这里来的。 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shiwei" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"zoulang1",
		"south" : __DIR__"zijincheng",
]));
	set("outdoors", "bj");

	setup();
	replace_program(ROOM);
}
