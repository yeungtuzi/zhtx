// /d/xizang/xmly1.c

inherit ROOM;

void create()
{
        set("short", "喜马拉雅山北坡");
        set("long", @LONG
这里是喜马拉雅山北坡,东边山下是一片美丽的草场,南边是上山路.
LONG
        );
        set("exits", ([
         "southup" : __DIR__"xmly2",
	"eastdown" : __DIR__"xmly0",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
