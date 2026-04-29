//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "碎石小路");
	set("long", @LONG
	一条碎石子铺成的小路，路上行人不多，而且商人模样的人居多。
也有一些老者，相互提携着，聊着天，快乐地走着。路边有一座寺庙，看
上去年代相当久远了，庙名写得十分清晰：龙井寺。
LONG
        );
        set("exits", ([
	"northeast"  : __DIR__"h_ljlu", 
	"west" : __DIR__"h_ljlu3",
	 ]) );
	set("objects",([
	__DIR__"npc/shang" : 1,
	__DIR__"npc/oldm" : 1,
	]));
	
        setup();
}

