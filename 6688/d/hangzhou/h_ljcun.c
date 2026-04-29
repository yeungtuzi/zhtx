//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "龙井村");
	set("long", @LONG
	天下大概没有几个人不知道龙井茶的名字，但天下大概也没有几个
人会知道龙井村名。虽然龙井茶产自此处，但除了经营茶叶的商人，谁还会在
意这个呢？这地方并不大，但相当干净，相当温馨，不少采茶姑娘正一边唱
着山歌，一边采着茶，地方美，地方上的人更美。
LONG
        );
        set("exits", ([
	"northeast"  : __DIR__"h_ljlu3", 
	"eastdown" : __DIR__"h_river",
	 ]) );
	set("objects",([
	__DIR__"npc/teagirl" : 3,
	]));
	
        setup();
}

