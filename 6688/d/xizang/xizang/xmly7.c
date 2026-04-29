// /d/xizang/xmly7.c

inherit ROOM;

void create()
{
        set("short", "雪线");
        set("long", @LONG
从这里往上的山坡终年寒冷,积雪不化,已经没有植物可以生存.站在这里可以看
到四外皆是被强劲山风吹得光秃秃的褐色乱石,一片荒凉, 一道冰川横亘在南边不远
处,北边是下山的方向.
LONG
        );
        set("exits", ([
		  "southup" : __DIR__"xmly8",
		"northdown" : __DIR__"xmly6",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
