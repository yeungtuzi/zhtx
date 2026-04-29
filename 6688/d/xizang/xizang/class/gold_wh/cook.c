// /d/xizang/class/gold_wh/cook.c

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是一间烟熏火燎的厨房.与中原佛教不同,藏边的密宗喇嘛教并不戒荤,所
以这里既有素食,也有肉食,甚至还有酒,不过制作都很粗糙.
LONG
        );
        set("exits", ([
		 "west" : __DIR__"garden",
]));
	set("objects", ([
		__DIR__"obj/meat" : random(4),
		__DIR__"obj/cake" : random(4),
		__DIR__"obj/skin" : random(4),
	]));
	setup();
	replace_program(ROOM);
}
