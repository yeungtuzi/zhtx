//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "飞来峰底");
	set("long", @LONG
	这儿是著名的飞来峰峰底，景色端地奇丽异常。但这儿这时候没有
踏春的游客，却有个脏脏的和尚。从这儿可以望见飞来峰顶怪石崎岖，上面
似乎有人。但这儿往上全是绝壁，爬上去几乎是不可能的。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_lysi2",
	 ]) );
	set("objects",([
	__DIR__"npc/jigong" : 1,
	]));
	
	setup();
}


	

