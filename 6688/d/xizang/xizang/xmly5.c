// /d/xizang/xmly5.c

inherit ROOM;

void create()
{
        set("short", "灌木丛");
        set("long", @LONG
随着山势增高,周围已经没有高大树木,只有一人多高的小灌木到处丛生着.可能
是人迹罕至的缘故,到这里你已经找不到往山上去的路了,下山的路在东边.
LONG
        );
        set("exits", ([
	"eastdown" : __DIR__"xmly4",
	  "westup" : __DIR__"xmly6",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
