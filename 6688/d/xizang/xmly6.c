// /d/xizang/xmly6.c

inherit ROOM;

void create()
{
        set("short", "荒草坡");
        set("long", @LONG
山势越来越高,越来越陡也越来越寒冷,到这里似乎灌木也无法生长,只有一些
稀疏的荒草散布在褐色的乱石间.到这里已经没有道路可言, 南边继续往上就是雪
线了,东边较低的山坡上丛生着灌木,穿过那些灌木丛就是下山的路.
LONG
        );
        set("exits", ([
	"eastdown" : __DIR__"xmly5",
          "westup" : __DIR__"xmly7",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
