// /d/xizang/class/bad/entrance.c

inherit ROOM;

void create()
{
        set("short", "洞口");
	set("long", @LONG
这里是一个阴森森的洞口,一股劲风呼啸而来,吹得人头发四处乱飘,让人
有些犹豫里面是否住着鬼怪.
LONG
);
	set("exits", ([
		"northdown" : "/d/xizang/valley",
		"southdown" : __DIR__"path0",
	]));
	set("outdoors", "xizang");
	setup();
        replace_program(ROOM);
}
