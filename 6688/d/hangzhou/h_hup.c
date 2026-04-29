//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"虎跑梦泉"NOR);
	set("long", @LONG
	这儿位于大慈山麓，丛山环抱，古寺掩映，溪水潺潺。相传唐代
高僧夜梦神人指点，有两虎跑地作穴涌泉，故名。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_cross2", 
	"north" : __DIR__"h_jlgy",
	 ]) );
	set("objects",([
	__DIR__"npc/kid" : 3,
	]));	
        setup();
}

