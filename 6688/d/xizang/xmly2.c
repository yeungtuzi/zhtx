// /d/xizang/xmly2.c

inherit ROOM;

void create()
{
        set("short", "上山路");
        set("long", @LONG
这是一条上山小路,山势渐行渐高,已经略有些寒冷.路旁长满了高大的温带树木,几
只不知名的飞鸟不时从你身边掠过,发出悦耳的鸣叫声.
LONG
        );
        set("exits", ([
           "westup" : __DIR__"xmly3",
	"northdown" : __DIR__"xmly1",
]));
	set("objects", ([
		__DIR__"npc/bird" : random(3),
	]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
