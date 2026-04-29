//仙人桥
//
inherit ROOM;
void create()
{
	set("short","仙人桥");
	set("long",
@LONG
过了几段险峻的石梯，就到了仙人桥，好象山势缓了些，而路上的人也越
来越少。终于在视野中见不到一个人了。唱着歌走在小路上，两边是密密的树
林，潮湿的空气里飘着翠绿的气息。再往上走，一阵阵白色的云雾飘过来，有
些冷了。看看前面没有人，回头看看，也没有人，听着树丛里发出的不知是什
么动物的叫声，你不由心里也有了些寒意。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"baichixia",
		"eastup": __DIR__"laojungou",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

