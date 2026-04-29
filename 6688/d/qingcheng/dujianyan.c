// Room: /d/qingcheng/dujianyan.c

inherit ROOM;

void create()
{
	set("short", "都江堰");
	set("long", @LONG
这里是当年李冰奉命在此驻守时，和当地军民共同所建的
都江堰，在当时为当地的人民水利造福非常大，它一直到今天
还在使用，都江堰的成功是有口皆碑的。从中也可以看到
当时修建的不容易。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"qchyidao",
		"west" : __DIR__"shanlu",
]));

	setup();
	replace_program(ROOM);
}
