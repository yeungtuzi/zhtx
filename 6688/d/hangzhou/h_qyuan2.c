//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"曲院风荷"NOR);
	set("long", @LONG
          人常说江南的春色若有十分，那么有七分是在杭州，杭州的春色
若有十分，那么有七分是在西湖。其实很是正确，这里的秀丽景色深刻地体
现了这些话的内容。站在曲院中，望四周一望，只见轻雪般的垂柳，半开的
红荷，在轻风中翩翩起舞，朦胧的远山倒映在闪动着金光的湖水里，让人只
想醉到在这水里，这风中。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_qyuan", 
	"south" : __DIR__"h_xslu",
	 ]) );
	set("objects",([
	__DIR__"npc/pitygirl" : 1,
	__DIR__"npc/woman2" : 1,
	]));
	
        setup();
}

