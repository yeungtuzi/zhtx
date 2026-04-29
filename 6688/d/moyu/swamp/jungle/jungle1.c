// swamp1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/doom.c";

void create()
{
	set("short", "森林边");
	set("long", @LONG
只见丈余远的一棵大树，大树有一枝横桠，横桠上有叶子浓密的地方，有叶子稀疏的
地方，在叶子稀疏的地方，闲闲地生了两个人，闲淡得就像坐在那儿聊天一般，坐的
地方就像他家里的凳椅。
LONG );
	
	set("exits", ([
		"west":"/d/moyu/swamp/tojungle",
		]));
	setup();
}