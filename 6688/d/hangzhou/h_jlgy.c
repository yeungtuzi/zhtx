//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIM"满陇桂雨"NOR);
	set("long", @LONG
	虎跑泉涌出的水流到这儿，汇成一个水池，池子四周种满了桂树，
八月来时，满陇桂花飘香，更有微风掠过，花瓣翩然飞在空中，停在清清的
泉水上，如一阵细雨下过，湿润温馨。
LONG
        );
        set("exits", ([
	"south" : __DIR__"h_hup",
	 ]) );
	set("objects",([
	__DIR__"npc/h_girl" : 2,
	]));	

        setup();
}

