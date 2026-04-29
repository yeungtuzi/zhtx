//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "飞来峰");
	set("long", @LONG
	这儿就是著名的飞来峰，从这儿可以看见杭州的大部分地方，远处
的平湖秋月，三潭映月，近处的云栖竹径，双峰插云都清晰入目。峰顶很大，
但只有不远处的石亭里有一老一少在对弈。
LONG
        );
        set("exits", ([
	"down"  : __DIR__"h_flf",
	 ]) );
	set("objects",([
	__DIR__"npc/oldplayer" : 1,
	__DIR__"npc/yplayer" : 1,
	]));
	
	setup();
}


	

